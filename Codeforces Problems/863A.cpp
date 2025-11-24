#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
  string text;
  cin >> text;
  string res;
  bool flag = true;
  for(ll i = text.size() - 1; i >= 0; i--){
    if(text[i] == '0' && flag){
      continue;
    }
    if(text[i] != '0') flag = false;
    res += text[i];
  }
  for(ll i = 0; i < res.size()/2; i++){
    if(res[i] != res[res.size() - 1 - i]){
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
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  solve();
}