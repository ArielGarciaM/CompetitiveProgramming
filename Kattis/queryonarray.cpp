#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll inv2 = 500000004, inv4 = 250000002,  inv6 = 166666668;

inline ll add(ll a, ll b) {
	ll res = (a + b)%MOD;
	if(res < 0)
		res += MOD;
	return res;
}

inline ll mul(ll a, ll b) {
	ll res = (a * b)%MOD;
	if(res < 0)
		res += MOD;
	return res;
}

struct node {
	int l, r;
	ll a, b, c, d, sum;
	node *left, *right;

	node(int l, int r) : l(l), r(r) {
		a = b = c = d = sum = 0;
		if(l < r) {
			int mi = (l + r)/2;
			left = new node(l, mi);
			right = new node(mi + 1, r);
		}
	}

	void merge() {
		sum = add(left->get(), right->get());
	}

	ll get() {
		ll k = r - l + 1;
		ll t3 = mul(k, k + 1);
		t3 = mul(t3, t3);
		t3 = mul(t3, inv4);
		t3 = mul(t3, a);
		ll t2 = mul(k, k + 1);
		t2 = mul(t2, 2ll*k + 1);
		t2 = mul(t2, inv6);
		t2 = mul(t2, b);
		ll t1 = mul(k, k + 1);
		t1 = mul(t1, inv2);
		t1 = mul(t1, c);
		ll t0 = mul(k, d);
		//cout << a << " " << b << " " << c << " " << d << endl;
		//cout << t3 << " " << t2 << " " << t1 << " " << t0 << endl;
		ll res = add(add(add(t3, t2), t1), t0);
		return add(sum, res);
	}

	ll compose(ll w, ll x, ll y, ll z) {
		a = add(a, w);
		b = add(b, x);
		c = add(c, y);
		d = add(d, z);
	}

	ll offset(ll w, ll x, ll y, ll z, ll k, ll &nx, ll &ny, ll &nz) {
		nx = add(x, mul(3ll*k, w));
		ny = add(add(y, mul(2ll*k, x)), mul(mul(3ll*k, k), w));
		nz = add(z, add(mul(y, k), add(mul(mul(k, k), x), mul(w, mul(k, mul(k, k))))));
	}

	ll push() {
		left->compose(a, b, c, d);
		ll mi = (l + r)/2;
		ll nb, nc, nd;
		//cout << "update " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << endl;
		offset(a, b, c, d, mi - l + 1, nb, nc, nd);
		//cout << "update " << a << "x^3 + " << nb << "x^2 + " << nc << "x + " << nd << " for right " << endl;
		right->compose(a, nb, nc, nd);
		a = b = c = d = 0;
		merge();
	}

	void upd(ll rl, ll rr, ll w, ll x, ll y, ll z) {
		if(rr < l || r < rl)
			return;
		if(rl <= l && r <= rr) {
			compose(w, x, y, z);
			return;
		}
		ll mi = (l + r)/2;
		ll k = max(0ll, mi - rl + 1ll);
		ll nx, ny, nz;
		offset(w, x, y, z, k, nx, ny, nz);
		push();
		left->upd(rl, rr, w, x, y, z);
		right->upd(rl, rr, w, nx, ny, nz);
		merge();
	}

	ll qry(ll rl, ll rr) {
		//cout << "node " << l << " " << r << " query " << rl << " " << rr << endl;
		if(r < rl || l > rr)
			return 0;
		if(rl <= l && r <= rr) {
			//cout << sum << endl;
			return get();
		}
		push();
		merge();
		return add(left->qry(rl, rr), right->qry(rl, rr));
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	node tree(1, n);
	while(q--) {
		int t, l, r;
		cin >> t >> l >> r;
		if(t == 0)
			cout << tree.qry(l, r) << endl;
		if(t == 1)
			tree.upd(l, r, 1, 3, 2, 0);
		if(t == 2)
			tree.upd(l, r, -1, -3, -2, 0);
	}
}
