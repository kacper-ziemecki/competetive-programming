#include <bits/stdc++.h>
using namespace std;
// #define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool same_sum(ll l, ll r){
  ll a,b;
  cout <<"1 " << l << ' ' << r << endl;
  cin >> a;
  cout <<"2 " << l << ' ' << r << endl;
  cin >> b;
  return a == b;
}

void solve(){
  ll n;
  cin >> n;
  ll lewo,prawo;
  ll l=1,r=n;
  while(l < r){
    ll mid = (l+r)/2;
    if(!same_sum(l,mid)) r = mid;
    else l = mid+1;
  }
  lewo = r;
  ll suma = n*(n+1)/2;
  ll nowaSuma;
  cout << "2 " << 1 << ' ' << n << endl;
  cin >> nowaSuma;
  // dbg(suma, nowaSuma, lewo);
  prawo = lewo + (nowaSuma-suma)-1;
  cout << "! " << lewo << ' ' << prawo << endl;
}

int main()
{

//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  int t;
  cin >> t;
  while(t--)
  solve();
}