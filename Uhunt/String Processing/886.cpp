#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


struct node{
  vector<node*> children;
  bool end;
  vector<string> codeList;
  node(){
    end=false;
    children.assign(10, NULL);
  }
};
class Trie{
private:
  node* root;
public:
  Trie(){
    root = new node();
  }
  void insert(string number, string code){
    node* cur = root;
    for(auto letter : number){
      ll alphaNum = letter-'0';
      if(cur->children[alphaNum] == NULL){
        cur->children[alphaNum] = new node();
      }
      cur = cur->children[alphaNum];
      cur->codeList.push_back(code);
    }
    cur->end = true;
  }
  bool search(string number){
    node* cur = root;
    for(auto letter : number){
      ll alphaNum = letter-'0';
      if(cur->children[alphaNum] == NULL) return false;
      cur = cur->children[alphaNum];
    }
    return cur->end;
  }
  vector<string> count_prefix(string number){
    node* cur = root;
    for(auto letter : number){
      ll alphaNum = letter-'0';
      if(cur->children[alphaNum] == NULL) return {};
      cur = cur->children[alphaNum];
    }
    return cur->codeList;
  }
};


void solve()
{
  string a,b,c,s;
  vector<vector<string>> numbers;
  vector<string> codes;
  Trie tr1, tr2;
  while(true){
    stringstream stream;
    s.clear();
    getline(cin >> ws, s);
    stream << s;
    if(s.empty()) break;
    stream >> a;
    if(stream.eof()){
      codes.push_back(a);
    } else{
      stream >> b >> c;
      numbers.push_back({a,b,c});
    }
    if(cin.eof()) break;
  }
  for(auto el : numbers) tr1.insert(el[2], el[2]);

  map<char, ll> convert{{'a' , 2}, {'b', 2}, {'c', 2}, {'d', 3}, {'e', 3}, {'f', 3}, {'g', 4}, {'h', 4}, {'i', 4}, {'j', 5}, {'k', 5}, {'l', 5}, {'m', 6}, {'n', 6}, {'o', 6}, {'p', 7}, {'q', 7}, {'r', 7}, {'s', 7}, {'t', 8}, {'u', 8}, {'v', 8}, {'w', 9}, {'x', 9}, {'y', 9}, {'z', 9}};
  for(auto sub : numbers){
    string new_code = to_string(convert[char(tolower(sub[0][0]))]);
    for(auto el : sub[1]){
      new_code += to_string(convert[char(tolower(el))]);
    }
    tr2.insert(new_code, sub[2]);
  }

  for(auto el : codes){
    if(tr1.search(el)){
      cout << el << endl;
    } else{
      vector<string> res = tr2.count_prefix(el);
      for(ll i = 0; i < res.size(); i++){
        if(i!=0) cout << " ";
        cout << res[i];
      }
      if(res.empty()) cout << 0;
      cout << endl;
    }
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

  solve();
}