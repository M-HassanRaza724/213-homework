#include<iostream>
#include<windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void name(int x, int y)
{
    gotoxy(x,y);
    cout <<"  ###   ##    #####     #####    #####    #####   ###  ##  " << endl;
    y++;
    gotoxy(x,y);
    cout <<"   ##   ##   ##   ##   ##   ##  ##   ##  ##   ##  #### ##  " << endl;
    y++;
    gotoxy(x,y);
    cout <<"   ##   ##   ##   ##   ##       ##       ##   ##  #######  " << endl;
    y++;
    gotoxy(x,y);
    cout <<"   #######   #######    #####    #####   #######  ## ####  " << endl;
    y++;
    gotoxy(x,y);
    cout <<"   ##   ##   ##   ##        ##       ##  ##   ##  ##  ###  " << endl;
    y++;
    gotoxy(x,y);
    cout <<"   ##   ##   ##   ##   ##   ##  ##   ##  ##   ##  ##   ##  " << endl;
    y++;
    gotoxy(x,y);
    cout <<"   ##   ###  ##   ##    #####    #####   ##   ##  ##   ##  " << endl;
}

main()
{
    system("cls");

    name(10,10);
}