#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,h,mx=0;
map<vector<int>, int> dist;
vector<int> lista, new_cur;

bool check(vector<int> &l){
  for(int i = 0; i < n-1; i++){
    if(abs(l[i+1]-l[i]) > h) return false;
  }
  return true;
}


void solve(){
  cin >> n >> h;
  lista.resize(n);
  for(auto &el : lista){
    cin >> el;
    mx = max(mx, el);
  }
  if(h == 0){
    int res = INT_MAX;
    for(int wysokosc = 0; wysokosc <= mx; wysokosc++){
      int cur = 0;
      for(int i = 0; i < n; i++){
        cur += abs(lista[i] - wysokosc);
      }
      res = min(res, cur);
    }
    cout << res << endl;
  } else{
    queue<vector<int>> q;
    q.push(lista);
    dist[lista] = 0;
    while(!q.empty()){
      vector<int> cur = q.front(); q.pop();

      if(check(cur)){
        cout << dist[cur] << endl;
        return;
      }
      for(int i = 0; i < n; i++){
        if(cur[i] > 0){
          new_cur = cur;
          new_cur[i]--;
          if(dist.count(new_cur) == 0){
            q.push(new_cur);
            dist[new_cur] = dist[cur]+1;
          }
        }
        new_cur = cur;
        new_cur[i]++;
        if(dist.count(new_cur) == 0){
          q.push(new_cur);
          dist[new_cur] = dist[cur]+1;
        }
      }
    }
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}