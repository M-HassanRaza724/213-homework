#include <iostream>
using namespace std;

void input(int arr[][5], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "Enter element at position [" << i << "] [" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}
void largest_column_first(int arr[][5], int row)
{
    int max = -1, sum = 0, previous_sum = sum;
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < row; i++)
        {
            sum += arr[i][j];
        }
        if (sum > previous_sum)
        {
            max = j;
        }
        previous_sum = sum;
        sum = 0;
    }
    for (int i = 0; i < row; i++)
    {
        int temp = arr[i][0];
        arr[i][0] = arr[i][max];
        arr[i][max] = temp;
    }
}
void output(int arr[][5], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;
    int matrix[rows][5];
    input(matrix, rows);
    cout << "\nOriginal Matrix: \n";
    output(matrix, rows);
    largest_column_first(matrix, rows);
    cout << "\nMatrix after largest column moved to first: \n";
    output(matrix, rows);

    return 0;
}