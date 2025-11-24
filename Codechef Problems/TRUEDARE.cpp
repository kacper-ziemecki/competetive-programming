#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll a;
  cin >> a;
  vector<ll> one(a, 0);
  for(auto &el : one) cin >> el;
  map<ll, bool> mapa1;
  for(auto el : one) mapa1[el] = true;
  ll b;
  cin >> b;
  vector<ll> two(b, 0);
  for(auto &el : two) cin >> el;
  map<ll, bool> mapa2;
  for(auto el : two) mapa2[el] = true;
  ll c;
  cin >> c;
  vector<ll> three(c, 0);
  for(auto &el : three) cin >> el;
  ll d;
  cin >> d;
  vector<ll> four(d, 0);
  for(auto &el : four) cin >> el;

  for(auto el : three){
    if(!mapa1[el]){
      cout << "no\n";
      return;
    }
  }
  for(auto el : four){
    if(!mapa2[el]){
      cout << "no\n";
      return;
    }
  }
  cout << "yes\n";
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
  
  ll t;
  cin >> t;
  while(t--) solve();
}