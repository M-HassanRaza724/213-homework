# include <iostream>
using namespace std;

bool primeChecker(int n);
string primeNumbers(int);


main(){
    int n;
    string pn;

    cout<<"Enter the number: ";
    cin>>n;

    pn = primeNumbers(n);
    cout<<pn;

    return 0;
}

bool primeChecker(int num){
    if (num == 2)
        return true;
    for (int i = 2; i < num; i++)
    {
        if (num%i == 0)
        {
            return false;
        }
    }
    return true;
}

string primeNumbers(int n){
    string primenumbers = "";
    for (int i = 2; i <= n; i++)
    {
        if (primeChecker(i))
        {
            if (i == 2)
                primenumbers = primenumbers+to_string(i);
            else
                primenumbers = primenumbers+", "+to_string(i);
        }
    }
    return primenumbers;
}