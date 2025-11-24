#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
	ll n,m;
	cin >> n >> m;
	vector<ll> jeden(n),dwa(m);
	for(auto &el : jeden) cin >> el;
	for(auto &el : dwa) cin >> el;
	ll i = 0;
	ll res = 0;
	ll prev = 0;
	for(ll j = 0; j < m; j++){
		if(j > 0 && dwa[j-1] == dwa[j]){
			res += prev;
			continue;
		}
		prev = 0;
		while(i < n && jeden[i] <= dwa[j]){
			if(jeden[i] == dwa[j]){
				res++;
				prev++;
			}
			else{
				prev = 0;
			}
			i++;
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
  freopen("../../../../input.txt", "r", stdin);
  freopen("../../../../output.txt", "w", stdout);
#endif

  solve();
}