#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
	int n,a,minimum=INT_MAX;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a;
    minimum = min(minimum, a);
  }
  cout << minimum << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("input.txt", "r", stdin);
  ll t;
  cin >> t;
  while(t--) solve();
}