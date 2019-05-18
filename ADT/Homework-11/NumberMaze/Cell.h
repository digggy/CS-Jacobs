// This is a Cell Class in the table of the puzzle board
class Cell
{
public:
    // x and y are it's indexes
    int x, y;
    // value is data
    int value;
    int steps;
    friend bool operator<(const Cell &cella, const Cell &cellb)
    {
        return (cella.steps < cellb.steps);
    }
};
