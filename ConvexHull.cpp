vector<ii> getHull(vector<ii>& points) {
	sort(points.begin(),points.end());
	points.erase(unique(points.begin(),points.end()),points.end());
	int n = points.size();
	vector<ii> hull;
	if(n < 3) {
		return points;
	}
	auto area = [&](ii a, ii b, ii c) -> int {
		return (b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0]);
	};
	for(int i = 0; i < n; i++) {
		while(hull.size() > 1 && area(hull[hull.size()-2],hull.back(),points[i]) <= 0) {
			hull.pop_back();
		}
		hull.push_back(points[i]);
	}
	int lower = hull.size();
	for(int i = n-2; i >= 0; i--) {
		while(hull.size() > lower && area(hull[hull.size()-2],hull.back(),points[i]) <= 0) {
			hull.pop_back();
		}
		hull.push_back(points[i]);
	}
	hull.pop_back();
	return hull;
}
