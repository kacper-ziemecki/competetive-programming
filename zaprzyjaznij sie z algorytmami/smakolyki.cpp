#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
	ll n,m;
	cin >> n >> m;
	vector<bool> vis(m+1, false);
	vector<ll> list(n, 0);
	for(auto &el : list) cin >> el;
	ll res = 0;
	ll begin = 0;
	for(ll end = 0; end < n; end++){
		
		while(vis[list[end]] && begin < end){
			vis[list[begin]] = false;
			begin++;
		}
		vis[list[end]] = true;
			
		res += end - begin + 1;
	}
	cout << res << endl;
}
	

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../input.txt", "r", stdin);
//   freopen("../../output.txt", "w", stdout);
// #endif

  solve();
}