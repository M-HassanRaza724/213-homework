# include <iostream>
using namespace std;

int fruit_price_cal(string[4],  string);

main(){
    string fruit[4] = {"peach", "apple", "guava", "watermelon"}, type;
    int price[4] = {60, 70, 40, 30}, quantity, total_price,idx;

    cout<<"Enter fruit {peach, apple, guava, watermelon}: ";
    cin>>type;
    cout<<"Enter quantity in Kg: ";
    cin>>quantity;

    idx = fruit_price_cal(fruit,type);
    total_price = price[idx]*quantity;
    cout<<total_price;

    return 0;
}

int fruit_price_cal(string fruit[4], string type){
    for (int i = 0; i < 4; i++)
    {
        if (fruit[i] == type)
        {
            return i;
        }
        
    }
    
}
