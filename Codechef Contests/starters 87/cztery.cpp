#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,minimum=INT_MAX;
  cin >> n;
  vector<int> list(n, 0);
  for(auto &el : list){
    cin >> el;
    minimum = min(minimum, el);
  }
  for(auto &el: list){
    el -= minimum;
  }
  int suma = minimum;
  for(auto el : list){
    suma *= el;
  }
  if(suma&1){
    cout << "CHEF\n";
  }
  else{
    cout << "CHEFINA\n";
  }
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