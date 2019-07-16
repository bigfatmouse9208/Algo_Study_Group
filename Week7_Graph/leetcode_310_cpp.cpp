/**
Runtime: 80 ms, faster than 62.37% of C++ online submissions for Minimum Height Trees.
Memory Usage: 30.8 MB, less than 18.15% of C++ online submissions for Minimum Height Trees.
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 2){
            vector<int> res;
            for (int i = 0 ; i < n ; ++i){
                res.push_back(i);
            }
            return res;
        }

        vector<unordered_set<int>> graph (n , unordered_set<int> ({}));
        vector<int> connection (n , 0);

        for (auto& p : edges){
            graph[p[0]].insert(p[1]);
            graph[p[1]].insert(p[0]);
            connection[p[0]]++;
            connection[p[1]]++;
        }

        vector<int> leaves;
        for (int i = 0 ; i < n ; ++i){
            if (connection[i] == 1){
                leaves.push_back(i);
            }
        }

        while (n > 2){
            n -= leaves.size();
            vector<int> new_leaves;
            for (auto& leaf : leaves){
                for (auto& node : graph[leaf]){
                    graph[node].erase(leaf);
                    if (graph[node].size() == 1){
                        new_leaves.push_back(node);
                    }
                }
            }
            leaves = new_leaves;
        }
        return leaves;
    }
};
