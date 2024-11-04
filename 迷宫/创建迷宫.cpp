#include"迷宫函数.h"
#define wall  '#'
#define path ' '

void dfs(char maze[rows][cols],int x, int y) {
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };

    // 随机打乱方向数组
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp = dx[i];
        dx[i] = dx[j];
        dx[j] = temp;
        temp = dy[i];
        dy[i] = dy[j];
        dy[j] = temp;
    }

    // 对每个方向进行深度优先搜索
    for (int i = 0; i < 4; i++) {
        int nx = x + 2 * dx[i];
        int ny = y + 2 * dy[i];

        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && maze[nx][ny] == wall) {
            maze[nx][ny] = path;
            maze[x + dx[i]][y + dy[i]] = path;
            dfs(maze, nx, ny);
        }
    }
}

void generate_maze(char maze[rows][cols]) {
    system("cls");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = wall;
        }
    }
    maze[1][1] = path;
    srand((unsigned int) time(NULL));
    dfs(maze, 1, 1);

    int a = rand() % 2;
    if (a == 0) {
        int exit_col = rand() % cols;
        maze[rows - 1][exit_col] = path;
    }
    else {
        int exit_row = rand() % rows;
        maze[exit_row][cols -1] = path;
    }

}
