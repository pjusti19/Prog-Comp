#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> alturas(n);
    for(int &a: alturas) cin >> a;

    int maior = alturas[n-1];
    int coladores = 0;
    for(int i = n-2; i >= 0; i--){
        if(alturas[i] <= maior)
            coladores++;
        else maior = alturas[i];
    }
    cout << coladores << "\n";
}