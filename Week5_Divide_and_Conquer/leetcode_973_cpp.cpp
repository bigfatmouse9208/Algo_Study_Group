/**
Runtime: 208 ms, faster than 95.58% of C++ online submissions for K Closest Points to Origin.
Memory Usage: 36.6 MB, less than 98.72% of C++ online submissions for K Closest Points to Origin.
*/

class Solution {
private:
    bool further(vector<int>& point , vector<int>& pivot){
        return (pow(point[0] , 2) + pow(point[1] , 2) > pow(pivot[0] , 2) + pow(pivot[1] , 2));
    }

    bool closer(vector<int>& point , vector<int>& pivot){
        return (pow(point[0] , 2) + pow(point[1] , 2) < pow(pivot[0] , 2) + pow(pivot[1] , 2));
    }

    int partition(vector<vector<int>>& points , int left , int right){
        int pivot = left , l = left + 1 , r = right;
        while (l <= r){
            if (further(points[l] , points[pivot]) && closer(points[r] , points[pivot])){
                swap(points[l++] , points[r--]);
            }
            if (!further(points[l] , points[pivot])){
                l++;
            }
            if (!closer(points[r] , points[pivot])){
                r--;
            }
        }
        swap(points[pivot] , points[r]);
        return r;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int left = 0 , right = points.size() - 1;
        while (true){
            int p = partition(points , left , right);
            if (p == K -1){
                break;
            }
            else if(p > K - 1){
                right = p - 1;
            }
            else{
                left = p + 1;
            }
        }
        return vector<vector<int>> (points.begin() , points.begin() + K);
    }
};
