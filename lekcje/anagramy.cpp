#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<"("<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

bool check(ll l, ll r, vector<vector<ll>>& prefixSum){
	vector<ll> cur = prefixSum[r];
	if(l>0){
		for(ll i = 0; i < 'z'-'a'+1; i++){
			cur[i] -= prefixSum[l-1][i];
		}
	}
	ll cnt=0;
	for(auto el : cur){
		if(el&1) cnt++;
	}
	if(((r-l+1)&1 && cnt==1) || (!((r-l+1)&1) && cnt==0)) return true;
	return false;
}

void solve(){
	ll n;
	string s;
	cin >> n >> s;

	set<char> st;
	for(auto el : s) st.emplace(el);
	if(st.size() <= 2 && !(n&1)){
		ll onel=0,oner=0,twol=0,twor=0;
		for(ll i = 0; i < n/2; i++){
			if(s[i] == s.front()) onel++;
			else twol++;
		}
		for(ll i = n/2; i < n; i++){
			if(s[i] == s.front()) oner++;
			else twor++;
		}
		// dbg(onel,twol,oner,twor);
		if(!((onel+oner)&1) && !((twol+twor)&1)){
			cout << n << endl;
			cout << 1 << endl;
			cout << "1 " << n << endl;
		}
		else if((!(onel&1) && !(oner&1) && !(twol&1) && !(oner&1)) || (n/2)&1){
			cout << n/2 << endl;
			cout << 2 << endl;
			cout << "1 " << n/2 << endl;
			cout << n/2+1 << " " << n << endl;
		} else{
			if(n==2){
				cout << 1 << endl;
				cout << 2 << endl;
				cout << "1 1\n";
				cout << "2 2\n";
			}else{
				cout << n/2-1 << endl;
				cout << 2 << endl;
				cout << "1 " << n/2-1 << endl;
				cout << n/2 << " " << n << endl;
			}
		}
		return;
	} else if(st.size() <= 2 && n&1){
		cout << n << endl;
		cout << 1 << endl;
		cout << "1 " << n << endl;
		return;
	}

	vector<vector<ll>> prefixSum(n, vector<ll>('z'-'a'+1, 0));
	vector<ll> dp(n, 1), parent(n, -1);
	prefixSum[0][s[0]-'a']=1;
	for(ll i = 1; i < n; i++){
		prefixSum[i] = prefixSum[i-1];
		prefixSum[i][s[i]-'a']++;
	}
	for(ll i = 1; i < n; i++){
		for(ll j = 0; j <= i; j++){
			if(check(j, i, prefixSum) && dp[i] <= min((j>0 ? dp[j-1] : LLONG_MAX), i-j+1)){
				dp[i] = min((j>0 ? dp[j-1] : LLONG_MAX), i-j+1);
				parent[i] = j-1;
			}
		}
	}
	ll cur = parent[n-1];
	vector<ll> res{n-1};
	while(cur != -1){
		res.push_back(cur);
		cur = parent[cur];
	}
	res.push_back(-1);
	reverse(res.begin(), res.end());
	cout << dp[n-1] << endl;
	cout << res.size()-1 << endl;
	for(ll i = 1; i < res.size(); i++){
		cout << res[i-1]+2 << " " << res[i]+1 << endl;
	}
	// for(auto el : res) cout << el << " ";
	// cout << endl;
	// for(auto el : dp) cout << el << " ";
	// cout << endl;
	// for(auto el : parent) cout << el << " ";
	// cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("./in.in", "r", stdin);
	// freopen("./out.out", "w", stdout);

	solve();
}