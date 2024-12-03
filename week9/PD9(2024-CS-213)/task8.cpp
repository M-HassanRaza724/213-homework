#include <iostream>
using namespace std;

int stripTime(string[],int);

main()
{
    int size, s_time;

    cout << "Enter the number of total strip pattern: ";
    cin >> size;
    string array[size];

    for (int i = 0;i < size ; i++)
    {
        cout << "Enter strip color" << i + 1 << ": ";
        cin >> array[i];

    }

    s_time = stripTime(array,size);

    cout <<"Strip time: "<< s_time;

    return 0;
}

int stripTime(string strip[],int size)
{

    int time = size*2;
    for (int i = 1; i < size; i++)
    {
        if (strip[i-1] != strip[i])
            time++;
    }
    return time;
}
