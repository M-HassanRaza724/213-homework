# include <iostream>
# include <iomanip>
using namespace std;

string Cargo(int);
int tonnage(int,int);


main(){
    int no;
    string report;
    cout<<"Enter the count of cargo for traportation: ";
    cin>>no;

    report = Cargo(no);
    cout<<report;
    return 0;
}


string Cargo(int no){

    int total_ton = 0,ton = 0,minibus = 0,truck = 0, train = 0;
    float avg_ton_price = 0.0, minibus_percent = 0.0, truck_percent = 0.0, train_percent = 0.0;

    for (int i = 1; i <= no; i++)
    {
        ton = tonnage(i,ton);
        total_ton = total_ton + ton;
        if(ton<=3)
            minibus = minibus +ton;
        else if(ton<=11)
            truck = truck +ton;
        else if(ton>11)
            train = train +ton;
    }
    avg_ton_price = ((minibus*200.0)+(truck*175)+(train*120))/total_ton;
    minibus_percent = (minibus*100.00)/total_ton;
    truck_percent = (truck*100.00)/total_ton;
    train_percent = (train*100.00)/total_ton;

    return to_string(avg_ton_price)+"\n"+to_string(minibus_percent)+"%\n"+to_string(truck_percent)+"%\n"+to_string(train_percent)+"%";
}

int tonnage(int no,int ton){
    cout<<"Enter the tonnage of cargo "<<no<<" :";
    cin>>ton;
    return ton;
}