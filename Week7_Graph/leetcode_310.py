"""
Runtime: 76 ms, faster than 96.33% of Python3 online submissions for Minimum Height Trees.
Memory Usage: 17.8 MB, less than 47.40% of Python3 online submissions for Minimum Height Trees.
"""

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n <= 2:
            return list(range(n))
        graph = collections.defaultdict(set)

        for a , b in edges:
            graph[a].add(b)
            graph[b].add(a)

        leaves = [node for node in graph if len(graph[node]) == 1]

        while n > 2:
            n -= len(leaves)
            new_leaves = []
            for leaf in leaves:
                node = graph[leaf].pop() # leaf only has one connection
                graph[node].remove(leaf)
                if len(graph[node]) == 1:
                    new_leaves.append(node)
            leaves = new_leaves

        return leaves
