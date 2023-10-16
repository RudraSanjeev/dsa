#include <bits/stdc++.h>
using namespace std;

int Bionomial(int n, int k)
{

    if (k == 0 || k == n)
    {
        return 1;
    }
    return Bionomial(n - 1, k - 1) +
           Bionomial(n - 1, k);
}

int main()
{

    cout << Bionomial(5, 2);

    cout << endl;

    return 0;
}