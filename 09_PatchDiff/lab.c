#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int room_cnt = 6;
    int maze_size = room_cnt * 2 + 1;

    char **maze = (char**)malloc(maze_size * sizeof(char*));
    for(int i = 0; i < maze_size; i++) {
        maze[i] = (char*)malloc(maze_size * sizeof(char));
    }

    char wall = '#';
    char empty = '.';

    for (int i = 0; i < maze_size; i++)
        for (int j = 0; j < maze_size; j++)
            maze[i][j] = wall;

    int x = 2 * (rand() % room_cnt) + 1;
    int y = 2 * (rand() % room_cnt) + 1;
    maze[x][y] = empty;

    bool flag;
    do
    {
        bool direction_is_valid = false;
        int direction;
        while (!direction_is_valid)
        {
            direction = rand() % 4; // 0 - left, 1 - up, 2 - right, 3 - down
            direction_is_valid = true;

            if (direction == 0 && x <= 1)
                direction_is_valid = false;
            if (direction == 1 && y <= 1)
                direction_is_valid = false;
            if (direction == 2 && x >= maze_size - 2)
                direction_is_valid = false;
            if (direction == 3 && y >= maze_size - 2)
                direction_is_valid = false;
        }

        if (direction == 0)
        {
            if (maze[x - 2][y] == wall)
            {
                maze[x - 2][y] = empty;
                maze[x - 1][y] = empty;
            }
            x -= 2;
        }
        else if (direction == 1)
        {
            if (maze[x][y - 2] == wall)
            {
                maze[x][y - 2] = empty;
                maze[x][y - 1] = empty;
            }
            y -= 2;
        }
        else if (direction == 2)
        {
            if (maze[x + 2][y] == wall)
            {
                maze[x + 2][y] = empty;
                maze[x + 1][y] = empty;
            }
            x += 2;
        }
        else if (direction == 3)
        {
            if (maze[x][y + 2] == wall)
            {
                maze[x][y + 2] = empty;
                maze[x][y + 1] = empty;
            }
            y += 2;
        }

        flag = true;
        for (int i = 0; i < maze_size; i++)
            for (int j = 0; j < maze_size; j++)
                if (i % 2 == 1 && j % 2 == 1 && maze[i][j] == wall)
                    flag = false;
    } while (!flag);

    for (int i = 0; i < maze_size; i++)
    {
        for (int j = 0; j < maze_size; j++)
            printf("%c", maze[i][j]);
        printf("\n");
    }

    for(int i = 0; i < maze_size; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}