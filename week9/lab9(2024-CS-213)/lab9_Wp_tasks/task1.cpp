# include <iostream>
using namespace std;



main(){
    int array[5];
    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter number "<<i+1<<": ";
        cin>>array[i];
    }

    cout<<array[1]<<endl;
    cout<<array[3]<<endl;

    return 0;
}