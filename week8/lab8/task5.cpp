# include <iostream>
using namespace std;

string howBad(int);
bool primeChecker(int num);


main(){
    int no;
    string property;

    cout<<"Enter the number: ";
    cin>>no;

    property = howBad(no);
    cout<<property;

    return 0;
}

string howBad(int no){
    string property="";
    if(no%2==0)
        property = property+"Evil";
    else
        property = property+"Odious";

    if(primeChecker(no))
        property = property+",Pernicious";
    return property;
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
