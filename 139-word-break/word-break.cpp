class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> canBuildFrom(s.size()+1);
        canBuildFrom[0] = true;

        for (int i = 0; i < canBuildFrom.size()-1; ++i) {
            if (!canBuildFrom[i]) continue;

            for (string& word : wordDict) {
                if (word == s.substr(i, word.size()))
                    canBuildFrom[i + word.size()] = true;
            }
        }

        return canBuildFrom[s.size()];
    }
};