"""
Runtime: 56 ms, faster than 84.33% of Python3 online submissions for Median of Two Sorted Arrays.
Memory Usage: 13.4 MB, less than 51.36% of Python3 online submissions for Median of Two Sorted Arrays.
"""

class Solution:
    def findMedianSortedArrays(self, A, B): # median means there will be half values smaller than it, so we can call findKth
        l = len(A) + len(B)
        return self.findKth(A , B , l//2) if l % 2 == 1 else (self.findKth(A , B , l//2-1) + self.findKth(A , B , l//2)) / 2.0

    def findKth(self , A , B , k): # k-th means there will be k - 1 number smaller than it
        if len(A) > len(B): # keep A the shorter list, this will make sure A is the first to be empty which saves our work
            A , B = B , A
        if not A:
            return B[k]
        if k == len(A) + len(B) - 1:
            return max(A[-1] , B[-1])
        i = len(A)//2 # note this way to do binary search!! Each tiem we at least kill i number
        j = k - i
        if A[i] > B[j]: # meaing the k-th element will not in in A[i:] or B[:j] and we got j number already
            return self.findKth(A[:i] , B[j:] , i)
        else: # vice versa and we got i numbers already
            return self.findKth(A[i:] , B[:j] , j)
