# include <iostream>
# include <windows.h>
using namespace std;

void print_maze()
{
    cout<<"#######################"<<endl;
    cout<<"#                     #"<< endl;
    cout<<"#                     #"<< endl;
    cout<<"#                     #"<< endl;
    cout<<"#                     #"<< endl;
    cout<<"#                     #"<< endl;
    cout<<"#                     #"<< endl;
    cout<<"#                     #"<< endl;
    cout<<"#######################"<<endl;
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}


void V_up_movement(int x,int y)
{
    gotoxy(x,y);
    cout<<"P";
    Sleep(200);
    gotoxy(x,y);
    cout<<" ";
    y--;
}

void V_down_movement(int x,int y)
{
    gotoxy(x,y);
    cout<<"P";
    Sleep(200);
    gotoxy(x,y);
    cout<<" ";
    y++;
}

int main()
{
    system("cls");
    int x=3,y=4;
    print_maze();
    while(y<8)
    {
        if (y == 0)
        {
            y++;
        }

        V_down_movement(x,y);
        y++;
        
        if(y == 8)
        {
            y=7;
            
            while(y>0)
            {
                V_up_movement(x,y);
                y--;
            }
        }
    }
    gotoxy(0,10);
    return 0;
}

