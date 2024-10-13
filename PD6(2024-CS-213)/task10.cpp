# include <iostream>
# include<windows.h>
# include<conio.h>
using namespace std;

int lax = 23, lbx = 46, ly = 1;
int e_lax = 23, e_lbx = 46, e_ly = 1;
int Px = 27,Py = 25;
int Ex = 3,Ey = 2;
int Ex2 = 29,Ey2 = 2;
int Ex3 = 52,Ey3 = 2;
int BulletX = -1, BulletY = -1;
bool BulletActive = false;


void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);

void print_header();
void print_road();

void print_lines();
void erase_lines();
void move_lines(int);

void print_car();
void erase_car();
void move_car_left();
void move_car_right();
void move_car_up(int i);
void move_car_down(int i);

void print_enemy1();
void erase_enemy1();
void move_enemy1(int i);
void move_enemy2(int i);
void erase_enemy2();
void print_enemy2();
void move_enemy3(int i);
void erase_enemy3();
void print_enemy3();

void print_bullet(int,int);
void erase_bullet(int,int);
void bullet_initialization(int,int);


main(){
    int i = 1, speed = 30;
    print_header();
    cout<<"\n\n\n\n\nPress any key to continue...";
    getch();
    system("cls");
    print_road();
    // print_enemy1();
    // print_enemy3();
    print_enemy2();
    print_car();
    while(true){

        i++;
        if(i==999) 
            i = 10;   //control line lenght

        //left movement
        if(GetAsyncKeyState(VK_LEFT)){
                move_car_left();
        }
        //right movement
        if(GetAsyncKeyState(VK_RIGHT)){
                move_car_right();
        }
        //speed and vertical movement
        if(GetAsyncKeyState(VK_UP)){
                move_car_up(i);
            if((speed != 10) && (i%5 == 0)){
                speed--;
            }
        }
        if(GetAsyncKeyState(VK_DOWN)){
                move_car_down(i);
            if((speed != 30) && (i%5 == 0)){
                speed++;
            }
        }
        else{
            if((i%100 == 0) && (speed != 30))
                speed++;
        }

        // Bullet movement logic
        if ((GetAsyncKeyState(VK_SPACE)) && !BulletActive)
            bullet_initialization(Px, Py+5);
        print_car();
        if (BulletActive){
            erase_bullet(BulletX,BulletY); 
            BulletY = BulletY-2;  
            if (BulletY == 0 || BulletY == 1 || getCharAtxy(BulletX, BulletY) != ' '  &&
             getCharAtxy(BulletX, BulletY) != '#'/*|| getCharAtxy(BulletX, BulletY-1) != ' ' */)
                BulletActive = false;          // Reset bullet
            else
                print_bullet(BulletX, BulletY);            
        }

        move_lines(i);
        // move_enemy1(i);
        move_enemy2(i);
        // move_enemy3(i);
        Sleep(speed);
    }

    return 0;
}

void print_header(){

    system("cls");
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
    cout<<"######################################################################"<<endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"|                                                                    |"<< endl;
    cout<<"######################################################################"<<endl;
    // 64x35
}
void print_lines(){

        gotoxy(lax,ly);
        cout<<"#";
        gotoxy(lbx,ly);
        cout<<"#";
        ly++;
        if(ly == 34)
            ly = 1;
}

void erase_lines(){

        gotoxy(e_lax,e_ly);
        cout<<" ";
        gotoxy(e_lbx,e_ly);
        cout<<" ";
        e_ly++;
        if(e_ly == 34)
            e_ly = 1;
        
}

void move_lines(int erase_permit){

    print_lines();
    if(erase_permit>9)  //decides the lenght of lines
        erase_lines();
}

void print_car(){
    gotoxy(Px,Py);
    cout<<"   _-___-_   ";
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
    if(getCharAtxy(Px-1,Py) != '|'){
    erase_car();
    Px = Px-1;
    print_car();
    }
}

void move_car_right(){
    if(getCharAtxy(Px+14,Py) != '|'){
        erase_car();
        Px = Px+1;
        print_car();
    }
}
void move_car_up(int i){
    if((Py >= 24) && (i%2 == 0)){
        erase_car();
        Py = Py-1;
        print_car();
    }
}
void move_car_down(int i){
    if((Py <= 24)&& (i%2 == 0)){
        erase_car();
        Py = Py+1;
        print_car();
    }
}

void print_enemy1(){
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

void erase_enemy1(){
    gotoxy(Ex,Ey);
    cout<<"             ";
    gotoxy(Ex,Ey+1);
    cout<<"             ";
    gotoxy(Ex,Ey+2);
    cout<<"             ";
    gotoxy(Ex,Ey+3);
    cout<<"             ";
    gotoxy(Ex,Ey+4);
    cout<<"             ";
    gotoxy(Ex,Ey+5);
    cout<<"             ";
    gotoxy(Ex,Ey+6);
    cout<<"             ";
    gotoxy(Ex,Ey+7);
    cout<<"             ";
}

void move_enemy1(int i){

    if(i%6 == 0){
    erase_enemy1();
    Ey++;
    if(Ey == 26)
        Ey = 2;
    print_enemy1();
    }
}
void print_enemy2(){
    gotoxy(Ex2,Ey2);
    cout<<"  _#___#_   ";
    gotoxy(Ex2,Ey2+1);
    cout<<" / _____ \\  ";
    gotoxy(Ex2,Ey2+2);
    cout<<"[| |   | |] ";
    gotoxy(Ex2,Ey2+3);
    cout<<" | \\___/ |_ ";
    gotoxy(Ex2,Ey2+4);
    cout<<" |       | |";
    gotoxy(Ex2,Ey2+5);
    cout<<" | /---\\ |  ";
    gotoxy(Ex2,Ey2+6);
    cout<<"[| |___| |] ";
    gotoxy(Ex2,Ey2+7);
    cout<<" \\_______/  ";
}

void erase_enemy2(){
    gotoxy(Ex2,Ey2);
    cout<<"             ";
    gotoxy(Ex2,Ey2+1);
    cout<<"             ";
    gotoxy(Ex2,Ey2+2);
    cout<<"             ";
    gotoxy(Ex2,Ey2+3);
    cout<<"             ";
    gotoxy(Ex2,Ey2+4);
    cout<<"             ";
    gotoxy(Ex2,Ey2+5);
    cout<<"             ";
    gotoxy(Ex2,Ey2+6);
    cout<<"             ";
    gotoxy(Ex2,Ey2+7);
    cout<<"             ";
}

void move_enemy2(int i){

    if(i%6 == 0){
    erase_enemy2();
    Ey2++;
    if(Ey2 == 26){
        Ey2 = 2;
        Ex2 = 51;
    }
    print_enemy2();
    }
    if(i%7 == 0){
    erase_enemy2();
    Ex2++;
    if(Ex2 == 52)
        Ex2 = 29;
    print_enemy2();
    }
}
void print_enemy3(){
    gotoxy(Ex3,Ey3);
    cout<<"  _#___#_   ";
    gotoxy(Ex3,Ey3+1);
    cout<<" / _____ \\  ";
    gotoxy(Ex3,Ey3+2);
    cout<<"[| |   | |] ";
    gotoxy(Ex3,Ey3+3);
    cout<<" | \\___/ |_ ";
    gotoxy(Ex3,Ey3+4);
    cout<<" |       | |";
    gotoxy(Ex3,Ey3+5);
    cout<<" | /---\\ |  ";
    gotoxy(Ex3,Ey3+6);
    cout<<"[| |___| |] ";
    gotoxy(Ex3,Ey3+7);
    cout<<" \\_______/  ";
}

void erase_enemy3(){
    gotoxy(Ex3,Ey3);
    cout<<"             ";
    gotoxy(Ex3,Ey3+1);
    cout<<"             ";
    gotoxy(Ex3,Ey3+2);
    cout<<"             ";
    gotoxy(Ex3,Ey3+3);
    cout<<"             ";
    gotoxy(Ex3,Ey3+4);
    cout<<"             ";
    gotoxy(Ex3,Ey3+5);
    cout<<"             ";
    gotoxy(Ex3,Ey3+6);
    cout<<"             ";
    gotoxy(Ex3,Ey3+7);
    cout<<"             ";
}

void move_enemy3(int i){

    if(i%6 == 0){
    erase_enemy3();
    Ex3--;
    if(Ex3 == 2)
        Ex3 = 52;
    print_enemy3();
    }
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

void bullet_initialization(int x, int y){
    BulletX = x;
    BulletY = y;
    BulletActive = true;
}