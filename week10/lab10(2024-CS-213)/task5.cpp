# include <iostream>
using namespace std;
void input(int str[],int size){
    cout<<"Enter array Elements one by one: \n";
    for (int i = 0; i < size; i++){
        cin>>str[i];
    }
}
int total_volume(int arr[],int size){
    int t_volume = 0;
    for (int i = 0; i < size; i = i+3)
    {
        t_volume += (arr[i]*arr[i+1]*arr[i+2]);
    }
    // t_volume += (1*1*1);
    return t_volume;
}

main(){
    int box_no,volume,size;
    cout<<"Enter total number of boxes: ";
    cin>>box_no;
    size = box_no*3;
    int boxes[size];
    input(boxes,size);
    volume = total_volume(boxes,size);
    cout<<"Total Volume: "<<volume;
    return 0;
}