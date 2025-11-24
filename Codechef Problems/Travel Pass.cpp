#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,a,b;
  cin >> n >> a >> b;
  string text;
  cin >> text;
  int res = 0;
  for(auto el : text){
    if(el == '0'){
      res += a;
    }
    else{
      res += b;
    }
  }
  cout << res << endl;
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