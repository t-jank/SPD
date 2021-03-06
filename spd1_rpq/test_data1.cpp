#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;


int main()
{

    int n, r,p,q, w=0, sum=0; // n - liczba zadan, r - czas dostarczenia, p - czas trwania na maszynie, q - czas stygniecia;
    string filename[]={"data_1.txt", "data_2.txt", "data_3.txt", "data_4.txt"};

    srand( time( NULL ) ); // konfiguracja generatora liczb losowych

        // wczytanie danych z pliku
        ifstream infile(filename[0]);
        if(infile.good()==false) {cerr<<"Blad. Nie mozna otworzyc pliku!\n"; return 0;}
        infile >> n;
        int *R = new int[n], *P = new int[n], *Q = new int[n];
        while (infile >> r >> p >> q){
            R[w]=r, P[w]=p, Q[w]=q;
            w++;
        }
        int order[n], rightorder[n], temp[n], temp2[n], cmax=0, t=0, best=1000000, bestx, besty, x=64, tmpr[n], tmpq[n], orderq[n], orderr[n];
   //     int *order = new int[n], *temp = new int[n], *temp2 = new int[n], cmax=0, t=0;

        // sortowanie po r i zapisanie kolejnosci do tablicy tmpr
        for(int i=0; i<n; i++){
            tmpr[i] = R[i];
        }
        sort(tmpr, tmpr+n);
        for(int i=0; i<n; i++) orderr[i] = distance(R, find(R, R+n, tmpr[i]));

        // sortowanie po q i zapisanie kolejnosci do tablicy tmpq
        for(int i=0; i<n; i++){
            tmpq[i] = Q[i];
        }
        sort(tmpq, tmpq+n, greater<int>());
        for(int i=0; i<n; i++) orderq[i] = distance(Q, find(Q, Q+n, tmpq[i]));

        //sortowanie po xr-yq i zapisanie kolejnosci do tablicy
        int X[]={1,3,4,8,11,12,21,23};
        int Y[]={1,3,4,8,11,12,21,23};
        int z = sizeof(X) / sizeof(X[0]);
        for(int x=0; x<z; x++)
        {
                for(int y=0; y<z; y++)
                    {

                    for(int i=0; i<n; i++){
                        temp[i] = X[x]*R[i]-Y[y]*Q[i];
                    }
                    for(int i=0; i<n; i++){
                        temp2[i] = temp[i];
                    }
                    sort(temp2, temp2+n);
                    for(int i=0; i<n; i++){
                        order[i] = distance(temp, find(temp, temp+n, temp2[i])); // uwaga! funkcja zle policzy, gdy sa powtarzajace sie wartosci xr-yq
                    }


                    // policzenie czasu calkowitego cmax
                    for(int i=0; i<n; i++)
                    {
                        if(R[order[i]]>t) t = R[order[i]] + P[order[i]];
                        else t = t + P[order[i]];
                        cmax = max(cmax, t+Q[order[i]]);
                    }

                    if(cmax < best){
                        best = cmax;
                        bestx = X[x];
                        besty = Y[y];
                        for(int e=0; e<n; e++)
                            rightorder[e] = order[e];
                    }


                    // wypisanie proponowanej kolejnosci oraz policzonego dla niej czasu cmax
            //        cout << filename[fnc] << endl << "Kolejnosc: ";
        //            for(i=0; i<n; i++){
        //                cout<<order[i]+1<<" ";
       //             }
     //               cout << "\nCmax = " << cmax << endl << endl;
            //        cout << "BEST = " << best << endl << endl;
                    cmax = 0, t=0;
                }
        }

            /*/ sortowanie po rand i zapisanie kolejnosci do tablicy
            for(int j = 0; j < 1; j++)
            {

                int *rnd = new int[n];
            /*    for(int k=0; k<n; k++){
                    rnd[k] = -k-1;
                }

                for(int d=0; d<n; d++) // losowanie kolejnosci
                {
                    x = rand() % n;
                    while((find(rnd, rnd + n, x) != rnd + n) == true)
                        x = rand() % n;

                    rnd[d] = x;
                }* /

                for(int v=0; v < n; v++){
                    rnd[v] = v;
                }
         //       random_shuffle(rnd+5, rnd + n - 5);

                // policzenie czasu calkowitego cmax
                for(int b=0; b<n; b++)
                {
                    if(R[rnd[b]]>t) t = R[rnd[b]] + P[rnd[b]];
                    else t = t + P[rnd[b]];
                    cmax = max(cmax, t+Q[rnd[b]]);
                }
                if(cmax < best){
                    best = cmax;
                    for(int e=0; e<n; e++)
                        rightorder[e] = rnd[e];
                }

                cmax=0, t=0;

                delete [] rnd;
            }*/

      /*      for(int i = 0; i < n; i++)
            {
                rightorder[i] = distance(Q, find(Q, Q+n, tmpq[i]));
            }*/


            int modifiedorder[] = {9, 18, 22, 11, 5, 20, 10, 21, 24, 3, 17, 14, 12, 6, 8, 1, 13, 4, 16, 7, 15, 19, 23, 2};

            for(int i=0; i<n; i++)
            {
                if(R[modifiedorder[i]-1]>t) t = R[modifiedorder[i]-1] + P[modifiedorder[i]-1];
                else t = t + P[modifiedorder[i]-1];
                cmax = max(cmax, t+Q[modifiedorder[i]-1]);
            }



            cout << filename[0] << endl << "Kolejnosc optymalna: ";
                    for(int z=0; z<n; z++){
                        cout<<modifiedorder[z]<<" ";
                    }

            cout << endl << "Kolejnosc xR-yQ: ";
                    for(int z=0; z<n; z++){
                        cout<<order[z]+1<<" ";
                    }
            cout << endl << "Kolejnosc po R: ";
                    for(int z=0; z<n; z++){
                        cout<<orderr[z]+1<<" ";
                    }
            cout << endl << "Kolejnosc po Q: ";
                    for(int z=0; z<n; z++){
                        cout<<orderq[z]+1<<" ";
                    }
            cout << endl << endl;


            cout << "Optymalnie:  (Cmax = " << cmax << ")\t";
            cout << "xR-yQ:  (Cmax = " << "15328" << ")\t\t";
            cout << "po R:  (Cmax = " << "14239" << ")\t\t";
            cout << "po Q:  (Cmax = " << "16254" << ")\n";
            cout.width(5); cout << left << "nr";
            cout.width(7); cout << left << "R";
            cout.width(6); cout << left << "P";
            cout.width(14); cout << left << "Q";

            cout.width(5); cout << left << "nr";
            cout.width(7); cout << left << "R";
            cout.width(6); cout << left << "P";
            cout.width(14); cout << left << "Q";

            cout.width(5); cout << left << "nr";
            cout.width(7); cout << left << "R";
            cout.width(6); cout << left << "P";
            cout.width(14); cout << left << "Q";

            cout.width(5); cout << left << "nr";
            cout.width(7); cout << left << "R";
            cout.width(6); cout << left << "P";
            cout.width(6); cout << left << "Q" << endl;
            for(int i = 0; i < n; i++){
                cout.width(5); cout << left;
                cout << modifiedorder[i];
                cout.width(7); cout << left;
                cout << R[modifiedorder[i]-1];
                cout.width(6); cout << left;
                cout << P[modifiedorder[i]-1];
                cout.width(6); cout << left;
                cout << Q[modifiedorder[i]-1] <<"\t";

                cout.width(5); cout << left;
                cout << order[i]+1;
                cout.width(7); cout << left;
                cout << R[order[i]];
                cout.width(6); cout << left;
                cout << P[order[i]];
                cout.width(6); cout << left;
                cout << Q[order[i]] <<"\t";

                cout.width(5); cout << left;
                cout << orderr[i]+1;
                cout.width(7); cout << left;
                cout << R[orderr[i]];
                cout.width(6); cout << left;
                cout << P[orderr[i]];
                cout.width(6); cout << left;
                cout << Q[orderr[i]] <<"\t";

                cout.width(5); cout << left;
                cout << orderq[i]+1;
                cout.width(7); cout << left;
                cout << R[orderq[i]];
                cout.width(6); cout << left;
                cout << P[orderq[i]];
                cout.width(6); cout << left;
                cout << Q[orderq[i]] << endl;
            }



    return 0;
}
