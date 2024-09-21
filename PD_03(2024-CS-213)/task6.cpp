# include <iostream>
using namespace std;

int main()
{
    int bag_size;
    int bag_prize;
    int bag_area;

    cout<<"Enter the size of fertilizer bag in pounds: ";
    cin>>bag_size;

    cout<<"Enter the cost of the bag: $";
    cin>>bag_prize;

    cout<<"Enter the are in square feet that can be covered by the bag: ";
    cin>>bag_area;

    int rate_p = bag_prize/bag_size;
    int rate_sf = bag_prize/bag_area;

    cout<<"Cost of the fertilizer per pound: $"<<rate_p<<endl;
    cout<<"Cost of the fertilizer per square feet: $"<<rate_sf;

    return 0;
}
