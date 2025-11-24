#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll a,b,x,y;
  cin >> a >> b >> x >> y;
  if(a&1 && b == a-1){ cout << y << endl;}
  else if(a <= b){
    // dbg((b-1)/2-(a-1)/2, a, b);
    cout << min((b-a)*x, ((b-1)/2-(a-1)/2) * y + (b-a-((b-1)/2-(a-1)/2))*x) << endl;
  }
  else{ cout << -1 << endl; }
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