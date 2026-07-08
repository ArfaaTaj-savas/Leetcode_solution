// Approach
// I first build nonZeroCount.

// nonZeroCount[i] stores how many non-zero digits exist in the first i characters of s.

// For a query [l, r]:

// left = nonZeroCount[l]

// right = nonZeroCount[r + 1]

// So the required non-zero digits are exactly the compressed range [left, right).

// Next, I build three more prefix arrays over the compressed non-zero digits.

// prefixValue[i] stores the number formed by the first i non-zero digits, modulo 10^9 + 7.

// prefixSum[i] stores the sum of the first i non-zero digits.

// power10[i] stores 10^i modulo 10^9 + 7.

// Suppose I need the compressed range [left, right).

// Its length is:

// len = right - left

// The full prefix up to right contains:

// prefix before left + required range

// To remove the earlier digits, I shift prefixValue[left] left by len decimal places:

// prefixValue[left] * 10^len

// So I get:

// x = prefixValue[right] - prefixValue[left] * power10[len]

// All operations are done modulo 10^9 + 7.

// The digit sum is simpler:

// sum = prefixSum[right] - prefixSum[left]

// Then the answer is:

// x * sum mod (10^9 + 7)

// If the query contains no non-zero digits, then left == right. The same formula naturally gives x = 0 and sum = 0, so the answer is also 0.


class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007LL;
        int n = s.size();

        vector<int> nonZeroCount(n + 1, 0);

        vector<int> digits;

        for (int i = 0; i < n; i++) {
            nonZeroCount[i + 1] = nonZeroCount[i];

            if (s[i] != '0') {
                nonZeroCount[i + 1]++;
                digits.push_back(s[i] - '0');
            }
        }

        int k = digits.size();

        vector<long long> prefixValue(k + 1, 0);

        vector<long long> prefixSum(k + 1, 0);

        vector<long long> power10(k + 1, 1);

        for (int i = 0; i < k; i++) {
            prefixValue[i + 1] = (prefixValue[i] * 10 + digits[i]) % MOD;

            prefixSum[i + 1] = prefixSum[i] + digits[i];

            power10[i + 1] = (power10[i] * 10) % MOD;
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];

            int left = nonZeroCount[l];

            int right = nonZeroCount[r + 1];

            int len = right - left;

            long long x = (
                prefixValue[right]
                - (prefixValue[left] * power10[len]) % MOD
                + MOD
            ) % MOD;

            long long sum = prefixSum[right] - prefixSum[left];

            answer.push_back((int)((x * sum) % MOD));
        }

        return answer;
    }
};