#include <iostream>
using namespace std;

int main(){
    int count;
    long int number;
    while(number != 0){
        number = number/10;
        count++;
    }
    
    return 0;
}