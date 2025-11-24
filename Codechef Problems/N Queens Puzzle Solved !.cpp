#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
	double n;
  cin >> n;
  cout << round(pow((0.143 * n), n)) << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  ll t;
  cin >> t;
  while(t--) solve();
}