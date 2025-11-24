#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  unordered_map<string, bool> list;
  string temp;
  for(int i = 0; i < n; i++){
    cin >> temp;
    list[temp] = true;
  }
  if(!list["cakewalk"] || !list["simple"] || !list["easy"] || !(list["easy-medium"] || list["medium"]) || !(list["medium-hard"] || list["hard"])){
    cout << "No\n";
  }
  else{
    cout << "Yes\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}