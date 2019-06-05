/**
Runtime: 4 ms, faster than 96.92% of C++ online submissions for Partition to K Equal Sum Subsets.
Memory Usage: 8.6 MB, less than 60.91% of C++ online submissions for Partition to K Equal Sum Subsets.
*/

class Solution {
public:
   // use global variables to avoid verbose parameter passing
   int target; // sum of each bucket
   vector< int > Nums;
   vector< int > buckets;

   bool canPartitionKSubsets( vector<int>& nums, int k ) {
       int sum = 0;
       for( auto& n : nums ) {
         sum += n;
       }
       if( sum % k ){
         return false;
       }
       target = sum / k;
       Nums = vector< int >(nums);
       buckets = vector< int >(k, 0);
       // starting with bigger numbers will make it faster
       sort(Nums.begin(), Nums.end());
       reverse(Nums.begin(), Nums.end());
       return put(0);
   }

   // returns whether possible to put nums[n:] into buckets
   bool put(int n){
       for(int i = 0; i < buckets.size(); ++i) { // try every bucket
           if( buckets[i] + Nums[n] > target ){
             continue; // too large, try next bucket
           }
           buckets[i] += Nums[n];
           if(n == Nums.size() - 1) {
             return true; // all items in bucket, no overflow
           }
           if(put(n + 1)){
             return true; // means we can put nums[n:]
           }
           else{ // no solution = wrong bucket
               buckets[i] -= Nums[n]; // take it out
               if(buckets[i] == 0) {
                 return false; // no need to try other empty bucket
               }
           }
       }
       return false; // no bucket fits
   }
};
