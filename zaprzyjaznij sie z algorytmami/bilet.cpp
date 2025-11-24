#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
	ll n;
	cin >> n;
	n--;
	vector<ll> list(n, 0);
	for (auto &el : list)
		cin >> el;
	ll minimum = 0, res1 = 0;
	ll maximum = 0, res2 = 0;
	ll suma = 0;
	for (auto el : list)
	{
		minimum = min(minimum + el, min(el, 0ll));
		maximum = max(maximum + el, max(el, 0ll));
		res1 = min(res1, minimum);
		res2 = max(res2, maximum);
		suma += el;
	}

	cout << max(suma + res2, suma - res1) << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	ll t;
	cin >> t;
	while (t--)
		solve();
}
