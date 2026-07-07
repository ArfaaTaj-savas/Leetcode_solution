// Approach
// Class Declaration and Member Functions:
// The Solution class contains two main functions:
// letterCombinations (public)
// solve (private)
// letterCombinations Function:
// This is the main function that the user calls.
// It initializes an empty vector ans to store the final letter combinations.
// If the input string digit is empty, it returns ans immediately.
// It defines a mapping array that maps each digit (0-9) to its corresponding letters.
// It then calls the recursive solve function to generate the combinations.
// solve Function:
// This is a helper function that performs the recursive backtracking to generate all combinations.

// Parameters:

// digit: The input digit string.
// output: The current combination being built.
// i: The current index in the digit string being processed.
// ans: The vector storing all the generated combinations.
// mapping: The array that maps digits to corresponding letters.
// Base Case:

// If i is greater than or equal to the length of digit, it means we have processed all digits. The current combination (output) is added to ans.
// Recursive Case:

// The digit at index i is converted to an integer num.
// The corresponding letters for this digit are retrieved from the mapping array.
// A loop iterates over these letters, adding each letter to the output string and recursively calling solve with the next index (i + 1).
// After the recursive call, the last added letter is removed from output to backtrack and try the next possible letter.
// Upvote! It only takes 1 click😉

// IF ANY DOUBT IN ABOVE APPROACH I HAVE GIVEN A STEP-BY-STEP EXAMPLE / DRY RUN -->
// Let's consider an example where digit = "23".

// Initial Call:
// letterCombinations("23") is called.
// solve("23", "", 0, ans, mapping) is called.
// First Level of Recursion (i = 0):
// num = 2, value = "abc".
// Loop through value:
// output = "a", call solve("23", "a", 1, ans, mapping).
// output = "b", call solve("23", "b", 1, ans, mapping).
// output = "c", call solve("23", "c", 1, ans, mapping).
// Second Level of Recursion (i = 1):
// For each recursive call from the first level, num = 3, value = "def".
// Loop through value:
// output = "ad", solve("23", "ad", 2, ans, mapping).
// output = "ae", solve("23", "ae", 2, ans, mapping).
// output = "af", solve("23", "af", 2, ans, mapping).
// Similarly for b and c from the first level.
// Third Level of Recursion (i = 2):
// For each recursive call from the second level, since i is now equal to digit.length(), output is added to ans.
// Backtracking:
// After each addition to ans, the function backtracks by removing the last added letter (output.pop_back()) and continues with the next letter in the loop.


// Complexity
// Time complexity: O(2n)
// Space complexity: O(2n)




class Solution {
private:
    void solve(string digit, string output, int i, vector<string>& ans,
               string mapping[]) {
        if (i >= digit.length()) {
            ans.push_back(output);
            return;
        }

        int num = digit[i] - '0';
        string value = mapping[num];

        for (int j = 0; j < value.length(); j++) {
            output.push_back(value[j]);
            solve(digit, output, i + 1, ans, mapping);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digit) {
        vector<string> ans;
        if (digit.length() == 0) {
            return ans;
        }
        int i = 0;
        string output;
        string mapping[10] = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digit, output, i, ans, mapping);
        return ans;
    }
};