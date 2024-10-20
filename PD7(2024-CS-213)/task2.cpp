# include <iostream>
using namespace std;

void halfDiamond(int);
void upper(int);
void lower(int, int);

main(){
    int n;
    cout<<"Enter the desired number of rows: ";
    cin>>n;

    halfDiamond(n);
    return 0;
}
void halfDiamond(int n){
    int n1,n2;
    if(n%2 == 0){
        n1 = n2 = n/2;
    }
    else if(n%2 == 1){
        n1 = (n+1)/2;
        n2 = (n-1)/2;
    }
    upper(n1);
    lower(n2 ,n1);
}
void upper(int n1){

    for (int i = 1; i <= n1; i++)
    {
        for (int j = (n1-1); j >= i; j--)
        {
            cout<<" ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout<<"*";
        }
        cout<<endl;
        
    }
    
}
void lower(int n2, int n1){
    if(n1 == n2){

        for (int i = 1; i <= n2; i++)
        {
            for (int j = 1; j < i; j++)
            {
                cout<<" ";
            }
            for (int k = (n2); k >= i; k--)
            {
                cout<<"*";
            }
            cout<<endl;
            
        }
    }
    else if(n1 > n2){
        for (int i = 1; i <= n2; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout<<" ";
            }
            for (int k = (n2); k >= i; k--)
            {
                cout<<"*";
            }
            cout<<endl;
            
        }
    }
}