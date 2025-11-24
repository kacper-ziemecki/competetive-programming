#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n,m,a;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> a;
    if(m - a >= 0){
      m -= a;
      cout << '1';
    }
    else{
      cout << '0';
    }
  }
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--)
    solve();
}