#include <cstddef>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    string c;
    cin >> n >> c;
    int maior = 1;
    for(int i = 0; i < n; i++){
        int l, r;
        l = i-1;
        r = i + 1;
        while(c[l] == c[r] && l >= 0 && r < n){
            l--;
            r++;
        }
        maior = max(maior, r - l - 1);
        l = i;
        r = i + 1;
        while(c[l] == c[r] && l >= 0 && r < n){
            l--;
            r++;
        }
        maior = max(maior, r - l - 1);
    }

    cout << maior << "\n";

    return 0;
}