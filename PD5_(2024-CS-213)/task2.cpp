# include <iostream>
// # include <iomanip>
using namespace std;

string pyramidVolume(int,int,int,string);

main(){
    int l,w,h;
    string unit;
    cout<<"Enter the lenght of the pyramid (meters): ";
    cin>>l;
    cout<<"Enter the width of the pyramid (meters): ";
    cin>>w;
    cout<<"Enter the height of the pyramid (meters): ";
    cin>>h;
    cout<<"Enter the desired output unit (millimeters, centimeters, meters, kilometers): ";
    cin>>unit;

    string r = pyramidVolume(float(l),w,h,unit);
    cout<<r;

}

string pyramidVolume(int l,int w,int h,string unit){
    float volume_meter = (float(l)*w*h)/3;
    if (unit == "meters"){
        string str_volume = to_string(volume_meter);
        return str_volume+" cubic "+unit;
    }

    else if (unit == "millimeters"){
        string str_volume = to_string(volume_meter*(1000000000));
        return str_volume+" cubic "+unit;
    }

    else if (unit == "centimeters"){
        string str_volume = to_string(volume_meter*(1000000));
        return str_volume+" cubic "+unit;
    }

    else if (unit == "kilometers"){
        string str_volume = to_string(volume_meter/(1000000000));
        return str_volume+" cubic "+unit;
    }
    else{
        return "You have entered the wrong unit";
    }
}