# include <iostream>
using namespace std;

bool similarityCheck(string[4]);

main(){

    string input[4];
    cout<<"Enter element 1: ";
    cin>>input[0];
    cout<<"Enter element 2: ";
    cin>>input[1];
    cout<<"Enter element 3: ";
    cin>>input[2];
    cout<<"Enter element 4: ";
    cin>>input[3];

    bool result = similarityCheck(input);
    if (result)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }

    return 0;
    
}

bool similarityCheck(string word[4]){

    int i = 1;
    while(i<4){
        if (word[i-1] != word[i])
        {
            return false;
        }
        i++;
    }
    return true;
}
