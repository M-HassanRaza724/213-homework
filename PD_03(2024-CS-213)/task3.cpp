# include<iostream>
using namespace std;

int main(){

    int a;
    int t;
    int Vi;

    cout<<"Enter Acceleartion (m/s^2): ";
    cin>>a;

    cout<<"Enter Time (s): ";
    cin>>t;

    cout<<"Enter Initial velocity (m/s): ";
    cin>>Vi;

    int Vf = (a*t)+Vi;
    cout<<"Final velocity (m/s): "<<Vf;

    return 0;
}