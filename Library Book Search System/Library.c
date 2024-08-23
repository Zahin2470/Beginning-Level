#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 15
#define MAX_COLS 15
#define MAX_BOOKS 100

typedef struct {
    char title[50];
    int row;
    int col;
} Book;

typedef struct {
    int row;
    int col;
} QueueNode;

typedef struct {
    QueueNode nodes[MAX_ROWS * MAX_COLS];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int row, int col) {
    if (q->rear == MAX_ROWS * MAX_COLS - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->nodes[q->rear].row = row;
    q->nodes[q->rear].col = col;
}

QueueNode dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue underflow\n");
        exit(1);
    }
    QueueNode node = q->nodes[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return node;
}

int binarySearch(Book books[], int n, char *title);
void bfs(int startRow, int startCol, int destRow, int destCol, int rows, int cols, int library[MAX_ROWS][MAX_COLS]);
void printPath(int parent[MAX_ROWS][MAX_COLS][2], int destRow, int destCol);
int loadBooksFromFile(const char *filename, Book books[], int maxBooks);

int main() {
    Book books[MAX_BOOKS];
    int numBooks = loadBooksFromFile("books.txt", books, MAX_BOOKS);

    if (numBooks == -1) {
        printf("Error loading books from file.\n");
        return 1;
    }

    int library[MAX_ROWS][MAX_COLS] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    char title[50];
    printf("Enter The Book Title to Search for : ");
    scanf("%[^\n]%*c", title);

    int index = binarySearch(books, numBooks, title);
    if (index == -1) {
        printf("Book not found.\n");
        return 0;
    }

    int userRow, userCol;
    printf("Enter Book's Current Location (Row & Column) : ");
    scanf("%d %d", &userRow, &userCol);

    printf("Searching for '%s' at (%d, %d)...\n", books[index].title, books[index].row, books[index].col);
    bfs(userRow, userCol, books[index].row, books[index].col, MAX_ROWS, MAX_COLS, library);

    return 0;
}

int loadBooksFromFile(const char *filename, Book books[], int maxBooks) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return -1;
    }

    int count = 0;
    while (count < maxBooks && fscanf(file, "%[^,],%d,%d\n", books[count].title, &books[count].row, &books[count].col) == 3) {
        count++;
    }

    fclose(file);
    return count;
}

int binarySearch(Book books[], int n, char *title) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(books[mid].title, title);
        if (cmp == 0)
            return mid;
        if (cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void bfs(int startRow, int startCol, int destRow, int destCol, int rows, int cols, int library[MAX_ROWS][MAX_COLS]) {
    int visited[MAX_ROWS][MAX_COLS] = {0};
    int parent[MAX_ROWS][MAX_COLS][2];
    Queue queue;
    initQueue(&queue);

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    enqueue(&queue, startRow, startCol);
    visited[startRow][startCol] = 1;
    parent[startRow][startCol][0] = -1;
    parent[startRow][startCol][1] = -1;

    while (!isQueueEmpty(&queue)) {
        QueueNode current = dequeue(&queue);

        if (current.row == destRow && current.col == destCol) {
            printf("Path found : ");
            printPath(parent, destRow, destCol);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newRow = current.row + directions[i][0];
            int newCol = current.col + directions[i][1];

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol] && library[newRow][newCol] == 0) {
                enqueue(&queue, newRow, newCol);
                visited[newRow][newCol] = 1;
                parent[newRow][newCol][0] = current.row;
                parent[newRow][newCol][1] = current.col;
            }
        }
    }

    printf("No Path Found to The destination \n");
}

void printPath(int parent[MAX_ROWS][MAX_COLS][2], int destRow, int destCol) {
    if (parent[destRow][destCol][0] == -1 && parent[destRow][destCol][1] == -1) {
        printf("(%d, %d)\n", destRow, destCol);
        return;
    }

    printPath(parent, parent[destRow][destCol][0], parent[destRow][destCol][1]);
    printf(" -> (%d, %d)\n", destRow, destCol);
}