#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
 ll n,k;
 cin >> n >> k;
 string s;
 cin >> s;
 ll left=0;
 ll sum = (s[0] == 'a' ? 0 : 1);
 for(ll right = 1; right < n; right++){
  sum += (s[i] == 'a' ? 0 : 1);
  while(sum > k && left){
    sum -= (s[left] == 'a' ? 0 : 1);
    left++;
  }
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

  solve();
}