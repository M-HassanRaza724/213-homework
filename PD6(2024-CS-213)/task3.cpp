# include <iostream>
using namespace std;

string findZodiacSign(int day, string month);

int main(int argc, char const *argv[])
{
    int date;
    string month,sign;

    cout<<"Enter the date of birth: ";
    cin>>date;
    cout<<"Enter the month of birth: ";
    cin>>month;

    sign = findZodiacSign(date,month);
    cout<<sign;

    return 0;
}

string findZodiacSign(int day, string month){

    string sign;
    if(month == "April"){
        if (day<=19)
            return "Aries";
        return "Taurus";
    }
    else if(month == "May"){
        if (day<=20)
            return "Taurus";
        return "Gemini";
    }
    else if(month == "June"){
        if (day<=20)
            return "Gemini";
        return "Cancer";
    }
    else if(month == "July"){
        if (day<=22)
            return "Cancer";
        return "Leo";
    }
    else if(month == "August"){
        if (day<=22)
            return "leo";
        return "Virgo";
    }
    else if(month == "September"){
        if (day<=22)
            return "Virgo";
        return "Libra";
    }
    else if(month == "October"){
        if (day<=22)
            return "Libra";
        return "Scorpio";
    }
    else if(month == "November"){
        if (day<=21)
            return "Scorpio";
        return "Sagittarius ";
    }
    else if(month == "December"){
        if (day<=21)
            return "Sagittarius ";
        return "Capricorn";
    }
    else if(month == "January"){
        if (day<=19)
            return "Capricorn";
        return "Aquarius";
    }
    else if(month == "February"){
        if (day<=18)
            return "Aquarius";
        return "Pisces";
    }
    else if(month == "March"){
        if (day<=20)
            return "Pisces";
        return "Aries";
    }
}
