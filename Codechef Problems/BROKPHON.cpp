#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0), ans{1};
  for(auto &el : list) cin >> el;
  ll res = 0;
  for(ll i = 1; i < n; i++){
    if(list[i-1] == list[i]) ans.back()++;
    else{
      ans.push_back(1);
    }
  }
  for(ll i = 1; i < ans.size()-1; i++){
    if(ans[i] != 1) res+=2;
    else res++;
  }
  if(ans.size() == 1){
    cout << 0 << endl;
    return;
  }
  else if(ans.size() == 2){
    cout << 2 << endl;
    return;
  }
  res+=2;
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
  
  ll t;
  cin >> t;
  while(t--) solve();
}