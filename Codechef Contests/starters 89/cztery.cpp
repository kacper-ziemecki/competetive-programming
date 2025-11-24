#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> one(n, 0), two(m, 0);
	for(auto &el : one) cin >> el;
	for(auto &el : two) cin >> el;
	double up1 = 0, up2 = 0, down1 = 0, down2 = 0;
	for(auto el : one) up1 += el;
	for(auto el : two) up2 += el;
	down1 = one.size();
	down2 = two.size();
	double mean1 = up1/down1;
	double mean2 = up2/down2;
	int cnt = 0;
	while(mean1 < mean2){
		cnt++;
		if(mean1 * (down1/(down1+1)) + (k/(down1 + 1)))
	}
	cout << cnt << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 