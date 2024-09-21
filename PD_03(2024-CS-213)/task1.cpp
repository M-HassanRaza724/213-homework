# include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter total number of sides of polygon: ";
    cin>>n;

    int AngleSum = (n-2)*180;
    cout<<"Sum of all internal angles is: "<<AngleSum;

    return 0;
}