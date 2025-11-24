#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
  ll n,q;
  cin >> n >> q;
  string text;
  cin >> text;
  ll first0 = LONG_LONG_MAX, first1 = LONG_LONG_MAX, last0 = LONG_LONG_MIN, last1 = LONG_LONG_MIN;
  for(ll i = 0; i < n; i++){
    if(text[i] == '0') {
      first0 = i;
      break;
    }
  }
  for(ll i = 0; i < n; i++){
    if(text[i] == '1') {
      first1 = i;
      break;
    }
  }
  for(ll i = n-1; i >= 0; i--){
    if(text[i] == '0') {
      last0 = i;
      break;
    }
  }
  for(ll i = n-1; i >= 0; i--){
    if(text[i] == '1') {
      last1 = i;
      break;
    }
  }

  ll a,b;
  for(ll i = 0; i < q; i++){
    cin >> a >> b;
    if(text[a-1] == '0'){
      if(first0 < a-1){
        cout << "YES\n";
        continue;
      }
    }
    else{
      if(first1 < a-1){
        cout << "YES\n";
        continue;
      }
    }

    if(text[b-1] == '0'){
      if(last0 > b-1){
        cout << "YES\n";
        continue;
      }
    }
    else{
      if(last1 > b-1){
        cout << "YES\n";
        continue;
      }
    }
    cout << "NO\n";
  }
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