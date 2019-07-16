/**
Runtime: 16 ms, faster than 99.58% of C++ online submissions for Course Schedule II.
Memory Usage: 13.2 MB, less than 43.70% of C++ online submissions for Course Schedule II.
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> indegree (numCourses , 0);
        vector<vector<int>> advanced_course (numCourses , vector<int> ({}));

        for (auto& p : prerequisites){
            indegree[p[0]]++;
            advanced_course[p[1]].push_back(p[0]);
        }

        queue<int> Q;
        for (int c = 0 ; c < numCourses ; ++c){
            if (indegree[c] == 0){
                Q.push(c);
            }
        }

        while (!Q.empty()){
            int curr = Q.front();
            res.push_back(curr);
            Q.pop();

            for (auto& c : advanced_course[curr]){
                indegree[c]--;
                if (indegree[c] == 0){
                    Q.push(c);
                }
            }
        }

        return (res.size() == numCourses) ? res : vector<int> ({});
    }
};
