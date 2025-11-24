#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  vector<int> res(n, 0);
  int j = 1;
  for(int i = 0; i < n/2; i++){
    res[i] = j;
    j++;
    res[n-1-i] = j;
    j++;
  }
  for(auto el : res) cout << el << " ";
  cout << endl;
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