#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool check(ll b,ll c,ll d,ll i){
  if(!((b>>i)&1) && ((c>>i)&1) && ((d>>i))&1) return false;
  if(((b>>i)&1) && !((c>>i)&1) && !((d>>i))&1) return false;
  return true;
}
void convert(ll &res,ll &b,ll &c,ll &d,ll i){
  if(!((b>>i)&1) && !((c>>i)&1) && ((d>>i))&1) res |= 1<<i;
  if(((b>>i)&1) && ((c>>i)&1) && !((d>>i))&1) res |= 1<<i;
}

void solve()
{
  ll b,c,d,res=0;
  cin >> b >> c >> d;
  for(ll i = 0; i < 63; i++){
    if(!check(b,c,d,i)){cout<<-1<<endl;return;}
    convert(res,b,c,d,i);
  }
  cout<<res<<endl;
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