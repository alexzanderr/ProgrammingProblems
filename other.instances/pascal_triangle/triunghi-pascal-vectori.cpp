#include <iostream>

using namespace std;

int main()
{
    int n, v[31],u[31];
    cin >> n;
    v[0] = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        u[0] = u[i] = 1;
        for(int j = 1 ; j < i ; j ++)
            u[j] = v[j-1] + v[j];
        for(int j = 0 ; j <= i ; j ++)
            v[j] = u[j];
    }
    for(int j = 0 ; j <= n ; j ++)
        cout << v[j] << " ";
    return 0;
}
