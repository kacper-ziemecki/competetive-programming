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


void solve(ll n){
  vector<vector<ll>> list;
  vector<ll> tmp{0,0,0};
  for(ll i = 0; i < n; i++){
    cin >> tmp[0] >> tmp[1] >> tmp[2];
    sort(tmp.begin(), tmp.end());
    do{
      list.push_back(tmp);
    }
    while(next_permutation(tmp.begin(), tmp.end()));
  }
  sort(list.begin(), list.end());
  n = list.size();
  vector<ll> dp(n, 0);
  ll res=0;
  for(ll i = 0; i < n; i++){
    dp[i] = list[i][2];
    for(ll j = 0; j < i; j++){
      if(list[j][0] < list[i][0] && list[j][1] < list[i][1]){
        dp[i] = max(dp[i],dp[j]+list[i][2]);
      }
    }
    res = max(res, dp[i]);
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
  
  ll n;
  ll t=0;
  while(cin >> n, n != 0){
    cout << "Case " << ++t << ": maximum height = "; 
    solve(n);
  }
}