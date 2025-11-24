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
  ll n,q;
  cin >> n >> q;
  vector<ll> list(n, 0ll);
  for(auto &el : list) cin >> el;
  ll cnt1=0,cnt2=0;
  ll suma1=0,suma2=0;
  for(auto el : list){
    if(el&1){
      cnt2++;
      suma2+=el;
    }
    else{
      cnt1++;
      suma1+=el;
    } 
  }
  ll a=0,b=0;
  pair<ll, ll> tmp;
  for(ll i = 0; i < q; i++){
    cin >> tmp.first >> tmp.second;
    if(tmp.first == 0){
      suma1 += cnt1*tmp.second;
      if(tmp.second&1){
        cnt2 += cnt1;
        cnt1 = 0;
      }
    } else{
      suma2 += cnt2*tmp.second;
      if(tmp.second&1){
        cnt1 += cnt2;
        cnt2 = 0;
      }
    }
    cout << suma1+suma2 << endl;
  } 
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

  ll t;
  cin >> t;
  while(t--)
  solve();
  
} 