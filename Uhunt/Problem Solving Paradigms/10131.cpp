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

bool comparator(vector<ll> one, vector<ll> two){
  if(one[0] != two[0]) return (one[0] < two[0]);
  else return (one[1] > two[1]);
}

void solve(){
  vector<vector<ll>> list;
  ll a,b,i=0;
  while(cin>>a>>b){
    list.push_back({a,b,i});
    if(cin.eof()) break;
    i++;
  }
  sort(list.begin(), list.end(), comparator);
  vector<ll> dp(list.size(), 1), p(list.size(), -1);
  ll lis_end=0, k=1;
  // for(auto el : list) cout << el[0] << " " << el[1] << " " << el[2] << endl;
  for(ll i = 0; i < dp.size(); i++){
    for(ll j = 0; j < i; j++){
      if(list[j][0] < list[i][0] && list[j][1] > list[i][1] && dp[j]+1 > dp[i]){
        dp[i] = dp[j]+1;
        p[i] = j;
        if(dp[i] > k){
          k = dp[i];
          lis_end = i;
        }
      }
    }
  }
  vector<ll> res;
  while(lis_end != -1){
    res.push_back(list[lis_end][2]+1);
    lis_end = p[lis_end];
  }
  cout << res.size() << endl;
  reverse(res.begin(), res.end());
  for(auto el : res) cout << el << endl;
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
  
  solve();
}