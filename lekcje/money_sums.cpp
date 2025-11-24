#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n;
const int maxN = 101, maxSum= 1e5+1;
int coins[maxN];
bitset<maxSum> bit;
set<int> res;

void solve()
{
  cin >> n;
  for(int i = 0; i < n; i++) cin >> coins[i];
  bit[0] = 1;
  for(int i = 0; i < n; i++){
    bit |= bit << coins[i];

    for(int j = 1; j < maxSum; j++){
      if(bit[j]) res.emplace(j);
    }
  }
  cout << res.size() << endl;
  for(auto el : res) cout << el << " ";
  cout << endl;
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

}