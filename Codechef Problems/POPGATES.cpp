#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,k;
  cin >> n >> k;
  vector<char> list(n, ' ');
  for(auto &el : list) cin >> el;
  ll res = 0, ans = 0;
  for(ll i = n-1; i >= n-k; i--){
    if(list[i] == 'H' && res%2 == 0){
      res++;
    }
    else if(list[i] == 'T' && res%2 == 1){
      res++;
    }
  }
  for(ll i = 0; i < n-k; i++){
    if(list[i] == 'H' && res%2 == 0){
      ans++;
    }
    else if(list[i] == 'T' && res%2 == 1){
      ans++;
    }
  }
  cout << ans << endl;
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