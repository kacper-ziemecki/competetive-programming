#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,k,a,b,time=0,res=0;
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    time += a;
    res += a*b;
    if(time - a < k){
      res -= min((k - (time - a)), a) * b;
    }
  }
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