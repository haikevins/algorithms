
void dfs(char** grid, int gridSize, int gridColSize, int i, int j) 
{
    // Check for out-of-bounds or water
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize || grid[i][j] == '0') 
    {
        return;
    }

    // Mark the current cell as visited
    grid[i][j] = '0';

    // Explore all four directions
    dfs(grid, gridSize, gridColSize, i + 1, j); // Down
    dfs(grid, gridSize, gridColSize, i - 1, j); // Up
    dfs(grid, gridSize, gridColSize, i, j + 1); // Right
    dfs(grid, gridSize, gridColSize, i, j - 1); // Left
}

int numIslands(char** grid, int gridSize, int* gridColSize) 
{
    int count = 0;

    for (int i = 0; i < gridSize; i++) 
    {
        for (int j = 0; j < *gridColSize; j++) 
        {
            if (grid[i][j] == '1') 
            {
                count++;
                // Perform DFS to mark all connected land as visited
                dfs(grid, gridSize, *gridColSize, i, j);
            }
        }
    }

    return count;    
}