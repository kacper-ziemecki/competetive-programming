#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  ll n,res=0;
  cin >> n;
  vector<int> list(n, 0);
  for(auto &el : list) cin >> el;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      
      if(list[i]&list[j] == list[i]){
        cout << i << " " << j << endl;
        res++;
      } 

    } 
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