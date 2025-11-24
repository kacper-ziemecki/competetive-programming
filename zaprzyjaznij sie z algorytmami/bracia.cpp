#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
	int n;
	cin >> n;
	int temp;
	unordered_map<int, pair<int, int>> mapa{};
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(mapa[temp].first != 0){
			mapa[temp].first = i+1;
		}
		else{
			mapa[temp] = {i+1, i+1};
		}
	}
	
	// for(auto el : mapa) cout << el.second.first << " " << el.second.second << endl;
	vector<pair<int,int>> list1;
	for(auto el : mapa){
		list1.push_back(el.second);
	}
	sort(list1.begin(), list1.end());
	int last = -1;
	int res = 0;
	for(auto el : list1){
		if(last < el.second){
			last = el.first;
			res++;
		}
	}
	cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../input.txt", "r", stdin);
//   freopen("../../output.txt", "w", stdout);
// #endif

  solve();
}