/*
	< 10^k          number     divisors   2 3 5 71113171923293137
	-------------------------------------------------------------
	1                    6            4   1 1
	2                   60           12   2 1 1
	3                  840           32   3 1 1 1
	4                 7560           64   3 3 1 1
	5                83160          128   3 3 1 1 1
	6               720720          240   4 2 1 1 1 1
	7              8648640          448   6 3 1 1 1 1
	8             73513440          768   5 3 1 1 1 1 1
	9            735134400         1344   6 3 2 1 1 1 1
	10          6983776800         2304   5 3 2 1 1 1 1 1
	11         97772875200         4032   6 3 2 2 1 1 1 1
	12        963761198400         6720   6 4 2 1 1 1 1 1 1
	13       9316358251200        10752   6 3 2 1 1 1 1 1 1 1
	14      97821761637600        17280   5 4 2 2 1 1 1 1 1 1
	15     866421317361600        26880   6 4 2 1 1 1 1 1 1 1 1
	16    8086598962041600        41472   8 3 2 2 1 1 1 1 1 1 1
	17   74801040398884800        64512   6 3 2 2 1 1 1 1 1 1 1 1
	18  897612484786617600       103680   8 4 2 2 1 1 1 1 1 1 1 1

	< 10^k    prime   # of prime          < 10^k            prime
	-------------------------------------------------------------
	1             7            4          10           9999999967
	2            97           25          11          99999999977
	3           997          168          12         999999999989
	4          9973         1229          13        9999999999971
	5         99991         9592          14       99999999999973
	6        999983        78498          15      999999999999989
	7       9999991       664579          16     9999999999999937
	8      99999989      5761455          17    99999999999999997
	9     999999937     50847534          18   999999999999999989
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mul(ll x, ll y, ll mod) { return (__int128) x * y % mod; }
ll ipow(ll x, ll y, ll p) {
	ll ret = 1, piv = x % p;
	while (y) {
		if (y & 1) ret = mul(ret, piv, p);
		piv = mul(piv, piv, p);
		y >>= 1;
	}
	return ret;
}
bool miller_rabin(ll x, ll a) {
	if (x % a == 0) return 0;
	ll d = x - 1;
	while (1) {
		ll tmp = ipow(a, d, x);
		if (d & 1) return (tmp != 1 && tmp != x - 1);
		else if (tmp == x - 1) return 0;
		d >>= 1;
	}
}
bool isprime(ll x) {
	for (auto &i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (x == i) return 1;
		if (x > 40 && miller_rabin(x, i)) return 0;
	}
	if (x <= 40) return 0;
	return 1;
}

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif
	
	for (int i = 1; i <= 100; i++) cerr << i << " " << boolalpha << isprime(i) << endl;

	return 0;
}