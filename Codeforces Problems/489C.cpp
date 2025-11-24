#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve(){
  ll n,m,cnt=0;
  cin >> n >> m;
  if(n==1 && m==0){
    cout << "0 0\n"; return;
  }
  if(m==0 || n*9 < m){
    cout << "-1 -1\n"; return;
  }
  string one="",two="";
  for(ll i = 0; i < n; i++){
    ll tmp = min(9ll, m-cnt);
    cnt += tmp;
    one += char(tmp+'0');
  }
  cnt=0;
  for(ll i = 0; i < n-1; i++){
    ll tmp = min(9ll, max(0ll,m-cnt-1));
    cnt += tmp;
    two += char(tmp+'0');
  }
  two += char(min(9ll, max(0ll,m-cnt))+'0');
  reverse(two.begin(), two.end());
  cout << two << " " << one << endl;
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