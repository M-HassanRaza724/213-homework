# include <iostream>
using namespace std;

bool doesBrickFit(int,int,int,int,int);

main(){
    int bh,bw,bd,hw,hh;
    bool answer;

    cout<<"Enter brick height: ";
    cin>>bh;
    cout<<"Enter brick width: ";
    cin>>bw;
    cout<<"Enter brick depth: ";
    cin>>bd;
    cout<<"Enter hole height: ";
    cin>>hh;
    cout<<"Enter hole width: ";
    cin>>hw;

    answer = doesBrickFit(bh,bw,bd,hh,hw);
    cout<<answer;

    return 0;
}

bool doesBrickFit(int bHeight,int bWidth,int bDepth,int hHeight,int hWidth){

    if((bHeight<=hHeight) && ((bDepth<=hWidth) || (bWidth<=hWidth)))
        return true;
    else
        return false;
}
