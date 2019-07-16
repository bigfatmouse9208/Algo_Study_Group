/**
Runtime: 200 ms, faster than 88.48% of C++ online submissions for Course Schedule III.
Memory Usage: 40.2 MB, less than 78.69% of C++ online submissions for Course Schedule III.
*/

class Solution {
private:
    struct comparator{
        bool operator() (const vector<int>& a , const vector<int>& b){
            return a[1] < b[1];
        }
    };

    void print(vector<vector<int>>& courses){
        for (auto& c : courses){
            cout << c[0] << " " << c[1] << endl;
        }
        return;
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin() , courses.end() , comparator());
        int end = 0;
        priority_queue<int> chosen;

        for (auto& c : courses){
            if (end + c[0] <= c[1]){
                end += c[0];
                chosen.push(c[0]);
            }
            else if (!chosen.empty() && chosen.top() > c[0]){
                end += c[0] - chosen.top();
                chosen.pop();
                chosen.push(c[0]);
            }
        }
        return chosen.size();
    }
};
