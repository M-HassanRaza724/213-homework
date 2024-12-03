#include <iostream>
using namespace std;

string NextLetter(string word)
{
    string Nextword = word;
    int i = 0, code;

    while (word[i] != '\0')
    {
        code = (int(word[i]) + 1);
        if (code == 91)
            code = 65;
        if (code == 123)
            code = 97;
        if (code == 33)
            code = 32;

        Nextword[i] = code;
        i++;
    }
    return Nextword;
}

int main()
{
    string word, nextWord;
    cout << "Enter word: ";
    getline(cin, word);

    nextWord = NextLetter(word);
    cout << nextWord;

    return 0;
}