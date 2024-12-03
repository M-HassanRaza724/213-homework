# include <iostream>
using namespace std;
void input(int str[],int size){
    cout<<"Enter string Elements one by one: \n";
    for (int i = 0; i < size; i++){
        cin>>str[i];
    }
}
string output(int str[],int size){
    string out = "[";
    for (int i = 0; i < size; i++){
        if(i != 0)
            out += ",";
        out += to_string(str[i]);
    }
    out += "]";
    return out;
}

void new_peak_string(int arr1[],int arr2[],int size){
    for (int i = 1,j = 0; i < size-1; i++)
    {
        if((arr1[i] > arr1[i+1]) && (arr1[i] > arr1[i-1])){
            arr2[j] = arr1[i];
            i++;
            j++;
        }
            
    }
}

main(){
    int no;
    cout<<"Enter total number of Elements: ";
    cin>>no;
    int arr1[no],arr2[no/2];
    input(arr1,no);
    new_peak_string(arr1,arr2,no);
    // cout<<"New string: "<<output(arr2,no/2);
    for (int i = 0; i < no; i++){
        cout<<arr2[i];
    }
    return 0;
}