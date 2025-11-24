#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll factorial(ll n){
  if(n == 0) return 1;
  return n * factorial(n-1);
}

ld permutation(ll n, ll r){
  return factorial(n)/(factorial(r)*factorial(n-r));
}

ld binpow(ll a, ll b){
  ld res = 1;
  while(b){
    if(b&1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}

void solve(){
  string s1,s2;
  cin >> s1 >> s2;
  ll plus1=0,plus2=0,dont=0,three;
  ld res;
  for(auto el : s1){
    if(el == '+') plus1++;
  }
  for(auto el : s2){
    if(el == '+') plus2++;
    if(el == '?') dont++;
  }
  three = plus1-plus2;

  if(three < 0 || s1.size()-plus1 < s2.size()-plus2-dont){
    res = 0;
  } else{
    res = permutation(dont, three)/binpow(2, dont);
  }
  cout << fixed << setprecision(9) << res << endl;
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