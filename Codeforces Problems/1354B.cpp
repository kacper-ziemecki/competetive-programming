#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  string text;
  cin >> text;
  ll last1 =-1, last2=-1, last3=-1, res = INT_MAX;
  bool flag = false;
  for(ll i = 0; i < text.size(); i++){
    if(text[i] == '1') last1 = i;
    if(text[i] == '2') last2 = i;
    if(text[i] == '3') last3 = i;
    if(last1 != -1 && last2 != -1 && last3 != -1){
      flag = true;
      res = min(res, 1 + max(last1,  max(last2, last3)) - min(last1, min(last2, last3)));
    }
  }
  if(!flag){
    cout << 0 << endl;
    return;
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

  ll t;
  cin >> t;
  while(t--) solve();
}