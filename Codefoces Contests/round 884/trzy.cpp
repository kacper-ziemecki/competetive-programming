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
  vector<bool> vis(n, false);
  ll one = 0, two = 0;
  for(ll i = 0; i < n; i+= 2){
    if(list[i] >= 0 && ((i-2 >= 0 && list[i-2] >= 0) || (i+2 < n && list[i+2] >= 0))){
      vis[i] = true;
      one += list[i];
    }
    else if((list[i] > 0) && !vis[i]){
      ll prawo = (i+2 < n ? list[i+2] : LONG_LONG_MIN);
      ll lewo = (i-2 >= 0 ? list[i-2] : LONG_LONG_MIN);
      if((lewo >= prawo) && (list[i]+lewo > 0) && (i-2 >= 0) && !vis[i-2]){
        vis[i] = true;
        vis[i-2] = true;
        one += list[i]+lewo;
      }
      else if((lewo < prawo) && (list[i]+prawo > 0) && (i+2 <n) && !vis[i+2]){
        vis[i] = true;
        vis[i-2] = true;
        one += list[i]+prawo;
      }
    }
  }
  for(ll i = 1; i < n; i+= 2){
    if(list[i] >= 0 && ((i-2 >= 0 && list[i-2] >= 0) || (i+2 < n && list[i+2] >= 0))){
      vis[i] = true;
      two += list[i];
    }
    else if((list[i] > 0) && !vis[i]){
      ll prawo = (i+2 < n ? list[i+2] : LONG_LONG_MIN);
      ll lewo = (i-2 >= 0 ? list[i-2] : LONG_LONG_MIN);
      if((lewo >= prawo) && (list[i]+lewo > 0) && (i-2 >= 0) && !vis[i-2]){
        vis[i] = true;
        vis[i-2] = true;
        two += list[i]+lewo;
      }
      else if((lewo < prawo) && (list[i]+prawo > 0) && (i+2 < n) && !vis[i+2]){
        vis[i] = true;
        vis[i-2] = true;
        two += list[i]+prawo;
      }
    }
  }
  ll all = LONG_LONG_MIN;
  for(auto el : list) all = max(all, el);
  if(max(one, two) == 0){
    cout << all << endl;
  }
  else{
    cout << max(one, two) << endl;
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}