#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
	ll n;
	cin >> n;
	map<ll, ll> first, second;
	ll temp;
	for(ll i = 0; i < n; i++){
		cin >> temp;
		if(i&1){
			second[temp]++;
		}
		else{
			first[temp]++;
		}
	}
	pair<ll, ll> firstMax1 = {0, 0}, firstMax2 = {0, 0};
	for(auto el : first){
		if(firstMax1.first < el.second){
			firstMax2 = firstMax1;
			firstMax1.first = el.second;
			firstMax1.second = el.first;
		}
		else if(firstMax2.first < el.second){
			firstMax2.first = el.second;
			firstMax2.second = el.first;
		}
	}
	// cout << firstMax1.first << " - " << firstMax1.second << endl;
	// cout << firstMax2.first << " - " << firstMax2.second << endl;

	pair<ll, ll> secondMax1 = {0, 0}, secondMax2 = {0, 0};
	for(auto el : second){
		if(secondMax1.first < el.second){
			secondMax2 = secondMax1;
			secondMax1.first = el.second;
			secondMax1.second = el.first;
		}
		else if(secondMax2.first < el.second){
			secondMax2.first = el.second;
			secondMax2.second = el.first;
		}
	}

	// cout << secondMax1.first << " - " << secondMax1.second << endl;
	// cout << secondMax2.first << " - " << secondMax2.second << endl;

	if(firstMax1.second != secondMax1.second){
		cout << n - (firstMax1.first + secondMax1.first) << endl;
	}
	else{
		cout << min((n - (firstMax1.first + secondMax2.first)), (n - (firstMax2.first + secondMax1.first))) << endl;
	}
	// for(auto el : first) cout << el.first << " " << el.second << endl;
	// cout << "----\n";
	// for(auto el : second) cout << el.first << " " << el.second << endl;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// #ifndef ONLINE_JUDGE
	// 	freopen("../../input.txt", "r", stdin);
	// 	freopen("../../output.txt", "w", stdout);
	// #endif
	
	solve();
}