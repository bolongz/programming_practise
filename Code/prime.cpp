#include<iostream>
#include<vector>
#include<map>
using namespace std;
bool is_prime(int x){
	for(int i = 2; i * i <= x ;i++){
		if( x % i == 0) return false;
	}
	return x != 0;
}

vector<int> divisor(int x){
	vector<int> res;
	for(int i = 2 ; i * i <= x; i++){
		if( x % i == 0){
			res.push_back(i);
			if( i != x/i){
				res.push_back(x/i);
			}
		}
	}
	return res;
}

map<int, int> prim_factor(int x){
	map<int, int> res;
	for(int i = 2 ; i * i <= x ; i++){
		if( x % i == 0){
			++res[i];
			x = x / i;
		}
	}
	if ( x != 1) res[x] = 1;

	return res;
}

int sieve(int x){
	int p = 0;
	vector<int> prime;
	vector<bool> is_prim;
	prime.resize(x + 1, 0);
	is_prim.resize( x + 1, true);
	is_prim[0] = false;
	is_prim[1] = false;
	for(int i = 2; i <= x; i++){
		if(is_prim[i]){
			prime[p++] = i;
			for(int j = 2 * i; j <= x ; j+= i){
				is_prim[j] = false;
			}
		}
	}
	return p;
}

int main(){
	int n;
	cin >> n;
	cout << "prime " << is_prime(n) << endl;
	vector<int> d = divisor(n);
	map<int, int> pf = prim_factor(n);
	cout << "All the divisors: ";
	for(int i = 0 ; i< d.size();i++){
		cout << d[i] << " ";
	}
	cout << endl;
	cout << "prime factoring as following:" << endl;
	for(auto &x: pf){
			cout << x.first << " " << x.second << endl;
	}

	int is = sieve(n);
	cout << "The total prime less than n: ";
	cout << is << endl;
	return 0;
}
