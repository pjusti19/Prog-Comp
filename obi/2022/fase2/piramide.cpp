#include <cstddef>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << 1+ min(min(i,j),min(n - 1 -  i, n - 1 - j)) << " ";
            if(j == n - 1) cout << "\n";
        }
    }

    return 0;
}