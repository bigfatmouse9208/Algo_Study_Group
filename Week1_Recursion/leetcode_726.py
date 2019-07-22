"""
Runtime: 32 ms, faster than 99.26% of Python3 online submissions for Number of Atoms.
Memory Usage: 13.2 MB, less than 52.97% of Python3 online submissions for Number of Atoms.
"""
from collections import Counter
class Solution:
    def countOfAtoms(self, formula: str) -> str:
        self.n = len(formula)
        self.formula = formula
        counter = self.parse(0)[0]
        return "".join(k + (str(counter[k]) if counter[k] > 1 else '')
                       for k in sorted(counter.keys()) )

    def parse(self , idx):# return counter and end index for ')'
        counter = Counter()
        prev = None
        while idx < self.n:
            if self.formula[idx].isdigit(): # number
                start = idx
                while idx + 1 < self.n and self.formula[idx + 1].isdigit():
                    idx += 1
                num = int(self.formula[start : idx + 1])
                if type(prev) == str: # atom
                    counter[prev] += num - 1 # already count the atom once by default
                else:
                    for x in prev: # parenthesis
                        counter[x] += prev[x] * num
                    prev = None
            elif self.formula[idx] == "(": # reach a parenthesis
                prev , idx = self.parse(idx + 1)
            elif self.formula[idx] == ")": # finishing a parenthesis, output our count
                return counter , idx
            else: # atom
                atom = self.formula[idx]
                while idx + 1 < self.n and self.formula[idx + 1].islower():
                    idx += 1
                    atom += self.formula[idx]
                counter[atom] += 1 # by default we have one atom
                prev = atom
            idx += 1
        if prev is not None and not type(prev) == str:
            for x in prev: # deal with last parenthesis
                counter[x] += prev[x]
        return counter , idx
