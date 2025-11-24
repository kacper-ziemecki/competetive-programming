#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int a,b,c;
    cin >> a >> b >> c;
    if(a&1){
      if(c&1){
        cout << b/2 << endl;
      }
      else{
        cout << (b+2-1)/2 << endl;
      }
    }
    else{
      if(c&1){
        cout << (b+2-1)/2 << endl;
      }
      else{
        cout << b/2 << endl;
      }
    }
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