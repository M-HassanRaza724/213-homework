#include <iostream>
using namespace std;

void printMenu();
void calculateAggregate(string,float,float,float);
void compareMarks(string,int,string,int);

main()
{
    system("cls");
    // ***************************HEADER***************************
    printMenu();
    //***************************Aggregate**************************
    string name1, name2;
    float matricMarks1, interMarks1, ecatMarks1, matricMarks2, interMarks2, ecatMarks2; 

    cout<<"Enter 1st student name: ";
    cin>>name1;
    cout<<"Enter his Matric marks(out of 1100): ";
    cin>>matricMarks1;
    cout<<"Enter his inter marks(out of 550): ";
    cin>>interMarks1;
    cout<<"Enter his Ecat marks(out of 400): ";
    cin>>ecatMarks1;

    system("cls");
    printMenu();

    cout<<"Enter 2nd student name: ";
    cin>>name2;
    cout<<"Enter his Matric marks(out of 1100): ";
    cin>>matricMarks2;
    cout<<"Enter his inter marks(out of 550): ";
    cin>>interMarks2;
    cout<<"Enter his Ecat marks(out of 400): ";
    cin>>ecatMarks2;

    calculateAggregate(name1,matricMarks1,interMarks1,ecatMarks1);
    calculateAggregate(name2,matricMarks2,interMarks2,ecatMarks2);
    // **********************Comparison********************************
   
    compareMarks(name1,ecatMarks1,name2,ecatMarks2);
}
void printMenu()
{
    cout<<"   ##   ##  ###  ##  ######  ##   ##  #######  ######    #####   ######  ######  ##    ##         #####   ######   #       #  ######   #####    #####   ######   #####   ###  ##  " << endl;
    cout<<"   ##   ##  #### ##    ##    ##   ##   ##  ##   ##  ##  ##   ##    ##      ##     ##  ##         ##   ##   ##  ##   ##   ##     ##    ##   ##  ##   ##    ##    ##   ##  #### ##  " << endl;
    cout<<"   ##   ##  #######    ##    ##   ##   ##       ##  ##  ##         ##      ##      ####          ##   ##   ##  ##   ### ###     ##    ##       ##         ##    ##   ##  #######  " << endl;
    cout<<"   ##   ##  ## ####    ##    ##   ##   ####     #####    #####     ##      ##       ##           #######   ##  ##   ## # ##     ##     #####    #####     ##    ##   ##  ## ####  " << endl;
    cout<<"   ##   ##  ##  ###    ##     ## ##    ##       ###          ##    ##      ##       ##           ##   ##   ##  ##   ##   ##     ##         ##       ##    ##    ##   ##  ##  ###  " << endl;
    cout<<"   ##   ##  ##   ##    ##      ###     ##  ##   ## ##   ##   ##    ##      ##       ##           ##   ##   ##  ##   ##   ##     ##    ##   ##  ##   ##    ##    ##   ##  ##   ##  " << endl;
    cout<<"    #####   ##   ##  ######     #     #######  ###  ##   #####   ######    ##       ##           ##   ##  ######   ###   ###  ######   #####    #####   ######   #####   ##   ##  " << endl;
    cout<<"                                                                                                                                                                                  " << endl;
    cout<<"      #       #   #####   ###  ##   #####    #####    #######  #       #  #######  ###  ##  ######         #####   ##    ##   #####   ######  #######  #       #  " << endl;
    cout<<"       ##   ##   ##   ##  #### ##  ##   ##  ##   ##    ##  ##   ##   ##    ##  ##  #### ##    ##          ##   ##   ##  ##   ##   ##    ##     ##  ##   ##   ##   " << endl;
    cout<<"       ### ###   ##   ##  #######  ##   ##  ##         ##       ### ###    ##      #######    ##          ##         ####    ##         ##     ##       ### ###   " << endl;
    cout<<"       ## # ##   #######  ## ####  #######  ##         ####     ## # ##    ####    ## ####    ##           #####      ##      #####     ##     ####     ## # ##   " << endl;
    cout<<"       ##   ##   ##   ##  ##  ###  ##   ##  ## ####    ##       ##   ##    ##      ##  ###    ##               ##     ##          ##    ##     ##       ##   ##   " << endl;
    cout<<"       ##   ##   ##   ##  ##   ##  ##   ##  ##  # ##   ##  ##   ##   ##    ##  ##  ##   ##    ##          ##   ##     ##     ##   ##    ##     ##  ##   ##   ##   " << endl;
    cout<<"      ###   ###  ##   ##  ##   ##  ##   ##   ###  ##  #######  ###   ###  #######  ##   ##    ##           #####      ##      #####     ##    #######  ###   ###  " << endl;
}

void calculateAggregate(string name,float matricMarks,float interMarks,float ecatMarks)
{
    float percentage1 =(matricMarks/1100)*30;
    float percentage2 =(interMarks/550)*30;
    float percentage3 =(ecatMarks/400)*40;

    float aggregate = percentage1+percentage2+percentage3;
    cout<<name<<" aggregate is: "<<aggregate<<endl;
}

void compareMarks(string nameStd1,int ecatMarksStd1,string nameStd2,int ecatMarksStd2)
{
    if(ecatMarksStd1>ecatMarksStd2)
    {
        cout<<nameStd1<<" got the first roll no based on his "<<ecatMarksStd1<<" ecat marks.";
    }
    if(ecatMarksStd1<ecatMarksStd2)
    {
        cout<<nameStd2<<" got the first roll no based on his "<<ecatMarksStd2<<" ecat marks.";
    }
}
