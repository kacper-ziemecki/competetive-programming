#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,a,cnt=0;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a;
    if(a == 1) cnt++;
  }
  if(cnt&1 && !(n&1)){
    cout << "NO\n";
  }
  else if(!(cnt&1) && n&1){
    cout << "NO\n";
  }
  else{
    cout << "YES\n";
  }
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