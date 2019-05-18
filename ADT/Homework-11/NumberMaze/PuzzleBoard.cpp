#include <cstdlib>
#include <iostream>
#include "PuzzleBoard.h"
#define INF INT8_MAX
using namespace std;

int main(int argc, char const **argv)
{
    // Null matrix
    int **matrix = NULL;
    // Size of the board
    int dim;

    cout << "\nWelcome to the Puzzle Game\n"
         << endl;
    cout << "Input the Size ? ";
    cin >> dim;
    // Creating a PuzzleBoard
    PuzzleBoard puzzle(dim, matrix);
    cout << "\n      THE PUZZLE BOARD" << endl;
    cout << "--------------------------------" << endl;

    // Printing the PuzzleBoard
    cout << puzzle << endl
         << endl;
    cout << "--------------------------------" << endl;

    // Solving the PuzzleBoard
    int steps = puzzle.solve();

    if (steps != INF)
    {
        cout << " \n |=> Minimum Steps : " << steps << endl;
    }
    else
    {
        cout << "The puzzle is not solvable :( !! " << endl;
    }
    cout << endl;
    return 0;
}
