/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) 
{
    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = *matrixColSize - 1;
    
    int* result = (int*)malloc(matrixSize * (*matrixColSize) * sizeof(int));
    int index = 0;

    while (top <= bottom && left <= right) 
    {
        // Traverse from left to right
        for (int j = left; j <= right; j++) 
        {
            result[index++] = matrix[top][j];
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++) 
        {
            result[index++] = matrix[i][right];
        }
        right--;

        if (top <= bottom) 
        {
            // Traverse from right to left
            for (int j = right; j >= left; j--) 
            {
                result[index++] = matrix[bottom][j];
            }
            bottom--;
        }

        if (left <= right) 
        {
            // Traverse from bottom to top
            for (int i = bottom; i >= top; i--) 
            {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }

    *returnSize = index;
    return result;    
}