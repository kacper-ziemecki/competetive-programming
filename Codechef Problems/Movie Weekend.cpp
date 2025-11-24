#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  vector<int> list1(n, 0), list2(n, 0), res(3, 0);
  for(auto &el : list1) cin >> el;
  for(auto &el : list2) cin >> el;
  for(int i = 0; i < n; i++){
    if(list1[i] * list2[i] > res[0] * res[1]){
      res[0] = list1[i];
      res[1] = list2[i];
      res[2] = i;
    }
    else if(list1[i] * list2[i] == res[0] * res[1] && list2[i] > res[1]){
      res[0] = list1[i];
      res[1] = list2[i];
      res[2] = i;
    }
  }
  cout << res[2] + 1 << endl;
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