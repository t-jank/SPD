#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //! chcemy zeby suma wybranych elementow tablicy P byla rowna 8368
    //! cel programu: znalezc indeksy tych elementow

    int P[] = {831, 867, 814, 915, 947, 997, 826, 966, 946, 871, 894, 989, 910, 851, 852, 931, 863, 822, 982, 926, 993, 945, 978};
    int n = sizeof(P) / sizeof(P[0]);
    int sum=0, order[n], x;
    bool win = false;

    srand( time( NULL ) ); // konfiguracja generatora liczb losowych


    for(int j = 0; j < 1961256; j++)
    {
        int *temp = new int[9];
        for(int i=0; i<9; i++){
            temp[i] = -i-1;
        }

        for(int i=0; i<9; i++) // losowanie niepowtarzalnych indeksow 0-23 (losowanie 10 elementow tablicy P)
        {
            while((find(temp, temp + 9, x) != temp + 9) == true)
                x = rand() % 23;

            temp[i] = x;
        }

        for(int i=0; i<9; i++) // policzenie sumy wylosowanych 10 elementow
        {
            sum = sum + P[temp[i]];
        }

        if(sum > 8367 && sum < 8369)
        {
            if(8368 == sum){
                win = true;
                cout << "Sukces!!\n";
            }
            cout << sum << "\nKolejnosc: ";
            for(int i=0; i<9; i++)
            {
                cout << temp[i]+1 << " ";
            }
            cout << "\nWartosci: ";
            for(int i=0; i<9; i++)
            {
                cout << P[temp[i]] << " ";
            }
                break;
        }

        sum = 0;
        delete [] temp;
    }

    if(win == false) cout << ":( Try again.\n";



    return 0;
}
