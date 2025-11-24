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
  if(n%3 == 1){
    cout << "YES\n";
    return;
  }
  if(n%3 == 2){
    map<char,ll> mapa;
    for(ll i = 1; i < n; i++){
      if((i-1)%3 == 0) mapa[text[i]] = i;
    }
    for(ll i = 0; i < n; i+= 3){
      if(mapa[text[i]] > i){
        cout << "YES\n";
        return;
      }
    }
    cout << "NO\n";
    return;
  }
  else if(n%3 == 0){
    map<char, ll> mapa;
    for(ll i = 2; i < n; i++){
      if((i-2)%3 == 0) mapa[text[i]] = i;
    }
    for(ll i = 0; i < n; i+= 3){
      if(mapa[text[i]] > i){
        cout << "YES\n";
        return;
      }
    }
    cout << "NO\n";
    return;
  }
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