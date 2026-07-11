#include <bits\stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int e, d;
    cin >> e >> d;
    if(e > d) cout << e + d;
    else cout << 2*(d-e);
    cout << "\n";
    return 0;
}