# include <iostream>
using namespace std;

void amplify(int n);

main(){
    int n;

    cout<<"Enter the number to amplify: ";
    cin>>n;

    amplify(n);
    return 0;
}

void amplify(int n){
    int num;
    for (int i = 1; i <= n ; i++)
    {
        num = i;
        if(num%4 == 0)
            num = num*10;
        cout<<num;
        if(i != n)
            cout<<", ";
    }
    
}