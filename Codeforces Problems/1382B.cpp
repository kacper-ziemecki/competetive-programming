#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double



void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  bool test = true;
  for(auto el : list){
    if(el != 1) test = false;
  }
  if(test){
    cout << (list.size()&1 ? "First\n" : "Second\n");
    return;
  }
  bool flag = true;
  for(auto el : list){
    if(el != 1) break;
    flag = !flag;
  }
  cout << (flag ? "First\n" : "Second\n");
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