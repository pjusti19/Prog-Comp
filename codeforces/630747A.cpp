#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    if (n % 2 == 0) {
        cout << 2 << " " << n - 2 << "\n";
    } else {
        cout << 3 << " " << n - 3 << "\n";
    }

    return 0;
}