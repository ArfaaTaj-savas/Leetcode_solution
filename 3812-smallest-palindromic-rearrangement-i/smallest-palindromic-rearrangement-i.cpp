#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        vector<char> chars;
        for (auto &p : freq) chars.push_back(p.first);
        sort(chars.begin(), chars.end());

        string left = "", mid = "";

        for (char c : chars) {
            if (freq[c] % 2 == 1) mid = c;  // middle character if odd count
            left += string(freq[c] / 2, c); // half of each character
        }

        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }
};
