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
  ll one = 0, two = 0;
  for(auto el : text){
    if(el == 'X') one++;
    else two++;
  }
  if(one == two){
    cout << 0 << endl;
  }
  else if(one > two){
    cout << (n/2) - two << endl;
    ll cnt = (n/2) - two;
    for(ll i = 0; cnt > 0; i++){
      if(text[i] == 'X'){
        text[i] = 'x';
        cnt--;
      } 

    }
  }
  else{
    cout << (n/2) - one << endl;
    ll cnt = (n/2) - one;
    for(ll i = 0; cnt > 0; i++){
      if(text[i] == 'x'){
        text[i] = 'X';
        cnt--;
      } 
    }
  }

  for(auto el : text) cout << el;
  cout << endl;
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