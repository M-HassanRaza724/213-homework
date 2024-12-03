#include <iostream>
using namespace std;
int no;
int g_arr[100];
void input()
{
    cout << "Enter array Elements one by one: \n";
    for (int i = 0; i < no; i++)
        cin >> g_arr[i];
}
bool isRepeatingCycle(int cycle_len)
{
    for (int i = 0; i < no-cycle_len; i++)
    {
        if (g_arr[i] != g_arr[i + cycle_len])
            return false;
    }
    return true;
}

main()
{
    int lenght;
    bool answer;
    cout << "Enter array lenght: ";
    cin >> no;
    input(); 
    cout << "Enter cycle lenght: ";
    cin >> lenght;
    answer = isRepeatingCycle (lenght);
    cout << answer;
    return 0;
}