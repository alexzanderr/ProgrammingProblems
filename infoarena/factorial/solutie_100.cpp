#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream fin("fact.in");
    ofstream fout("fact.out");

    int p;
    fin >> p;
    if (p == 0)
        fout << "1";
    else
    {
        int mij, copie, st, dr, ok, putere, s;
        ok = 1;
        st = 1;
        dr = 2000000000;

        while (st <= dr && ok)
        {
            mij = (st + dr) / 2;
            copie = mij;
            s = 0;
            putere = 5;

            while (copie / putere > 0)
            {
                s = s + copie / putere;
                putere *= 5;
            }

            if (s == p)
                ok = 0;
            else if (s > p)
                dr = mij - 1;
            else
                st = mij + 1;
        }

        if (ok)
        {
            mij = -1;
        }
        else
        {
            mij = mij - mij % 5;
        }

        fout << mij;
    }

    fin.close();
    fout.close();
    return 0;
}