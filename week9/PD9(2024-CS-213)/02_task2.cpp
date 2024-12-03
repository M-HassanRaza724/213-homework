# include <iostream>
using namespace std;

int finalPrice(string movies[5], string movie, int price);

main(){
    string movies[5] = {"Gladiator", "StarWars", "Terminator", "TakingLives", "TombRider"}, movie;
    int price = 500, final_price;

    cout<<"Enter movie name: ";
    cin>>movie;
    final_price = finalPrice(movies, movie, price);
    cout<<final_price;

    return 0;
}

int finalPrice(string movies[5], string movie, int price){
    for (int i = 0; i < 5; i++)
    {
        if ((movies[i] == movie) && (i%2==1))
        {
            return (price-(price/20));
        }else{
            return (price-(price/10));
        }
        
    }
    
}
