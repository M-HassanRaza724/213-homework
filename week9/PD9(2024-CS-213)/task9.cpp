#include <iostream>
using namespace std;

int char_to_int(char);
string int_to_string(int);
bool valid = true;

main()
{
    string dance[4], pin = "    ", moves[10] = {"Shimmy", "Shake", "Pirouette", "Slide", "Box Step", "Headspin", "Dosado", "Pop", "Lock", "Arabesque"};

    cout << "Enter 4 digit pin: ";
    cin >> pin;

    for (int i = 0; i < 4; i++)
    {
        if ((char_to_int(pin[i]) > 9) || (char_to_int(pin[i]) < 0))
        {
            valid = false;
        }

        dance[i] = moves[((char_to_int(pin[i])) + i) % 10];
    }

    if (valid)
    {
        for (int i = 0; i < 4; i++)
        {
            cout << dance[i];
            if ((i >= 0) && (i < 3))
                cout << ", ";
        }
    }
    else
    {
        cout << "Invalid input";
    }

    return 0;
}

int char_to_int(char p_digit)
{
    return int(p_digit - 48);
}