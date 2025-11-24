#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,temp;
  cin >> n;
  vector<vector<int>> list(n, vector<int>(n, 0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> temp;
      list[i][j] = temp;
    }
  }
  int res = 0;
  for(int i = 0; i < n; i++){
    temp = 0;
    int x = i;
    for(int j = 0; j < n-i; j++){
      temp += list[x][j];
      x++;
    }
    res = max(res, temp);
  }
  for(int i = 0; i < n; i++){
    temp = 0;
    int x = i;
    for(int j = 0; j < n-i; j++){
      temp += list[j][x];
      x++;
    }
    res = max(res, temp);
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