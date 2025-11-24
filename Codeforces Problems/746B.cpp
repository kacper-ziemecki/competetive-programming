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
  string res(text.size(), ' ');
  if(text.size()&1){
    res[text.size()/2] = text[0];

    ll first = text.size()/2 - 1;
    ll second = text.size()/2 + 1;
    for(ll i = 1; i < text.size(); i++){
      if(i&1){
        res[first] = text[i];
        first--;
      }
      else{
        res[second] = text[i];
        second++;
      }
    }
  }
  else{
    ll first = text.size()/2 - 1;
    ll second = text.size()/2;
    for(ll i = 0; i < text.size(); i++){
      if(!(i&1)){
        res[first] = text[i];
        first--;
      }
      else{
        res[second] = text[i];
        second++;
      }
    }
  }
  cout << res << endl;
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

  solve();
}