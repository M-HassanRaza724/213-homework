# include <iostream>
using namespace std;

void WordPostmortem(string);

main(){
    string word; int position;
    cout<<"Enter word: ";
    cin>>word;

    WordPostmortem(word);
    return 0;
}

void WordPostmortem(string word){
    for (int i = 0;word[i]!='\0' ; i++)
    {
        cout<<word[i]<<"found at Postion: "<<i<<endl;
    }
    
}
