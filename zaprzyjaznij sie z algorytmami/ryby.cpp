#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


void solve(){
	int n,res=0;
	cin >> n;
	vector<int> jeden(n, 0), dwa(n, 0);
	for(auto &el : jeden) cin >> el;
	for(auto &el : dwa) cin >> el;
	stack<int> stos;
	for(int i = n-1; i >= 0; i--){
		if(dwa[i] == 0){
			stos.push(jeden[i]);
		}
		else{
			while(stos.size() > 0 && stos.top() < jeden[i]) stos.pop();
			if(stos.size() == 0) res++;
		}
	}
	cout << stos.size()+res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 