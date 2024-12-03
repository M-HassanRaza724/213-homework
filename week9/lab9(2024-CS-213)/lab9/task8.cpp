# include <iostream>
using namespace std;

void insertArrayInMiddle (int firstArray[], int firstArraySize, int secondArray[], int secondArraySize);
int array3[100];

main(){
    int array1[2];
    
    cout<<"enter the elements of the first array (must be 2): "<<endl;
    for (int i = 0; i < 2; i++)
    {
        cin>>array1[i];
    }

    int size;
    cout<<"Enter the number of elements of second array: ";
    cin>>size;

    int array2[size];

    cout<<"enter "<<size<<" elements for the second array, one per line: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>array2[i];
    }

    insertArrayInMiddle (array1, 2, array2, size);

    cout << "Resulting array: [";
    for (int i = 0; i < size+2; i++)
    {
        cout << array3[i];
        if (i>=0 && i<size+1)
        {
            cout<<", ";
        }
    }
        cout<<"]";

    return 0;
}

void insertArrayInMiddle (int firstArray[], int firstArraySize, int secondArray[], int secondArraySize){
    array3[0] = firstArray[0];
    for (int i = 1; i < secondArraySize+1; i++)
    {
        array3[i] = secondArray[i-1];
    }
    array3[secondArraySize+1] = firstArray[1];
}
