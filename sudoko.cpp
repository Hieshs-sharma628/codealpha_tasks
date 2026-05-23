#include <iostream>
using namespace std;
class sudoko
{
    char problem[9][9];

public:
    sudoko(const char arr[9][9])
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                problem[i][j] = arr[i][j];
            }
        }
    }
    
    // Check if placing character ch at (row,col) is valid
    bool isSafe(int row, int col, char ch)
    {
        for (int i = 0; i < 9; i++)
        {
            if (problem[row][i] == ch)
                return false;
            if (problem[i][col] == ch)
                return false;
        }
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;
        for (int r = sr; r < sr + 3; r++)
        {
            for (int c = sc; c < sc + 3; c++)
            {
                if (problem[r][c] == ch)
                    return false;
            }
        }
        return true;
    }

    // Backtracking solver operating on the member `problem`
    bool solve()
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (problem[row][col] == '.')
                {
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (isSafe(row, col, ch))
                        {
                            problem[row][col] = ch;
                            if (solve())
                                return true;
                            problem[row][col] = '.';
                        }
                    }
                    return false; // no valid digit
                }
            }
        }
        return true; // solved
    }
    void display()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << problem[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    char array[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},

        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},

        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    sudoko a(array);
    cout << "Initial board:\n";
    a.display();
    if (a.solve())
    {
        cout << "\nSolved board:\n";
        a.display();
    }
    else
    {
        cout << "\nNo solution found" << endl;
    }
    return 0;
}
