#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

bool subsolve(vector<ll> list, ll i = 0, ll suma = 0, ll cnt = 0){
  if(i != 0 && suma == 0 && cnt != 0){
    return true;
  }
  if(i >= 4) return false;
  bool res = subsolve(list, i+1, suma+list[i], cnt+1);
  res |= subsolve(list, i+1, suma, cnt);
  return res;
} 

void solve()
{
  vector<ll> list(4, 0);
  for(auto &el : list) cin >> el;

  bool res = subsolve(list);
  cout << (res ? "Yes\n" : "No\n");
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