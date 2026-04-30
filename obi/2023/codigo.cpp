#include <bits/stdc++.h>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; string msg;
    cin >> n >> msg;
    char anterior = '!';
    int count = 0;
    for(int i = 0; i < n; i++){
        if(msg[i] == anterior || anterior == '!') count++;
        else
        {
            cout << count << " " << anterior << " "; 
            count = 1;
        }
        anterior = msg[i];
    }

    cout << count << " " << anterior << "\n"; 

    return 0;
}