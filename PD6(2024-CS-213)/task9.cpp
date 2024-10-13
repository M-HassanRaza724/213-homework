# include <iostream>
using namespace std;

string checkPointPosition(int h, int x, int y);

int main(int argc, char const *argv[])
{
    int h, x, y;
    string answer;
    cout<<"Enter height: ";
    cin>>h;
    cout<<"Enter x coordinates: ";
    cin>>x;
    cout<<"Enter y coordinates: ";
    cin>>y;

    answer = checkPointPosition( h,  x,  y);
    cout<<answer;

    return 0;
}


string checkPointPosition(int h, int x, int y){

    if(((x>=0 && x<=h*3) && (y>=0 && y<=h)) || ((x>=h && x<=h*2) && (y>=h && y<=h*4))){
        if((x==0 && y==0) || (x==0 && y==h) || (x==h && y==h) || (x==h*2 && y==h) || (x==h*3 && y==0) || (x==h*3 && y==h) || (x==h && y==h*4) || (x==h*2 && y==h*4))
            return "Border";
        return "Inside";
    }else{
        return "Outside";
    }

}