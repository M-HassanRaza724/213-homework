# include <iostream>
using namespace std;
int s_lenght(string str){
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}
string reverse(string str){
    string r_str = "";
    int len = s_lenght(str);
    int last_index = len;
    for (int i = len-1; i >= 0; i--)
    {
        if(i != len-1 && (i == 0 || str[i] == ' ')){
            if(i == 0){
                for (int j = i; j < last_index; j++)
                    r_str += str[j];
            }
            else if(str[i] == ' '){
                for (int j = i+1; j < last_index; j++)
                    r_str += str[j];
            }
            if(str[i] == ' ')
                r_str += ' ';
            last_index = i;
        }
    }
    return r_str;
}

main(){
    string statement;
    cout<<"Enter a statement: ";
    getline(cin,statement);

    // cout<<"Entered Statement: "<<statement;
    statement = reverse(statement);
    cout<<"\nReverse Statement: "<<statement;
    return 0;
}