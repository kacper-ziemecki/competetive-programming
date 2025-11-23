#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,lastNode=0;
const int maxN = 1e6+1;
string lista[maxN];
string prefix,suffix;
string res;
int iter = 0;

struct Node{
  char a,depth;
  int children['z'-'a'+1],cnt;
  Node(){
    a = '0';
    depth=0;
    cnt=0;
    for(int i = 0; i < ('z'-'a'+1); i++) children[i] = -1;
  }
};

Node nodes[maxN];

void print_nodes(){
  for(int i = 0; i <= lastNode; i++){
    cout << nodes[i].a << '-';
    for(int j = 0; j < ('z'-'a'+1); j++){
      cout << char(j+'a') << nodes[i].children[j] << ',';
    }
    cout << endl;
  }
}

int calc_depth(int u){
  int curDepth=1;
  for(int v = 0; v < ('z'-'a'+1); v++){
    if(nodes[u].children[v] != -1) curDepth = max(curDepth, calc_depth(nodes[u].children[v])+1);
  }
  nodes[u].depth = curDepth;
  return curDepth;
}

void calc_res(int u){
  // if(iter++ > 10000) return;
  vector<pair<int,int>> nxt;
  for(int v = 0; v < ('z'-'a'+1); v++){
    if(nodes[u].children[v] != -1){
      nxt.pb({nodes[nodes[u].children[v]].depth, nodes[u].children[v]});
    }
  }

  for(int i = 0; i < nodes[u].cnt && !nxt.empty(); i++){
    res += "ET";
  }
  if(nxt.empty()){
    res += 'E';
    // dbg(nodes[u].cnt);
    for(int i = 0; i < nodes[u].cnt-1; i++){
      res += "TE";
    }
  }

  sort(nxt.begin(), nxt.end());
  for(pair<int,int> el : nxt){
    int d = el.first, v = el.second;
    if(!suffix.empty()){ // przed nami bylo cos i teraz gdzies idziemy
      if(1+suffix.size() < prefix.size()){ // TBBBBBB...BB < ABGDCOD
        res +=  'T' + suffix;
      } else{
        res += prefix;
      }
      suffix.clear();
    } 
    prefix += nodes[v].a;
    res +=  nodes[v].a;
    calc_res(v);
  }
  suffix += 'B';
  prefix.pop_back();
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> lista[i];
  for(int i = 0; i < n; i++){
    int curNode=0;
    for(int j = 0; j < lista[i].size(); j++){
      if(nodes[curNode].children[lista[i][j]-'a'] == -1){
        lastNode++;
        nodes[curNode].children[lista[i][j]-'a'] = lastNode;
        nodes[lastNode].a = lista[i][j];
        curNode = lastNode;
      } else{
        curNode = nodes[curNode].children[lista[i][j]-'a'];
      }
      if(j == lista[i].size()-1) nodes[curNode].cnt++;
    }
  }
  // dbg(lastNode);
  // dbg(lista[0].size());
  // print_nodes();
  calc_depth(0);
  calc_res(0);
  cout << res.size() << endl;
  cout << res << endl;
}
 
int main()
{

  // freopen("../../in.in", "r", stdin);
  // freopen("../../out.out", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

} 