#include<iostream>
using namespace std;

int total_rotations(string[],int size);


main(){
    int no;
    int rotation;
    cout<< "Enter total no of rotations: ";
    cin>>no;
    string rotations[no]; 
    cout<<"Enter quarter rotations one by one: \n";
    for (int i = 0; i < no; i++)
        cin>>rotations[i];
    

    rotation = total_rotations(rotations,no);
    cout<<rotation;
    return 0;
}

int total_rotations(string rotations[],int size){
    int quarter_rotation = 0;
    for (int i = 0; i < size; i++)
    {
        if(rotations[i] == "right")
            quarter_rotation++;
        if(rotations[i] == "left")
            quarter_rotation--;
    }
    return quarter_rotation/4;
}




