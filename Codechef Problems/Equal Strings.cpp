#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  unordered_map<char, bool> list;
  string one,two;
  cin >> one >> two;
  for(int i = 0; i < n; i++){
    if(one[i] != two[i]){
      list[two[i]] = true;
    }
  }
  int cnt = 0;
  for(auto el : list){
    if(el.second) cnt++;
  }
  cout << cnt << endl;
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