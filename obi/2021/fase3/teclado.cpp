#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    string n; int m; cin >> n >> m;
    vector<string> strings(m);
    for(string&s:strings) cin >> s;
    vector<char> ref(26);
    ref[0] = ref[1] = ref[2] = '2';
    ref[3] = ref[4] = ref[5] = '3';
    ref[6] = ref[7] = ref[8] = '4';
    ref[9] = ref[10] = ref[11] = '5';
    ref[12] = ref[13] = ref[14] = '6';
    ref[15] = ref[16] = ref[17] = ref[18] = '7';
    ref[19] = ref[20] = ref[21] = '8';
    ref[22] = ref[23] = ref[24] = ref[25] = '9';
    for(string s:strings){
        if(s.length() != n.length()) {m--; continue;}
        for(int i = 0; i < n.length(); i++)
            if(ref[s[i]-'a'] != n[i]) {m--; break;}
    }
    cout << m << endl;
    return 0;
}
