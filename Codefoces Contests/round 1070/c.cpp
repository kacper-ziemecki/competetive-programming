#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  int n;
  cin >> n;
  vector<int> lista(n);
  for(auto &el : lista) cin >> el;
  vector<int> even,odd;
  vector<int> prefix_even,prefix_odd;
  for(auto el : lista){
    if(el & 1){
      odd.pb(el);
    } else{
      even.pb(el);
    }
  }
  sort(odd.begin(), odd.end(), greater<>());
  sort(even.begin(), even.end(), greater<>());
  if(!even.empty()) prefix_even.pb(even[0]);
  if(!odd.empty()) prefix_odd.pb(odd[0]);
  if(!even.empty()){
    for(int i = 1; i < even.size(); i++){
      prefix_even.pb(prefix_even[i-1] + even[i]);
    }
  }
  if(!odd.empty()){
    for(int i = 1; i < odd.size(); i++){
      prefix_odd.pb(prefix_odd[i-1] + odd[i]);
    }
  }
  // for(auto el : prefix_odd) cout << el << ' ';
  // cout << endl;
  for(int i = 1; i <= n; i++){
    int evenCnt = even.size();
    int oddCnt = odd.size();
    if(oddCnt == 0){
      cout << 0 << ' ';
      continue;
    }
    int cnt = min(i-1,evenCnt);
    // dbg(cnt);
    if(((i-(cnt+1)) & 1)){ // przed nimi jest nieparzysta liczba pozycji (tez nie starczylo even)
      // dodajemy jednego odd jezeli sie da
      if(oddCnt >= (i-cnt+1)){
        cnt--;
      } else{
        cout << 0 << ' ';
        continue;
      }
    }
    if(cnt < 0) {
      cout << 0 << ' ';
      continue;
    }
    // dbg(prefix_odd.size(), prefix_even.size(), cnt-1);
    cout << prefix_odd[0] + (cnt-1 < 0 ? 0 : prefix_even[cnt-1]) << ' ';
  }
  cout << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  int t;
  cin >> t;
  while(t--)
  solve();
}