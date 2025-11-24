#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  vector<int> list(26, 0);
  for(auto &el : list) cin >> el;
  string text;
  cin >> text;
  vector<bool> temp(26, false);
  for(auto el : text){
    temp[el - 'a'] = true;
  }
  int res = 0;
  for(int i = 0; i < 26; i++){
    if(!temp[i]) {
      res += list[i];
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