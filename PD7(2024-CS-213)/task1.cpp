# include <iostream>
using namespace std;

void shape(int);

main(){
    int n;
    cout<<"Enter the desired number of rows: ";
    cin>>n;

    shape(n);
    return 0;
}
void shape(int n){

for (int i = 1; i <= n; i++)
{
    for (int j = n; j >= i; j--)
    {
        cout<<"*";
    }
    cout<<endl;
}


}