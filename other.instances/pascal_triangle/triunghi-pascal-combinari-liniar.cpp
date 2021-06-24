#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int p = 1;
    cout << "1 ";
    for(int i = 1 ; i <= n ; i ++)
    {
        p = p * (n-i+1) / i;
        cout << p << " ";
    }
    return 0;
}
