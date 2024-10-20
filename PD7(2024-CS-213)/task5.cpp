# include <iostream>
using namespace std;

bool isPrime(int n);

main(){
    int n = 0;
    bool answer;
    cout<<"Enter a number: ";
    cin>>n;

    answer=isPrime(n);
    cout<<answer;

    return 0;
}
bool isPrime(int n){
    if(n == 2)
        return true;
    else{
        for(int i = 2;i<n;i++){
            if(n%i == 0)
                return false;
        }
        return true;
    }
}
