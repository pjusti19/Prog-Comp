#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (int i = a; i < n; i++)

char findKthBit(int n, int k)
{

    int mid = pow(2, (n - 1));

    if (n == 1)
    {
        cout << "here in zero\n";
        return '0';
    }
    if (k == mid)
        return '1';
    else if (k < mid)
    {
        cout << "here\n";
        return findKthBit(n - 1, k);
    }
    else
    {
        cout << "here inverted\n";
        char bit = findKthBit(n - 1, pow(2, n) - k);
        if (bit == '0')
            return '1';
        return '0';
    }
}

int main()
{

    cout << findKthBit(3,1);
    return 0;
}