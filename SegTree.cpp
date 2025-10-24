long long merge(long long a, long long b) {
	return a+b;
}

struct SegTree {
	int n;
	vector<long long> tree;

	SegTree(vector<int>& a) {
		n = a.size();
		tree = vector<long long>(2*n);
		for(int i = n; i < 2*n; i++) {
			tree[i] = a[i-n]; 
		}
		for(int i = n-1; i >= 1; i--) {
			tree[i] = merge(tree[i*2],tree[i*2+1]);
		}
	}

	SegTree(int n) {
		tree = vector<long long>(2*n);
	}

	long long query(int l, int r) {
		l += n; r += n;
		long long left = 0, right = 0;
		while(l <= r) {
			if(l % 2 == 1) left = merge(left,tree[l++]);
			if(r % 2 == 0) right = merge(tree[r--],right);
			l >>= 1;
			r >>= 1;
		}
		return merge(left,right);
	}

	void update(int i, long long val) {
		i += n;
		tree[i] = val;
		for(i >>= 1; i >= 1; i >>= 1) {
			tree[i] = merge(tree[i*2],tree[i*2+1]);
		}
	}
};
