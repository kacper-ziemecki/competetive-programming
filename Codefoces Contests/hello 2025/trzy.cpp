#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool possible1(ll c, ll j, ll l, ll r){
  if(c + (1<<j) <= r) return true;
  return false;
}
bool possible0(ll c, ll j, ll l, ll r){
  if(c + ((1<<j)-1) >= l) return true;
  return false;
}

void solve()
{
  ll l,r;
  cin >> l >> r;

  ll a=r,b=r,c=r,cur;
  ll power = 0, power1=0,cnt=0;
  while((r & ~(1<<(power1)))+cnt >= l && power1 <= 32){
    // dbg(r,(r & ~(1<<(power1))));
    if((r>>power1)&1) power = power1;
    else cnt += 1<<power1;
    power1++;
  }
  // dbg(power);
  b ^= (1<<power);
  // dbg(a,b,c);
  // dbg(b);
  for(ll j = power-1; j >= 0; j--){
    if(!((b>>j)&1)) b |= (1<<j);
    if((c>>j)&1) c ^= (1<<j);
  }
  // dbg(a,b,c);
  if(c == a) c ^= (1<<power);
  // for(ll j = 30; j >= 0; j--){
  //   if((!((a>>j)&1) && possible1(c,j,l,r)) || (((a>>j)&1) && !possible0(c,j,l,r))){
  //     ll mask = 1<<j;
  //     c = c|mask;
  //   } 
  // }
  // if(c == b) c--;
  // cur = (a^b)+(a^c)+(b^c);
  // dbg((98^85)+(98^76)+(85^76));
  // dbg(cur);
  cout << a << " " << b << " " << c << endl;
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