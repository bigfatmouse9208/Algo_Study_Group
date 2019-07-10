"""
Math Solution
Runtime: 36 ms, faster than 88.14% of Python3 online submissions for Super Egg Drop.
Memory Usage: 13.3 MB, less than 63.42% of Python3 online submissions for Super Egg Drop.
"""

class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        # first we define f(T,K) as the most solvable number of floors with T times and K eggs
        # so we have f(T,K)=1+f(T-1,K-1)+f(T-1,K), since at the optimal case, we throw the first egg at
        # a certain level, it either survives or breaks, then we apply the same function again.
        # with boundary condition being f(T,1)=T for T>=1 and f(1,K)=1 for K>=1
        # in order to solve f(T,K), consider g(T,K)=f(T,K)-f(T,K-1), it is easy to find g(T,K)=g(T-1,K)+g(T-1,K-1)
        # hence g(T,K) complies the cobination rule, meaning g(T,K)=C(T,K+1)
        # hence f(T,K)=sum(C(T,k) for k in range(1,K+1))
        # then we do a binary search to find the T such that f(T,K)>=N
        def f(x):
            ans = 0
            r = 1
            for i in range(1 , K + 1):
            # here to caculate f(T,K) faster, we use the translation relation:
            # C(n , k) * (n - k) / (k + 1) = C(n , k + 1)
                r *= x - i + 1
                r //= i
                ans += r
                if ans >= N:
                    return ans
            return ans

        l , h = 1 , N
        while l < h:
            m = l + ((h - l) >> 1)
            if f(m) < N:
                l = m + 1
            else:
                h = m
        return l


"""
naive dp solution
Runtime: 960 ms, faster than 19.07% of Python3 online submissions for Super Egg Drop.
Memory Usage: 19.4 MB, less than 41.46% of Python3 online submissions for Super Egg Drop.
"""

class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        dp = {} # dp[k , n] =superEggDrop(k , n)

        def max_floor(k , n):
            if n == 0: # no floors left
                return 0
            if k == 1: # only one egg, try one floor by one floor
                return n
            if (k , n) in dp:
                return dp[k , n]

            l , h = 1 , n
            while l + 1 < h:
                m = l + ((h - l) >> 1)
                t1 = max_floor(k - 1 , m - 1) # egg breaks
                t2 = max_floor(k , n - m) # egg survives
                """
                here comes the key, we know that max_floor(k,n)=1+min(max(max_floor(k-1,x-1),max_floor(k,n-x)) for x in (l,h)). so we analyze the behavior of the 2 arugments in the max(), which will either increase or decrease with x. so we can use bool(t1<t2) as a reference to guide us find the best m
                """
                if t1 < t2: # we can be more aggresive
                    l = m
                elif t1 > t2: # we need to be less aggresive
                    h = m
                else:
                    l = h = m

            dp[k , n] = 1 + min(max(max_floor(k - 1, x - 1), max_floor(k , n - x))
                                for x in (l , h)) # check both cases
            return dp[k , n]

        return max_floor(K , N)
