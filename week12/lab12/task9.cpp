#include <iostream>
using namespace std;

void input(int arr[][3], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter element at position [" << i << "] [" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}
int countIdenticalArrays(int arr[][3], int rows){
    int identical_rows = 0;
    for (int i = 0; i < rows; i++)
    {
        int identical_rows0 = 1;
        for (int j = 0; j < rows; j++)
        {
            if(j != i){
                if((arr[i][0] == arr[j][0]) && (arr[i][1] == arr[j][1]) && (arr[i][2] == arr[j][2])){
                    identical_rows0++;
                }
            }
        }
        if(identical_rows<identical_rows0){
            identical_rows = identical_rows0;
        }
    }
    if(identical_rows == 1)
        return 0;
    else
        return identical_rows;
}

int main(){
    
    int rows,identical_rows = 0;
    cout << "Enter number of rows: ";
    cin >> rows;
    int matrix[rows][3];
    input(matrix, rows);
    identical_rows = countIdenticalArrays(matrix,rows);

    cout<<"The count identical rows in the arrays is: "<<identical_rows<<endl;
    return 0;
}
