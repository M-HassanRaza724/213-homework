// task1
# include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter total number of sides of polygon: ";
    cin>>n;

    int AngleSum = (n-2)*180;
    cout<<"Sum of all internal angles is: "<<AngleSum;

    return 0;
}

//task2
# include<iostream>
using namespace std;

int main(){

    int min;
    cout<<"Number of minutes: ";
    cin>>min;

    int frameRate;
    cout<<"Frame per seconds: ";
    cin>>frameRate;

    int frames = frameRate*min*60;
    cout<<"total number of frames are: "<<frames<<"frames";

    return 0;
}

//task3
# include<iostream>
using namespace std;

int main(){

    int a;
    int t;
    int Vi;

    cout<<"Enter Acceleartion (m/s^2): ";
    cin>>a;

    cout<<"Enter Time (s): ";
    cin>>t;

    cout<<"Enter Initial velocity (m/s): ";
    cin>>Vi;

    int Vf = (a*t)+Vi;
    cout<<"Final velocity (m/s): "<<Vf;

    return 0;
}


//task4
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


//task5
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


//task6
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


//task7
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


//task8
# include<iostream>
using namespace std;

int main()
{
   float veg_rate;
   float fruit_rate;
   int veg_kg;
   int fruit_kg;

   cout<<"Enter vegetable price per kilogram (in coins): ";
   cin>>veg_rate;

   cout<<"Enter fruit price per kilogram (in coins): ";
   cin>>fruit_rate;

   cout<<"Enter total kilograms of vegetables: ";
   cin>>veg_kg;

   cout<<"Enter total kilograms of fruits: ";
   cin>>fruit_kg;

// 1 Rs == 1.94 coins

   float earning_Rs = ((veg_kg*veg_rate)+(fruit_kg*fruit_rate))/1.94;
   cout<<"Total earning in Rupees (Rps):"<<earning_Rs;

   return 0;
}


//task9
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


//task10
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


//task11
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


//task12
# include<iostream>
using namespace std;

int main()
{
    int n;
    int w;
    int h;

    cout<<"Number of square meter you can paint: ";
    cin>>n;

    cout<<"Width of single wall (in meters): ";
    cin>>w;

    cout<<"Height of single wall (in meters): ";
    cin>>h;

    int wall_no = n/(w*h);
    cout<<"Number of walls you can compeletely paint: ";

    return 0;
}

