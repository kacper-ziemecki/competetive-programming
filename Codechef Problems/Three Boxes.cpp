#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  vector<int> list = {a,b,c};
  sort(list.begin(), list.end());
  if(list[0] + list[1] + list[2] <= d){
    cout << 1 << endl;
  }
  else if(list[0] + list[1] <= d){
    cout << 2 << endl;
  }
  else{
    cout << 3 << endl;
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