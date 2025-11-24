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
  for(ll i = 0; i < n/2; i++){
    if(text[i] > text[n-1-i]){
      char temp = text[i]; 
      text[i] = text[n-1-i];
      text[n-1-i] = temp;
    }
  }
  for(ll i = 1; i < n; i++){
    if(text[i-1] > text[i]){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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