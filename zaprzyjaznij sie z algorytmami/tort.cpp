#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll a,b,n,k;
	cin >> a >> b >> n >> k;
	vector<int> jeden(n, 0), dwa(n, 0), trzy(n+1, 0), cztery(n+1, 0);
	for(auto &el : jeden) cin >> el;
	for(auto &el : dwa) cin >> el;
	for(int i = 0; i < n+1; i++){
		trzy[i] = (i==n ? a : jeden[i]) - (i==0 ? 0 : jeden[i-1]);
		cztery[i] = (i==n ? b : dwa[i]) - (i==0 ? 0 : dwa[i-1]);
	}
	sort(trzy.begin(), trzy.end());
	sort(cztery.begin(), cztery.end());
	ll temp = 0, index = 0;
	bool flag = true;
	for(int i = 1;i <= n;i++){
		if(temp + i >= k){
			flag = false;
			break;
		}
		temp+=i;
		index++;
	}
	if(flag){
		for(int i = n-1;i > 0;i--){
			if(temp + i >= k) break;
			temp+=i;
			index++;
		}
	}
	ll x = n, y = n - index;
	cout << y << " " << x << endl;
	y += k - temp - 1;
	x -= k - temp - 1;
	cout << y << " " << x << endl;
	for(auto el : trzy) cout << el << " ";
	cout << endl;
	for(auto el : cztery) cout << el << ' ';
	cout << endl;
	cout << trzy[y] * cztery[x] << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin); 
	solve();	
} 