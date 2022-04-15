/**
 * @File Name: 12 矩阵中的路径.cpp
 * @Brief : DFS
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-13
 *
 */
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (DFS(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

private:
    int rows, cols;
    bool DFS(vector<vector<char>> &board, string word, int i, int j, int k)
    {
        // 终止条件
        if (i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k])
            return false;
        if (k == word.size() - 1)
            return true;
        // 防止重复访问
        board[i][j] = '\0';

        bool res = DFS(board, word, i + 1, j, k + 1) ||
                   DFS(board, word, i, j + 1, k + 1) ||
                   DFS(board, word, i - 1, j, k + 1) ||
                   DFS(board, word, i, j - 1, k + 1);

        board[i][j] = word[k];
        return res;
    }
};