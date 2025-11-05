bool dfs(int u, vector<vector<int>> &adj, vector<int> &match, vector<bool> &visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (match[v] == -1 || (!visited[match[v]] && dfs(match[v], adj, match, visited))) {
            match[v] = u;
            return true;
        }
    }
    return false;
}
