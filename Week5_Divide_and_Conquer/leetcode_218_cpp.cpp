"""
Runtime: 28 ms, faster than 96.77% of C++ online submissions for The Skyline Problem.
Memory Usage: 14.9 MB, less than 49.87% of C++ online submissions for The Skyline Problem.
"""

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        unordered_set<int> corners;
        for (auto& b : buildings){
            corners.insert(b[0]);
            corners.insert(b[1]);
        }
        vector<int> pool;
        for (auto& e : corners){
            pool.push_back(e);
        }
        sort(pool.begin() , pool.end());
        int idx = 0;
        vector<vector<int>> res ({{0 , 0}});
        priority_queue<pair<int , int>> heap;
        heap.push(make_pair(0 , INT_MAX));

        for (auto& x : pool){
            while(idx < buildings.size() && x == buildings[idx][0]){
                heap.push(make_pair(buildings[idx][2] , buildings[idx][1]));
                idx++;
            }
            while (!heap.empty() && heap.top().second <= x){
                heap.pop();
            }
            if (res.back()[1] != heap.top().first){
                res.push_back({x , heap.top().first});
            }
        }
        res.erase(res.begin());
        return res;
    }
};
