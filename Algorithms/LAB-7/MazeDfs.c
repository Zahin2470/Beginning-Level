#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a cell can be included in DFS
bool isSafe(int matrix[][6], int visited[][6], int row, int col, int n, int m)
{
    // row number is in range, column number is in range and value is 1
    // and not yet visited
    return (row >= 0) && (row < n) && (col >= 0) && (col < m) &&
           (matrix[row][col] == 1 && !visited[row][col]);
}

// A utility function to do DFS for a 2D boolean matrix. It only considers
// the 8 neighbors as adjacent vertices
void DFS(int matrix[][6], int visited[][6], int row, int col, int n, int m)
{
    // These arrays are used to get row and column numbers of 8 neighbors
    // of a given cell
    static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Mark this cell as visited
    visited[row][col] = 1;

    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isSafe(matrix, visited, row + rowNbr[k], col + colNbr[k], n, m))
            DFS(matrix, visited, row + rowNbr[k], col + colNbr[k], n, m);
}

// The main function that returns count of islands in a given boolean
// 2D matrix
int countIslands(int matrix[][6], int n, int m)
{
    // Make a bool array to mark visited cells.
    int visited[6][6];
    memset(visited, 0, sizeof(visited));

    // Initialize count as 0 and traverse through the all cells of
    // given matrix
    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (matrix[i][j] && !visited[i][j])
            { // If a cell with
                // value 1 is not visited yet, then new island found
                DFS(matrix, visited, i, j, n, m); // Visit all cells in
                // this island and increment island count
                ++count;
            }

    return count;
}

int main()
{
    int matrix[6][6] = {
        {0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}};

    printf("Number of islands is: %d\n", countIslands(matrix, 6, 6));

    return 0;
}