#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b;
  cin >> a >> b;
  string text;
  cin >> text;
  unordered_map<int, bool>list;
  list[b] = true;
  for(auto el: text){
    if(el == 'L'){
      b--;
    }
    else{
      b++;
    }
    list[b] = true;
  }
  cout << list.size() << endl;
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