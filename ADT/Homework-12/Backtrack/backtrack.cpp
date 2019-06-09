
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class ChessBoard
{

public:
    int n;
    vector<string> possibilities;
    ChessBoard(int n)
    {
        this->n = n;
    }

    //Start function
    void start()
    {
        int **board = new int *[this->n];
        for (int i = 0; i < this->n; i++)
        {
            board[i] = new int[this->n];
        }
        this->assistFunction(board, 0);
    }
    string get_result(int **board)
    {
        //  The representation of the output
        string output = "";
        output += "\n  ________________\n |";
        for (int row = 0; row < this->n; row++)
        {
            for (int col = 0; col < this->n; col++)
            {
                if (board[row][col] == 0)
                {
                    output += " o ";
                }
                else
                {
                    output += " X ";
                }
            }
            if (row == 0 || row == this->n - 1)
            {
            }
            output += "| \n |";
        }
        output += "_______________|\n";

        return output;
    }
    //This is a helper function to add the result
    void assistFunction(int **board, int cCol)
    {

        if (cCol == this->n)
        {
            possibilities.push_back(get_result(board));
            return;
        }

        // Going through all the rows in column to find a suitable field
        int **tempBoard;
        for (int row = 0; row < this->n; row++)
        {
            // Check if the poition can be a valid position
            if (this->canPlace(board, row, cCol))
            {
                tempBoard = this->copyBoard(board);
                tempBoard[row][cCol] = 1;
                assistFunction(tempBoard, cCol + 1);
            }
        }

        return;
    }

    int **copyBoard(int **tempBoard)
    {
        // Copying the board from the tempBoard
        int **newBoard = new int *[this->n];
        for (int i = 0; i < this->n; i++)
        {
            newBoard[i] = new int[this->n];
        }

        for (int i = 0; i < this->n; i++)
        {
            for (int j = 0; j < this->n; j++)
            {
                newBoard[i][j] = tempBoard[i][j];
            }
        }

        return newBoard;
    }

    bool canPlace(int **board, int row, int col)
    {
        int trow, tcol;
        // Here we check through all the possible horse moviement
        // Below are the case how the horse moves

        // UP, UP, LEFT
        trow = row - 2;
        tcol = col - 1;
        if (!freeCell(board, trow, tcol))
            return false;

        // UP, UP, RIGHT
        trow = row - 2;
        tcol = col + 1;
        if (!freeCell(board, trow, tcol))
            return false;

        // UP, LEFT, LEFT
        trow = row - 1;
        tcol = col - 2;
        if (!freeCell(board, trow, tcol))
            return false;

        // UP, RIGHT, RIGHT
        trow = row - 1;
        tcol = col + 2;
        if (!freeCell(board, trow, tcol))
            return false;

        // DOWN, DOWN, LEFT
        trow = row + 2;
        tcol = col - 1;
        if (!freeCell(board, trow, tcol))
            return false;

        // DOWN, DOWN, RIGHT
        trow = row + 2;
        tcol = col + 1;
        if (!freeCell(board, trow, tcol))
            return false;

        // LEFT, LEFT, DOWN
        trow = row + 1;
        tcol = col - 2;
        if (!freeCell(board, trow, tcol))
            return false;

        // RIGHT, RIGHT, DOWN
        trow = row + 1;
        tcol = col + 2;
        if (!freeCell(board, trow, tcol))
            return false;

        return true;
    }

    // Method to check if the cell is free
    bool freeCell(int **board, int row, int col)
    {
        if (col >= 0 && row >= 0 && col < this->n && row < this->n)
        {
            // checking if it already filled with a Horse
            if (board[row][col] != 0)
            {
                return false;
            }
        }
        return true;
    }
    // Method to print all the possibilities
    void alloutputs()
    {
        cout << " These are the outputs for n = " << this->n << endl;
        for (string s : this->possibilities)
        {
            cout << s;
        }
    }
};

// Main function  printing the possible outputs
int main(int argc, char **argv)
{
    int inputSize = 5;
    ChessBoard board = ChessBoard(inputSize);
    board.start();
    board.alloutputs();
    return 0;
}
