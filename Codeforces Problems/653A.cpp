#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  set<ll> sito;
  for(auto el : list){
    sito.emplace(el);
  }
  list.clear();
  for(auto el : sito){
    list.push_back(el);
  }
  sort(list.begin(), list.end());
  for(ll i = 2; i < n; i++){
    if(list[i-2]+1 == list[i-1] && list[i-1] +1 == list[i]){
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  solve();
}