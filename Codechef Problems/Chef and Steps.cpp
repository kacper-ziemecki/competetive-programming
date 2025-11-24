#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b,c;
  cin >> a >> b;
  for(int i = 0; i < a; i++){
    cin >> c; 
    if(c % b == 0){
      cout << 1;
    }
    else{
      cout << 0;
    }
  }
  cout << endl;
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