#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  vector<int> list(n, 0), res(n, 0);
  for(auto &el : list) cin >> el;
  for(int i = 0; i < n; i++){
    int temp = 0;
    for(int j = 0; j < n; j++){
      if(j != i && list[i] < list[j]) temp++;
    }
    res[i] = temp;
  }
  for(auto el : res) cout << el << " ";
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}