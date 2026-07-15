#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    string palavra;
    cin >> n >> palavra;
    vector<vector<int>> freq(n, vector<int>(26));

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            for (int j = 0; j < n; j++) freq[j / i][palavra[j] - 'a']++;
            bool pode_ser_raiz = true;
            for (int k = 0; k < (n/i)-1; k++)
            {
                for (int l = 0; l < 26; l++)
                {
                    if (freq[k][l] != freq[k + 1][l])
                    {
                        pode_ser_raiz = false;
                        break;
                    }
                }
                if(pode_ser_raiz == false) break;
                else if (k == (n/i)-2){
                    for(int m = 0; m < i; m++)
                        cout << palavra[m];
                    cout << "\n";
                    return 0;
                }
            }
            for(int x = 0; x < n/i; x++)
                for(int y = 0; y < 26; y++)
                    freq[x][y] = 0;
        }
    }
    cout << "*" << "\n";
    return 0;
}