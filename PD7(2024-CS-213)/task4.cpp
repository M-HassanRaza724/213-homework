# include <iostream>
using namespace std;

int triangle(int n);

main(){
    int n = 0, dots = 0;
    cout<<"Enter the number of trangle: ";
    cin>>n;

    dots = triangle(n);
    cout<<dots;
    
    return 0;
}

int triangle(int n){
    int dot = 0;
    for (int i = 1; i <= n; i++)
    {
        dot = dot+i;
    }
    return dot;
}

// 0+1=1
// 1+2=3
// 3+3=6
// 6+4=10...