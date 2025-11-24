#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  ll n,k;
  cin >> n >> k;
  vector<ll> list(n), one, two;
  for(auto &el : list) cin >> el;
  sort(list.begin(), list.end());
  // for(auto el : list) cout << el << "-";
  // cout << endl;
  one.push_back(list[n-1]);
  two.push_back(list[n-2]);
  for(ll i = n-3; i >= 0; i--){
    if(i < k-1) one.push_back(list[i]);
    else two.push_back(list[i]);
  }
  sort(one.begin(), one.end());
  sort(two.begin(), two.end());
  for(auto el : one) cout << el << " ";
  cout << endl;
  for(auto el : two) cout << el << " ";
  cout << endl;
  cout << one.front()+one.back()+two.front()+two.back() << endl;
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