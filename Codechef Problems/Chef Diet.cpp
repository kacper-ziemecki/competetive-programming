#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,k,a,cnt=0;
  cin >> n >> k;
  bool flag = true;
  for(int i = 0; i < n; i++){
    cin >> a;
    cnt += a;
    cnt -= k;
    if(cnt < 0 && flag){
      cout << "NO " << i+1 << endl;
      flag = false;
    }
  }
  if(flag){
    cout << "YES\n";
  }
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