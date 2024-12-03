#include <iostream>
using namespace std;

bool isSpecialArray(int arr[], int size);

main()
{
    bool special;
    int size;
    cout<<"Enter the number of elements of array: ";
    cin>>size;

    int array[size];

    cout<<"enter "<<size<<" elements for array, one per line: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>array[i];
    }

    special = isSpecialArray(array, size);
    if (special)
        cout<<"The array is special: ";
    else    
        cout<<"The array is not special: ";    
    return 0;
}

bool isSpecialArray(int arr[], int size){

    for (int i = 0; i < size; i++)
    {
        if (((i%2 == 0) && (arr[i]%2 == 0)) || ((i%2 == 1) && (arr[i]%2 == 1)))
            return true;
        return false;
    }
}
