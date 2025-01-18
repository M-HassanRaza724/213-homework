using System;
using System.IO;

namespace HXA_SOFTWARE_LAB
{
    class Program
    {
        static void Main(string[] args)
        {
            string adminPath = "admins.txt";
            string CustPath = "customers.txt";
            string[,] adminCredentials = new string[2,3];
            string[,] customerCredentials = new string[100,3];
            int total_buyers = 0, total_admins = 0, userType = -1,userIndex = -1;
            int choice = -1;
            bool exit = false;

            string[] credentials = new string[3];
            GetCredentials(adminPath, adminCredentials,ref total_admins);
            GetCredentials(CustPath, customerCredentials,ref total_buyers);
            //Console.WriteLine(adminCredentials[0, 0]); //for debuging purpose
            //Console.WriteLine(customerCredentials[0, 0]);
            while (!exit)
            {
                PrintHeader();
                if(choice == -1)
                {
                    EntryMenu();
                    choice = int.Parse(Console.ReadLine());
                }
                else if (choice == 1)
                {   
                    LoginPage();
                    Console.SetCursorPosition(28, 12);
                    credentials[1] =  Console.ReadLine();
                    Console.SetCursorPosition(28, 15);
                    credentials[2] =  Console.ReadLine();
                    userIndex = EmailAuthenticatorScanner(credentials[1],total_admins,total_buyers,adminCredentials,customerCredentials,ref userType, credentials[2]);
                    if (userType == -1)
                    {
                        Console.WriteLine("Invalid credentials");
                        choice = -1;
                        //Console.ReadKey();
                    }
                    else
                    {
                        Console.WriteLine("Login Successfully");
                        exit = true;
                        //Console.ReadKey();  
                    }
                    
                }
                else if (choice == 2)
                {
                    SignUpPage();
                    Console.SetCursorPosition(28, 12);
                    credentials[0] = Console.ReadLine();
                    Console.SetCursorPosition(28, 15);
                    credentials[1] = Console.ReadLine();
                    if (!EmailValidation(credentials[1]))
                    {
                        Console.SetCursorPosition(0, 22);
                        Console.WriteLine("invalid email...!");
                    }
                    else
                    {
                        Console.SetCursorPosition(28, 18);
                        credentials[2] = Console.ReadLine();
                        if (!PasswordValidation(credentials[2]))
                        {
                            Console.SetCursorPosition(0, 22);
                            Console.WriteLine("A password must have 8 to 16 characters with letters, numbers and special characters...!");
                        }
                        else
                        {
                            userIndex = EmailAuthenticatorScanner(credentials[1], total_admins, total_buyers, adminCredentials, customerCredentials, ref userType);
                            if (userIndex != -1)
                            {
                                Console.WriteLine("Email already exists....");
                                userIndex = -1;
                            }
                            else
                            {
                                RegisterCredentials(credentials, 2, ref total_buyers, adminCredentials, customerCredentials);
                            }
                        }
                    }
                    //RegisterCredentials(credentials, 2, ref total_buyers, adminCredentials, customerCredentials);
                    choice = -1;
                }
                if (choice == 3)
                {
                    choice = -1;
                    exit = true;
                }
                Console.ReadKey();
                Console.Clear();
            }
        }

        static int EmailAuthenticatorScanner(string email, int totalAdmins, int totalCustomers,
                               string[,] adminCredentials, string[,] customerCredentials, ref int userType, string password = "pass")
        {

            for (int j = 0; j < totalAdmins; j++)
            {
                if (adminCredentials[j, 1] == email)
                {
                    if ((password != "pass" && adminCredentials[j, 2] == password) || password == "pass")
                    {
                        //Console.Write("Password is..{0}", password); // debug line
                        if (userType == -1)
                            userType = 1;
                        return j;
                    }
                }
            }

            for (int j = 0; j < totalCustomers; j++)
            {
                if (customerCredentials[j, 1] == email)
                    if ((password != "pass" && customerCredentials[j, 2] == password) || password == "pass")
                    {
                        //Console.Write("Password is..{0}", password); // debug line
                        if (userType == -1)
                            userType = 2;
                        return j; 
                    }
            }

            return -1;
        }
        static bool EmailValidation(string email)
        {
            int rateIdx = -1, dotIdx = -1;
            int emailLen = email.Length;
            
            for (int i = 0;i < emailLen; i++) 
                if (email[i] == ' ')    return false;

            if (email == "" || emailLen < 5)
                return false;

            for (int i = 0; i < emailLen; i++)
            {
                if (email[i] == '@')
                {
                    if (rateIdx != -1)
                        return false;
                    rateIdx = i;
                }
                else if (email[i] == '.')
                    dotIdx = i;
                else if (email[i] == ' ')
                    return false;
            }

            if (rateIdx == -1 || dotIdx == -1 || rateIdx == 0 || rateIdx > dotIdx - 2 || dotIdx == emailLen - 1)
                return false;

            return true;
        }

        static bool PasswordValidation(string password)
        {
            bool hasSpecial = false, hasNumber = false, hasLetter = false;
            int passwordLen = password.Length;

            for (int i = 0; i < passwordLen; i++)
                if (password[i] == ' ') return false;
            
            if ((passwordLen < 8) || (passwordLen > 16 )|| (password == ""))
                return false;

            for (int i = 0;i < passwordLen;i++)
            {
                char a = password[i];

                if ((a > 64 && a < 91) || (a > 96 && a < 123))
                    hasLetter = true;

                if (a > 47 && a < 58)
                    hasNumber = true;

                else if ((a >= 33 && a <= 47) || (a >= 58 && a <= 64) || (a >= 91 && a <= 96) || (a >= 123 && a <= 126))
                    hasSpecial = true;
            }

            return hasSpecial && hasNumber && hasLetter;
        }
        static void RegisterCredentials(string[] credentials, int userType, ref int count,
                        string[,] adminCredentials, string[,] customerCredentials)
        {
            string filePath = "path";

            if (userType == 1)
            {
                filePath = "admins.txt";


                for (int i = 0; i < 3; i++)
                {
                    adminCredentials[count, i] = credentials[i];
                }
            }
            else if (userType == 2)
            {
                filePath = "customers.txt";

                for (int i = 0; i < 3; i++)
                {
                    customerCredentials[count, i] = credentials[i];
                }
            }

            StreamWriter file = new StreamWriter(filePath, append: true);
            {
                file.WriteLine($"{credentials[0]},{credentials[1]},{credentials[2]}");
            }

            count++;
            file.Close();
        }

        static void GetCredentials(string filepath, string[,] credentials, ref int count)
        {
            count = 0;
            string line;
            if (File.Exists(filepath))
            {
                StreamReader file = new StreamReader(filepath);
                while ((line = file.ReadLine()) != null)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        credentials[count, i] = GetField(line, i + 1, ',');
                    }
                    count++;
                }
                file.Close();
            }
            else
            {
                Console.WriteLine("File not exist");
            }
        }
        static string GetField(string data, int fieldCount, char seperator)
        {
            int count = 1;
            string field = string.Empty;
            for (int i = 0; i < data.Length; i++)
            {
                if (data[i] == seperator)
                {
                    count++;
                }
                else if (count == fieldCount)
                {
                    field += data[i];
                }
            }
            return field;
        }
        static void EntryMenu()
        {
            Console.WriteLine("Welcome to HXA Software LAB");
            Console.WriteLine("\t\tMENU");
            Console.WriteLine("1. Log In.");
            Console.WriteLine("2. Sign Up.");
            Console.WriteLine("3. Exit.");
            Console.Write("Enter your choice: ");
        }
        static void LoginPage()
        {
            Console.WriteLine("\t\t\t/------------------------------------------------\\");
            Console.WriteLine("\t\t\t|                     LOGIN                      |");
            Console.WriteLine("\t\t\t|------------------------------------------------|");
            Console.WriteLine("\t\t\t|   EMAIL:                                       |");
            Console.WriteLine("\t\t\t|                                                |");
            Console.WriteLine("\t\t\t|------------------------------------------------|");
            Console.WriteLine("\t\t\t|   PASSWORD:                                    |");
            Console.WriteLine("\t\t\t|                                                |");
            Console.WriteLine("\t\t\t\\------------------------------------------------/");
        }
        static void SignUpPage()
        {
            Console.WriteLine("\t\t\t/------------------------------------------------\\");
            Console.WriteLine("\t\t\t|                    SIGN UP                     |");
            Console.WriteLine("\t\t\t|------------------------------------------------|");
            Console.WriteLine("\t\t\t|   USERNAME:                                    |");
            Console.WriteLine("\t\t\t|                                                |");
            Console.WriteLine("\t\t\t|------------------------------------------------|");
            Console.WriteLine("\t\t\t|   EMAIL:                                       |");
            Console.WriteLine("\t\t\t|                                                |");
            Console.WriteLine("\t\t\t|------------------------------------------------|");
            Console.WriteLine("\t\t\t|   PASSWORD:                                    |");
            Console.WriteLine("\t\t\t|                                                |");
            Console.WriteLine("\t\t\t\\------------------------------------------------/");
        }
        static void PrintHeader()
        {
            Console.WriteLine(" __________________________________________________________________________________________________ ");
            Console.WriteLine("|                                 __________                                                       |");
            Console.WriteLine("|                                |          |                                                      |");
            Console.WriteLine("|                                |__________|   HXA  SOFTWARE  LAB                                 |");
            Console.WriteLine("|                               /____________\\                                                     |");
            Console.WriteLine("|__________________________________________________________________________________________________|\n\n");
        }

    }
}