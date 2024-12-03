# include <iostream>
using namespace std;
void input(string str[],int size){
    for (int i = 0; i < size; i++){
        cout<<"Enter word "<<i+1<<": ";
        cin>>str[i];
    }
}
int letter_repitiion(string arr[],int size,char letter){
    int repitition = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; (arr[i])[j] != '\0'; j++)
        {
            if((arr[i])[j] == letter)
                repitition++;
        }
    }
    return repitition;
}

main(){
    int no,progress_days;
    char letter;
    cout<<"Enter total number of words: ";
    cin>>no;
    string miles[no];
    input(miles,no);
    cout<<"Enter  letter you want to count: ";
    cin>>letter;
    progress_days = letter_repitiion(miles,no,letter);
    cout<<"Progress Days: "<<progress_days;
    return 0;
}