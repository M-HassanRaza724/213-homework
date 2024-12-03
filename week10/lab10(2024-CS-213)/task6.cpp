# include <iostream>
using namespace std;
void input(int arr[],int no){
    cout<<"Enter array Elements one by one: \n";
    for (int i = 0; i < no; i++){
        cin>>arr[i];
    }
}
string output(int arr[],int size){
    string out = "[";
    for (int i = 0; i < size; i++){
        if(i != 0)
            out += ",";
        out += to_string(arr[i]);
    }
    out += "]";
    return out;
}
void swp(int &n1,int &n2){
    int temp = n1;
    n1 = n2;
    n2 = temp;
}
void sorted_weight(int arr[],int no){
    for (int i = 0; i < no; i++)
    {
        for (int j = i+1; j < no; j++)
        {
            if(arr[i]>=arr[j])
                swp(arr[i],arr[j]);
        }
    }
}
main(){
    int weight,no;
    cout<<"Enter total number of packages: ";
    cin>>no;
    int packages[no];
    
    input(packages,no);
    sorted_weight(packages,no);
    cout<<"sorted packages: "<<output(packages,no);
    return 0;
}