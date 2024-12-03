# include <iostream>
using namespace std;

int calculateDamage(string myType, string opponentType, int attack, int defense);

main(){
    
    string myType,opponentType;
    int attack, defense, damage;

    cout<<"Enter your type: ";
    cin>>myType;
    cout<<"Enter opponent type: ";
    cin>>opponentType;
    cout<<"Enter you attack power: ";
    cin>>attack;
    cout<<"Enter opponent defense: ";
    cin>>defense;

    damage = calculateDamage(myType, opponentType, attack, defense);
    cout<<damage;
    return 0;
}

int calculateDamage(string myType, string opponentType, int attack, int defense){

    float effect=0;
    int damage=0;
    if(((myType=="water")&&(opponentType=="fire")) || ((myType=="fire")&&(opponentType=="grass")) || (((myType=="grass")||(myType=="electricity"))&&(opponentType=="water")))
        effect = 2;
    else if((myType==opponentType)||(((myType=="grass")||(myType=="fire"))&&(opponentType=="electricity")))
        effect = 1;
    else
        effect = 0.5;
    
    damage = 50*(attack*effect)/defense;
    return damage;

}