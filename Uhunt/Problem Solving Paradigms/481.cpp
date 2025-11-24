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
  vector<ll> list;
  ll a;
  while(!cin.eof()){
    cin >> a;
    list.push_back(a);
  }
  ll n = list.size();
  vector<ll> l(n, 0), l_id(n, 0), p(n, -1);
  ll k=0,pos,lis_end;
  for(ll i = 0; i < n; i++){
    pos = lower_bound(l.begin(), l.begin()+k, list[i])-l.begin();
    l[pos] = list[i];
    l_id[pos] = i;
    p[i] = pos ? l_id[pos-1] : -1;
    if(pos==k){
      k++;
      lis_end = i;
    }
  }
  vector<ll> res;
  while(lis_end!=-1){
    res.push_back(list[lis_end]);
    lis_end = p[lis_end];
  }
  reverse(res.begin(), res.end());
  cout << k << endl;
  cout << "-\n";
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