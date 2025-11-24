#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b;
  cin >> a >> b;
  int maks = 0;
  int res = 0;
  int temp;
  for(int i = 0; i < a; i++){
    cin >> temp;
    maks = max(maks, temp);
    res += (temp+b-1)/b;
  }
  cout << min(maks, res) << endl;
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