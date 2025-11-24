#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,m;
  cin >> n >> m;
  string text;
  cin >> text;
  unordered_map<char, bool> mapa;
  char temp;
  for(ll i = 0; i < m; i++){
    cin >> temp;
    mapa[temp] = true;
  }
  vector<ll> res;
  ll temp1 = 0;
  for(auto el : text){
    if(!mapa[el]){
      res.push_back(temp1);
      temp1 = 0;
    }
    else{
      temp1++;
    }
  }
  res.push_back(temp1);
  ll ans = 0;
  for(auto el : res){
    ans += (el*(el+1))/2;
  }
  cout << ans << endl;

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