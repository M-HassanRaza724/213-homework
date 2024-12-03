# include <iostream>
using namespace std;

main(){
    int n;
    cout<<"Enter the numbers to be saved: ";
    cin>>n;

    int array[n];

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter number "<<i+1<<": ";
        cin>>array[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<"Number "<<i+1<<" is: "<<array[i]<<endl;
    }
    
    return 0;
}