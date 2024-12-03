# include <iostream>
using namespace std;
void input(string str[],int size){
    cout<<"Enter string Elements one by one: \n";
    for (int i = 0; i < size; i++)
        cin>>str[i];
}
int progressDays(string arr[],int size){
    int p_days = 0;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] < arr[i+1])
            p_days++;
    }
    return p_days;
}

main(){
    int no,progress_days;
    cout<<"Enter total number of saturdays: ";
    cin>>no;
    string miles[no];
    input(miles,no);
    progress_days = progressDays(miles,no);
    cout<<"Progress Days: "<<progress_days;
    return 0;
}