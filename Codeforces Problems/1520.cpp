#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
	int n;
	cin >> n;
	string text;
	cin >> text;
	vector<int> list('z' - 'a' + 1, -1);
	for (int i = 0; i < n; i++)
	{
		if (list[text[i] - 'A'] != -1 && list[text[i] - 'A'] != i - 1)
		{
			cout << "NO\n";
			return;
		}
		list[text[i] - 'A'] = i;
	}
	cout << "YES\n";
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

	int t;
	cin >> t;
	while (t--)
		solve();
}