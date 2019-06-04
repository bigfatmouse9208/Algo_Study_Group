/**
Runtime: 40 ms, faster than 85.14% of C++ online submissions for Strobogrammatic Number II.
Memory Usage: 26.3 MB, less than 28.44% of C++ online submissions for Strobogrammatic Number II.
*/

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if (n == 1){
            return vector<string> ({"1" , "8" , "0"});
        }
        if (n == 2){
            return vector<string> ({"11" , "88" , "69" , "96"});
        }
        vector<string> odd_seed ({"1" , "8" , "0"});
        vector<string> even_seed({"11" , "88" , "69" , "96" , "00"});
        int mid = (n - 1) >> 1;
        vector<string> res;
        if (n % 2){
            vector<string> prev = findStrobogrammatic(n - 1);
            for (auto& seed : odd_seed){
                for (auto& p : prev){
                    res.push_back(p.substr(0 , mid) + seed + p.substr(mid , mid));
                }
            }
        }
        else{
            vector<string> prev = findStrobogrammatic(n - 2);
            for (auto& seed : even_seed){
                for (auto& p : prev){
                    res.push_back(p.substr(0 , mid) + seed + p.substr(mid , mid));
                }
            }
        }
        return res;
    }
};
