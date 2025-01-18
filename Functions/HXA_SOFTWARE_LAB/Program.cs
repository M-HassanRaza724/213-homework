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
            int total_buyers = 0, total_admins = 0, userType = -1,userIndex;
            int choice = -1;
            bool exit = false;

            string[] credentials = new string[3];
            GetCredentials(adminPath, adminCredentials,ref total_admins);
            GetCredentials(CustPath, customerCredentials,ref total_buyers);
            //Console.WriteLine(adminCredentials[0,0]);   for debuging purpose
            //Console.WriteLine(customerCredentials[0,0]);
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
                    userIndex = EmailAuthenticator(credentials[1], credentials[2],total_admins,total_buyers,adminCredentials,customerCredentials,ref userType);
                    if (userType == -1)
                    {
                        Console.WriteLine("Invalid credentials");
                        choice = -1;
                    }
                    else
                    {
                        Console.WriteLine("Login Successfully");
                        exit = true;
                        Console.ReadKey();  
                    }
                    
                }
                else if (choice == 2)
                {
                    SignUpPage();
                    Console.SetCursorPosition(28, 12);
                    credentials[0] = Console.ReadLine();
                    Console.SetCursorPosition(28, 15);
                    credentials[1] = Console.ReadLine();
                    Console.SetCursorPosition(28, 18);
                    credentials[2] = Console.ReadLine();
                    RegisterCredentials(credentials, 2, ref total_buyers, adminCredentials, customerCredentials);
                    choice = -1;
                }
                if (choice == 3)
                {
                    choice = -1;
                    exit = true;
                }
                Console.Clear();
            }
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

            StreamWriter file = new StreamWriter(filePath,append: true);
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
                        credentials[count, i] = GetField(line,i+1,',');
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
        static int EmailAuthenticator(string email, string password, int totalAdmins, int totalCustomers,
                               string[,] adminCredentials, string[,] customerCredentials, ref int userType)
        {
            for (int j = 0; j < totalAdmins; j++)
            {
                if (adminCredentials[j, 1] == email && adminCredentials[j, 2] == password)
                {
                    userType = 1;
                    return j;
                }
            }

            for (int j = 0; j < totalCustomers; j++)
            {
                if (customerCredentials[j, 1] == email && customerCredentials[j, 2] == password)
                {
                    userType = 2; 
                    return j; 
                }
            }

            return -1;
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