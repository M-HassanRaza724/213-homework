# include <iostream>
using namespace std;

int main()
{
    string name;
    int target;

    cout<<"Enter the name of the person: ";
    cin>>name;

    cout<<"Enter the target weight loss in Kg: ";
    cin>>target;

    int days = target*15;
    cout<<name<<" will need "<<days<<" days to lose "<<target<<"kg of weight by following the doctor's suggestions";

    return 0;
}
