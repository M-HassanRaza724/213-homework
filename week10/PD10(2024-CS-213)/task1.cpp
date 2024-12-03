#include<iostream>
using namespace std;

bool specialstringChecker(int[],int size);
void sort(int numbers[],int size);
void swp(int &n1,int &n2);

main(){
    int no;
    bool answer;
    cout<< "Enter total no of numbers: ";
    cin>>no;
    int numbers[no]; 
    cout<<"Enter you integers one by one: \n";
    for (int i = 0; i < no; i++)
        cin>>numbers[i];
    
    // for (int i = 0; i < no; i++)
    //     cout<<numbers[i];
    answer = specialstringChecker(numbers,no);
    cout<<answer;
    return 0;
}

bool specialstringChecker(int numbers[],int size){
    sort(numbers,size);
    for (int i = 0; i < size-1; i++)
    {
        if(numbers[i]+1 != numbers[i+1])
            return false;
    }
    return true;
}
void sort(int numbers[],int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(numbers[i]>=numbers[j])
                swp(numbers[i],numbers[j]);
        }
    }
}


void swp(int &n1,int &n2){
    int temp = n1;
    n1 = n2;
    n2 = temp;
}
