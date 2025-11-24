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
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  map<ll,ll> cnt;
  for(auto el : list) cnt[el]++;
  priority_queue<ll> pq;
  for(auto el : cnt) pq.push(el.second);
  ll one,two;
  while(pq.size() >= 2){
    one = pq.top(); pq.pop();
    two = pq.top(); pq.pop();
    one--; two--;
    if(one>0) pq.push(one);
    if(two>0) pq.push(two);
  }
  ll res = 0;
  if(!pq.empty()) res = pq.top();
  cout << res << endl;
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