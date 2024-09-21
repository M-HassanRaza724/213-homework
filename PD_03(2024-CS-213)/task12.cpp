# include<iostream>
using namespace std;

int main()
{
    int n;
    int w;
    int h;

    cout<<"Number of square meter you can paint: ";
    cin>>n;

    cout<<"Width of single wall (in meters): ";
    cin>>w;

    cout<<"Height of single wall (in meters): ";
    cin>>h;

    int wall_no = n/(w*h);
    cout<<"Number of walls you can compeletely paint: ";

    return 0;
}
