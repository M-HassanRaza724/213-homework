# include <iostream>
using namespace std;

double calculateTotalResistance(double resistance[], int size);


main(){
    int size;
    cout<<"Enter the number of resistors in series circuit: ";
    cin>>size;

    double t_resistance, resistances[size];

    cout<<"enter the resistance values (in ohms) of the "<<size<<" resistors, one per line: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>resistances[i];
    }

    t_resistance = calculateTotalResistance(resistances, size);
    cout<<t_resistance;
    return 0;
}

double calculateTotalResistance(double resistance[], int size){
    double totalResistance;
    for (int i = 0; i < size; i++)
    {
        totalResistance += resistance[i];
    }
    return totalResistance;
}
