#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int e, s, l;
    cin >> e >> s >> l;
    cout << abs(s - e) + abs(l - s) + abs(e - l) << "\n";
    return 0;

}