#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,sum,times,res=0;
  cin >> n;
  vector<int> list(n, 0);
  for(auto &el : list) cin >> el;
  for(int i = 0; i < n; i++){
    sum = 0;
    times = 1;
    for(int j = i; j < n; j++){
      sum += list[j];
      times *= list[j];
      if(sum == times) res++;
    }
  }
  cout << res << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}