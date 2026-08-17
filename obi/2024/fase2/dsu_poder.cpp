#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> pai, sub;
vector<ll> p;
vector<vector<int>> active;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int N,M;

int getId(int i,int j){return i*M+j;}
int find(int v){return pai[v]==v?v:pai[v]=find(pai[v]);}

void une(int x,int y){
    x=find(x); y=find(y);
    if(x==y) return;
    if(sub[x]<sub[y]) swap(x,y);
    pai[y]=x; sub[x]+=sub[y]; p[x]+=p[y];
    if(active[x].size()<active[y].size()) swap(active[x],active[y]);
    for(int id:active[y]) active[x].push_back(id);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>N>>M;
    int SZ=N*M;
    pai.resize(SZ); iota(pai.begin(),pai.end(),0);
    sub.assign(SZ,1);
    p.resize(SZ); active.resize(SZ);
    for(int i=0;i<SZ;i++) active[i].push_back(i);
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) cin>>p[getId(i,j)];

    vector<int> order(SZ), marc(SZ,0);
    iota(order.begin(),order.end(),0);
    sort(order.begin(),order.end(),[&](int a,int b){return p[a]<p[b];});

    vector<ll> resp(SZ,-1);
    for(int id:order){
        marc[id]=1;
        int x=id/M,y=id%M;
        for(int k=0;k<4;k++){
            int hx=x+dx[k], hy=y+dy[k];
            if(hx<0||hx>=N||hy<0||hy>=M) continue;
            if(!marc[getId(hx,hy)]) continue;
            int viz=find(getId(hx,hy));
            if(p[viz]<p[id]){
                for(int aux:active[viz]) resp[aux]=p[viz];
                active[viz].clear();
            }
            une(viz,id);
        }
    }
    for(int i=0;i<SZ;i++){
        int r=find(i);
        for(int aux:active[r]) if(resp[aux]==-1) resp[aux]=p[r];
        active[r].clear();
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(j) cout<<' ';
            cout<<resp[getId(i,j)];
        }
        cout<<'\n';
    }
}
