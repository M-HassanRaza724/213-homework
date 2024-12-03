#include <iostream>
using namespace std;

void jazzifyChords(string chords[], int numChords);

main()
{
    int n;
    cout << "Enter total number of chords: ";
    cin >> n;
    string chords[n];

    cout << "Enter " << n << " chords , one per line: ";
    for (int i = 0; i < n; i++)
    {
        cin >> chords[i];
    }

    jazzifyChords(chords, n);

    return 0;
}

void jazzifyChords(string chords[], int numChords)
{

    string chord;
    int j;
    cout << "Jazzified chords: [";
    for (int i = 0; i < numChords; i++)
    {
        chord = chords[i];
        j = 0;
        while (chord[j] != '\0')
        {
            j++;
        }
        if (chord[j - 1] != '7')
        {
            chords[i] = chords[i] + "7";
        }

        cout << chords[i];
        if (i >= 0 && i < numChords - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
}
