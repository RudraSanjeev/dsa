#include <bits/stdc++.h>
using namespace std;

// quicksort
int p(int x, int n)
{
    if (n == 1)
        return x;
    return x * p(x * x, n / 2);
}
int main()
{
    cout << p(2, 5);
    cout << endl;
    return 0;
}