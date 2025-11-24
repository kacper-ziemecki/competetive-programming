#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long


void solve(){
	ull n;
	cin >> n;
	vector<pair<ull, ull>> list(n, {0, 0});
	for(auto &el : list) cin >> el.first >> el.second;

	sort(list.begin(), list.end());

	ull temp = list[0].second;
	ull res = temp + list[1].second + (list[1].first - list[0].first);

	for(ull i = 1; i < n; i++){
		res = min(res, temp + list[i].second + (list[i].first - list[i-1].first));
		temp = min(temp + (list[i].first - list[i-1].first), list[i].second);
		
	}
	cout << res << endl;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// #ifndef ONLINE_JUDGE
	// 	freopen("../../input.txt", "r", stdin);
	// 	freopen("../../output.txt", "w", stdout);
	// #endif
	
	solve();
}