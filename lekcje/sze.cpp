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


bool comparator(vector<ld>& one, vector<ld>& two){
  return (two[0]*one[1] <= one[0]*two[1]);
}

void solve()
{
  ll n;
  cin >> n;
  vector<vector<ld>> list(n, vector<ld>(3, 0));
  for(ll i = 0; i < n; i++){
    cin >> list[i][0] >> list[i][1];
    list[i][2] = i+1;
  }
  sort(list.begin(), list.end(), comparator);
  for(auto el : list) cout << el[2] << endl;
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}