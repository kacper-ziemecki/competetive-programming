#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


void solve(){
	string napis;
	cin >> napis;
	stack<int> stos;
	for(auto el : napis){
		if(el == '{' || el =='[' || el=='('){
			stos.push(el);
		}
		else{
			if(stos.size() == 0){
				cout << "NIE\n";
				return;
			}
			char temp = stos.top();
			stos.pop();
			if(el=='}' && temp!='{'){
				cout << "NIE\n";
				return;
			}
			if(el==')' && temp!='('){
				cout << "NIE\n";
				return;
			}
			if(el==']' && temp!='['){
				cout << "NIE\n";
				return;
			}
		}
	}
	if(stos.size() == 0){
		cout << "TAK\n";
	}
	else{
		cout << "NIE\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 