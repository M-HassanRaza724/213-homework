# include <iostream>
using namespace std;

string checkStudentStatus(int examHour, int examMinute, int studentHour, int studentMinute); 

int main(int argc, char const *argv[])
{
    int examHour, examMinute, studentHour, studentMinute; 
    string answer;
    cout<<"Enter exam starting time (hour): ";
    cin>>examHour;
    cout<<"Enter exam starting time (minutes): ";
    cin>>examMinute;
    cout<<"Enter students hour of arrival: ";
    cin>>studentHour;
    cout<<"Enter students minutes of arrival: ";
    cin>>studentMinute;

    answer = checkStudentStatus(examHour, examMinute, studentHour, studentMinute);
    cout<<answer;

    return 0;
}

string checkStudentStatus(int examHour, int examMinute, int studentHour, int studentMinute){
    int f_intervalHour,f_intervalMinute, interval_hour,interval_minute;  //Adittional intervals for negating errors
    float total_interval_minute;
    f_intervalHour = examHour-studentHour;
    f_intervalMinute = examMinute-studentMinute;
    
    total_interval_minute = (f_intervalHour*60)+f_intervalMinute;        //-ve for late +ve for early
    interval_hour = total_interval_minute/60;
    interval_minute = int(total_interval_minute) % 60;

    if(total_interval_minute>30){
        if(interval_hour>0)
            return "Early\n"+to_string(interval_hour)+":"+to_string(interval_minute)+" hours before the start";
        return "Early\n"+to_string(interval_minute)+" minutes before the start";
    }
    else if(total_interval_minute<=30 && total_interval_minute>=0){
        if(total_interval_minute == 0);
            return "On time";
        return "On time "+to_string(interval_minute)+" minutes before the start";
    }
    else if(total_interval_minute<0){
        if(interval_hour>0)
            return "Late\n"+to_string(-interval_hour)+":"+to_string(-interval_minute)+" hours before the start";
        return "Late\n"+to_string(-interval_minute)+" minutes before the start";
    }
}
