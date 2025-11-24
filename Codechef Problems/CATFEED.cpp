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
  cin >> m >> n;
  vector<ll> list1(n), list2(m+1, 0);
  for(auto &el : list1) cin >> el;
  for(auto el : list1){
    // dbg(list2[el]);
    // dbg(list2[min_element(list2.begin()+1, list2.end())-list2.begin()]);

    if(list2[el] > list2[min_element(list2.begin()+1, list2.end())-list2.begin()]){
      cout << "NO\n";
      return;
    }
    list2[el]++;
  }
  cout << "YES\n";
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