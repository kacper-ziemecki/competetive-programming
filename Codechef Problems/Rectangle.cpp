#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  vector<int> list = {a,b,c,d};
  sort(list.begin(), list.end());
  if(list[0] == list[1] && list[2] == list[3]){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
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