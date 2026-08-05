#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int main(){ _ 
    int n; cin >> n;
    vector<char> ans(n);
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(s[i] == 'a') ans[i] = 'b';
        else ans[i] = 'a';
    }
    for(char& c: ans) cout << c;
    cout << endl;

    return 0;
}