#include<iostream>
#include<stdlib.h>
#include<time.h>
#define rows 31
#define cols 31
using namespace std;

void generate_maze(char maze[rows][cols]);

void dfs(char maze[rows][cols], int x, int y);
