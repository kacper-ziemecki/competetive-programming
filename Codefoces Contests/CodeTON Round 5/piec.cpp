#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
	ll n,m,a;
  cin >> n >> m >> a;
  vector<vector<ll>> list(n, vector<ll>(3, 0));
  for(auto &el : list){
    for(auto &x : el) cin >> x;
  }

}
	

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  solve();
}