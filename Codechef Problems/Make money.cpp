#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b,c,d,res=0;
  cin >> a >> b >> c;
  for(int i = 0; i < a; i++){
    cin >> d;
    if(b-d > c){
      res += b-c;
    }
    else{
      res += d;
    }
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