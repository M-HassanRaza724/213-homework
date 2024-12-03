# include <iostream>
using namespace std;

bool evenOrOdd(string);

main(){

    string input = "";
    cout<<"Enter string: ";
    cin>>input;

    bool result = evenOrOdd(input);
    cout<<result;
}

bool evenOrOdd(string word){

    int i = 0;
    while(word[i] != '\0'){
        i++;
    }
    if (i%2 == 0)
    {
        return true;
    }
    return false;
}
