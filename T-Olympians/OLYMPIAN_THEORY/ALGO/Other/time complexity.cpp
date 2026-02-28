
int n;  // O(1)
cin >> n; // O(1)
// czy n = 100 to robimy okolo 1 ops
// czy n = 1000000 to robimy okolo 1 ops
vector<int> lista(n, 0); // O(n)
// 1s = 10^8
// n <= 10^8 -> ok
// n > 10^8 -> nie damy rady
//notacja dużego O
for(int i = 0; i < n; i++){ // O(n)

}

for(int i = 0; i < 30; i++){ // O(1)

}

for(int i = 0; i < n; i++){ // O(n)
	for(int j = 0; j < 100; j++){

	}
}

for(int i = 0; i < n; i++){ // O(n*m)
	for(int j = 0; j < m; j++){

	}
}

// O(log n)
n == 1000, log n = 10
n == 10^6, log n = 20
n == 10^9, log n = 30 