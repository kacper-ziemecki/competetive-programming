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
  ld x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  vector<vector<pair<ld,ld>>> list;
  vector<pair<ld,ld>> total;
  total.push_back({x1,y1});
  total.push_back({x2,y2});
  map<pair<ld,ld>,ll> mp;
  mp[{x1,y1}]=1;
  mp[{x2,y2}]=2;
  cin.ignore();
  string s;
  while(getline(cin, s), s.size() > 1){
    stringstream stream;
    stream << s;
    list.push_back({});
    ld x3,y3;
    while(stream >> x3 >> y3, x3 != -1 || y3 != -1){
      list.back().push_back({x3,y3});
      total.push_back({x3,y3});
    }
    if(cin.eof()) break;
  }
  ll k = 3;
  for(ll i = 0; i < list.size(); i++){
    for(ll j = 0; j < list[i].size(); j++){
      if(mp.count(list[i][j]) == 0) mp[list[i][j]] = k++;
    }
  }
  vector<vector<pair<ld,ld>>> adj(k);
  priority_queue<pair<ld,ld>,vector<pair<ld,ld>>,greater<pair<ld,ld>>> pq;
  vector<ld> dist(k, LLONG_MAX);

  dist[mp[{x1,y1}]]=0;
  pq.emplace(0,mp[{x1,y1}]);

  for(ll i = 0; i < list.size(); i++){
    for(ll j = 1; j < list[i].size(); j++){
      adj[mp[list[i][j-1]]].push_back({60*sqrt((list[i][j-1].first-list[i][j].first)*(list[i][j-1].first-list[i][j].first)+(list[i][j-1].second-list[i][j].second)*(list[i][j-1].second-list[i][j].second))/40000.0, mp[list[i][j]]});
      adj[mp[list[i][j]]].push_back({60*sqrt((list[i][j-1].first-list[i][j].first)*(list[i][j-1].first-list[i][j].first)+(list[i][j-1].second-list[i][j].second)*(list[i][j-1].second-list[i][j].second))/40000.0, mp[list[i][j-1]]});
    }
  }
  for(ll i = 0; i < total.size(); i++){
    for(ll j = i+1; j < total.size(); j++){
      adj[mp[total[i]]].push_back({60*sqrt((total[i].first-total[j].first)*(total[i].first-total[j].first)+(total[i].second-total[j].second)*(total[i].second-total[j].second))/10000.0, mp[total[j]]});
      adj[mp[total[j]]].push_back({60*sqrt((total[i].first-total[j].first)*(total[i].first-total[j].first)+(total[i].second-total[j].second)*(total[i].second-total[j].second))/10000.0, mp[total[i]]});
    }
  }

  while(!pq.empty()){
    auto [w1, u] = pq.top(); pq.pop();
    for(auto [w2, v] : adj[u]){
      if(dist[v] > w1+w2){
        dist[v] = w1+w2;
        pq.emplace(dist[v], v);
      }
    }
  }
  
  cout << round(dist[mp[{x2,y2}]]) << endl;
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

  ll t;
  cin >> t;
  for(ll i = 1; i <= t; i++){
    solve();
    if(i != t) cout << endl;
  }
}