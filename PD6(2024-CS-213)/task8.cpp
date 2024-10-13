# include <iostream>
using namespace std;

int calculateVolleyballGames(string yearType, int holidays, int hometownWeekends);

int main(int argc, char const *argv[])
{
    int holidays, h_weekends, v_no;
    string year_type;

    cout<<"Enter year type: ";
    cin>>year_type;
    cout<<"Enter number of holidays: ";
    cin>>holidays;
    cout<<"Enter the number of weekends at home: ";
    cin>>h_weekends;

    v_no = calculateVolleyballGames(year_type, holidays, h_weekends);
    cout<<v_no;
    return 0;
}

int calculateVolleyballGames(string yearType, int holidays, int hometownWeekends){

    float v_no = (holidays*0.67)+hometownWeekends+((48-hometownWeekends)*0.75); // one line formula after 3 hours of brainstorming
    if(yearType == "normal")
        return v_no;
    else if(yearType == "leap")
        return v_no+(v_no*0.15);
}
