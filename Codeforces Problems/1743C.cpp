#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double



void solve()
{
  ll n;
  cin >> n;
  string text;
  cin >> text;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  ll last0 = -1;
  for(ll i = 1; i < n; i++){
    if(text[i-1] == '0' && text[i] == '1' && list[i] < list[i-1]){
      text[i-1] = '1';
      text[i] = '0';
    }
    else if(text[i-1] == '1' && text[i] == '1' && last0 != -1 && list[i] < list[last0]){
      text[last0] = '1';
      text[i] = '0';
      while(text[last0] != '1' && last0 <= i) last0++;
      if(last0 == i && text[last0] != '0') last0 = -1;
    }

    if(text[i] == '0') last0 = i;
  }
  ll suma = 0;
  for(ll i = 0; i < n; i++){
    if(text[i] == '1'){
      suma += list[i];
    }
  }

  cout << suma << endl;
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