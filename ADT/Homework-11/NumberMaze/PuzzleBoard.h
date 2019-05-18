#include <iostream>
#include <queue>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "Cell.h"
using namespace std;

#define INF INT8_MAX

class PuzzleBoard
{
private:
    int boardSize;
    Cell **fields;
    // Keep track of current locations
    int CurX;
    int CurY;

public:
    PuzzleBoard(int boardSize, int **fields)
    {
        // Initially the board starts at the top left
        CurX = 0;
        CurY = 0;
        this->boardSize = boardSize;

        srand(time(0));
        this->fields = new Cell *[boardSize];
        if (this->fields == NULL)
        {
            std::cout << "Error allocating the memory" << std::endl;
            exit(1);
        }
        for (int i = 0; i < boardSize; i++)
        {
            this->fields[i] = new Cell[boardSize];
            if (this->fields[i] == NULL)
            {
                std::cout << "Error allocating the memory" << std::endl;
                exit(1);
            }
        }

        for (int i = 0; i < this->boardSize; ++i)
        {
            for (int j = 0; j < this->boardSize; ++j)
            {
                this->fields[i][j].steps = INF;
                this->fields[i][j].x = i;
                this->fields[i][j].y = j;
                if (fields)
                {
                    //Copying thr value
                    this->fields[i][j].value = fields[i][j];
                }
                else
                {
                    //Setting random values
                    int cellval = (rand() % (this->boardSize - 1)) + 1;
                    this->fields[i][j].value = cellval;
                }
            }
        }
    }

    //Checking the bounds
    bool CheckBounds(int i, int j)
    {
        if (i >= this->boardSize || i < 0 || j >= this->boardSize || j < 0)
        {
            return false;
        }
        // std::cout << "Here" << std::endl;
        return true;
    };

    // Helper function to make move and check if the move is possible
    bool checkset(int x, int y, int newX, int newY)
    {
        if (this->CheckBounds(newX, newY))
        {
            if (fields[newX][newY].steps > (fields[x][y].steps + 1))
            {
                CurX = newX;
                CurY = newY;
                fields[newX][newY].steps = (fields[x][y].steps + 1);
                return true;
            }
        }
        else
        {
            return false;
        }
        return false;
    };

    // Method to make move in a certain direction if possible
    bool makeMove(int direction)
    {
        int x = this->CurX;
        int y = this->CurY;
        int newposX, newposY;

        if (direction == 0)
        {
            // Condition of Back Direction
            newposY = y;
            newposX = x - fields[x][y].value;
            return checkset(x, y, newposX, newposY);
        }
        else if (direction == 1)
        {
            // Condition of Back Up direction
            newposX = x;
            newposY = y + fields[x][y].value;
            return checkset(x, y, newposX, newposY);
        }
        else if (direction == 2)
        {
            // Condition of Front
            newposX = x + fields[x][y].value;
            newposY = y;
            return checkset(x, y, newposX, newposY);
        }
        else if (direction == 3)
        {
            // Condition of Down Direction
            newposX = x;
            newposY = y - fields[x][y].value;
            return checkset(x, y, newposX, newposY);
        }
        return false;
    }

    // Output of the Puzzle Board
    friend std::ostream &operator<<(std::ostream &out, PuzzleBoard const &src)
    {
        for (int i = 0; i < src.boardSize; ++i)
        {
            out << "\n      ";
            for (int j = 0; j < src.boardSize; ++j)
            {
                out << " | " << src.fields[i][j].value;
            }
        }
        return out;
    }

    // Method to solve the puzzle
    int solve()
    {
        fields[0][0].steps = 0;
        //A priority queue where we compare the cells of the table
        priority_queue<Cell> priorityQ;
        priorityQ.push(fields[0][0]);
        Cell pick;

        //Dijkstra’s algorithm to solve the problem
        while (!priorityQ.empty())
        {
            pick = priorityQ.top();
            priorityQ.pop();
            this->CurX = pick.x;
            this->CurY = pick.y;

            //Loop for 4 different directions
            for (int i = 0; i < 4; ++i)
            {
                if (makeMove(i))
                {
                    int x = this->CurX;
                    int y = this->CurY;
                    this->CurX = pick.x;
                    this->CurY = pick.y;
                    priorityQ.push(fields[x][y]);
                }
            }
        }
        if (this->fields[this->boardSize - 1][this->boardSize - 1].steps == INF)
        {
            return INF;
        }
        else
        {
            return this->fields[this->boardSize - 1][this->boardSize - 1].steps;
        }
        return 0;
    }
    // Destructor
    ~PuzzleBoard()
    {
        for (int i = 0; i < boardSize; ++i)
            free(this->fields[i]);
        free(this->fields);
    }
};
