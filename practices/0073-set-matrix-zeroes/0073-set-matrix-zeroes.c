void setZeroes(int** matrix, int matrixSize, int* matrixColSize) 
{
    int firstRowHasZero = 0;
    int firstColHasZero = 0;

    // Check if the first row has any zeros
    for (int j = 0; j < *matrixColSize; j++) 
    {
        if (matrix[0][j] == 0) 
        {
            firstRowHasZero = 1;
            break;
        }
    }

    // Check if the first column has any zeros
    for (int i = 0; i < matrixSize; i++) 
    {
        if (matrix[i][0] == 0) 
        {
            firstColHasZero = 1;
            break;
        }
    }

    // Use the first row and column to mark zeros
    for (int i = 1; i < matrixSize; i++) 
    {
        for (int j = 1; j < *matrixColSize; j++) 
        {
            if (matrix[i][j] == 0)  
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set zeros based on markers in the first row and column
    for (int i = 1; i < matrixSize; i++) 
    {
        for (int j = 1; j < *matrixColSize; j++) 
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) 
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Set the first row to zero if needed
    if (firstRowHasZero == 1) 
    {
        for (int j = 0; j < *matrixColSize; j++) 
        {
            matrix[0][j] = 0;
        }
    }

    // Set the first column to zero if needed
    if (firstColHasZero == 1) 
    {
        for (int i = 0; i < matrixSize; i++) 
        {
            matrix[i][0] = 0;
        }
    }    
}