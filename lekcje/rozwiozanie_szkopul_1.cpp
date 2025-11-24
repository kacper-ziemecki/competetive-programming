// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// using namespace std;
// #define ll long long
// #define ull unsigned long long
// #define ld long double
// #define pb push_back
// void dbg_out() { cout << endl; }
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
// #define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


// void solve()
// {
//   ll n;
//   cin >> n;
//   vector<ll> left(n),right(n);
//   for(ll i = 0; i < n; i++){
//     cin >> left[i] >> right[i];
//   }
//   multiset<ll> st;
//   st.emplace(0);
//   for(ll i = 0; i < n; i++){
//     if(st.upper_bound(right[i]) != st.end()){
//       st.erase(st.upper_bound(right[i]));
//     }
//     st.insert(left[i]);
//     cout << st.size()-1 << " ";
//   }
//   cout << endl;
// }
  

// int main()
// {

//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);

//   ll t;
//   cin >> t;
//   while(t--)
//     solve();
// }

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
  cout << "Zrobione\n";
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}