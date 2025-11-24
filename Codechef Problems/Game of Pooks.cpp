#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  if(n == 2){
    cout << 1 << endl;
  }
  else if(n == 3){
    cout << 2 << endl;
  }
  else if(n == 4){
    cout << 3 << endl;
  }
  else{
    cout << n << endl;
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