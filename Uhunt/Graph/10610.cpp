#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(ld v,ld m){
  ld sx,sy,dx,dy;
  cin >> sx >> sy >> dx >> dy;
  cin.ignore();
  vector<pair<ld, ld>> list;
  list.push_back({sx, sy});
  list.push_back({dx, dy});
  string s;
  while(getline(cin, s), !s.empty()){
    stringstream stream;
    stream << s;
    pair<ld,ld> cur;
    stream >> cur.first >> cur.second;
    list.push_back(cur);
  }
  map<pair<ld,ld>,vector<pair<ld,ld>>> adj;
  for(ll i = 0; i < list.size(); i++){
    for(ll j = 0; j < list.size(); j++){
      if(i==j)continue;
      ld x = (list[i].first-list[j].first)*(list[i].first-list[j].first);
      ld y = (list[i].second-list[j].second)*(list[i].second-list[j].second);
      ld total = sqrt(x+y)/v;
      if(total > m*60) continue;
      adj[list[i]].push_back(list[j]);
    }
  }
  // for(auto el : adj){
  //   cout << "(" << el.first.first << "," << el.first.second << ") - ";
  //   for(auto el1 : el.second){
  //     cout << "{" << el1.first << "," << el1.second << "}";
  //   }
  //   cout << endl;
  // }
  map<pair<ld,ld>,bool> vis;
  queue<pair<ld,ld>> q;
  map<pair<ld,ld>,ll> dist;
  vis[{sx,sy}]=true;
  q.push({sx,sy});
  dist[{sx,sy}]=0;
  while(!q.empty()){
    pair<ld,ld> p = q.front(); q.pop();
    for(auto c : adj[p]){
      if(!vis[c]){
        vis[c] = true;
        dist[c] = dist[p]+1;
        q.push(c);
      }
    }
  }
  if(dist.count({dx,dy}) == 0){
    cout << "No.\n";
  } else{
    cout << "Yes, visiting " << dist[{dx,dy}]-1 << " other holes.\n";
  }
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

  ld v,m;
  while(cin>>v>>m, v!=0||m!=0){
    solve(v,m);
  }
}