#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(vector<ll> &tab)
{
  ll k;
  cin >> k;
  if(k == 1){
    cout << "1 1\n";
    return;
  }
  for(ll i = 1; i < tab.size(); i++){
    if(tab[i-1] < k && tab[i] >= k){
      if(k-tab[i-1] <= i+1){
        cout << k-tab[i-1] << " " << i+1 << endl;
        return;
      } else{
        cout << i+1 << " " << tab[i]-k+1 << endl;
        return;
      }
    }
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  vector<ll> tab{1};
  ll cnt = 1;
  for(ll i = 1;tab.back() <= 1e9; i++){
    cnt+=2;
    tab.push_back(tab.back()+cnt);
  }

  ll t;
  cin >> t;
  while(t--)
  solve(tab);
  
}