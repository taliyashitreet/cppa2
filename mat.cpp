#include "mat.hpp"
// #define low 33
// #define high 126
int const low=33;
int const high=126;

namespace ariel
{
    string mat(int col, int row, char sym1, char sym2)
    {
        if (col % 2 == 0 || row % 2 == 0 || col < 0 || row < 0)
        {
            throw invalid_argument("Mat size is always odd");
        }
        if (sym1<low || sym2<low || sym1>high || sym2>high)
        {
            throw invalid_argument("Not a valid symball");
        }
        string ans = string("");
        int plus = min(col, row)/2;
        char val=' ';
        vector< vector<char> > mymat(row, vector<char> (col, val)); 
        char symball = sym1;
        for (int i = 0; i <= plus; i++)
        {
            for (int r = i; r < row - i; r++)
            {
                mymat[r][i] = symball;
                mymat[r][col - i - 1] = symball;
            }
            for (int c = i; c < col - i; c++)
            {
                mymat[i][c] = symball;
                mymat[row - i - 1][c] = symball;
            }
            symball = (symball == sym1) ? sym2 : sym1;
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                ans += mymat[i][j];
            }
            ans += '\n';
        }
        return ans;
    }
}