#include <iostream>

using namespace std;

void flip(int n, int v[], int i, int j)
{
    for(; i < j; i++, j--)
    {
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
}

void print(int n, int v[])
{
    for(int i = 1; i <= n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int power(int exp)
{
    int b = 1;
    for(int i = 0; i < exp; i++)
    {
        b *= 2;
    }
    return b;
}

int main()
{
    int n, m = 1;
    int v[9] = {3,2,6,8,5,9,1,7,4};
    //cin >> n;
    int copy = n;
    while(copy > 2)
    {
        copy /= 2;
        m++;
    }

//    print(n, v);
//    for(int i = 1; i <= m; i++)
//    {
//        for(int j = 1; j <= power(m - i); j++)
//        {
//            for(int k = 1; k <= power(m - i); k++)
//            {
//                flip(n, v, power(i) * (j - 1) + 1, power(i) * j);
//            }
//        }
//    }
//    print(n, v);
//    for(int k = 1,i = 1; i <= m, k <= power(m - i); i++, k++)
//    {
//            cout << power(i) * (k - 1) + 1 << " ";
//
//    }
    return 0;
}

