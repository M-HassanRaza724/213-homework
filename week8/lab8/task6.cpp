# include <iostream>
using namespace std;

int pileCubes(long long volume);

main(){
    long long volume;
    int cubes;
    cout<<"Enter volume: ";
    cin>>volume;
    cubes = pileCubes(volume);
    cout<<cubes;

    return 0;
}

int pileCubes(long long volume){
    int i =0;
    long long number = 0;
    while (number<volume)
    {
        i++;
        number += static_cast<long long>(i)*i*i;
    }
    if(number == volume)
        return i;
    else
        return -1;
}
 