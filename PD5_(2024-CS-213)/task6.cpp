# include <iostream>
# include<windows.h>
# include<conio.h>
using namespace std;

int lax = 21, lbx = 42, ly = 1;
int e_lax = 21, e_lbx = 42, e_ly = 1;
int Px = 25,Py = 20;
int Ex = 3,Ey = 2;
int BulletX = -1, BulletY = -1;
bool BulletActive = false;


void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void print_header();
void print_road();
void print_lines();
void erase_lines();
void move_lines();
void print_car();
void erase_car();
void move_car_left();
void move_car_right();
void print_enemy();
void print_bullet(int,int);
void erase_bullet(int,int);
void shoot_bullet(int,int);


main(){
    print_header();
    cout<<"Press any key to continue...\n";
    getch();
    system("cls");
    print_road();

    while(true){

        print_car();
        move_lines();

        //left movement
        if(GetAsyncKeyState(VK_LEFT)){
            if(getCharAtxy(Px-1,Py) == ' '){
                move_car_left();
            }
        }
        //right movement
        if(GetAsyncKeyState(VK_RIGHT)){
            if(getCharAtxy(Px+14,Py) == ' '){
                move_car_right();
            }
        }
                // Shoot bullet when space is pressed
        if ((GetAsyncKeyState(VK_SPACE)) && !BulletActive){
            shoot_bullet(Px, Py+5); //sets bullet position
        }

        // Bullet movement logic
        if (BulletActive){

            erase_bullet(BulletX,BulletY); // Erase previous bullet
            BulletY = BulletY-2;  // Move bullet up

            if (BulletY == 0 || getCharAtxy(BulletX, BulletY) != ' '|| getCharAtxy(BulletX, BulletY-1) != ' '){
                BulletActive = false;  // Reset bullet if it hits top or enemy
            } else {
                print_bullet(BulletX, BulletY);  // Print new bullet position
            }
        }

        print_enemy();
        Sleep(25);
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

        gotoxy(lax,ly);
        cout<<"#";
        gotoxy(lbx,ly);
        cout<<"#";
        ly++;
        if(ly == 29){
            ly = 1;
        }
}

void erase_lines(){

        gotoxy(e_lax,e_ly);
        cout<<" ";
        gotoxy(e_lbx,e_ly);
        cout<<" ";
        e_ly++;
        if(e_ly == 29){
            e_ly = 1;
        }
}

void move_lines(){

        print_lines();

        if(getCharAtxy(21,10) == '#' || getCharAtxy(21,18) == '#' || getCharAtxy(21,26) == '#' || getCharAtxy(21,28) == '#'){
            erase_lines();
        }
}

void print_car(){
    gotoxy(Px,Py);
    cout<<"   _#___#_   ";
    gotoxy(Px,Py+1);
    cout<<"  /_______\\  ";
    gotoxy(Px,Py+2);
    cout<<" [|\\     /|] ";
    gotoxy(Px,Py+3);
    cout<<"  | \\___/ |  ";
    gotoxy(Px,Py+4);
    cout<<"|_| |   | |_|";
    gotoxy(Px,Py+5);
    cout<<"  | |___| |  ";
    gotoxy(Px,Py+6);
    cout<<" [|/_____\\|] ";
    gotoxy(Px,Py+7);
    cout<<"  |_______|  ";
}
void erase_car(){
    gotoxy(Px,Py);
    cout<<"             ";
    gotoxy(Px,Py+1);
    cout<<"             ";
    gotoxy(Px,Py+2);
    cout<<"             ";
    gotoxy(Px,Py+3);
    cout<<"             ";
    gotoxy(Px,Py+4);
    cout<<"             ";
    gotoxy(Px,Py+5);
    cout<<"             ";
    gotoxy(Px,Py+6);
    cout<<"             ";
    gotoxy(Px,Py+7);
    cout<<"             ";
}

void move_car_left(){
    erase_car();
    Px = Px-1;
    print_car();
}

void move_car_right(){
    erase_car();
    Px = Px+1;
    print_car();
}

void print_enemy(){
    gotoxy(Ex,Ey);
    cout<<"  _#___#_   ";
    gotoxy(Ex,Ey+1);
    cout<<" / _____ \\  ";
    gotoxy(Ex,Ey+2);
    cout<<"[| |   | |] ";
    gotoxy(Ex,Ey+3);
    cout<<" | \\___/ |_ ";
    gotoxy(Ex,Ey+4);
    cout<<" |       | |";
    gotoxy(Ex,Ey+5);
    cout<<" | /---\\ |  ";
    gotoxy(Ex,Ey+6);
    cout<<"[| |___| |] ";
    gotoxy(Ex,Ey+7);
    cout<<" \\_______/  ";
}

void print_bullet(int x,int y){
    gotoxy(x,y);
    cout<<"^";
    gotoxy(x,y+1);
    cout<<"|";
}
void erase_bullet(int x,int y){
    gotoxy(x,y);
    cout<<" ";
    gotoxy(x,y+1);
    cout<<" ";
}

void shoot_bullet(int x, int y){
    BulletX = x;
    BulletY = y;
    BulletActive = true;
}