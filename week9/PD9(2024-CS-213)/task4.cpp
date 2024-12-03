# include <iostream>
using namespace std;

bool sevenCheck(string);

main(){

    string input = "";
    cout<<"Enter string: ";
    cin>>input;

    bool result = sevenCheck(input);
    if (result)
    {
        cout<<"boom!";
    }
    else
    {
        cout<<"there is no 7 in the array";
    }

    return 0;
    
}

bool sevenCheck(string word){

    int i = 0;
    while(word[i] != '\0'){
        if (word[i] == '7')
        {
            return true;
        }
        i++;
    }
    return false;
}
