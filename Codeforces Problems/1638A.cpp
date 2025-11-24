#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  ll index1 = -1, index2 = -1;
  for(ll i = 0; i < n; i++){
    if(list[i] != i+1){
      index1 = i;
      break;
    }
  }
  if(index1 != -1){
    for(ll i = 0; i < n; i++){
      if(list[i] == index1+1){
        index2 = i;
      }
    }
    // dbg(index1, index2);
    reverse(list.begin() + index1, list.begin() + index2+1);
  }
  for(auto el : list) cout << el << " ";
  cout << endl;
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

  ll t;
  cin >> t;
  while(t--)
  solve();  
  
} 