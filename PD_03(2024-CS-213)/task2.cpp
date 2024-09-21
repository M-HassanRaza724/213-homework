# include<iostream>
using namespace std;

int main(){

    int min;
    cout<<"Number of minutes: ";
    cin>>min;

    int frameRate;
    cout<<"Frame per seconds: ";
    cin>>frameRate;

    int frames = frameRate*min*60;
    cout<<"total number of frames are: "<<frames<<"frames";

    return 0;
}