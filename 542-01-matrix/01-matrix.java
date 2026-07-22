import java.util.ArrayDeque;
import java.util.Queue;

class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;

        // Queue stores array of size 3: {row, col, current_distance}
        Queue<int[]> que = new ArrayDeque<>();
        int[][] res = new int[m][n];

        // Step 1: Push all '0's into the queue to start multi-source BFS
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    que.offer(new int[]{i, j, 0});
                }
            }
        }

        // Direction arrays for traveling Up, Down, Left, Right
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Step 2: Process the queue level-by-level
        while (!que.isEmpty()) {
            int[] cell = que.poll();
            int cr = cell[0];
            int cc = cell[1];
            int ct = cell[2]; // current distance/time

            for (int[] dir : dirs) {
                int nr = cr + dir[0];
                int nc = cc + dir[1];
                int newTime = ct + 1;

                // If neighbor is within bounds and is an unvisited '1'
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] != 0) {
                    que.offer(new int[]{nr, nc, newTime});
                    mat[nr][nc] = 0;       // Mark as visited in-place
                    res[nr][nc] = newTime;  // Store the shortest distance
                }
            }
        }

        return res;
    }
}