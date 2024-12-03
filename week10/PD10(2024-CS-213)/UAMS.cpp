#include <iostream>
#include <conio.h>

using namespace std;

const int userArrSize = 10;
string users[userArrSize];
string passwords[userArrSize];
string roles[userArrSize];


int usersCount = 0;

string signIn(string name, string password);
bool signUp(string name, string password, string role);
void topHeader();
void subMenuBeforeMainMenu(string submenu);
void subMenu(string submenu);
int loginMenu();
int adminMenu();
void adminInterface();
int userMenu();
void userInterface();
void clearScreen();

main()
{
    int loginOption = 0;
    while (loginOption != 3)
    {
        topHeader();
        subMenuBeforeMainMenu("Login");
        loginOption = loginMenu();
        if (loginOption == 1)
        {
            system("cls");

            string name;
            string password;
            string role;
            topHeader();
            subMenuBeforeMainMenu("SignIn");
            cout << "Enter your Name: " << endl;
            cin >> name;
            cout << "Enter your Password: " << endl;
            cin >> password;
            role = signIn(name, password);

            if (role == "Admin")
            {
                clearScreen();
                adminInterface();
            }
            else if (role == "User")
            {
                clearScreen();
                userInterface();
            }
            else if (role == "undefined")
            {
                cout << "You Entered wrong Credentials" << endl;
            }
        }
        else if (loginOption == 2)
        {
            system("cls");
            string name;
            string password;
            string role;
            topHeader();
            subMenuBeforeMainMenu("SignUp");
            cout << "Enter your Name: " << endl;
            cin >> name;
            cout << "Enter your Password: " << endl;
            cin >> password;
            cout << "Enter your Role (Admin or User): " << endl;
            cin >> role;
            bool isValid = signUp(name, password, role);
            if (isValid)
            {
                cout << "SignedUp Successfully" << endl;
            }
            if (!isValid)
            {
                cout << "Users in the System have exceeded the Capacity" << endl;
            }
        }
        clearScreen();
    }
}

int loginMenu()
{
    int option;
    cout << "1. SignIn with your Credentials" << endl;
    cout << "2. SignUp to get your Credentials" << endl;
    cout << "3. Exit the Application" << endl;
    cout << endl;
    cout << "Enter the Option Number > ";
    cin >> option;
    return option;
}
string signIn(string name, string password)
{
    for (int index = 0; index < usersCount; index++)
    {
        if (users[index] == name && passwords[index] == password)
        {
            return roles[index];
        }
    }
    return "undefined";
}

bool signUp(string name, string password, string role)
{
    bool isPresent = false;

    for (int index = 0; index < usersCount; index++)
    {
        if (users[index] == name && passwords[index] == password)
        {
            isPresent = true;
            break;
        }
    }
    if (isPresent == true)
    {
        return 0;
        cout << "User Already Present";
    }
    else if (usersCount < userArrSize)
    {
        users[usersCount] = name;
        passwords[usersCount] = password;
        roles[usersCount] = role;
        usersCount++;
        return true;
    }
    else
    {
        return false;
    }
}

void topHeader()
{
    cout << "************************************************************" << endl;
    cout << "*        University Admission Management System            *" << endl;
    cout << "************************************************************" << endl;
    cout << endl;
}

void subMenuBeforeMainMenu(string submenu)
{
    string message = submenu + " Menu";
    cout << message << endl;
    cout << "---------------------" << endl;
}

void subMenu(string submenu)
{
    string message = "Main Menu > " + submenu;
    cout << message << endl;
    cout << "---------------------" << endl;
}

void clearScreen()
{
    cout << "Press Any Key to Continue.." << endl;
    getch();
    system("cls");
}

int adminMenu()
{
    int option;
    cout << "Select one of the following options number..." << endl;
    cout << "1. Add New Student Record" << endl;
    cout << "2. View all Records" << endl;
    cout << "3. Print the Record in Merit Order" << endl;
    cout << "4. Generate Merit List" << endl;
    cout << "5. Seat Management" << endl;
    cout << "6. Exit" << endl;
    cout << "Your Option..";
    cin >> option;
    return option;
}

void adminInterface()
{
    int adminOption = 0;
    while (adminOption != 6)
    {
        topHeader();
        subMenu("");
        adminOption = adminMenu();
        if (adminOption == 1)
        {
            system("cls");
            topHeader();
            subMenu("Add Student");
            // Implement the Add Student Functionality
        }
        // Implement the rest of the Admin Options
        clearScreen();
    }
}

int userMenu()
{
    int option;
    cout << "Select one of the following options number..." << endl;
    cout << "1. View your Details" << endl;
    cout << "2. Update password" << endl;
    cout << "3. Apply in a Degree Program" << endl;
    cout << "4. Exit" << endl;
    cout << "Your Option..";
    cin >> option;
    return option;
}

void userInterface()
{
    int userOption = 0;
    while (userOption != 4)
    {
        topHeader();
        subMenu("");
        userOption = userMenu();
        if (userOption == 1)
        {
            system("cls");
            topHeader();
            subMenu("View Details");
            // Implement the View Details Functionality
        }
        // Implement the rest of the User Options
        clearScreen();
    }
}