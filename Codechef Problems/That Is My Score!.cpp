#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  unordered_map<int, int> list;
  int a,b;
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    list[a] = max(list[a], b);
  }
  int cnt = 0;
  for(auto el : list){
    if(el.first <= 8){
      cnt+=el.second;
    }
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