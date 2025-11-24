#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  string one,two;
  cin >> one >> two;
  int res = 0;
  bool flag = false;
  for(int i = 0; i < n; i++){
    if(!flag && one[i] == two[i]){
      res++;
    }
    else if(!flag && two[i] != 'N' && one[i] != two[i]){
      flag = true;
    }
    else if(flag){
      flag = false;
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