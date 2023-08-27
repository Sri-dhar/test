#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

class Solution {
public:
    // Function to calculate the maximum safeness factor of a path in the grid
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(); // Get the size of the grid (assuming it's a square)
        
        vector<pair<int, int>> path; // Vector to store the coordinates of cells containing obstacles
        
        // Iterate through the entire grid to find cells with obstacles and store their coordinates in 'path'
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    path.push_back({r, c});
                }
            }
        }
        
        // Create a 2D vector to store the safeness factor for each cell in the grid
        vector<vector<int>> safeness(n, vector<int>(n, 0));
        
        // Iterate through each cell in the grid to calculate the safeness factor
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r == 0 && c == 0) { // If we are at the top-left corner of the grid
                    int minDist = INT_MAX; // Initialize a variable to store the minimum distance to an obstacle
                    
                    // Calculate the minimum Manhattan distance from this cell to any obstacle in the 'path'
                    for (auto& p : path) {
                        int dist = abs(r - p.first) + abs(c - p.second);
                        minDist = min(minDist, dist);
                    }
                    safeness[r][c] = minDist; // Store the minimum distance as the safeness factor for this cell
                } else {
                    // Calculate the safeness factor for other cells (not top-left corner)
                    int fromAbove = (r > 0) ? safeness[r - 1][c] : 0; // Safeness factor from the cell directly above (if it exists)
                    int fromLeft = (c > 0) ? safeness[r][c - 1] : 0; // Safeness factor from the cell directly to the left (if it exists)
                    safeness[r][c] = max(fromAbove, fromLeft); // Store the maximum of these two safeness factors
                    
                    int minDist = INT_MAX; // Initialize a variable to store the minimum distance to an obstacle
                    
                    // Calculate the minimum Manhattan distance from this cell to any obstacle in the 'path'
                    for (const auto& p : path) {
                        int dist = abs(r - p.first) + abs(c - p.second);
                        minDist = min(minDist, dist);
                    }
                    safeness[r][c] = min(safeness[r][c], minDist); // Update the safeness factor with the minimum distance
                }
            }
        }
        
        // Return the safeness factor of the bottom-right cell (cell at position (n-1, n-1))
        // This represents the maximum safeness factor of a path through the grid
        return safeness[n - 1][n - 1];
    }
};
