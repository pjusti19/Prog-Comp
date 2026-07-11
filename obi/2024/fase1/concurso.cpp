#include <bits\stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> notas(n);
    for(auto &n : notas) cin >> n;
    sort(notas.begin(), notas.end());
    cout << notas[n-k] << "\n";
    return 0;
}