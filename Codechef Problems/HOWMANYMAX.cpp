#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ll n;
  cin >> n;
  string text;
  cin >> text;
  ll res = 0;
  if(n == 2){
    cout << 1 << endl;
    return;
  }
  if(text[0] == '1') res++;
  if(text[n-2] == '0') res++;
  for(ll i = 0; i < n-2; i++){
    if(text[i] == '0' && text[i+1] == '1') res++;
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
  while(t--) solve();
}