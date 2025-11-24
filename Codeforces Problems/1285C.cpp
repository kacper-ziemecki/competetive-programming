#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

pair<ll,ll> helper(ll i, vector<ll> &list, ll one=1, ll two=1){
  if(i==list.size()) return {one, two};
  pair<ll,ll> res1 = helper(i+1, list, one*list[i], two);
  pair<ll,ll> res2 = helper(i+1, list, one, two*list[i]);

  if(max(res1.first,res1.second) < max(res2.first,res2.second)){
    return res1;
  } else{
    return res2;
  }
}

void solve()
{
 ll n;
 cin >> n;
 vector<ll> list;
 for(ll i = 2; i*i <= n; i++){
  if(n%i) continue;

  list.push_back(1);
  while(n%i==0){
    list.back()*=i;
    n/=i;
  }
 }
 if(n > 1) list.push_back(n);
 pair<ll,ll> res = helper(0, list);
 cout << res.first << " " << res.second << endl;
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

  solve();  
  
} 