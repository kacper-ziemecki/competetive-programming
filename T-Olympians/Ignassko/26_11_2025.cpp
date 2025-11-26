// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define ll long long
// #define ull unsigned long long
// #define ld long double
// void dbg_out() { cout << endl; }
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
// #define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

// ll n,a=LLONG_MAX,b=LLONG_MAX,c=LLONG_MAX;
// const ll maxn = 1e5+1;
// ll lista[maxn][3];

// void solve(){
//   cin >> n;
//   for(ll i = 0; i < n; i++){
//     cin >> lista[i][0] >> lista[i][1] >> lista[i][2];
//     sort(lista[i], lista[i]+3);
//     a = min(a, lista[i][0]);
//     b = min(b, lista[i][1]);
//     c = min(c, lista[i][2]);
//   }
//   cout << a*b*c << endl;
// }

// int main()
// {

//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

//   solve();
// }

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
#define ll long long
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

ll n,a,b,c;
const ll maxn = 1e5+1;
ll dp[maxn];

void solve(){
  cin >> n >> a >> b >> c;
  dp[1] = a;
  for(ll i = 2; i <= n; i++){
    dp[i] = LLONG_MAX;
    for(ll j = 1; j < i; j++){
      // dbg(i,j,i-j,i/j);
      dp[i] = min(dp[i], dp[j]+dp[i-j]+b); //dodawanie
      if(i % j == 0) dp[i] = min(dp[i], dp[j]+dp[i/j]+c);
    }
  }
  for(ll i = 1; i <= n; i++){
    cout << dp[i] << ' ';
  }
  cout << endl;
  max(0, i-k);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // freopen("../in.in", "r", stdin);
  // freopen("../out.out", "w", stdout);

  solve();
}

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n;
const ll maxN = 1e5+1;
ll h[maxN], dp[maxN];

void solve()
{
  cin >> n;
  for(ll i = 0; i < n; i++) cin >> h[i];
  dp[0] = 0;
  for(ll i = 1; i < n; i++){
    dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]), (i-2 >= 0 ? dp[i-2] + abs(h[i]-h[i-2]) : LLONG_MAX));
  }
  cout << dp[n-1] << endl;
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