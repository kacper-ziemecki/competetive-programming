#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  string text;
  cin >> text;
  ll first = -1, second = -1;
  for(ll i = 0; i < text.size()-1; i++){
    if(text[i] == '1' && text[i+1] == '1'){
      first = i;
      break;
    }
  }
  for(ll i = text.size()-1; i > 0; i--){
    if(text[i] == '0' && text[i-1] == '0'){
      second = i-1;
      break;
    }
  }
  if(first == -1 || second == -1){
    cout << "YES\n";
  }
  else if(first < second){
    cout << "NO\n";
  }
  else{
    cout << "YES\n";
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