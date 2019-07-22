"""
Runtime: 36 ms, faster than 83.21% of Python3 online submissions for Binary Watch.
Memory Usage: 13.7 MB, less than 5.52% of Python3 online submissions for Binary Watch.
"""
class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        hour = [1 , 2 , 4 , 8]
        minute = [1 , 2 , 4 , 8 , 16 , 32]

        def get_time(l , pool , limit):
            if l == 0:
                return ["0"]
            res = []
            for c in itertools.combinations(pool , l):
                h = sum(c)
                if h < limit:
                    res.append(str(h))
            return res

        res = []
        for l in range(num + 1):
            for h in get_time(l , hour , 12):
                for m in get_time(num - l , minute , 60):
                    res.append(h + ":" + "0" * (2 - len(m)) + m)

        return res
