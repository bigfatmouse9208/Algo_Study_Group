/**
Runtime: 4 ms, faster than 93.58% of C++ online submissions for Number of Atoms.
Memory Usage: 10 MB, less than 19.20% of C++ online submissions for Number of Atoms.
*/

using namespace std;
class Solution {
public:
    string countOfAtoms(string formula) {
        unordered_map<string , int> counter = parse(formula , 0).first;
        set<string> atoms;
        for (auto& p : counter){
            atoms.insert(p.first);
        }
        string ans;
        for (auto& atom : atoms){
            ans += atom;
            if (counter[atom] > 1){
                ans += to_string(counter[atom]);
            }
        }
        return ans;
    }

    pair<unordered_map<string , int> , int> parse(string& formula , int idx){
        unordered_map<string , int> res;
        string atom;
        string prev_atom;
        unordered_map<string , int> prev_res;
        int n = formula.size();
        while (idx < n){
            if (isdigit(formula[idx])){
                int start = idx;
                while ((idx + 1 < n) and (isdigit(formula[idx + 1]))){
                    idx++;
                }
                int num = stoi(formula.substr(start , idx - start + 1));
                if (prev_res.size() != 0){
                    for (auto& p : prev_res){
                        res[p.first] = res[p.first] + p.second * num;
                    }
                    prev_res.clear();
                }
                else{
                    res[prev_atom] = res[prev_atom] + (num - 1);
                    prev_atom.clear();
                }
            }
            else{
                if (formula[idx] == '('){
                    auto tempres = parse(formula , idx + 1);
                    prev_res = tempres.first;
                    idx = tempres.second;
                }
                else{
                    if (formula[idx] == ')'){
                        pair<unordered_map<string , int> , int> ans (res , idx);
                        return ans;
                    }
                    else{
                        atom.push_back(formula[idx]);
                        while ((idx + 1 < n) and (islower(formula[idx + 1]))){
                            idx++;
                            atom.push_back(formula[idx]);
                        }
                        res[atom] = res[atom] + 1;
                        prev_atom = atom;
                        atom.clear();
                    }
                }
            }
            idx++;
        }
        if (prev_res.size() != 0){
            for (auto& p : prev_res){
                        res[p.first] = res[p.first] + p.second;
                    }
            prev_res.clear();
        }
        pair<unordered_map<string , int> , int> ans (res , idx);
        return ans;
    }
};
