#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


ll beauty(vector<ll> &lista, ll i, ll j){
	vector<ll> clone, cloneSorted;
	for(int x = i; x <= j; x++){
		clone.push_back(lista[x]);
		cloneSorted.push_back(lista[x]);
	}
	for(auto el : clone) cout << el << ",,,";
	cout << endl;

	sort(cloneSorted.begin(), cloneSorted.end());
	unordered_map<ll, ll> indeks;
	vector<pair<ll, ll>> test = {};

	for(int x = 0; x < cloneSorted.size(); x++){
		indeks[cloneSorted[x]] = x;
		
	}

	for(ll x = 0; x < clone.size(); x++){
		if(clone[x] != cloneSorted[x]){
			test.push_back({min(indeks[clone[x]], x), max(indeks[clone[x]], x)});
		}
	}
	sort(test.begin(), test.end());

	for(auto el : test) cout << "{ " << el.first << ", " << el.second << " }, ";
	cout << endl;
	cout << "------\n";

	ll result = 0;
	for(ll x = 1; x < test.size(); x++){
		result += max(0ll, test[x].first - test[x-1].second);
		cout << "res in for: " << result << endl;
	}
	cout <<"===---" <<  (j - i + 1) - result << endl;
	if(test.size() == 0) return 0;
	else{
		result += test[0].first;
		result += j - test[test.size() - 1].second;
	}
	cout <<"---" <<  (j - i + 1) - result << endl;
	return  (j - i + 1) - result;
}

void solve(){
	ll n,res = 0;
	cin >> n;
	vector<ll> lista(n, 0);
	for(auto &el : lista) cin >> el;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			res += beauty(lista, i, j);

		}
	}
	cout << res << endl;
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