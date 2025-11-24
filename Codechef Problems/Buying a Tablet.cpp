#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,b,c,d,e,res=0;
  cin >> n >> b;
  for(int i = 0; i < n; i++){
    cin >> c >> d >> e;
    if(e <= b){
      res = max(res, c*d);
    }
  }
  if(res){
    cout << res << endl;
  }
  else{
    cout << "no tablet\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}