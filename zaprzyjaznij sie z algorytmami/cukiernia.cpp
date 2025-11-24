#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


void solve(){
	long long unsigned int n,a,res=0,temp;
	cin >> n;
	stack<long long unsigned int> stos;
	for(long long unsigned int i = 0; i < n; i++){
		cin >> a;
		stos.push(a);
	}
	temp = stos.top();
	res = temp;
	stos.pop();
	for(long long unsigned int i = 0; i < n-1; i++){
		if(stos.top() < temp){
			temp = stos.top();
		}
		stos.pop();
		res+=temp;
	}
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 