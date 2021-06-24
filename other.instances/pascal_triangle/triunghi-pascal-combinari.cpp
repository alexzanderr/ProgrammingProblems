#include <iostream>

using namespace std;

int comb(int n , int k)
{
    int p = 1;
    for(int i = 1 ; i <= k ; i ++)
        p = p * (n-i+1) / i;
    return p;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i <= n ; i ++)
        cout << comb(n,i) << " ";
    return 0;
}
