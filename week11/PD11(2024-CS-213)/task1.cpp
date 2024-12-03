# include <iostream>
using namespace std;

main(){
    char box = 219;
    char tank1[6] = {box,box,box,'-','-','>'};
    char tank2[6] = {'0',' ','0',' ',' ',' '};
    for(int i = 0;i<6;i++){
        cout<<tank1[i];
    }
    cout<<endl;
    for(int i = 0;i<6;i++){
        cout<<tank2[i];
    }

    return 0;
}