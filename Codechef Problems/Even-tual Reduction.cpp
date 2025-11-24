#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  string text;
  cin >> text;
  unordered_map<char, int> list;
  for(auto el : text){
  	list[el]++;
  }
  for(auto el : list){
  	if(el.second&1){
  		cout << "NO\n";
  		return;
  	}
  }
  cout << "YES\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}