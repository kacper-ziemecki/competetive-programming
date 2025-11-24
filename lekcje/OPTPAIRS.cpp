#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(){
  ll n;
  cin >> n;
  ll res = 0;
  set<ll> st;
  for(ll i = 1; i*i <= n; i++){
    if(n % i == 0){ st.emplace(i); st.emplace(n/i); }
  }
  for(auto el : st){
    if(el == n) continue;
    // dbg(el);
    if(el*2 != n) res += 2;
    else res += 1;
  }
  cout << res<< endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  ll t;
  cin >> t;
  while(t--)
  solve();
}