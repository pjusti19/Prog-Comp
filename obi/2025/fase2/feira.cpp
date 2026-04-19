#include <functional>
#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
#include <queue>

#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n, t;
  cin >> n >> t;
  vector<ll> tipos(n);
  vector<ll> precos(n);
  for(ll &tipo : tipos) cin >> tipo;
  for(ll &preco : precos) cin >> preco;
  unordered_map<ll, priority_queue<ll, vector<ll>, greater<ll>>> por_tipo;
  set<pair<ll, ll>> global;
  for(int i = 0; i < n; i++) por_tipo[tipos[i]].push(precos[i]);
  for(auto &it : por_tipo) global.insert({it.second.top(), it.first});

  ll sum = 0;
  ll c;
  cin >> c;

  for(int i = 0; i < c; i++){
    ll u;
    cin >> u;
    if(u == 0 && !global.empty()){
      auto item = *global.begin();
      por_tipo[item.second].pop();
      sum += item.first;
      global.erase(item);
      if(!por_tipo[item.second].empty())
        global.insert({por_tipo[item.second].top(), item.second});
    }
    else if(!por_tipo[u].empty()){
      ll p = por_tipo[u].top();
      por_tipo[u].pop();
      sum += p;
      global.erase({p, u});
      if(!por_tipo[u].empty()) global.insert({por_tipo[u].top(), u});
    }
  }

  cout << sum << "\n";
  return 0;
}
