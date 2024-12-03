#include <iostream>
using namespace std;

string ReverseGenerator(string);

main()
{
    string word, reverseWord = "";
    cout << "Enter word: ";
    cin >> word;

    reverseWord = ReverseGenerator(word);
    cout << reverseWord;

    return 0;
}

string ReverseGenerator(string word)
{
    int lastIndex = -1;
    string reverse;
    for (int i = 0; word[i] != '\0'; i++)
        lastIndex++;

    // cout<<lastIndex;
    for (int i = 0; lastIndex >= 0; lastIndex--, i++)
        reverse += word[lastIndex];
        
    return reverse;
}