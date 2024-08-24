#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100
#define MAX_M 100

// Directions for moving up, down, left, right
int rowDirection[] = {-1, 1, 0, 0};
int colDirection[] = {0, 0, -1, 1};

bool isValidMove(int maze[MAX_N][MAX_M], bool visited[MAX_N][MAX_M], int n, int m, int row, int col) {
    return (row >= 0) && (row < n) && (col >= 0) && (col < m)
            && (maze[row][col] == 1) && (!visited[row][col]);
}
 
bool dfs(int maze[MAX_N][MAX_M], bool visited[MAX_N][MAX_M], int n, int m, int startRow, int startCol, int endRow, int endCol) {
    if (startRow == endRow && startCol == endCol) {
        printf("(%d, %d)", startRow, startCol);
        return true;
    }

    visited[startRow][startCol] = true;

    for (int i = 0; i < 4; i++) {
        int newRow = startRow + rowDirection[i];
        int newCol = startCol + colDirection[i];

        if (isValidMove(maze, visited, n, m, newRow, newCol)) {
            if (dfs(maze, visited, n, m, newRow, newCol, endRow, endCol)) {
                printf(" <- (%d, %d)", startRow, startCol);
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    printf("Enter the number of rows and columns in the maze: ");
    scanf("%d %d", &n, &m);

    int maze[MAX_N][MAX_M];
    printf("Enter the maze matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    int startRow, startCol, endRow, endCol;
    printf("Enter the starting position (row and column): ");
    scanf("%d %d", &startRow, &startCol);
    printf("Enter the ending position (row and column): ");
    scanf("%d %d", &endRow, &endCol);

    bool visited[MAX_N][MAX_M] = {false};

    if (dfs(maze, visited, n, m, startRow, startCol, endRow, endCol)) {
        printf("\nPath found\n");
    } else {
        printf("No path found\n");
    }

    return 0;
}