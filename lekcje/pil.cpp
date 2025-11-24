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
  ll t,n,res=1;
  cin >> t >> n;
  vector<ll> list(n);
  for(auto &el : list) cin >> el;
  deque<ll> mx,mn;
  mx.push_back(0); mn.push_back(0);
  ll left = 0;
  for(ll right = 1; right < n; right++){

    while(!mx.empty() && list[mx.back()] <= list[right]) mx.pop_back();
    mx.push_back(right);
    while(!mn.empty() && list[mn.back()] >= list[right]) mn.pop_back();
    mn.push_back(right);

    while(list[mx.front()]-list[mn.front()] > t){
      if(mx.front() == left) mx.pop_front();
      if(mn.front() == left) mn.pop_front();
      left++;
    }
    res = max(res, right-left+1);
  }
  cout << res << endl;
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}