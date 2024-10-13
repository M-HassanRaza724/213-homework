# include <iostream>
using namespace std;

float calculateAverage(float marksEnglish, float marksMaths, float marksChemistry, float marksSocialScience, float marksBiology);
string calculateGrade(float average);

int main(int argc, char const *argv[])
{
    float english, maths, chemistry, socialScience, biology, avg;
    string name, grade;

    cout<<"Enter students name: ";
    cin>>name;
    cout<<"Enter marks for English: ";
    cin>>english;
    cout<<"Enter marks for Maths: ";
    cin>>maths;
    cout<<"Enter marks for SocialScience: ";
    cin>>socialScience;
    cout<<"Enter marks for Chemistry: ";
    cin>>chemistry;
    cout<<"Enter marks for Biology: ";
    cin>>biology;

    avg = calculateAverage(english,maths,chemistry,socialScience,biology);
    grade = calculateGrade(avg);

    cout<<"Student Name: "<<name<<endl;
    cout<<"Percentage: "<<avg<<endl;
    cout<<"Grade: "<<grade<<endl;

    return 0;
}

float calculateAverage(float marksEnglish, float marksMaths, float marksChemistry, float marksSocialScience, float marksBiology){
    return ((marksEnglish+marksChemistry+marksBiology+marksMaths+marksSocialScience)/5);
}

string calculateGrade(float average){
    if (average>100 || average<0)
        return  "Invalid entries marks should be in range 0 to 100!";
    else if (average<=90)
        return "A+";
    else if (average>=80)
        return "A";
    else if (average>=70)
        return "B+";
    else if (average>=60)
        return "B";
    else if (average>=50)
        return "C";
    else if (average>=40)
        return "D";
    else if (average>=0)
        return "F";

}