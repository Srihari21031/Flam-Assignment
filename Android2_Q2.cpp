#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& onPath) {
		visited[node] = true;
		onPath[node] = true;

		for (int neighbor : graph[node]) {
			if (!visited[neighbor]) {
				if (dfs(neighbor, graph, visited, onPath))
					return true;
			} else if (onPath[neighbor]) {
				return true; // Cycle detected
			}
		}

		onPath[node] = false; // Backtrack
		return false;
	}

	bool hasCircularDependency(int n, vector<vector<int>>& edges) {
		vector<vector<int>> graph(n);

		// Build adjacency list
		for (auto& edge : edges) {
			int u = edge[0], v = edge[1];
			graph[u].push_back(v);
		}

		vector<bool> visited(n, false);
		vector<bool> onPath(n, false);

		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				if (dfs(i, graph, visited, onPath))
					return true;
			}
		}

		return false;
	}
};

int main() {
	Solution sol;

	int n1 = 4;
	vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 3}};
	cout << boolalpha << sol.hasCircularDependency(n1, edges1) << endl;  // false

	int n2 = 4;
	vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 0}};
	cout << boolalpha << sol.hasCircularDependency(n2, edges2) << endl;  // true

	return 0;
}
