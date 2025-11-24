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
  if(n&1){ //last position is odd
    for(ll i = 0; i < n; i+=2){
      if((text[i] - '0')&1){
        cout << 1 << endl;
        return;
      }
    }
    cout << 2 << endl;
  }
  else{ //last position is even
    for(ll i = 1; i < n; i+=2){
      if(!((text[i] - '0')&1)){
        cout << 2 << endl;
        return;
      }
    }
    cout << 1 << endl;
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