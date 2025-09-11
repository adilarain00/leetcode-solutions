class Solution {
public:
    vector<string> res;
    vector<string> mapping = {
        "",    "",    "abc",  "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string& digits, int index, string current) {
        if (index == digits.size()) {
            res.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for (char ch : letters) {
            backtrack(digits, index + 1, current + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        backtrack(digits, 0, "");
        return res;
    }
};
