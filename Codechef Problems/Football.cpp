#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
	int n,res=0;
  cin >> n;
  vector<int> list1(n, 0), list2(n, 0);
  for(auto &el : list1) cin >> el;
  for(auto &el : list2) cin >> el;
  for(int i = 0;i < n;i++){
    res = max(res, list1[i] * 20 - list2[i] * 10);
  }
  cout << res << endl;
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