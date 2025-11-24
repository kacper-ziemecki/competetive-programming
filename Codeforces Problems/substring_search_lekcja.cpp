#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
typedef unsigned long long hs;
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

const hs prime[] = {5586985605742039601,6889537187409766193};
hs hashS[2];
hs hashT[2];
string s,t;

void solve()
{
  cin >> t >> s;
  if(t.size() < s.size()) return;
  for(int i = 0; i < s.size(); i++){
    hashS[0] = hashS[0]*prime[0] + s[i];
    hashS[1] = hashS[1]*prime[1] + s[i];
  }
  hs primeOkna0 = 1, primeOkna1 = 1;
  for(int i = 0; i < s.size(); i++){
    primeOkna0 *= prime[0];
    primeOkna1 *= prime[1];

    hashT[0] = hashT[0]*prime[0] + t[i];
    hashT[1] = hashT[1]*prime[1] + t[i];
  }
  if((hashS[0] == hashT[0] || hashS[1] == hashT[1])){
    cout << 0 << ' ';
  }
  for(int i = s.size(); i < t.size(); i++){
    hashT[0] = hashT[0]*prime[0] + t[i] - primeOkna0*t[i-s.size()];
    hashT[1] = hashT[1]*prime[1] + t[i] - primeOkna1*t[i-s.size()];

    if((hashS[0] == hashT[0] && hashS[1] == hashT[1])){
      cout << i-s.size()+1 << ' ';
    }
  }
  cout << '\n';
}
  

int main()
{  

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

}