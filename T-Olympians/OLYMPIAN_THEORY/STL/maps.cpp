#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int main(){
  map<string,bool> mp;
  // indeksowanie oraz ustawianie warosci
  mp["harry"] = true;
  // count - O(log n)
  if(mp.count("harry") == 1){
    cout << "wystepuje\n";
  } else{
    cout << "nie wystepuje\n";
  }

  // find - O(log n)
  if(mp.find("harry") != mp.end()){
    cout << "wystepuje\n";
  } else{
    cout << "nie wystepuje\n";
  }


  // indeksowanie - O(log n)
  if(mp["harry"] == true){
    cout << "wystepuje\n";
  } else{
    cout << "nie wystepuje\n"; 
  }

  // usuwanie erase - O(log n)
  mp.erase("harry");
  mp["harry"] = true;
  mp.erase(mp.find("harry"));

}
// https://leetcode.com/problems/two-sum/description/?envType=problem-list-v2&envId=hash-table
// https://leetcode.com/problems/longest-substring-without-repeating-characters/?envType=problem-list-v2&envId=hash-table
// https://codeforces.com/contest/855/problem/A
vector<string> lista = {"tom","lucius","ginny","harry","ginny","harry"};
map<string,bool> odwiedzone;
for(auto napis : lista){
  if(odwiedzone.count(napis) == 0){
    cout << "NO\n";
  } else{
    cout << "YES\n";
  }
  odwiedzone[napis] = true;
}
// https://leetcode.com/problems/isomorphic-strings/description/?envType=problem-list-v2&envId=hash-table
