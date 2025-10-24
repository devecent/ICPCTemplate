struct DSU {
	vector<int> parent;
	vector<int> size;

	DSU(int n) {
		parent = vector<int>(n);
		size = vector<int>(n,1);
		iota(parent.begin(),parent.end(),0);
	}


	int find(int x) {
		if(parent[x] == x) {
			return x;
		}
		return parent[x] = find(parent[x]);
	}

	bool unite(int a, int b) {
		a = find(a);
		b = find(b);
		if(a != b) {
			if(size[a] < size[b]) {
				swap(a,b);
			}
			parent[b] = a;
			size[a] += size[b];
			return true;
		}
		return false;
	}
};
