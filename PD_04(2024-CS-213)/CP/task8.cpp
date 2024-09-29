#include<iostream>
using namespace std;

void pet(int holidays)
{
    int norm_time = 30000;
    int working_days = 365-holidays;
    int game_time = (working_days*63)+(holidays*127);

    if(game_time<norm_time)
    {
        int spare_time = norm_time-game_time;
        cout<<"Tom sleeps well."<<endl;
        cout<<(spare_time/60)<<" hours and "<<(spare_time%60)<<" minutes less for play.";
    }
    if(game_time>norm_time)
    {
        int spare_time = game_time-norm_time;
        cout<<"Tom will run away."<<endl;
        cout<<(spare_time/60)<<" hours and "<<(spare_time%60)<<" minutes more for play.";
    }

}

int main()
{
    system("cls");

    int holidays;
    cout<<"Holidays: ";
    cin>>holidays;

    pet(holidays);
}
