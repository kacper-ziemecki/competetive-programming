#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
	ll n;
	cin >> n;
	vector<ll> one(n, 0), two;
	for(auto &el : one) cin >> el;

	for(ll i = 1; i < n-1; i++){
		if(one[i] > one[i-1] && one[i] > one[i+1]) two.push_back(i);
	}
	
	for(ll i = n; i >= 1; i--){

		if(n % i != 0) continue;

		ll temp = 0, index = 0;
		bool flag = true;

		while(temp < n){
			
			while(index < two.size() && two[index] < temp){
				index++;
			}

			if(index >= two.size() || two[index] >= (temp + n/i)){
				flag = false;
				break;
			}

			temp += n/i;
			index++;
		}

		if(flag){
			cout << i << endl;
			return;
		}
	}
	cout << 0 << endl;
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