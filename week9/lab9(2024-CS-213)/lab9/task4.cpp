#include <iostream>
using namespace std;

void printReverseArray(int arr[], int n);

main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int numbers[n];

    cout << "Enter " << n << " numbers , one perline:\n";

    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    printReverseArray(numbers, n);

    return 0;
}

void printReverseArray(int arr[], int n)
{

    cout << "Numbers in reverse order: ";

    for (int i = n - 1; i >= 0; i--)
        cout << arr[i] << " ";
}