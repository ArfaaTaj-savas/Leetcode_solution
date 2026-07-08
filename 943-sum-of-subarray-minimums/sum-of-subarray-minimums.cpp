// Approaches
// (Also explained in the code)

// Monotonically Increasing Stack:

// The algorithm uses a monotonically increasing stack to keep track of the indices of elements in the array.
// Iterating Through Array:

// It iterates through the array and processes each element.
// Processing Elements:

// For each element, the algorithm checks if the stack is not empty and the current element is less than the element at the top of the stack.
// If true, it means the current element is a potential minimum for elements in the stack.
// Calculating Subarray Counts:

// For each element popped from the stack, the algorithm calculates the count of subarrays where that element is the minimum.
// The count is calculated by multiplying the difference between the left and right boundaries by the difference between the right boundary and the popped element.
// Calculating Contribution:

// The algorithm calculates the contribution of the current minimum to the sum of minimums.
// It multiplies the count by the value of the minimum and updates the sum of minimums.
// Modulo Operation:

// To prevent integer overflow, the algorithm performs the modulo operation (MOD) on intermediate and final results.
// Final Result:

// The final result is the sum of minimums of all subarrays.
// Complexity



// Time complexity:
// O(n)

// Space complexity:
// O(n)



class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1000000007;
        stack<int> st;
        long sumOfMinimums = 0;

        for (int i = 0; i <= arr.size(); i++) {
            while (!st.empty() && (i == arr.size() || arr[st.top()] >= arr[i])) {
                int mid = st.top();
                st.pop();
                int leftBoundary = st.empty() ? -1 : st.top();
                int rightBoundary = i;

                long count = (mid - leftBoundary) * (rightBoundary - mid) % MOD;

                sumOfMinimums += (count * arr[mid]) % MOD;
                sumOfMinimums %= MOD;
            }
            st.push(i);
        }

        return static_cast<int>(sumOfMinimums);
    }
};

