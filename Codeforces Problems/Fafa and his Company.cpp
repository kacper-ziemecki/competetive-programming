#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n,res;
  cin >> n;
  for(int i = 2; i <= n; i++){
  	if(n%i == 0)res++;
  }
  cout << res << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
