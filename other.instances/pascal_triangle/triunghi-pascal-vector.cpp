#include <iostream>

using namespace std;

int main()
{
    int n = 5, v[31];
    v[0] = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        v[i] = 1;
        for(int j = i - 1 ; j > 0 ; j --)
            v[j] = v[j] + v[j-1];
        v[0] = 1;
    }
    for(int j = 0 ; j <= n ; j ++)
        cout << v[j] << " ";
    return 0;
}
