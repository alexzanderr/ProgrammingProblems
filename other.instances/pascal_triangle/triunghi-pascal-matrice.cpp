#include <iostream>

using namespace std;

int main()
{
    int n, A[31][31];
    cin >> n;
    for(int i = 0 ; i <= n ; i ++)
    {
        A[i][0] = A[i][i] = 1;
        for(int j = 1 ; j < i ; j ++)
            A[i][j] = A[i-1][j-1] + A[i-1][j];
    }
    for(int j = 0 ; j <= n ; j ++)
        cout << A[n][j] << " ";
    return 0;
}
