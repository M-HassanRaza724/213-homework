#include <iostream>
using namespace std;

main()
{
    string argument;

    cout << "Enter an string: ";
    getline(cin, argument);

    for (int i = 0; argument[i] != '\0'; i++)
    {
        if ((argument[i] == 'a') || (argument[i] == 'e') || (argument[i] == 'i') || (argument[i] == 'o') || (argument[i] == 'u') || (argument[i] == 'A') || (argument[i] == 'E') || (argument[i] == 'I') || (argument[i] == 'O') || (argument[i] == 'U'))
            argument[i] = '\0';
    }

    cout << "string with vowels removed: " + argument;
    return 0;
}