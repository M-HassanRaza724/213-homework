# include <iostream>
using namespace std;

int array[100];
int transform;
void evenOddTransform();

main(){

    cout<<"Enter number of times even-odd transformation need to be done: ";
    cin>>transform;

    for (int i = 0; i < 3; i++)
    {
        cout<<"Enter array element "<<i+1<<": ";
        cin>>array[i];
    }

    evenOddTransform();

    
    for (int i = 0; i < 3; i++)
    {
        // cout<<"Enter array element "<<i+1;
        cout<<array[i]<<" ";
    }

    return 0;
    
}

void evenOddTransform(){

    int i = 0;
    while(i < 4){
        if (i%2 == 0)
        {
            array[i] += 2*transform;
        }
        if (i%2 == 1)
        {
            array[i] -= 2*transform;
        }
        
        i++;
    }
    
}
