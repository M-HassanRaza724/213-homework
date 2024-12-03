# include <iostream>
using namespace std;

string plant(string,int,int,int);

main(){
    string seed,grown;
    int water,fert,temp;

    cout<<"Enter the type of seed(@, #, $, &): ";
    cin>>seed;
    cout<<"Enter the unit quantity of water per day: ";
    cin>>water;
    cout<<"Enter the fertilizer: ";
    cin>>fert;
    cout<<"Enter the tempurature of plant reservior: ";
    cin>>temp;

    grown = plant(seed,water,fert,temp);
    cout<<grown;

    return 0;
}

string plant(string seed,int water,int fert,int temp){
    string plnt = "";

// generate single plant
    for (int j = 1; j <= water; j++)
    {
        plnt = plnt+"-";
    }
    if (temp<=30 && temp>=20)
    {
        for (int k = 0; k <= fert; k++)
        {
            plnt = plnt+seed;
        }
        
    }
// increase plant no
    for (int i = 1; i < water; i++)
        plnt = plnt+plnt;
    if(temp>30 || temp<20)
        plnt = plnt+seed;
    return plnt;
}
