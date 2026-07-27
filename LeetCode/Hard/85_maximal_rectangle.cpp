#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n';

typedef long long ll;

int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix[0].size();
    vector<int> hist(m, 0);
    int maior = INT_MIN;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < m; j++)
            hist[j] = matrix[i][j] == '1'? hist[j]+1 : 0;
        vector<int> esq(m), dir(m);
        stack<int> st_esq, st_dir;
        for(int i = 0; i < m; i++){
            while(!st_esq.empty() && hist[st_esq.top()] >= hist[i]) st_esq.pop();
            if(st_esq.empty()) esq[i] = -1;
            else esq[i] = st_esq.top();
            st_esq.push(i);
        }
        for(int i = m-1; i >= 0; i--){
            while(!st_dir.empty() && hist[st_dir.top()] >= hist[i]) st_dir.pop();
            if(st_dir.empty()) dir[i] = m;
            else dir[i] = st_dir.top();
            st_dir.push(i);
        }
        for(int i = 0; i < m; i++) maior = max(maior, hist[i] * (dir[i] - esq[i] - 1));
    }
    return maior;
}

int main(){_ 

    return 0;
}