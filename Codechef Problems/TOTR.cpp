#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  string alfabet2, alfabet1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  cin >> alfabet2;
  for(ll i = 0; i < alfabet1.size()/2; i++){
    alfabet2 += toupper(alfabet2[i]);
  }
  map<char, char> mapa;
  for(ll i = 0; i < alfabet2.size(); i++){
    mapa[alfabet1[i]] = alfabet2[i];
  }
  string temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;

    string res = "";
    for(auto el : temp){
      if(el == '_'){
        res += ' ';
      }
      else if(el == '.' || el == ',' || el == '!' || el == '?'){
        res += el;
      }
      else{
        res += mapa[el];
      }
    }
    
    cout << res << endl;
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
  
  solve();
}