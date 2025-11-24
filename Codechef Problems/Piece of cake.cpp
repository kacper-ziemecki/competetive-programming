#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  string text;
  cin >> text;
  unordered_map<char, int> list;
  for(auto el : text){
    list[el]++;
  }
  for(auto el : list){
    if(el.second == text.size()/2 && text.size() % 2 == 0){
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}