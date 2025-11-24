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
  ll res = (text[n-1] == '0' ? 1 : 0);
  ll grupy = (text[0] == '1' ? 1 : 0);
  for(ll i = 1; i < n; i++){
    if(text[i] == '1' && text[i-1] == '0'){
      grupy++;
    }
  }
  cout << max(0ll, (grupy - 1)*2 + res) << endl;
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

  ll t;
  cin >> t;
  while(t--) solve();
}