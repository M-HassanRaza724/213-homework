#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
int lax = 23, lbx = 46, ly = 1,e_ly = -9;
int Px = 27,Py = 26;
int Ex[3] ={3,29,52};
int Ey[3] ={2,2,2};
char console[][95] = {
    "##############################################################################################",
    "|                                                                    |                       |",
    "|                                                                    |      --STATICS--      |",
    "|                                                                    |                       |",
    "|                                                                    |  SCORE :              |",
    "|                                                                    |  HEALTH:@@@@@@@@@@    |",
    "|                                                                    |  DAMAGE: 1x           |",
    "|                                                                    |                       |",
    "|                                                                    |  ENEMY 1 health:@@@@  |",
    "|                                                                    |  ENEMY 2 health:@@@@  |",
    "|                                                                    |  ENEMY 3 health:@@@@  |",
    "|                                                                    |                       |",
    "|                                                                    |-----------------------|",
    "|                                                                    |                       |",
    "|                                                                    |                       |",
    "|                                                                    |                       |",
    "|                                                                    |                       |",
    "|                                                                    |                       |",
    "|                                                                    |                       |",
    "|                                                                    |                       |",
    "|                                                                    |-----------------------|",
    "|                                                                    |                       |",
    "|                                                                    |       --MENU--        |",
    "|                                                                    |                       |",
    "|                                                                    |  Press 0 to start     |",
    "|                                                                    |  Press 1 for MainMenu |",
    "|                                                                    |  Press 2 to exit      |",
    "|                                                                    |                       |",
    "|                                                                    |     --CONTROLS--      |",
    "|                                                                    |                       |",
    "|                                                                    |  Accelerate: up key   |",
    "|                                                                    |  Break: down key      |",
    "|                                                                    |  Left: down key       |",
    "|                                                                    |  Right: down key      |",
    "|                                                                    |  Shoot: space bar     |",
    "|                                                                    |                       |",
    "##############################################################################################"
    // (94)x37
};

void gotoxy(int x, int y);
void print_console();
void update_lines();


void print_car(string car[]);
void erase_car();
void move_car_left(string car[]);
void move_car_right(string car[]);
void move_car_up(string car[],int i);
void move_car_down(string car[],int i);

void erase_enemy(int n);
void print_enemy1(string enemy1[]);
void print_enemy2(string enemy2[]);
void print_enemy3(string enemy3[]);
int main(){
    int i = 1, speed = 30;
    int score = 0,damage = 1;
    string player_health = "@@@@@@@@@@", enemy1_health = "@@@@", enemy2_health = "@@@@", enemy3_health = "@@@@";
    char light = 220,block = 219,pistol0 = 200;
    string pistol = {pistol0};
    string car[9];
    car[0] = {' ',' ',' ','_',light,'_','_','_',light,'_',' ',' ',' '};
    car[1] = "  /_______\\  ";
    car[2] = " /         \\ ";
    car[3] = "[|  \\   /  |]";
    car[4] = " |   \\_/   | ";
    car[5] = pistol+"|  | | |  | ";
    car[6] = " |  | | |  | ";
    car[7] = "[|___/_\\___|]";
    car[8] = " |_________| ";
    string enemy1[9];
    enemy1[0] = {' ',' ',' ','_',light,'_','_','_',light,'_',' ',' ',' '};
    enemy1[1] = "  /_______\\  ";
    enemy1[2] = " /         \\ ";
    enemy1[3] = "[|  |   |  |]";
    enemy1[4] = " |   \\_/   | ";
    enemy1[5] = " |         | ";
    enemy1[6] = " |  /---\\  | ";
    enemy1[7] = "[|__|   |__|]";
    enemy1[8] = " \\_________/ ";
    string enemy2[9];
    enemy2[0] = {' ',' ',' ','_',light,'_','_','_',light,'_',' ',' ',' '};
    enemy2[1] = "  /_______\\  ";
    enemy2[2] = " /         \\ ";
    enemy2[3] = "[|  \\___/  |]";
    enemy2[4] = " |   |_|   | ";
    enemy2[5] = " |         | ";
    enemy2[6] = " |  /___\\  | ";
    enemy2[7] = "[|_/_____\\_|]";
    enemy2[8] = " \\_________/ ";  
    string enemy3[9];
    enemy3[0] = {' ',' ',' ','_',light,'_','_','_',light,'_',' ',' ',' '};
    enemy3[1] = "  /_______\\  ";
    enemy3[2] = " /         \\ ";
    enemy3[3] = "[| |     | |]";
    enemy3[4] = " | |_____| | ";
    enemy3[5] = " |         | ";
    enemy3[6] = " |  /---\\  | ";
    enemy3[7] = "[|_|     |_|]";
    enemy3[8] = " \\_________/ ";
    system("cls");
    while(true){
        print_console();
        update_lines();
        Sleep(30);
        gotoxy(0,0);
    }
    return 0;
}



void update_lines(){
        char line = 219;
        console[ly][lax] = line;
        console[ly][lbx] = line;
        ly++;
        if(ly == 36)
            ly = 1;

        if(e_ly>0){
            console[e_ly][lax] = ' ';
            console[e_ly][lbx] = ' ';
        }
        e_ly++;
        if(e_ly == 36)
            e_ly = 1;
}

void print_console(){
    for (int i = 0; i < 37; i++)
    {
        cout<<console[i];
        cout<<endl;
    }
}
void gotoxy(int x, int y){

    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}