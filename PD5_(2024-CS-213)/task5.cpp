# include <iostream>
# include <windows.h>
# include <conio.h>
using namespace std;

string  email = "", password = "";

void intro();
void print_header();
void login_entry();
void login_page();
int order_entry();
string order_details(int);


main(){

    string order_detail = "";
    int order_type = 0;

    intro();
    system("cls");

    while(true){
        Sleep(100);
        print_header();
        if(email == ""){
        login_page();
        }
        if(email != ""){
        order_type = order_entry();
        }
        if(order_type != 0){
            order_detail = order_details(order_type);
        }
        if(order_detail != ""){
            cout<<"Thanks for your order.\n";
            cout<<"We will try to complete your order as soon as possible.";
            break;
        }
        cout<<"PRess any key to continue: ";
        getch();
        system("cls");
    }
    return 0;
}

void intro(){
    cout<<"                                                   ###   ##   ##   ##   #####                                               \n";
    Sleep(80);
    cout<<"                                                    ##   ##   ##   ##  ##   ##                                              \n";
    Sleep(80);
    cout<<"                                                    ##   ##    ## ##   ##   ##                                              \n";
    Sleep(80);
    cout<<"                                                    #######     ###    #######                                              \n";
    Sleep(100);
    cout<<"         _____________________________              ##   ##    ## ##   ##   ##                                              \n";
    Sleep(80);
    cout<<"        /                             \\             ##   ##   ##   ##  ##   ##                                              \n";
    Sleep(80);
    cout<<"       |                               |            ##   ###  ##   ##  ##   ##                                              \n";
    Sleep(80);
    cout<<"       |                               |                                                                                    \n";
    Sleep(80);
    cout<<"       |                               |                                                                                    \n";
    Sleep(80);
    cout<<"       |                               |            #####     #####   #######  ######  ##    ##    #####   ######    #######\n";
    Sleep(80);
    cout<<"       |                               |           ##   ##   ##   ##   ##  ##    ##    ##    ##   ##   ##   ##  ##    ##  ##\n";
    Sleep(80);
    cout<<"       |                               |           ##        ##   ##   ##        ##    ##    ##   ##   ##   ##  ##    ##    \n";
    Sleep(80);
    cout<<"       |                               |            #####    ##   ##   ####      ##    ## ## ##   #######   #####     ####  \n";
    Sleep(80);
    cout<<"       |                               |                ##   ##   ##   ##        ##    ########   ##   ##   ###       ##    \n";
    Sleep(80);
    cout<<"       |_______________________________|           ##   ##   ##   ##   ##        ##    ###  ###   ##   ##   ## ##     ##  ##\n";
    Sleep(80);
    cout<<"       /                               \\            #####     #####   ####       ##    ##    ##   ##   ##   ##  ###  #######\n";
    Sleep(80);
    cout<<"      /                                 \\                                                                                   \n";
    Sleep(80);
    cout<<"     /                                   \\                                                                                  \n";
    Sleep(80);
    cout<<"    /                                     \\        ##        #####   ######                                                 \n";
    Sleep(80);
    cout<<"   /                                       \\       ##       ##   ##   ##  ##                                                \n";
    Sleep(80);;
    cout<<"   \\_______________________________________/       ##       ##   ##   ##  ##                                                \n";
    Sleep(80);
    cout<<"                                                   ##       #######   #####                                                 \n";
    Sleep(80);
    cout<<"                                                   ##       ##   ##   ##  ##                                                \n";
    Sleep(80);
    cout<<"                                                   ##       ##   ##   ##  ##                                                \n";
    Sleep(80);
    cout<<"                                                   #######  ##   ##  ######                                                 "<<endl;
    Sleep(1000);
}

void print_header(){
    cout<<"                           __________                      "<<endl;
    cout<<"                          |          |                     "<<endl;
    cout<<"                          |__________|   HXA  SOFTWARE  LAB"<<endl;
    cout<<"                         /____________\\                    "<<endl;
}

void login_entry(){

    cout<<"Enter Email"<<endl;
    cin>>email;
    Sleep(300);
    cout<<"Enter password"<<endl;
    cin>>password;
}
void login_page(){
    Sleep(300);
    login_entry();
    Sleep(300);
    system("cls");
    cout<<"Hello "<<email<<endl;
}
int order_entry(){

    int order_type = 0;
    cout<<"Please enter your choice or 0 to exit:-\n";
    cout<<"1. Website.\n";
    cout<<"2. Game.\n";
    cout<<"3. Application."<<endl;
    cin>>order_type;
    if(order_type == 0){
        cout<<"exiting the program";
        system("exit");
    }
    return order_type;
}

string order_details(int order_type){

    string order_details = ""; 
    cout<<"Enter some details like name and other features of your "<<order_type<<":"<<endl;
    cin>>order_details;
    return order_details;
}