class Solution {
    private static final int MOD = 1_000_000_007;

    public int subsequencePairCount(int[] nums) {
        int maxVal = 0;

        for (int num : nums)
            maxVal = Math.max(maxVal, num);

        long[][] dp = new long[maxVal + 1][maxVal + 1];
        dp[0][0] = 1;

        for (int num : nums) {
            long[][] next = new long[maxVal + 1][maxVal + 1];

            for (int g1 = 0; g1 <= maxVal; g1++) {
                for (int g2 = 0; g2 <= maxVal; g2++) {
                    if (dp[g1][g2] == 0)
                        continue;

                    next[g1][g2] =
                        (next[g1][g2] + dp[g1][g2]) % MOD;

                    int newG1 = gcd(g1, num);
                    int newG2 = gcd(g2, num);

                    next[newG1][g2] =
                        (next[newG1][g2] + dp[g1][g2]) % MOD;

                    next[g1][newG2] =
                        (next[g1][newG2] + dp[g1][g2]) % MOD;
                }
            }

            dp = next;
        }

        long ans = 0;

        for (int g = 1; g <= maxVal; g++)
            ans = (ans + dp[g][g]) % MOD;

        return (int) ans;
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }
}