# include <iostream>
using namespace std;

int main()
{
    string movie;
    int adult_prize;
    int child_prize;
    int adult_tickets;
    int child_tickets;
    float charity_percent;

    cout<<"Enter the movie name: ";
    cin>>movie;
    
    cout<<"Enter the adult tickets prize: $";
    cin>>adult_prize;
    
    cout<<"Enter the child tickets prize: $";
    cin>>child_prize;
    
    cout<<"Enter the number of adult tickets sold: ";
    cin>>adult_tickets;
    
    cout<<"Enter the number of child tickets sold: ";
    cin>>child_tickets;
    
    cout<<"Enter the percentage of amount to be donated to charity: ";
    cin>>charity_percent;

    int total = (adult_prize*adult_tickets)+(child_prize*child_tickets);
    int charity = total*(charity_percent/100);
    int remaing_amount = total - charity;

    cout<<"Movie: "<<movie<<endl;
    cout<<"Total amount generated from tickets sales: $"<<total<<endl;
    cout<<"Donation to charity ("<<charity_percent<<"%) : $"<<charity<<endl;
    cout<<"Remaining amount after doation: $"<<remaing_amount;  

    return 0;
}
