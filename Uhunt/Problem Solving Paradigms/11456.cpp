#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
 
// vector<int> p,A;

// void print_LIS(int i){
//   if(p[i]==-1) cout << " " << A[i] << endl;
//   print_LIS(p[i]);
//   cout << " " << A[i];
// }

// void LIS(){
//   int k = 0, lis_end = 0;
//   vector<int> L(n, 0), L_id(n, 0);
//   p.assign(n, -1);

//   for(int i = 0; i < n; i++){
//     int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
//     L[pos] = A[i];
//     L_id[pos] = i;
//     p[i] = pos ? L_id[pos-1] : -1;
//     if(pos == k){
//       k++;
//       lis_end = i;
//     }
//   }
//   cout << "Final LIS is of length: " << k << endl;
//   print_LIS(lis_end);
// }


void solve(){
  ll n;
  cin >> n;
  vector<ll> list(n),dp1(n,1),dp2(n,1);
  for(auto &el : list) cin >> el;
  reverse(list.begin(), list.end());
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < i; j++){
      if(list[i] > list[j]){
        dp1[i] = max(dp1[i],dp1[j]+1);
      } else if(list[i] < list[j]){
        dp2[i] = max(dp2[i],dp2[j]+1);
      }
    }
  }
  ll res=0;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      if(list[j] < list[i]){
        res = max(res, dp1[j]+dp2[i]);
      }else if(list[j] == list[i]){
        res = max(res, dp1[j]+dp2[i]-1);
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
 
#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif
  
  ll t;
  cin >> t;
  while(t--) solve();
}