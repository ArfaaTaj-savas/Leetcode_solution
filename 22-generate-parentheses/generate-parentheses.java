class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        backtrack(0, 0, n, "", result);
        return result;
    }

    private void backtrack(int open, int close, int n,
                           String current, List<String> result) {
        if (current.length() == 2 * n) {
            result.add(current);
            return;
        }

        if (open < n)
            backtrack(open + 1, close, n, current + "(", result);

        if (close < open)
            backtrack(open, close + 1, n, current + ")", result);
    }
}