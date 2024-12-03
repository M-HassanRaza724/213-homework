#include <iostream>
using namespace std;

bool canPayWithChange(double change[], double totalDue);

main()
{

    double due, pocket_change[4];
    bool payable;

    cout << "Enter the total amount due: ";
    cin >> due;

    cout << "Enter quarters: ";
    cin >> pocket_change[0];
    cout << "Enter dimes: ";
    cin >> pocket_change[1];
    cout << "Enter nickel: ";
    cin >> pocket_change[2];
    cout << "Enter pennies: ";
    cin >> pocket_change[3];

    payable = canPayWithChange(pocket_change, due);
    cout << "Con you pay amount? ";
    if (payable)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

bool canPayWithChange(double change[], double totalDue)
{
    double change_amount = 0.0;
    change_amount += change[0] * 0.25;
    change_amount += change[1] * 0.10;
    change_amount += change[2] * 0.05;
    change_amount += change[3] * 0.01;

    if (change_amount > totalDue)
        return true;
    else
        return false;
}
