# include <iostream>
using namespace std;

bool isPrime(int);
int primorial(int);


main(){
    int n = 0,product = 0;
    cout<<"Enter number: ";
    cin>>n;

    product=primorial(n);
    cout<<product;

    return 0;
}

int primorial(int n){
    bool state;
    int product = 1, numbers = 0;

    for (int num = 2; numbers<n; num++)
    {
        if(num == 2){
            product =2;
            numbers++;
        }else{
            state = isPrime(num);
            if(state){
                product = product*num;
                numbers++;
            }
        }
    }
    return product;
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
