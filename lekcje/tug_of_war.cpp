#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
#define endl '\n'
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,suma;
const int maxN = 1e5+1;
bool flag = false;
bitset<100> check;
bitset<10011> bit;
int lista[maxN];



void solve()
{
  cin >> n;
  flag = false; suma = 0;
  check.reset();
  bit.reset();
  for(int i = 0; i < n; i++){
    cin >> lista[i];
    suma += lista[i];
    if(check[lista[i]]) flag = true;
    check[lista[i]] = 1;
  }
  if(flag){
    cout << "YES\n";
    return;
  }
  bit[0] = 1;
  for(int i = 0; i < n; i++) bit = bit | (bit << lista[i]);
  for(int i = bit.size()-1; i > 0; i--){
    if(i&1) continue;
    if(bit[i]!=0 && bit[i/2]!=0){
      cout << "YES\n"; return;
    }
  }
  cout << "NO\n"<< endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >>t;
  while(t--)
    solve();

}