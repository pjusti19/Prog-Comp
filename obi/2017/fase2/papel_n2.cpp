// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N;
//     cin >> N;

//     vector<long long> A(N);
//     for (auto &x : A) cin >> x;

//     int ans = 0;

//     // Testa cada altura A[i] como altura do corte
//     for (int i = 0; i < N; i++) {
//         long long h = A[i];

//         int groups = 0;
//         bool inside = false;

//         for (int j = 0; j < N; j++) {
//             if (A[j] >= h) {
//                 if (!inside) {
//                     groups++;
//                     inside = true;
//                 }
//             } else {
//                 inside = false;
//             }
//         }

//         // Cada grupo atravessado pelo corte gera uma separação extra.
//         ans = max(ans, groups + 1);
//     }

//     cout << ans << '\n';

//     return 0;
// }