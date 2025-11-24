#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  unordered_map<string, int> list1;
  vector<pair<string, string>> list2;
  string temp1,temp2;
  for(int i = 0; i < n; i++){
  	cin >> temp1 >> temp2;
  	list1[temp1]++:
  	list2.push_back({temp1, temp2});
  }
  for(auto el : list2){
  	if(list1[el.first] != 1){
  		cout << el.first << ' ' << el.second << endl;
  	}
  	else{
  		cout << el.first << endl;
  	}
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