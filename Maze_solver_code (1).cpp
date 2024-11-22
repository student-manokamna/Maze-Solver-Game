#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 20;

int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void printMaze(int maze[MAX_SIZE][MAX_SIZE], int height, int width) {
    cout << "+";
    for (int i = 0; i < width * 2 + 1; i++) cout << "-";
    cout << "+\n";

    for (int i = 0; i < height; i++) {
        cout << "| ";
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == 1)
                cout << "# ";
            else if (maze[i][j] == 2)
                cout << ". ";
            else
                cout << "  ";
        }
        cout << "|\n";
    }

    cout << "+";
    for (int i = 0; i < width * 2 + 1; i++) cout << "-";
    cout << "+\n";
}

bool isValid(int x, int y, int maze[MAX_SIZE][MAX_SIZE], int height, int width) {
    return (x >= 0 && y >= 0 && x < height && y < width && maze[x][y] == 0);
}

bool solveMaze(int x, int y, int maze[MAX_SIZE][MAX_SIZE], int height, int width) {
    if (x == height - 1 && y == width - 1) {
        maze[x][y] = 2;
        return true;
    }

    if (isValid(x, y, maze, height, width)) {
        maze[x][y] = 2;

        for (int i = 0; i < 4; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            if (solveMaze(newX, newY, maze, height, width)) {
                return true;
            }
        }
        maze[x][y] = 0;
    }

    return false;
}

int main() {
    int maze[MAX_SIZE][MAX_SIZE];
    int height, width;

    cout << "***************************************************\n";
    cout << "*                                                 *\n";
    cout << "*         Welcome to the Maze Solver Game!        *\n";
    cout << "*                                                 *\n";
    cout << "***************************************************\n\n";
    cout << "Solve the maze by finding a path from top-left to bottom-right!\n";
    cout << "You can create walls (1) and paths (0) in the maze.\n";
    cout << "Hashtags (#) represent walls, and dots (.) show the path.\n";
    cout << "Good luck!\n\n";

    cout << "Enter the dimensions of the maze (height and width): ";
    cin >> height >> width;

    cout << "Enter the maze (1 for wall, 0 for open space):\n";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> maze[i][j];
        }
    }

    cout << "\nInitial Maze:\n";
    printMaze(maze, height, width);

    if (solveMaze(0, 0, maze, height, width)) {
        cout << "\nCongratulationss! A path has been foundd! Yayyy!!\n";
    } else {
        cout << "\nOops!! No path could be found.\n";
    }

    cout << "\nSolved Maze:\n";
    printMaze(maze, height, width);

    cout << "***************************************************\n";
    cout << "*                                                 *\n";
    cout << "*       Thankk youu for playing Maze Solver!!        *\n";
    cout << "*                                                 *\n";
    cout << "***************************************************\n";

    return 0;
}
