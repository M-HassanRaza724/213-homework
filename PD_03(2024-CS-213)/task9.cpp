# include <iostream>
using namespace std;

int main()
{
    int no_4dgt;
    cout<<"Enter a 4-Digit number: ";
    cin>>no_4dgt;

    int digit1 = no_4dgt%10;
    int no_3dgt = no_4dgt/10;
    
    int digit2 = no_3dgt%10;
    int no_2dgt = no_3dgt/10;

    int digit3 = no_2dgt%10;
    int no_1dgt = no_2dgt/10;

    int digit4 = no_1dgt;

    int dgt_sum = digit1+digit2+digit3+digit4;
    cout<<"Sum of the individual digits: "<<dgt_sum;

    return 0;
}
