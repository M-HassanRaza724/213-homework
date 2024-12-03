#include <iostream>
using namespace std;

    char objects[6][5] = { 
    {'-', '-', '-', '-', '-'},
    {'-', '#', '#', '-', '#'}, 
    {'#', '-', '-', '#', '-'}, 
    {'-', '#', '-', '-', '-'}, 
    {'#', '-', '#', '-', '#'}, 
    {'#', '-', '-', '-', '-'} 
    };
bool gravity = false;

void displayWorld(){
        
    for (int i = 1; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << objects[i][j] << "\t";
        }
        cout << endl << endl;
    }
        cout << endl << endl<< endl;

}
bool setGravityStatus(bool status){
    gravity = status;
} 
void timeTick(int no){
    int count = 0;
    while(gravity && no>count){
        for(int i = 5;i >= 0;i--){
            for(int j = 0;j < 5;j++){
                if((objects[(i+1)%6][j] != '#') && (objects[i][j] == '#')){
                    objects[(i+1)%6][j] = '#';
                    objects[i][j] = '-';
                }
            }
        }
        count++;
    }
} 
int main(){
    displayWorld(); 
    setGravityStatus(true); 
    timeTick(2); 
    displayWorld(); 
    return 0;
}
