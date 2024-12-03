#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int lax = 23, lbx = 46, ly = 1, e_ly = -9;
int Px = 27, Py = 26;
int Ex[3] = {3, 29, 52};
int Ey[3] = {2, 2, 2};

const int rows = 37;
const int cols = 95;

char console[rows][cols] = {
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
};

// Buffer to track changes
char renderBuffer[rows][cols];

void update_lines();
void renderBoard();

int main() {
    // Initialize render buffer with a blank state
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            renderBuffer[i][j] = ' ';
        }
    }

    system("cls");
    while (true) {
        update_lines();
        renderBoard();
        Sleep(30);
    }
    return 0;
}
void print_enemy1(string enemy1[]){

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
void print_enemy2(string enemy2[]){
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
void print_enemy3(string enemy3[]){
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
        gotoxy(Px,Py+i);
        cout<<space;
    }
}
void update_lines() {
    char line = 219;
    console[ly][lax] = line;
    console[ly][lbx] = line;
    ly++;
    if (ly == 36)
        ly = 1;

    if (e_ly > 0) {
        console[e_ly][lax] = ' ';
        console[e_ly][lbx] = ' ';
    }
    e_ly++;
    if (e_ly == 36)
        e_ly = 1;
}

// Efficiently render the board by only updating changed cells
void renderBoard() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (console[i][j] != renderBuffer[i][j]) {
                // Only print changed cells
                COORD coord = {(SHORT)j, (SHORT)i};
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                cout << console[i][j];
                renderBuffer[i][j] = console[i][j]; // Update the render buffer
            }
        }
    }
}
