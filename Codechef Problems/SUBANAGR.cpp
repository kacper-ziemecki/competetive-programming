#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  string temp;
  map<char, ll> mapa;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    set<char> lista;
    for(auto el : temp) lista.emplace(el);
    for(auto el : lista){
      mapa[el]++;
    }
  }
  string res = "";
  for(auto el : mapa){
    if(el.second == n){
      res += el.first;
    }
  }
  sort(res.begin(), res.end());
  if(res.size() == 0){
    cout << "no such string\n";
    return;
  }
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  
  solve();
}