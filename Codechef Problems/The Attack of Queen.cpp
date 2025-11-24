#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,x,y;
  cin >> n >> x >> y;
  int res = 0;
  res += n-1;
  res += n-1;
  res += min(x-1,y-1);
  res += min(x-1, n-y);
  res += min(n-x,y-1);
  res += min(n-x, n-y);
  cout << res << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}