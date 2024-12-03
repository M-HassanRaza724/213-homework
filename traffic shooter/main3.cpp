# include <iostream>
# include<windows.h>
# include<conio.h>
using namespace std;

int lax = 23, lbx = 46, ly = 1;
int e_lax = 23, e_lbx = 46, e_ly = 1;
int Px = 27,Py = 26;
int Ex[3] ={3,29,52};
int Ey[3] ={2,2,2};
int BulletX = -1, BulletY = -1;
bool BulletActive = false;
char line = 219;

char light = 220,block = 219,pistol0 = 200;
string pistol = {pistol0};
string car[9];
string enemy1[9];
string enemy2[9];
string enemy3[9];


void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);

void initialize_vehicles();
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

void erase_enemy(int n);
void print_enemy1();
void print_enemy2();
void print_enemy3();

void move_enemy1(int i);
void move_enemy2(int i);
void move_enemy3(int i);


void print_bullet(int,int);
void erase_bullet(int,int);
void bullet_initialization(int,int);

inline int scoreCal(int iteration, int score);
string enemy_1HealthCal(string enemy1_health);

main(){
    int i = 1, speed = 30;
    int score = 0,damage = 1;
    string player_health = "@@@@@@@@@@", enemy1_health = "@@@@", enemy2_health = "@@@@", enemy3_health = "@@@@";

    initialize_vehicles();
    print_header();
    cout<<"\n\n\n\n\nPress any key to continue...";
    getch();
    system("cls");
    print_road();

    print_enemy1();
    print_enemy2();
    print_enemy3();
    print_car();
    while(true){

        //Iterations
        i++;
        if(i==999) 
            i = 10;   //control line lenght
        // statics
        score = scoreCal(i, score);
        gotoxy(80, 4);
        cout<<score;

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
            bullet_initialization(Px, Py+2);
        else if (BulletActive){
            erase_bullet(BulletX,BulletY); 
            BulletY = BulletY-2;  
            if (BulletY == 0 || BulletY == 1 || getCharAtxy(BulletX, BulletY) != ' '  &&
             getCharAtxy(BulletX, BulletY) != block/*|| getCharAtxy(BulletX, BulletY-1) != ' ' */)
                BulletActive = false;          // Reset bullet
            else
                print_bullet(BulletX, BulletY);            
        }

        move_lines(i);

        move_enemy1(i);
        move_enemy2(i);
        move_enemy3(i);
        Sleep(speed);
    }

    return 0;
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

inline int scoreCal(int iteration, int score){
    if(iteration%5 == 0)
        score++;
    return score;
}

// string enemy_1HealthCal(string enemy1_health){
//     if(BulletX)
// }



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


void move_car_left(){
    if((getCharAtxy(Px-1,Py) == ' ' && getCharAtxy(Px-1,Py+8) == ' ')|| getCharAtxy(Px+14,Py) == line){
        erase_car();
        Px = Px-1;
        if((Px==23 || Px == 46))
            Px--;
        print_car();
    }
}

void move_car_right(){
    if((getCharAtxy(Px+14,Py) == ' ' && getCharAtxy(Px+14,Py+8) == ' ' )|| getCharAtxy(Px+14,Py) == line){
        erase_car();
        Px = Px+1;
        if((Px==23 || Px == 46))
            Px++;
        print_car();
    }
}
void move_car_up(int i){
    if((Py >= 25) && (i%2 == 0)){
        erase_car();
        Py = Py-1;
        print_car();
    }
}
void move_car_down(int i){
    if((Py < 26)&& (i%2 == 0)){
        erase_car();
        Py = Py+1;
        print_car();
    }
}


void move_enemy1(int i){ //vertical
    if(getCharAtxy(Ex[0]+4,Ey[0]+10) == ' '){
        erase_enemy(0);
        if(i%80 == 0){
            if(Ey[0]<Py-1)
                Ey[0]++;
            if(Ey[0]>Py+1)
                Ey[0]--;
        }

        print_enemy1();
    }
}

void move_enemy2(int i){ //diagonal

    if(getCharAtxy(Ex[1]+1,Ey[1]) == ' ' && i%6 == 0){
        erase_enemy(1);
            if(Ey[1]<Py-1)
                Ey[1]++;
            if(Ey[1]>Py+1)
                Ey[1]--;
    }
    if(getCharAtxy(Ex[1]+15,Ey[1]) == ' '){
        if((Ex[1]<52) && (i%6 == 0))
        Ex[1]++;
    }   

    print_enemy2();
}

void move_enemy3(int i){  //horizontal
    if(i%6 == 0){
        erase_enemy(2);
        if(Px+3<Ex[2]){
            if(getCharAtxy(Ex[2]-1,Ey[2]) == ' ' && Ex[2]> 20)
                Ex[2]--;
        }
        else if(Px-3>Ex[2]){
            if(getCharAtxy(Ex[2]+15,Ey[2]) == ' '&& Ex[2]<38)
                Ex[2]++;
        }
        print_enemy3();
    }
}

void print_lines(){
        gotoxy(lax,ly);
        cout<<line;
        gotoxy(lbx,ly);
        cout<<line;
        ly++;
        if(ly == 36)
            ly = 1;
}

void erase_lines(){

        gotoxy(e_lax,e_ly);
        cout<<" ";
        gotoxy(e_lbx,e_ly);
        cout<<" ";
        e_ly++;
        if(e_ly == 36)
            e_ly = 1;
        
}

void move_lines(int erase_permit){

    print_lines();
    if(erase_permit>9)  //decides the lenght of lines
        erase_lines();
}

void print_car(){

    gotoxy(Px,Py);
    cout<<car[0];
    gotoxy(Px,Py+1);
    cout<<car[1];
    gotoxy(Px,Py+2);
    cout<<car[2];
    gotoxy(Px,Py+3);
    cout<<car[3];
    gotoxy(Px,Py+4);
    cout<<car[4];
    gotoxy(Px,Py+5);
    cout<<car[5];
    gotoxy(Px,Py+6);
    cout<<car[6];
    gotoxy(Px,Py+7);
    cout<<car[7];
    gotoxy(Px,Py+8);
    cout<<car[8];
}
void erase_car(){
    string space = "              ";
    for (int i = 0; i < 9; i++)
    {
        gotoxy(Px,Py+i);
        cout<<space;
    }
    
}

void print_enemy1(){

    gotoxy(Ex[0],Ey[0]);
    cout<<enemy1[0];
    gotoxy(Ex[0],Ey[0]+1);
    cout<<enemy1[1];
    gotoxy(Ex[0],Ey[0]+2);
    cout<<enemy1[2];
    gotoxy(Ex[0],Ey[0]+3);
    cout<<enemy1[3];
    gotoxy(Ex[0],Ey[0]+4);
    cout<<enemy1[4];
    gotoxy(Ex[0],Ey[0]+5);
    cout<<enemy1[5];
    gotoxy(Ex[0],Ey[0]+6);
    cout<<enemy1[6];
    gotoxy(Ex[0],Ey[0]+7);
    cout<<enemy1[7];
    gotoxy(Ex[0],Ey[0]+8);
    cout<<enemy1[8];
}
void print_enemy2(){
    gotoxy(Ex[1],Ey[1]);
    cout<<enemy2[0];
    gotoxy(Ex[1],Ey[1]+1);
    cout<<enemy2[1];
    gotoxy(Ex[1],Ey[1]+2);
    cout<<enemy2[2];
    gotoxy(Ex[1],Ey[1]+3);
    cout<<enemy2[3];
    gotoxy(Ex[1],Ey[1]+4);
    cout<<enemy2[4];
    gotoxy(Ex[1],Ey[1]+5);
    cout<<enemy2[5];
    gotoxy(Ex[1],Ey[1]+6);
    cout<<enemy2[6];
    gotoxy(Ex[1],Ey[1]+7);
    cout<<enemy2[7];
    gotoxy(Ex[1],Ey[1]+8);
    cout<<enemy2[8];
}
void print_enemy3(){
    gotoxy(Ex[2],Ey[2]);
    cout<<enemy3[0];
    gotoxy(Ex[2],Ey[2]+1);
    cout<<enemy3[1];
    gotoxy(Ex[2],Ey[2]+2);
    cout<<enemy3[2];
    gotoxy(Ex[2],Ey[2]+3);
    cout<<enemy3[3];
    gotoxy(Ex[2],Ey[2]+4);
    cout<<enemy3[4];
    gotoxy(Ex[2],Ey[2]+5);
    cout<<enemy3[5];
    gotoxy(Ex[2],Ey[2]+6);
    cout<<enemy3[6];
    gotoxy(Ex[2],Ey[2]+7);
    cout<<enemy3[7];
    gotoxy(Ex[2],Ey[2]+8);
    cout<<enemy3[8];
}

void erase_enemy(int n){
    string space = "             ";
    for (int i = 0; i < 9; i++)
    {
        gotoxy(Ex[n],Ey[n]+i);
        cout<<space;
    }
}
void initialize_vehicles(){

car[0] = {' ',' ',' ','_',light,'_','_','_',light,'_',' ',' ',' '};
car[1] = "  /_______\\  ";
car[2] = " /         \\ ";
car[3] = "[|  \\   /  |]";
car[4] = " |   \\_/   | ";
car[5] = pistol+"|  | | |  | ";
car[6] = " |  | | |  | ";
car[7] = "[|___/_\\___|]";
car[8] = " |_________| ";

enemy1[0] = {' ',' ',' ','_',light,'_','_','_',light,'_',' ',' ',' '};
enemy1[1] = "  /_______\\  ";
enemy1[2] = " /         \\ ";
enemy1[3] = "[|  |   |  |]";
enemy1[4] = " |   \\_/   | ";
enemy1[5] = " |         | ";
enemy1[6] = " |  /---\\  | ";
enemy1[7] = "[|__|   |__|]";
enemy1[8] = " \\_________/ ";

enemy2[0] = {' ',' ',' ','_',light,'_','_','_',light,'_',' ',' ',' '};
enemy2[1] = "  /_______\\  ";
enemy2[2] = " /         \\ ";
enemy2[3] = "[|  \\___/  |]";
enemy2[4] = " |   |_|   | ";
enemy2[5] = " |         | ";
enemy2[6] = " |  /___\\  | ";
enemy2[7] = "[|_/_____\\_|]";
enemy2[8] = " \\_________/ ";  

enemy3[0] = {' ',' ',' ','_',light,'_','_','_',light,'_',' ',' ',' '};
enemy3[1] = "  /_______\\  ";
enemy3[2] = " /         \\ ";
enemy3[3] = "[| |     | |]";
enemy3[4] = " | |_____| | ";
enemy3[5] = " |         | ";
enemy3[6] = " |  /---\\  | ";
enemy3[7] = "[|_|     |_|]";
enemy3[8] = " \\_________/ ";
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
void print_road(){
    gotoxy(0,0);
    cout<<"##############################################################################################"<<endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"|                                                                    |      --STATICS--      |"<< endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"|                                                                    |  SCORE :              |"<< endl;
    cout<<"|                                                                    |  HEALTH:@@@@@@@@@@    |"<< endl;
    cout<<"|                                                                    |  DAMAGE: 1x           |"<< endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"|                                                                    |  ENEMY 1 health:@@@@  |"<< endl;
    cout<<"|                                                                    |  ENEMY 2 health:@@@@  |"<< endl;
    cout<<"|                                                                    |  ENEMY 3 health:@@@@  |"<< endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"|                                                                    |-----------------------|"<< endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"|                                                                    |-----------------------|"<< endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"|                                                                    |       --MENU--        |"<< endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"|                                                                    |  Press 0 to start     |"<< endl;
    cout<<"|                                                                    |  Press 1 for MainMenu |"<< endl;
    cout<<"|                                                                    |  Press 2 to exit      |"<< endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"|                                                                    |     --CONTROLS--      |"<< endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"|                                                                    |  Accelerate: up key   |"<< endl;
    cout<<"|                                                                    |  Break: down key      |"<< endl;
    cout<<"|                                                                    |  Left: down key       |"<< endl;
    cout<<"|                                                                    |  Right: down key      |"<< endl;
    cout<<"|                                                                    |  Shoot: space bar     |"<< endl;
    cout<<"|                                                                    |                       |"<< endl;
    cout<<"##############################################################################################"<<endl;
    // (64+24)x37
}