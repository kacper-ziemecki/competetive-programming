#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define hs unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

const hs prime[] = {5586985605742039601,6889537187409766193};

int n,k,v;
int cnt=1;
const int N = 5e5+1;
set<int> graf[N];
pair<pair<hs,hs>, int> lista[N];
set<pair<int,int>> resGraf;
int old_to_new[N], new_size[N];

bool sortownik(pair<pair<hs,hs>, int>& a, pair<pair<hs,hs>, int>& b){
  if(a.first.first == b.first.first && a.first.second == b.first.second){
    return a.second < b.second;
  } else if(a.first.first == b.first.first){
    return a.first.second < b.first.second;
  } 
  return a.first.first < b.first.first;
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> k;
    graf[i+1].emplace(i+1);
    for(int j = 0; j < k; j++){
      cin >> v;
      graf[i+1].emplace(v);
    }
  }
  if(n == 1){
    cout << 1 << endl;
    cout << 1 << endl;
    return;
  }
  for(int i = 1; i <= n; i++){
    hs hash1=0, hash2=0;
    for(auto node : graf[i]){
      hash1 = hash1*prime[0]+node;
      hash2 = hash2*prime[1]+node;
    }
    lista[i-1] = make_pair(make_pair(hash1,hash2),i);
  }
  sort(lista, lista+n, sortownik);
  old_to_new[lista[0].second] = cnt;
  new_size[cnt]++;
  for(int i = 1; i < n; i++){
    if(lista[i].first.first == lista[i-1].first.first && lista[i].first.second == lista[i-1].first.second){
      old_to_new[lista[i].second] = cnt;
    } else{
      old_to_new[lista[i].second] = ++cnt;
    }
    new_size[cnt]++;
  }
  for(int i = 1; i <= n; i++){
    if(new_size[old_to_new[i]] == graf[i].size()){
      new_size[cnt]--;
      old_to_new[i] = ++cnt;
      new_size[cnt]++;
    }
  }
  for(int i = 1; i <= n; i++){
    for(auto v : graf[i]){
      if(old_to_new[i] != old_to_new[v]){
        resGraf.emplace(make_pair(min(old_to_new[i], old_to_new[v]), max(old_to_new[i], old_to_new[v])));
      }
    }
  }
  cout << cnt << endl;
  for(int i = 1; i <= n; i++) cout << old_to_new[i] << ' ';
  cout << endl;
  for(auto el : resGraf){
    cout << el.first << ' ' << el.second << endl;
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