#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


ll cost(vector<ll> &list, ll m){
  ll res = 0;
  for(auto el : list) res += abs(el-m);
  return res;
}

ll helper(vector<ll>& list){
  // for(ll i = 0; i <= 10; i++) cout << cost(list,i) << " ";
  // cout << endl;

  ll l = 0, r = 1e10;
  while(l+2 < r){
    ll m1 = l + (r-l)/3;
    ll m2 = r - (r-l)/3;
    // dbg(l,m1,m2,r);
    if(cost(list,m1) < cost(list,m2)){
      r = m2;
    } else if(cost(list,m1) > cost(list,m2)){
      l = m1;
    } else{
      l = m1;
      r = m2;
    }
  }
  pair<ll,ll> mn = {LLONG_MAX,0};
  ll right = 0, left = LLONG_MAX;
  for(ll i = l; i <= r; i++){
    if(cost(list,i) < mn.first){
      mn = {cost(list,i),i};
    }
  }
  // dbg(mn.first, mn.second);
  // cout << l << " " << r << endl;

  l = mn.second, r = 1e10;
  while(l<r){
    ll m = (l+r+1)/2;
    if(cost(list,m) > mn.first) r = m-1;
    else l = m;
  }
  right = l;
  l = 0, r = mn.second;
  while(l<r){
    ll m = (l+r)/2;
    if(cost(list,m) > mn.first) l = m+1;
    else r = m;
  }
  left = r;
  // dbg(left, right);

  return right-left+1;
}

void solve()
{
	ll n,tmp;
  cin >> n;
  vector<ll> x(n), y(n);
  for(ll i = 0; i < 2*n; i++){
    cin >> tmp;
    if(i&1) y[i/2] = tmp;
    else x[i/2] = tmp;
  }
  
  ll res1 = helper(x);
  ll res2 = helper(y);
  cout << res1 * res2 << endl;
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