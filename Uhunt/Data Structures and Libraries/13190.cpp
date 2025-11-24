#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
  ll n,k;
  cin >> n >> k;
  priority_queue<tuple<ll, ll, string, ll>, vector<tuple<ll, ll, string, ll>>, greater<tuple<ll, ll, string, ll>>> pq;
  string text;
  ll number;
  for(ll i = 0; i < n; i++){
    cin >> text >> number;
    pq.push({number, i, text, number});
  }
  for(ll i = 0; i < k; i++){
    tuple<ll, ll, string, ll> data = pq.top();
    cout << get<0>(data) << " " << get<2>(data) << endl;
    pq.pop();
    tuple<ll, ll, string, ll> res = make_tuple(get<0>(data)+get<3>(data), get<1>(data), get<2>(data), get<3>(data));
    pq.push(res);
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../input.txt", "r", stdin);
// #endif

  ll t;
  cin >> t;
  while(t--) solve();
}