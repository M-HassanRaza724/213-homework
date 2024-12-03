#include <iostream>
using namespace std;

main()
{
    string argument;

    cout << "Enter an argument 'a': ";
    getline(cin, argument);
    cout << "Result: Something " + argument;
    return 0;
}