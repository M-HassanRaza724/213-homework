#include <iostream>
using namespace std;

main()
{
    int initial_size;
    cout << "Enter the number of elements: ";
    cin >> initial_size;

    int unique[initial_size];

    cout << "Enter " << initial_size << " numbers one per line: " << endl;
    for (int i = 0; i < initial_size; i++)
    {
        cin >> unique[i];

        for (int j = 0; j < i; j++)
        {
            if (unique[i] == unique[j])
            {
                cout << "already entered: "<<unique[i];
                i--;
                initial_size--;
            }
        }
    }

    cout << "Unique number entered: ";
    for (int i = 0; i < initial_size; i++)
    {
        cout << unique[i] << " ";
    }

    return 0;
}