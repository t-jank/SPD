#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    int n,r,p,q, i=0; // n - liczba zada�, r - czas dostarczenia, p - czas trwania, q - czas stygni�cia;
    ifstream infile("data_1.txt");
    infile >> n;
    int R[n], P[n], Q[n];
    while (infile >> r >> p >> q)
    {
        R[i]=r, P[i]=p, Q[i]=q;
        i++;
    }


    return 0;
}
