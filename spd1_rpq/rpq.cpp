#include <iostream>
#include <fstream>
#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n, r,p,q, i=0; // n - liczba zadan, r - czas dostarczenia, p - czas trwania na maszynie, q - czas stygniecia;

    // wczytanie danych z pliku
    ifstream infile("data_1.txt");
    if(infile.good()==false) cerr<<"Blad. Nie mozna otworzyc pliku!\n";
    infile >> n;
    int R[n], P[n], Q[n];
    while (infile >> r >> p >> q){
        R[i]=r, P[i]=p, Q[i]=q;
        i++;
    }

    // sortowanie i zapisanie kolejnosci do tablicy
    int order[n], temp[n];
    for(i=0; i<n; i++){
        temp[i] = R[i];
    }
    sort(temp, temp+n);

    for(i=0; i<n; i++)
    {
        order[i] = distance(R, find(R, R+n, temp[i]))+1;
    }


    cout << "Kolejnosc: ";
    for(i=0; i<n; i++){
        cout<<order[i]<<" ";
    }


    return 0;
}
