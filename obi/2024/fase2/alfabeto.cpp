#include <iostream>
#include <unordered_set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int k, n;
    cin >> k >> n;
    unordered_set<char> isPresent;

    for(int i = 0; i < k; i++){
        char caractere;
        cin >> caractere;
        isPresent.insert(caractere);
    }

    for(int i = 0; i < n; i++){
        char caractere;
        cin >> caractere;
        if(isPresent.count(caractere) == 0){
            cout << 'N' << "\n";
            return 0;
        }
    }

    cout << 'S' << "\n"; 

    return 0;

}