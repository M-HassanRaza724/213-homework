# include <iostream>
using namespace std;

string decideActivity(string, string);

int main(int argc, char const *argv[])
{
    string temp,humid,result;

    cout<<"Enter tempurature (Warm or cold): ";
    cin>>temp;
    cout<<"enter humidity (dry or humid): ";
    cin>>humid;

    result = decideActivity(temp, humid);
    cout<<result;
    
    return 0;
}

string decideActivity(string temp, string humid){

    if (temp == "warm"){
        if(humid == "dry")
            return "Play tennis";
        return "Swim";
    }else{
        if(humid == "dry")
            return "Play basketball";
        return "Watch tv";
    }
}
