#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,v1,v2;
  cin >> n >> v1 >> v2;
  if(2 * n * v2 < sqrt(2) * n * v1){
    cout << "Elevator\n";
  }
  else{
    cout << "Stairs\n";
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