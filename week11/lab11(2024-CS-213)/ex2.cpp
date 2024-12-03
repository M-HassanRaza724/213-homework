#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr; // Pointer to the first element
    for (int i = 0; i < 5; i++)
    {
        cout << "Element address " << i << ": " << (ptr + i) << endl;
        cout << "Element " << i << ": " << *(ptr + i) << endl;
    }
    // idea: array element has adjacent memory cells
    return 0;
}