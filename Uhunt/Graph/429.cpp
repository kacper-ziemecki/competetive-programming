#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool canConnect(string a, string b){
  if(a.size() != b.size()) return false;
  ll cnt=0;
  for(ll i = 0; i < a.size(); i++){
    if(a[i]!=b[i]) cnt++;
  }
  if(cnt == 1) return true;
  return false;
}

void solve(){
  vector<string> list;
  string s,s1,s2,u;
  while(cin>>s, s[0]!='*'){
    list.push_back(s);
  }
  map<string,vector<string>> adj;
  for(ll i = 0; i < list.size(); i++){
    for(ll j = 0; j < list.size(); j++){
      if(i==j)continue;
      if(canConnect(list[i],list[j])) adj[list[i]].push_back(list[j]);
    }
  }
  cin.ignore();
  while(getline(cin,s), s.size()>0){
    stringstream stream;
    stream << s;
    stream >> s1 >> s2;
    queue<string> q;
    map<string,ll> dist;
    map<string,bool> vis;
    q.push(s1);
    dist[s1]=0;
    vis[s1]=true;
    while(!q.empty()){
      u = q.front();q.pop();
      for(auto v : adj[u]){
        if(!vis[v]){
          q.push(v);
          vis[v]=true;
          dist[v]=dist[u]+1;
        }
      }
    }
    cout << s1 << " " << s2 << " " << dist[s2] << endl;
    if(cin.eof()) break;
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

  ll t;
  cin >> t;
  for(ll i = 0; i < t; i++){
    if(i!=0)cout << endl;
    solve();
  }
}