/**
Runtime: 4 ms, faster than 92.48% of C++ online submissions for Super Egg Drop.
Memory Usage: 8.2 MB, less than 92.48% of C++ online submissions for Super Egg Drop.
*/

class Solution {
private:
    int f(int T , int K , int N){
        int r = 1 , ans = 0;
        for (int i = 1 ; i <= K ; ++i){
            r *= T - i + 1;
            r /= i;
            ans += r;
            if (ans >= N){
                return ans;
            }
        }
        return ans;
    }
public:
    int superEggDrop(int K, int N) {
        int l = 1 , h = N;

        while (l < h){
            int m = l + ((h - l) >> 1);
            if (f(m , K , N) < N){
                l = m + 1;
            }
            else{
                h = m;
            }
        }
        return l;
    }
};
