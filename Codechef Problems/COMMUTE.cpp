#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<vector<ll>> list(n, vector<ll>(3, 0));
  for(auto &sub : list){
    for(auto &el : sub){
      cin >> el;
    }
  }
  ll time = list[0][1] + list[0][0];
  for(ll i = 1; i < n; i++){
    if(time < list[i][0]) time = list[i][0];

    if((time - list[i][0])%list[i][2] == 0){
      time+=list[i][1];
    }
    else{
      time += list[i][2] - ((time - list[i][0])%list[i][2]);
      time += list[i][1];
    }
  }
  cout << time << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  
  ll t;
  cin >> t;
  while(t--)
  solve();
}