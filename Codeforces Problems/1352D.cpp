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
  ll n;
  cin >> n;
  vector<ll> list(n), prefix(n), suffix(n);
  for(auto &el : list) cin >> el;
  prefix[0] = list[0];
  suffix[n-1] = list[n-1];
  for(ll i = 1; i < n; i++){
    prefix[i] = prefix[i-1] + list[i];
    suffix[n-i-1] = suffix[n-i] + list[n-i-1];
  }

  ll idx1=-1,idx2=n,cur=0,cnt=0;
  for(ll i = 0;idx1+1 < idx2;i++){
    ll idx;
    cnt++;
    if(i&1){
      idx = n-1-(upper_bound(suffix.rbegin(), suffix.rend(), cur+(idx2 < n ? suffix[idx2] : 0))-suffix.rbegin());
      // dbg(idx, cur, cur)
      if(idx <= idx1){
        idx2 = idx1+1;
        break;
      }
      cur = suffix[idx] - (idx2 < n ? suffix[idx2] : 0);
      idx2 = idx;
    } else{
      idx = upper_bound(prefix.begin(), prefix.end(), cur+(idx1 > -1 ? prefix[idx1] : 0))-prefix.begin();
      if(idx >= idx2){
        idx1 = idx2-1;
        break;
      }
      cur = prefix[idx] - (idx1 > -1 ? prefix[idx1] : 0);
      idx1 = idx;
    }
    // dbg(cnt, idx, idx1, idx2, cur);
  }
  cout << cnt << " " << prefix[idx1] << " " << (idx2 >= n ? 0 : suffix[idx2]) << endl;
  // dbg(cnt,idx1,idx2,prefix[idx1],suffix[idx2]);
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
  while(t--) solve();
}