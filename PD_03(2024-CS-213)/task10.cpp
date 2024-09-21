# include <iostream>
using namespace std;

int main()
{
    int no1;int no2;int no3;int no4;int no5;

    cout<<"Number1: ";
    cin>>no1;
    cout<<"Number2: ";
    cin>>no2;
    cout<<"Number3: ";
    cin>>no3;
    cout<<"Number4: ";
    cin>>no4;
    cout<<"Number5: ";
    cin>>no5;
    int sum = no1+no2+no3+no4+no5;

    cout<<"Number6: ";
    cin>>no1;
    cout<<"Number7: ";
    cin>>no2;
    cout<<"Number8: ";
    cin>>no3;
    cout<<"Number9: ";
    cin>>no4;
    cout<<"Number10: ";
    cin>>no5;
    int multiply = no1*no2*no3*no4*no5;

    cout<<"Number11: ";
    cin>>no1;
    cout<<"Number12: ";
    cin>>no2;
    cout<<"Number13: ";
    cin>>no3;
    cout<<"Number14: ";
    cin>>no4;
    cout<<"Number15: ";
    cin>>no5;
    int subtract = no1-no2-no3-no4-no5;

    int result = sum + multiply - subtract;
    cout<<"The final result is: "<<result;

    return 0;
}
