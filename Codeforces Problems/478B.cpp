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
  ll n,m;
  cin >> n >> m;
  ll one=((n/m)*(n/m-1))/2 * (m-1) + ((n-((m-1)*(n/m)))*(n-((m-1)*(n/m))-1))/2;
  if(m != 1 && n%(m-1) != 0){
    one = min(one, (((n+m-1)/m)*((n+m-1)/m-1))/2 * (m-1) + (n-((m-1)*((n+m-1)/m)))*(n-((m-1)*((n+m-1)/m))-1)/2);
  }
  ll two=((n-m)*(n-m+1))/2;
  cout << one << " " << two << endl;
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