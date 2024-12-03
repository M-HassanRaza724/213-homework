# include <iostream>
# include<windows.h>
# include<conio.h>
using namespace std;

int lax = 21, lbx = 42, l1y = 1;
int e_lax = 21, e_lbx = 42, e_l1y = 1;


void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void print_header();
void print_road();
void print_lines();
void erase_lines();
void move_lines();


main(){
    print_header();
    cout<<"Press any key to continue...\n";
    getch();
    system("cls");
    print_road();

    while(true){

        move_lines();
        Sleep(50);
    }

    return 0;
}

void print_header(){

    cout<<"____________________________________________________________________________________________________________________________________________\n";
    cout<<"|                                                                                                                                          |\n";
    cout<<"| ######  ######     #####    #######  #######  ######    #####          #####   ###   ##    #####     #####   ######  #######   ######    |\n";
    cout<<"|   ##     ##  ##   ##   ##    ##  ##   ##  ##    ##     ##   ##        ##   ##   ##   ##   ##   ##   ##   ##    ##     ##  ##    ##  ##   |\n";
    cout<<"|   ##     ##  ##   ##   ##    ##       ##        ##     ##             ##        ##   ##   ##   ##   ##   ##    ##     ##        ##  ##   |\n";
    cout<<"|   ##     #####    #######    ####     ####      ##     ##              #####    #######   ##   ##   ##   ##    ##     ####      #####    |\n";
    cout<<"|   ##     ###      ##   ##    ##       ##        ##     ##                  ##   ##   ##   ##   ##   ##   ##    ##     ##        ###      |\n";
    cout<<"|   ##     ## ##    ##   ##    ##       ##        ##     ##   ##        ##   ##   ##   ##   ##   ##   ##   ##    ##     ##  ##    ## ##    |\n";
    cout<<"|   ##     ##  ###  ##   ##   ####     ####     ######    #####          #####    ##   ###   #####     #####     ##    #######    ##  ###  |\n";
    cout<<"|__________________________________________________________________________________________________________________________________________|\n";
}
void gotoxy(int x, int y){

    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void print_road(){
    gotoxy(0,0);
    cout<<"################################################################"<<endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"#                                                              #"<< endl;
    cout<<"################################################################"<<endl;
}
void print_lines(){

        gotoxy(lax,l1y);
        cout<<"#";
        gotoxy(lbx,l1y);
        cout<<"#";
        l1y++;
        if(l1y == 29){
            l1y = 1;
        }
}

void erase_lines(){

        gotoxy(e_lax,e_l1y);
        cout<<" ";
        gotoxy(e_lbx,e_l1y);
        cout<<" ";
        e_l1y++;
        if(e_l1y == 29){
            e_l1y = 1;
        }
}

void move_lines(){

        print_lines();

        if(getCharAtxy(21,10) == '#' || getCharAtxy(21,18) == '#' || getCharAtxy(21,26) == '#' || getCharAtxy(21,28) == '#'){
            erase_lines();
        }
}

void print_car(){
   __#_____#__   
  / _________ \  
 [| \       / |] 
  |  \_____/  |  
| |  |     |  | |
|-|  |     |  |-|
  |  |     |  |  
  |  |_____|  |  
 [| /_______\ |] 
  |___________|  
}



