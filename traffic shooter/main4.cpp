#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;

int lax = 23, lbx = 46, ly = 1;
int e_lax = 23, e_lbx = 46, e_ly = 1;
int Px = 27, Py = 26;
int Ex[3] = {3, 29, 52};
int Ey[3] = {2, 2, 2};
int speed = 30;
int bulletX[200];
int bulletY[200];
bool isBulletActive[200];
int bulletCount = 0;
int totalBullets = 100;
int score = 0;
int h_score = 0;

int h_biscuitX[3];
int h_biscuitY[3];
bool h_biscuitActive[3];
int h_biscuitCount = 0;

int p_health = 100;
int e_health[3] = {40, 40, 40};
bool healthChange[4] = {true, true, true, true};
bool life[4] = {true, true, true, true};

int e_bulletX[20][3];
int e_bulletY[20][3];
bool is_e_BulletActive[20][3];
int e_bulletCount[3] = {0, 0, 0};

char light = 220, block = 219, pistol0 = 200, line = 219;
string pistol = {pistol0};
string car[9], enemy1[9], enemy2[9], enemy3[9];

void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void setColor(int color);
int checked_input(int,int,int,int);
void initialize_vehicles();
void intro();
void print_header();
void print_menu();
void print_road();
void print_statics();
void reset();
string getData(string fileName);
void printScoreStatics(int &choice);

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

void generate_p_Bullet();
void move_p_Bullet();
void print_p_Bullet(int x, int y);
void erase_p_Bullet(int x, int y);
void print_e_Bullet(int x, int y);
void erase_e_Bullet(int x, int y);
void make_p_BulletInactive(int index);
bool enemyBulletCollision();
int p_bulletTargetX(int index);
void p_bulletUpdater(int iteration);
void print_bullet_no();

void addScore(bool death[]);
void printScore();

void generate_e_Bullet(int enemy_idx);
void move_e_Bullet(int enemy_idx);
void make_e_BulletInactive(int index, int enemy_idx);
bool playerBulletCollision();

void generateBiscuit(int enemy_idx,int iteration);
void moveBiscuit();
void printBiscuit(int x, int y);
void eraseBiscuit(int x, int y);
bool playerBiscuitCollision();

void e_healthCal();
void p_healthCal();
void healthDisplay(int character, int x, int y);
void lifeCal();

main()
{
    int choice = -1, iteration;
    bool exit = false;
    intro();
    while (!exit)
    {   int end = 0;
        print_header();
        if (choice == -1)
        {
            print_menu();
            choice = checked_input(1, 4, 19, 15);
        }
        else if (choice == 1)
        {
            int runTime_choice = -1;
            iteration = 1;
            // end = 0;
            bool death[4] = {false, false, false, false};

            system("cls");
            initialize_vehicles();

            print_road();
            print_statics();

            print_enemy1();
            print_enemy2();
            print_enemy3();
            print_car();
            while (end < 100)
            {
                iteration++;
                if (iteration == 999)
                    iteration = 10;
                // if this reduce line lenght will reduce

                if (life[3])
                {

                    if (GetAsyncKeyState(VK_LEFT))
                        move_car_left();
                    if (GetAsyncKeyState(VK_RIGHT))
                        move_car_right();
                    if (GetAsyncKeyState(VK_UP))
                    {
                        move_car_up(iteration);
                        if ((speed > 10) && (iteration % 5 == 0))
                        {
                            speed--;
                        }
                    }
                    if (GetAsyncKeyState(VK_DOWN))
                    {
                        move_car_down(iteration);
                        if ((speed < 30) && (iteration % 5 == 0))
                        {
                            speed++;
                        }
                    }
                    else
                    {
                        if ((iteration % 100 == 0) && (speed < 30))
                            speed++;
                    }
                    if (GetAsyncKeyState(VK_SPACE))
                        generate_p_Bullet();
                    move_p_Bullet();
                }
                else
                {
                    if (!death[3])
                    {
                        death[3] = true;
                        erase_car();
                        Px = 0, Py = 0;
                    }
                }
                for (int i = 0; i < 3; i++)
                {
                    if (iteration % 2 == 0 && life[i])
                        generate_e_Bullet(i);
                    move_e_Bullet(i);
                }

                move_lines(iteration);
                // for (int i = 0; i < 3; i++)
                // {
                //     if(life[0] || life[1] || life[2]){
                //         if(life[0] && i == 0)
                //         move_enemy1(iteration);
                //         if(life[1] && i == 1)
                //         move_enemy2(iteration);
                //         if(life[2] && i == 2)
                //         move_enemy3(iteration);
                //     }
                //     else{

                //         if(!death[i]){
                //             death[i] = true;
                //             erase_enemy(i);
                //             generateBiscuit(i);
                //         }
                //     }
                // }

                if (life[0])
                    move_enemy1(iteration);
                else
                {
                    if (!death[0])
                    {
                        death[0] = true;
                        erase_enemy(0);
                        generateBiscuit(0,iteration);
                    }
                }
                if (life[1])
                    move_enemy2(iteration);
                else
                {
                    if (!death[1])
                    {
                        death[1] = true;
                        erase_enemy(1);
                        generateBiscuit(1,iteration);
                    }
                }
                if (life[2])
                    move_enemy3(iteration);
                else
                {
                    if (!death[2])
                    {
                        death[2] = true;
                        erase_enemy(2);
                        generateBiscuit(2,iteration);
                    }
                }
                if (!life[3] || (!life[0] && !life[1] && !life[2])){
                    // choice = -1;
                    gotoxy(0,41); cout<<"ending..."<<end;
                    end++;
                }
                if(GetAsyncKeyState(VK_ESCAPE)){
                    // print_runTimeMenu();
                    runTime_choice = checked_input(1,3,91,28);
                    if(runTime_choice == 2){
                        end = 100;
                    }
                    else if(runTime_choice == 3){
                        choice = -1;
                        end = 100;
                    }
                    runTime_choice = -1;
                }
                // generateBiscuit(-1,iteration);
                moveBiscuit();
                p_healthCal();
                e_healthCal();
                lifeCal();
                p_bulletUpdater(iteration);
                addScore(death);

                printScore();
                healthDisplay(0, 88, 8);
                healthDisplay(1, 88, 9);
                healthDisplay(2, 88, 10);
                healthDisplay(3, 80, 5);

                Sleep(speed);
            }
            system("cls");
            printScoreStatics(choice);

            if (p_health > 0 && e_health[0] == 0 && e_health[1] ==  0 && e_health[2] ==  0){
                cout << "You win!!!\nYour Score: "<<score;
                cout << "High Score: "<<h_score;
                choice = -1;
            }
            else if(p_health == 0 && (e_health[0] > 0 || e_health[1] >  0 || e_health[2] >  0)){
                cout << "You lose!!!\nYour Score: "<<score;
                cout << "High Score: "<<h_score;
                choice = -1;
            }
            reset();
            cin.ignore();
        }        
        else if (choice == 2)
        {
            choice = -1;
        }        
        else if (choice == 3)
        {
            cout<<getData("controls.txt")<<endl;
            choice = -1;
        }       
        if (choice == 4)
        {
            exit = true;
        }

        cout << "\n\n\n\n\nPress any key to continue...";
        getch();
        system("cls");
    }
    return 0;
}
// ---------------------User Defined Functions-----------------------------
void gotoxy(int x, int y)
{

    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printScoreStatics(int &choice){
    if(h_score<score) h_score = score;
    if (p_health > 0 && e_health[0] == 0 && e_health[1] ==  0 && e_health[2] ==  0){
        cout << "You win!!!\nYour Score: "<<score;
        cout << "High Score: "<<h_score;
        choice = -1;
    }
    else if(p_health == 0 && (e_health[0] > 0 || e_health[1] >  0 || e_health[2] >  0)){
        cout << "You lose!!!\nYour Score: "<<score;
        cout << "High Score: "<<h_score;
        choice = -1;
    }

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

void generate_p_Bullet()
{
    if (bulletCount < totalBullets)
    {
        bulletX[bulletCount] = Px;
        bulletY[bulletCount] = Py - 2;
        isBulletActive[bulletCount] = true;
        bulletCount++;
        gotoxy(Px, Py - 2);
        cout << '^';
        print_bullet_no();
    }
}

void move_p_Bullet()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if (isBulletActive[i])
        {
            char next = getCharAtxy(bulletX[i], bulletY[i] - 1);
            // gotoxy(0,38); cout << "Next char: " << next << " at (" << bulletX[i] << ", " << bulletY[i] - 1 << ")" << endl; // debug helper
            if (next != ' ')
            {
                // gotoxy(0,39); cout << "Bullet collision detected at (" << bulletX[i] << ", " << bulletY[i] - 1 << ") at char: "<<next << endl; ///debug helper
                erase_p_Bullet(bulletX[i], bulletY[i]);
                make_p_BulletInactive(i);
            }
            else
            {
                erase_p_Bullet(bulletX[i], bulletY[i]);
                bulletY[i]--;
                print_p_Bullet(bulletX[i], bulletY[i]);
            }
            // gotoxy(0,40); cout << "Bullet state of bullet count "<<bulletCount<<" is "<< isBulletActive[i] << endl; ///debug helper
        }
    }
}
void print_p_Bullet(int x, int y)
{
    gotoxy(x, y);
    cout << '*';
}
void erase_p_Bullet(int x, int y)
{
    gotoxy(x, y);
    cout << ' ';
}
void make_p_BulletInactive(int index)
{
    isBulletActive[index] = false;
}
bool enemyBulletCollision()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if (isBulletActive[i])
        {
            int targetXindex = p_bulletTargetX(i);
            if (targetXindex != -1 && bulletY[i] - 1 == Ey[targetXindex] + 8)
            {
                // gotoxy(0,41); cout<<"bullet collision detected at enemy: "<<targetXindex; //debug Helper
                return true;
            }
        }
    }
    return false;
}
int p_bulletTargetX(int index)
{
    for (int j = 0; j < 3; j++)
    {
        for (int i = Ex[j]; i < Ex[j] + 13; i++)
        {
            if (i == bulletX[index])
                return j;
        }
    }
    return -1;
}
void initialize_enemy_bullet(int enemy_idx, int x_increment, int y_increment)
{

    e_bulletCount[enemy_idx] = (e_bulletCount[enemy_idx] % 20);
    e_bulletX[e_bulletCount[enemy_idx]][enemy_idx] = Ex[enemy_idx] + x_increment;
    e_bulletY[e_bulletCount[enemy_idx]][enemy_idx] = Ey[enemy_idx] + y_increment;
    is_e_BulletActive[e_bulletCount[enemy_idx]][enemy_idx] = true;
    e_bulletCount[enemy_idx]++;
}
void generate_e_Bullet(int enemy_idx)
{
    if (enemy_idx == 0)
    {
        if (Ex[0] + 2 < Px && Px < Ex[0] + 14)
            initialize_enemy_bullet(0, 12, 8);
    }
    // else if(enemy_idx == 0  ){
    //     if(Ex[enemy_idx]+1 > Px && Px > Ex[enemy_idx]-10){
    //         initialize_enemy_bullet(enemy_idx,0,8);
    //     }

    // }
    else
    {
        if (Ex[enemy_idx] + 1 > Px && Px > Ex[enemy_idx] - 10)
        {
            initialize_enemy_bullet(enemy_idx, 0, 8);
        }
    }
}

void move_e_Bullet(int enemy_idx)
{
    for (int i = 0; i < 20; i++)
    {
        if (is_e_BulletActive[i][enemy_idx])
        {
            char next = getCharAtxy(e_bulletX[i][enemy_idx], e_bulletY[i][enemy_idx] + 1);
            // gotoxy(0,38); cout << "Next char: " << next << " at (" << e_bulletX[i] << ", " << e_bulletY[i]+1 << ")" << endl; // debug helper
            if (next != ' ')
            {
                // gotoxy(0,39); cout << "Bullet collision detected at (" << e_bulletX[i] << ", " << e_bulletY[i] << ") at char: "<<next << endl; ///debug helper
                erase_e_Bullet(e_bulletX[i][enemy_idx], e_bulletY[i][enemy_idx]);
                make_e_BulletInactive(i, enemy_idx);
            }
            else
            {
                erase_e_Bullet(e_bulletX[i][enemy_idx], e_bulletY[i][enemy_idx]);
                e_bulletY[i][enemy_idx]++;
                print_e_Bullet(e_bulletX[i][enemy_idx], e_bulletY[i][enemy_idx]);
            }
            // gotoxy(0,40); cout << "Bullet state of bullet count "<<e_bulletCount[0]<<" is "<< is_e_BulletActive[i][0] << endl; ///debug helper
            // gotoxy(0,41); cout << "Bullet state of bullet count "<<e_bulletCount[1]<<" is "<< is_e_BulletActive[i][1] << endl; ///debug helper
            // gotoxy(0,42); cout << "Bullet state of bullet count "<<e_bulletCount[2]<<" is "<< is_e_BulletActive[i][2] << endl; ///debug helper
        }
    }
}
void make_e_BulletInactive(int index, int enemy_idx)
{
    is_e_BulletActive[index][enemy_idx] = false;
}
void print_e_Bullet(int x, int y)
{
    gotoxy(x, y);
    cout << '*';
}
void erase_e_Bullet(int x, int y)
{
    gotoxy(x, y);
    cout << ' ';
}

bool playerBulletCollision()
{
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < e_bulletCount[j]; i++)
        {
            if (is_e_BulletActive[i][j])
            {
                if ((e_bulletX[i][j] > Px && e_bulletX[i][j] < Px + 13) && e_bulletY[i][j] == Py - 1)
                {
                    // gotoxy(0,43); cout<<"bullet collision detected by enemy "<<j+1<<" at("<<e_bulletX[i][j]<<","<<e_bulletY[i][j]<<")"<<endl; //debug Helper
                    return true;
                }
            }
        }
    }
    return false;
}
void p_healthCal()
{
    if (playerBulletCollision() && p_health > 0)
    {
        healthChange[3] = true;
        p_health--;
    }
    if (playerBiscuitCollision() && p_health < 100)
    {
        healthChange[3] = true;
        p_health += 10;
    }
}
void p_bulletUpdater(int iteration)
{
    if (totalBullets < 200)
    {

        if (((Px > Ex[0] + 2 && Px < Ex[0] + 4) || (Px > Ex[1] - 3 && Px < Ex[1]) || (Px > Ex[1] - 3 && Px < Ex[1])) && iteration % 10 == 0)
        {
            totalBullets++;
            print_bullet_no();
        }
        if (playerBiscuitCollision())
        {
            totalBullets += 15;
            print_bullet_no();
        }
    }
}
void print_bullet_no()
{
    setColor(0x05);
    gotoxy(81, 6);
    cout << "             ";
    gotoxy(81, 6);
    cout << totalBullets - bulletCount;
    setColor(0x07);
}

void e_healthCal()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if (isBulletActive[i])
        {
            int enemyHit = p_bulletTargetX(i);
            if (enemyHit != -1 && bulletY[i] - 1 == Ey[enemyHit] + 8 && e_health[enemyHit] > 0)
            {
                healthChange[enemyHit] = true;
                e_health[enemyHit]--;
            }
        }
    }
}
void lifeCal()
{
    for (int i = 0; i < 3; i++)
    {
        if (e_health[i] == 0)
            life[i] = false;
    }
    if (p_health == 0)
        life[3] = false;
}
void generateBiscuit(int enemy_idx,int iteration)
{
    if(enemy_idx != -1){
        h_biscuitActive[enemy_idx] = true;
        h_biscuitX[enemy_idx] = Ex[enemy_idx] + 4;
        h_biscuitY[enemy_idx] = Ey[enemy_idx] + 4;
    }
    // else{
    //     if((Px+Ex[0]-Ex[1]+Ex[2]+iteration)%50 == 0 && (Px+Ex[0]-Ex[1]-Ex[2]+iteration)%70 != 0 && (Px+Ex[0]-Ex[1]-Ex[2]+iteration)%70 != 1 && (Px+Ex[0]-Ex[1]-Ex[2]+iteration)%70 != Ex[0] && (Px+Ex[0]-Ex[1]-Ex[2]+iteration)%70 != Ex[1] && (Px+Ex[0]-Ex[1]-Ex[2]+iteration)%70 != Ex[2] && (Px+Ex[0]-Ex[1]-Ex[2]+iteration)%70 != Px){
    //         h_biscuitCount = (h_biscuitCount%10);
    //         if(h_biscuitCount == 0) h_biscuitCount = 3;
    //         h_biscuitX[h_biscuitCount] = (Px+Ex[0]-Ex[1]-Ex[2]+iteration)%70;
    //         h_biscuitY[h_biscuitCount] = 3;
    //         h_biscuitCount++;

    //     }
    // }
    printBiscuit(Ex[enemy_idx] + 4, Ey[enemy_idx] + 4);
}
void moveBiscuit()
{
    for (int i = 0; i < 10; i++)
    {
        if (h_biscuitActive[i])
        {
            if (h_biscuitY[i] > 34 || playerBiscuitCollision())
            {
                eraseBiscuit(h_biscuitX[i], h_biscuitY[i]);
                h_biscuitActive[i] = false;
            }
            else
            {
                eraseBiscuit(h_biscuitX[i], h_biscuitY[i]);
                h_biscuitY[i]++;
                printBiscuit(h_biscuitX[i], h_biscuitY[i]);
            }
            // gotoxy(0,39); cout <<"state Biscuit of enemy"<<i+1<<" is "<<h_biscuitActive[i]<< endl; //debug helper
        }
    }
}
void printBiscuit(int x, int y)
{
    gotoxy(x, y);
    cout << '@';
}
void eraseBiscuit(int x, int y)
{
    gotoxy(x, y);
    cout << ' ';
}
bool playerBiscuitCollision()
{
    for (int i = 0; i < 10; i++)
    {
        if (h_biscuitActive[i])
        {
            if ((h_biscuitX[i] >= Px && h_biscuitX[i] <= Px + 13) && (h_biscuitY[i] >= Py - 1 && h_biscuitY[i] <= Py + 7))
            {
                gotoxy(0, 42);
                cout << "Yohoooooooo!!!!!!!";
                return true;
            }
        }
    }
    return false;
}
void healthDisplay(int character, int x, int y)
{
    int health_hearts = 0;
    if (healthChange[character])
    {
        gotoxy(x, y);
        if (character == 3)
        {
            cout << "            ";
            gotoxy(x, y);
            if (p_health != 0)
                health_hearts = (p_health + 10) / 10;
            else
                health_hearts = 0;
        }
        else
        {
            cout << "     ";
            gotoxy(x, y);
            if (e_health[character] != 0)
                health_hearts = (e_health[character] + 10) / 10;
            else
                health_hearts = 0;
        }
        if ((health_hearts < 2 && character != 3) || (health_hearts < 4 && character == 3))
            setColor(0x04);
        else if ((health_hearts < 3 && character != 3) || (health_hearts < 5 && character == 3))
            setColor(0x06);
        else
            setColor(0x02);

        for (int i = 0; i < health_hearts; i++)
            cout << light;
        setColor(0x07);
        healthChange[character] = false;
        // gotoxy(88,11);  cout<<"Health of character "<<character<<" is changed "<<healthChange[character];    //debug helper
    }
}

void addScore(bool death[])
{
    if (enemyBulletCollision())
        score++;
    if(playerBulletCollision())
        score--;
    for (int i = 0; i < 3; i++)
    {
        if (!life[i] && !death[i])
            score += 10;
    }
}
void printScore()
{
    gotoxy(80, 4);
    cout << score;
}

void move_car_left()
{
    if ((getCharAtxy(Px - 1, Py) == ' ' && getCharAtxy(Px - 1, Py + 8) == ' ' && getCharAtxy(Px - 1, Py + 4) == ' ') || getCharAtxy(Px - 1, Py) == line || getCharAtxy(Px - 1, Py + 4) == line || getCharAtxy(Px - 1, Py + 8) == line)
    {
        erase_car();
        Px = Px - 1;
        if ((Px == 23 || Px == 46))
            Px--;
        print_car();
    }
}

void move_car_right()
{
    if ((getCharAtxy(Px + 14, Py) == ' ' && getCharAtxy(Px + 14, Py + 4) == ' ' && getCharAtxy(Px + 14, Py + 8) == ' ') || getCharAtxy(Px + 14, Py) == line || getCharAtxy(Px + 14, Py + 4) == line || getCharAtxy(Px + 14, Py + 8) == line)
    {
        erase_car();
        Px = Px + 1;
        if ((Px == 23 || Px == 46))
            Px++;
        print_car();
    }
}
void move_car_up(int i)
{
    if ((Py >= 25) && (i % 2 == 0))
    {
        erase_car();
        Py = Py - 1;
        print_car();
    }
}
void move_car_down(int i)
{
    if ((Py < 26) && (i % 2 == 0))
    {
        erase_car();
        Py = Py + 1;
        print_car();
    }
}

void move_enemy1(int i)
{ // vertical
    erase_enemy(0);
    if (life[2] || life[1])
    {

        if (getCharAtxy(Ex[0] + 4, Ey[0] + 10) == ' ')
        {
            if (i % 6 == 0)
            {
                if (Ey[0] < 11)
                    Ey[0]++;
            }
        }
    }
    else
    {
        if (getCharAtxy(Ex[0] + 3, Ey[1] - 1) == ' ' && i % 6 == 0)
        {
            if (Ey[0] > 2)
                Ey[0]--;
        }
        if (i % 2)
        {

            if (Px - 3 < Ex[0])
            {
                if (getCharAtxy(Ex[0] - 1, Ey[0]) == ' ' && Ex[0] > 1)
                    Ex[0]--;
            }
            else if (Px - 3 > Ex[0])
            {
                if (getCharAtxy(Ex[0] + 15, Ey[0]) == ' ' && Ex[0] < 43)
                    Ex[0]++;
            }
        }
    }
    print_enemy1();
}

void move_enemy2(int i)
{ // diagonal
    erase_enemy(1);
    if (life[2])
    {
        if (getCharAtxy(Ex[1] + 3, Ey[1] + 9) == ' ' && i % 6 == 0)
        {
            if (Ey[1] < 13)
                Ey[1]++;
        }
        if (getCharAtxy(Ex[1] + 18, Ey[1] - 1) == ' ' && getCharAtxy(Ex[1] + 17, Ey[1] - 1) == ' ')
        {
            if ((Ex[1] < 52) && (i % 6 == 0))
                Ex[1]++;
        }
    }
    else
    {
        if (getCharAtxy(Ex[1] + 3, Ey[1] - 1) == ' ' && i % 6 == 0)
        {
            if (Ey[1] > 2)
                Ey[1]--;
        }
        if (i % 3)
        {

            if (Px + 3 < Ex[1])
            {
                if (getCharAtxy(Ex[1] - 1, Ey[1]) == ' ' && Ex[1] > 20)
                    Ex[1]--;
            }
            else if (Px + 1 > Ex[1])
            {
                if (getCharAtxy(Ex[1] + 15, Ey[1]) == ' ' && Ex[1] < 65)
                    Ex[1]++;
            }
        }
    }
    print_enemy2();
}

void move_enemy3(int i)
{ // horizontal
    erase_enemy(2);
    if (i % 4 == 0)
    {
        if (Px + 3 < Ex[2])
        {

            if (getCharAtxy(Ex[2] - 2, Ey[2] + 8) == ' ' && Ex[2] > 20)
                Ex[2]--;
        }
        else if (Px + 1 > Ex[2])
        {
            if (getCharAtxy(Ex[2] + 15, Ey[2]) == ' ' && Ex[2] < 43)
                Ex[2]++;
        }
    }
    print_enemy3();
}

void print_lines()
{
    gotoxy(lax, ly);
    cout << line;
    gotoxy(lbx, ly);
    cout << line;
    ly++;
    if (ly == 36)
        ly = 1;
}

void erase_lines()
{

    gotoxy(e_lax, e_ly);
    cout << " ";
    gotoxy(e_lbx, e_ly);
    cout << " ";
    e_ly++;
    if (e_ly == 36)
        e_ly = 1;
}

void move_lines(int erase_permit)
{

    print_lines();
    if (erase_permit > 9) // decides the lenght of lines
        erase_lines();
}

void print_car()
{

    gotoxy(Px, Py);
    cout << car[0];
    gotoxy(Px, Py + 1);
    cout << car[1];
    gotoxy(Px, Py + 2);
    cout << car[2];
    gotoxy(Px, Py + 3);
    cout << car[3];
    gotoxy(Px, Py + 4);
    cout << car[4];
    gotoxy(Px, Py + 5);
    cout << car[5];
    gotoxy(Px, Py + 6);
    cout << car[6];
    gotoxy(Px, Py + 7);
    cout << car[7];
    gotoxy(Px, Py + 8);
    cout << car[8];
}
void erase_car()
{
    string space = "              ";
    for (int i = 0; i < 9; i++)
    {
        gotoxy(Px, Py + i);
        cout << space;
    }
}

void print_enemy1()
{
    setColor(0x03);
    gotoxy(Ex[0], Ey[0]);
    cout << enemy1[0];
    gotoxy(Ex[0], Ey[0] + 1);
    cout << enemy1[1];
    gotoxy(Ex[0], Ey[0] + 2);
    cout << enemy1[2];
    gotoxy(Ex[0], Ey[0] + 3);
    cout << enemy1[3];
    gotoxy(Ex[0], Ey[0] + 4);
    cout << enemy1[4];
    gotoxy(Ex[0], Ey[0] + 5);
    cout << enemy1[5];
    gotoxy(Ex[0], Ey[0] + 6);
    cout << enemy1[6];
    gotoxy(Ex[0], Ey[0] + 7);
    cout << enemy1[7];
    gotoxy(Ex[0], Ey[0] + 8);
    cout << enemy1[8];
    setColor(0x07);
}
void print_enemy2()
{
    setColor(0x02);
    gotoxy(Ex[1], Ey[1]);
    cout << enemy2[0];
    gotoxy(Ex[1], Ey[1] + 1);
    cout << enemy2[1];
    gotoxy(Ex[1], Ey[1] + 2);
    cout << enemy2[2];
    gotoxy(Ex[1], Ey[1] + 3);
    cout << enemy2[3];
    gotoxy(Ex[1], Ey[1] + 4);
    cout << enemy2[4];
    gotoxy(Ex[1], Ey[1] + 5);
    cout << enemy2[5];
    gotoxy(Ex[1], Ey[1] + 6);
    cout << enemy2[6];
    gotoxy(Ex[1], Ey[1] + 7);
    cout << enemy2[7];
    gotoxy(Ex[1], Ey[1] + 8);
    cout << enemy2[8];
    setColor(0x07);
}
void print_enemy3()
{
    setColor(0x0C);
    gotoxy(Ex[2], Ey[2]);
    cout << enemy3[0];
    gotoxy(Ex[2], Ey[2] + 1);
    cout << enemy3[1];
    gotoxy(Ex[2], Ey[2] + 2);
    cout << enemy3[2];
    gotoxy(Ex[2], Ey[2] + 3);
    cout << enemy3[3];
    gotoxy(Ex[2], Ey[2] + 4);
    cout << enemy3[4];
    gotoxy(Ex[2], Ey[2] + 5);
    cout << enemy3[5];
    gotoxy(Ex[2], Ey[2] + 6);
    cout << enemy3[6];
    gotoxy(Ex[2], Ey[2] + 7);
    cout << enemy3[7];
    gotoxy(Ex[2], Ey[2] + 8);
    cout << enemy3[8];
    setColor(0x07);
}

void erase_enemy(int n)
{
    string space = "             ";
    for (int i = 0; i < 9; i++)
    {
        gotoxy(Ex[n], Ey[n] + i);
        cout << space;
    }
}
void reset(){

lax = 23, lbx = 46, ly = 1;
e_lax = 23, e_lbx = 46, e_ly = 1;
Px = 27, Py = 26;
Ex[0] = 3;
Ex[1] = 29;
Ex[2] = 52;
for (int i = 0; i < 3; i++){
    Ey[i] = 2;
    h_biscuitActive[i] = false;
    e_health[i] = 40;
    e_bulletCount[i] = 0;
    for (int j = 0; j < 20; j++)
        is_e_BulletActive[j][i];
}
speed = 30;
for (int i = 0; i < 200; i++)
    isBulletActive[i] = false;

bulletCount = 0;
totalBullets = 100;
score = 0;
p_health = 100;

for (int i = 0; i < 4; i++)
{
    healthChange[i] = true;
    life[i] = true;
}


}
// int getData(string hfile)
// {
//     int data;
//     fstream hs_file;
//     hs_file.open(hfile,ios::in);
//     hs_file>>data;
//     hs_file.close();
//     return data;
// }   
string getData(string fileName)
{
    string l_data = "",data = "";
    fstream file;
    file.open(fileName,ios::in);
    while(getline(file,l_data))
        data += l_data+"\n";
    file.close();
    return data;
}   

int checked_input(int interval_start, int interval_end, int x, int y)
{
    int var;
    gotoxy(x, y);
    cin >> var;
    while ((var < interval_start) || (var > interval_end))
    {
        gotoxy(1, y + 1);
        cout << "Wrong input...";
        gotoxy(x, y);
        cin >> var;
    }
    gotoxy(1, y + 1);
    cout << "              ";
    gotoxy(0, y + 1);
    return var;
}
void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void initialize_vehicles()
{

    car[0] = {' ', ' ', ' ', '_', light, '_', '_', '_', light, '_', ' ', ' ', ' '};
    car[1] = "  /_______\\  ";
    car[2] = " /         \\ ";
    car[3] = "[|  \\   /  |]";
    car[4] = " |   \\_/   | ";
    car[5] = pistol + "|  | | |  | ";
    car[6] = " |  | | |  | ";
    car[7] = "[|___/_\\___|]";
    car[8] = " |_________| ";

    enemy1[0] = {' ', ' ', ' ', '_', light, '_', '_', '_', light, '_', ' ', ' ', ' '};
    enemy1[1] = "  /_______\\  ";
    enemy1[2] = " /         \\ ";
    enemy1[3] = "[|  |   |  |]";
    enemy1[4] = " |   \\_/   | ";
    enemy1[5] = " |         | ";
    enemy1[6] = " |  /---\\  | ";
    enemy1[7] = "[|__|   |__|]";
    enemy1[8] = " \\_________/ ";

    enemy2[0] = {' ', ' ', ' ', '_', light, '_', '_', '_', light, '_', ' ', ' ', ' '};
    enemy2[1] = "  /_______\\  ";
    enemy2[2] = " /         \\ ";
    enemy2[3] = "[|  \\___/  |]";
    enemy2[4] = " |   |_|   | ";
    enemy2[5] = " |         | ";
    enemy2[6] = " |  /___\\  | ";
    enemy2[7] = "[|_/_____\\_|]";
    enemy2[8] = " \\_________/ ";

    enemy3[0] = {' ', ' ', ' ', '_', light, '_', '_', '_', light, '_', ' ', ' ', ' '};
    enemy3[1] = "  /_______\\  ";
    enemy3[2] = " /         \\ ";
    enemy3[3] = "[| |     | |]";
    enemy3[4] = " | |_____| | ";
    enemy3[5] = " |         | ";
    enemy3[6] = " |  /---\\  | ";
    enemy3[7] = "[|_|     |_|]";
    enemy3[8] = " \\_________/ ";
}
void print_header()
{

    system("cls");
    cout << "____________________________________________________________________________________________________________________________________________\n";
    cout << "|                                                                                                                                          |\n";
    cout << "| ######  ######     #####    #######  #######  ######    #####          #####   ###   ##    #####     #####   ######  #######   ######    |\n";
    cout << "|   ##     ##  ##   ##   ##    ##  ##   ##  ##    ##     ##   ##        ##   ##   ##   ##   ##   ##   ##   ##    ##     ##  ##    ##  ##   |\n";
    cout << "|   ##     ##  ##   ##   ##    ##       ##        ##     ##             ##        ##   ##   ##   ##   ##   ##    ##     ##        ##  ##   |\n";
    cout << "|   ##     #####    #######    ####     ####      ##     ##              #####    #######   ##   ##   ##   ##    ##     ####      #####    |\n";
    cout << "|   ##     ###      ##   ##    ##       ##        ##     ##                  ##   ##   ##   ##   ##   ##   ##    ##     ##        ###      |\n";
    cout << "|   ##     ## ##    ##   ##    ##       ##        ##     ##   ##        ##   ##   ##   ##   ##   ##   ##   ##    ##     ##  ##    ## ##    |\n";
    cout << "|   ##     ##  ###  ##   ##   ####     ####     ######    #####          #####    ##   ###   #####     #####     ##    #######    ##  ###  |\n";
    cout << "|__________________________________________________________________________________________________________________________________________|\n";
}
void print_road()
{
    setColor(0x09);
    gotoxy(0, 0);
    cout << "##############################################################################################" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |-----------------------|" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |-----------------------|" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "|                                                                    |                       |" << endl;
    cout << "##############################################################################################" << endl;
    setColor(0x07);
    // (64+24)x37
}
void print_statics()
{
    int x = 72;
    setColor(0x05);
    gotoxy(x, 2);
    cout << "    --STATICS--    ";
    gotoxy(x, 4);
    cout << "SCORE :            ";
    gotoxy(x, 5);
    cout << "HEALTH :           ";
    gotoxy(x, 6);
    cout << "Bullets:            ";
    gotoxy(x, 8);
    cout << "ENEMY 1 health:    ";
    gotoxy(x, 9);
    cout << "ENEMY 2 health:    ";
    gotoxy(x, 10);
    cout << "ENEMY 3 health:    ";
    gotoxy(x, 22);
    cout << "     --MENU--      ";
    gotoxy(x, 24);
    cout << "Press Esc to access   ";
    gotoxy(x, 25);
    cout << "1. Resume";
    gotoxy(x, 26);
    cout << "2. Restart";
    gotoxy(x, 27);
    cout << "3.  MainMenu";
    gotoxy(x, 28);
    cout << "Enter your choice: ";

    setColor(0x07);
    // (64+24)x37
}

void print_menu()
{
    cout << "    --MENU--\n";
    cout << "01 Start.\n";
    cout << "02 High score.\n";
    cout << "03 Controls.\n";
    cout << "04 Exit.\n";
    cout << "Enter your choice: ";
}
void intro()
{
    cout << "                                                   ###   ##   ##   ##   #####                                               \n";
    Sleep(40);
    cout << "                                                    ##   ##   ##   ##  ##   ##                                              \n";
    Sleep(40);
    cout << "                                                    ##   ##    ## ##   ##   ##                                              \n";
    Sleep(40);
    cout << "                                                    #######     ###    #######                                              \n";
    Sleep(40);
    cout << "         _____________________________              ##   ##    ## ##   ##   ##                                              \n";
    Sleep(40);
    cout << "        /                             \\             ##   ##   ##   ##  ##   ##                                              \n";
    Sleep(40);
    cout << "       |                               |            ##   ###  ##   ##  ##   ##                                              \n";
    Sleep(40);
    cout << "       |                               |                                                                                    \n";
    Sleep(40);
    cout << "       |                               |                                                                                    \n";
    Sleep(40);
    cout << "       |                               |            #####     #####   #######  ######  ##    ##    #####   ######    #######\n";
    Sleep(40);
    cout << "       |                               |           ##   ##   ##   ##   ##  ##    ##    ##    ##   ##   ##   ##  ##    ##  ##\n";
    Sleep(40);
    cout << "       |                               |           ##        ##   ##   ##        ##    ##    ##   ##   ##   ##  ##    ##    \n";
    Sleep(40);
    cout << "       |                               |            #####    ##   ##   ####      ##    ## ## ##   #######   #####     ####  \n";
    Sleep(40);
    cout << "       |                               |                ##   ##   ##   ##        ##    ########   ##   ##   ###       ##    \n";
    Sleep(40);
    cout << "       |_______________________________|           ##   ##   ##   ##   ##        ##    ###  ###   ##   ##   ## ##     ##  ##\n";
    Sleep(40);
    cout << "       /                               \\            #####     #####   ####       ##    ##    ##   ##   ##   ##  ###  #######\n";
    Sleep(40);
    cout << "      /                                 \\                                                                                   \n";
    Sleep(40);
    cout << "     /                                   \\                                                                                  \n";
    Sleep(40);
    cout << "    /                                     \\        ##        #####   ######                                                 \n";
    Sleep(40);
    cout << "   /                                       \\       ##       ##   ##   ##  ##                                                \n";
    Sleep(40);
    cout << "   \\_______________________________________/       ##       ##   ##   ##  ##                                                \n";
    Sleep(40);
    cout << "                                                   ##       #######   #####                                                 \n";
    Sleep(40);
    cout << "                                                   ##       ##   ##   ##  ##                                                \n";
    Sleep(40);
    cout << "                                                   ##       ##   ##   ##  ##                                                \n";
    Sleep(40);
    cout << "                                                   #######  ##   ##  ######                                                 " << endl;
    Sleep(1000);
}