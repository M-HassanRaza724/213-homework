# include<iostream>
using namespace std;

int main(){

    float imp;
    float player;


    cout<<"Enter Imposter count: ";
    cin>>imp;

    cout<<"Enter Player count: ";
    cin>>player;

    float chance = (imp/player)*100;
    cout<<"The chance of being imposter: "<<chance<<"%";

    return 0;
}