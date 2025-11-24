#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<bool> vis(n, false);
  string text;
  cin >> text;
  for(ll i = 0; i < n; i++){
    if(text[i] == '1'){
      vis[i] = true;
      if(i-1 >= 0) vis[i-1] = true;
      if(i+1 < n) vis[i+1] = true; 
    }
  }
  ll res = 0;
  for(auto el : vis){
    if(!el) res++;
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
  
  ll t;
  cin >> t;
  while(t--)
  solve();
}