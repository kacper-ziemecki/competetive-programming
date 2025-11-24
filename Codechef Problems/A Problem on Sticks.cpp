#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  unsigned long long n;
  cin >> n;
  vector<unsigned long long> list(n, 0);
  for(auto &el : list) cin >> el;
  sort(list.begin(), list.end());
  if(list[0] == 0 && list[n-1] == 0){
    cout << 0 << endl;
    return;
  }
  unsigned long long res = 1;
  for(unsigned long long i = 1; i < n; i++){
    if(list[i] != list[i-1]) res++;
  }
  cout << res << endl;
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