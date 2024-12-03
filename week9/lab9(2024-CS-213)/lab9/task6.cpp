# include <iostream>
using namespace std;

int findLargestNumber(int arr[], int size);


main(){
    int size, l_index = 0;
    cout<<"Enter the number of elements: ";
    cin>>size;

    int array[size];

    cout<<"enter "<<size<<" numbers, one per line: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>array[i];
    }

    l_index = findLargestNumber(array, size);
    cout<<"The largest number entered is: "<<array[l_index];
    return 0;
}

int findLargestNumber(int arr[], int size){
    int l_index = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[l_index] < arr[i])
        {
            l_index = i;
        }
    }
    return l_index;    
}