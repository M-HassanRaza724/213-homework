#include <iostream>
#include <windows.h>
using namespace std;

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    setColor(0x8B); // Yellow text on Blue background
    cout << "This is Yellow text on Blue background!" << endl;

    setColor(0x09); // Bright White text on Black background
    cout << "This is Bright White text on Black background!" << endl;

    return 0;
}