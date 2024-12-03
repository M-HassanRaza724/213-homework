# include <iostream>
#include<windows.h>
using namespace std;

void gotoxy(int x, int y){
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void a(int x,int y){
    gotoxy(x,y);
    cout<<" #####    "<<endl;
    gotoxy(x,y+1);
    cout<<"##   ##   "<<endl;
    gotoxy(x,y+2);
    cout<<"##   ##   "<<endl;
    gotoxy(x,y+3);
    cout<<"#######   "<<endl;
    gotoxy(x,y+4);
    cout<<"##   ##   "<<endl;
    gotoxy(x,y+5);
    cout<<"##   ##   "<<endl;
    gotoxy(x,y+6);
    cout<<"##   ##   "<<endl;
}
void b(int x,int y){
    gotoxy(x,y);
    cout<<"######    \n";
    gotoxy(x,y+1);
    cout<<" ##  ##   \n";
    gotoxy(x,y+2);
    cout<<" ##  ##   \n";
    gotoxy(x,y+3);
    cout<<" #####    \n";
    gotoxy(x,y+4);
    cout<<" ##  ##   \n";
    gotoxy(x,y+5);
    cout<<" ##  ##   \n";
    gotoxy(x,y+6);
    cout<<"######    \n"; 
}
void c(int x,int y){
    gotoxy(x,y);
    cout<<" #####    \n";
    gotoxy(x,y+1);
    cout<<"##   ##   \n";
    gotoxy(x,y+2);
    cout<<"##        \n";
    gotoxy(x,y+3);
    cout<<"##        \n";
    gotoxy(x,y+4);
    cout<<"##        \n";
    gotoxy(x,y+5);
    cout<<"##   ##   \n";
    gotoxy(x,y+6);
    cout<<" #####    \n";
}
void e(int x,int y){
    gotoxy(x,y);
    cout<<"#######   \n";
    gotoxy(x,y+1);
    cout<<" ##  ##   \n";
    gotoxy(x,y+2);
    cout<<" ##       \n";
    gotoxy(x,y+3);
    cout<<" ####     \n";
    gotoxy(x,y+4);
    cout<<" ##       \n";
    gotoxy(x,y+5);
    cout<<" ##  ##   \n";
    gotoxy(x,y+6);
    cout<<"#######   \n";
}
void s(int x, int y){
    gotoxy(x,y);
    cout<<" #####    "<<endl;
    gotoxy(x,y+1);
    cout<<"##   ##   "<<endl;
    gotoxy(x,y+2);
    cout<<"##        "<<endl;
    gotoxy(x,y+3);
    cout<<" #####    "<<endl;
    gotoxy(x,y+4);
    cout<<"     ##   "<<endl;
    gotoxy(x,y+5);
    cout<<"##   ##   "<<endl;
    gotoxy(x,y+6);
    cout<<" #####    "<<endl;
}
void p(int x,int y){
    gotoxy(x,y);
    cout<<"######    \n";
    gotoxy(x,y+1);
    cout<<" ##  ##   \n";
    gotoxy(x,y+2);
    cout<<" ##  ##   \n";
    gotoxy(x,y+3);
    cout<<" #####    \n";
    gotoxy(x,y+4);
    cout<<" ##       \n";
    gotoxy(x,y+5);
    cout<<" ##       \n";
    gotoxy(x,y+6);
    cout<<"####      \n"; 
}
void f(int x,int y){
    gotoxy(x,y);
    cout<<"#######   \n";
    gotoxy(x,y+1);
    cout<<" ##  ##   \n";
    gotoxy(x,y+2);
    cout<<" ##       \n";
    gotoxy(x,y+3);
    cout<<" ####     \n";
    gotoxy(x,y+4);
    cout<<" ##       \n";
    gotoxy(x,y+5);
    cout<<" ##       \n";
    gotoxy(x,y+6);
    cout<<"####      \n";
}
void t(int x,int y){
    gotoxy(x,y);
    cout<<"######   \n";
    gotoxy(x,y+1);
    cout<<"  ##     \n";
    gotoxy(x,y+2);
    cout<<"  ##     \n";
    gotoxy(x,y+3);
    cout<<"  ##     \n";
    gotoxy(x,y+4);
    cout<<"  ##     \n";
    gotoxy(x,y+5);
    cout<<"  ##     \n";
    gotoxy(x,y+6);
    cout<<"  ##     \n";
}
void i(int x,int y){
    gotoxy(x,y);
    cout<<"######   \n";
    gotoxy(x,y+1);
    cout<<"  ##     \n";
    gotoxy(x,y+2);
    cout<<"  ##     \n";
    gotoxy(x,y+3);
    cout<<"  ##     \n";
    gotoxy(x,y+4);
    cout<<"  ##     \n";
    gotoxy(x,y+5);
    cout<<"  ##     \n";
    gotoxy(x,y+6);
    cout<<"######   \n";
}
void o(int x,int y){
    gotoxy(x,y);
    cout<<" #####    \n";
    gotoxy(x,y+1);
    cout<<"##   ##   \n";
    gotoxy(x,y+2);
    cout<<"##   ##   \n";
    gotoxy(x,y+3);
    cout<<"##   ##   \n";
    gotoxy(x,y+4);
    cout<<"##   ##   \n";
    gotoxy(x,y+5);
    cout<<"##   ##   \n";
    gotoxy(x,y+6);
    cout<<" #####    \n";
}
void r(int x,int y){
    gotoxy(x,y);
    cout<<"######    \n";
    gotoxy(x,y+1);
    cout<<" ##  ##   \n";
    gotoxy(x,y+2);
    cout<<" ##  ##   \n";
    gotoxy(x,y+3);
    cout<<" #####    \n";
    gotoxy(x,y+4);
    cout<<" ###      \n";
    gotoxy(x,y+5);
    cout<<" ## ##    \n";
    gotoxy(x,y+6);
    cout<<" ##  ###  \n";
}
void h(int x,int y){
    gotoxy(x,y);
    cout<<"###   ##   \n";
    gotoxy(x,y+1);
    cout<<" ##   ##   \n"; 
    gotoxy(x,y+2);
    cout<<" ##   ##   \n";
    gotoxy(x,y+3);
    cout<<" #######   \n";
    gotoxy(x,y+4);
    cout<<" ##   ##   \n";
    gotoxy(x,y+5);
    cout<<" ##   ##   \n";
    gotoxy(x,y+6);
    cout<<" ##   ###  \n";
}
void w(int x,int y){
       
    gotoxy(x,y);
    cout<<"##    ##";
    gotoxy(x,y+1);
    cout<<"##    ##";
    gotoxy(x,y+2);
    cout<<"##    ##";
    gotoxy(x,y+3);
    cout<<"## ## ##";
    gotoxy(x,y+4);
    cout<<"########";
    gotoxy(x,y+5);
    cout<<"###  ###";
    gotoxy(x,y+6);
    cout<<"##    ##";
}

void X(int x, int y){
    gotoxy(x,y);
    cout<<"##   ##";
    gotoxy(x,y+1);
    cout<<"##   ##";
    gotoxy(x,y+2);
    cout<<" ## ## ";
    gotoxy(x,y+3);
    cout<<"  ###  ";
    gotoxy(x,y+4);
    cout<<" ## ## ";
    gotoxy(x,y+5);
    cout<<"##   ##";
    gotoxy(x,y+6);
    cout<<"##   ##";
}
void l(int x, int y){
    gotoxy(x,y);
    cout<<"##     ";
    gotoxy(x,y+1);
    cout<<"##     ";
    gotoxy(x,y+2);
    cout<<"##     ";
    gotoxy(x,y+3);
    cout<<"##     ";
    gotoxy(x,y+4);
    cout<<"##     ";
    gotoxy(x,y+5);
    cout<<"##     ";
    gotoxy(x,y+6);
    cout<<"#######";
}
void logo(int x, int y){
    gotoxy(x,y);
    cout<<"        _____________________________";
    gotoxy(x,y+1);
    cout<<"       /                             \\";
    gotoxy(x,y+1);
    cout<<"      |                               |";
    gotoxy(x,y+2);
    cout<<"      |                               |";
    gotoxy(x,y+3);
    cout<<"      |                               |";
    gotoxy(x,y+4);
    cout<<"      |                               |";
    gotoxy(x,y+5);
    cout<<"      |                               |";
    gotoxy(x,y+6);
    cout<<"      |                               |";
    gotoxy(x,y+7);
    cout<<"      |                               |";
    gotoxy(x,y+8);
    cout<<"      |                               |";
    gotoxy(x,y+9);
    cout<<"      |_______________________________|";
    gotoxy(x,y+10);
    cout<<"      /                               \\";
    gotoxy(x,y+11);
    cout<<"     /                                 \\";
    gotoxy(x,y+12);
    cout<<"    /                                   \\";
    gotoxy(x,y+13);
    cout<<"   /                                     \\";
    gotoxy(x,y+14);
    cout<<"  /                                       \\";
    gotoxy(x,y+15);
    cout<<"  \\_______________________________________/";
}

main(){
    int x=1,y=1;
    logo(x,y+5);

    h(x+50,x);
    X(x+11+50,y);
    a(x+20+50,y);

    s(x+50,y+9);
    o(x+10+50,y+9);
    f(x+19+50,y+9);
    t(x+28+50,y+9);
    w(x+36+50,y+9);
    a(x+47+50,y+9);
    r(x+56+50,y+9);
    e(x+66+50,y+9);

    l(x+50,y+18);
    a(x+9+50,y+18);
    b(x+18+50,y+18);

    

    return 0;
}

