#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n,a;
  cin >> n >> a;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  for(int i = 0; i < 31; i++){
    vector<ll> res;
    bool flag = false;
    for(auto el : list){
      if(((a >> i)&1) && ((el >> i)&1)){
        res.push_back(el);
        flag = true;
      }
      else if(!((a >> i)&1)){
        if((el >> i)&1){
          res.push_back(el);
        }
        else{
          res.push_back(el);
          flag = true;
        }
      }
    }
    list = res;
    if(!flag){
      cout << "NO\n";
      return;
    }
  }
  ll fin = list[0];
  for(auto el : list){
    fin &= el;
  }

  if(fin == a){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();

}