# include <iostream>
using namespace std;

int main()
{
    int age;
    int migration;

    cout<<"Enter the the person's age: ";
    cin>>age;
    
    cout<<"Enter the the number of times they've moved: ";
    cin>>migration;

    int house_avg_time = age/(migration+1);
    cout<<"Average number of years lived in the same house: "<<house_avg_time;
    return 0;
}
