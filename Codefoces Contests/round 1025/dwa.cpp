#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

// ll iter=0;

ll helper(ll n, ll m, ll a, ll b, bool flag=true){
  // dbg(n,m,a,b);
  if(!flag){
    ll res = 0;
    while(n != 1){
      res++;
      n = (n+1)/2;
    }
    while(m != 1){
      res++;
      m = (m+1)/2;
    }
    return res;
  }
  if(n == 1 && m == 1) return 0;
  ll res = LLONG_MAX;
  if(m-b+1 != m) res = min(res, helper(n,m-b+1,(n+1)/2,(m-b+1+1)/2,false));
  if(n-a+1 != n) res = min(res, helper(n-a+1,m,(n-a+1+1)/2,(m+1)/2,false));
  if(a != n) res = min(res, helper(a,m,(a+1)/2,(m+1)/2,false));
  if(b != m) res = min(res, helper(n,b,(n+1)/2,(b+1)/2,false));

  return res+1;
}

void solve()
{
  ll n,m,a,b;
  cin >> n >> m >> a >> b;
  ll res = 0;
  cout << helper(n,m,a,b) << endl;
  // while(n != 1 || m != 1){
  //   ll pole1 = (b-1) * n;
  //   ll pole2 = m * (n-a);
  //   ll pole3 = (a-1) * m;
  //   ll pole4 = (m-b) * n;
  //   ll mx = max({pole1, pole2, pole3, pole4});
  //   if(pole1 == mx){
  //     m -= b-1;
  //   } else if(pole2 == mx){
  //     n -= (n-a);
  //   } else if(pole3 == mx){
  //     n -= a-1;
  //   } else if(pole4 == mx){
  //     m -= (m-b);
  //   }
  //   a = (n+1)/2;
  //   b = (m+1)/2;
  //   res++;
  //   // dbg(n,m,a,b);
  // }
  // cout << res << endl;
  // dbg(res);
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
  while(t--)
  solve();
}