#include <iostream>
#include <vector>
using namespace std;

bool hungerGame(vector<vector<char>> &Map, int move[4][2], vector<string> &answer);
void solve(vector<vector<char>> Map);
bool movePlayer(vector<vector<char>> &Map, int r, int c, int move[], int rowNo, int colNo);
string intToString(int x);
string moveLog(int r, int c, int m);
void getMap(vector<vector<char>> &Map, int rowNo, int colNo);

int main()
{
    int colNo, rowNo;
    cin >> rowNo >> colNo;
    vector<vector<char>> Map(rowNo, vector<char>(colNo));
    getMap(Map, rowNo, colNo);
    solve(Map);
}

void getMap(vector<vector<char>> &Map, int rowNo, int colNo)
{
    for (int r = 0; r < rowNo; r++)
        for (int c = 0; c < colNo; c++)
            cin >> Map[r][c];
}
void solve(vector<vector<char>> Map)
{
    vector<string> answer;
    int move[4][2] = {{2, 0}, {-2, 0}, {0, 2}, {0, -2}};

    if (hungerGame(Map, move, answer))
    {
        cout << "Insane!" << endl;
        for (int i = answer.size() - 1; i >= 0; i--)
            cout << answer[i] << endl;
    }
    else
        cout << "Bad map configuration!" << endl;
}
string intToString(int x)
{
    return string(1, (char)(x + '0'));
}
string moveLog(int r, int c, int m)
{
    return intToString(r + 1) + " " + intToString(c + 1) + " " + (m == 0 ? "D" : m == 1 ? "U" : m == 2 ? "R" : "L");
}

bool hungerGame(vector<vector<char>> &Map, int move[4][2], vector<string> &answer)
{
    int rowNo = Map.size(), colNo = Map[0].size(), NumberOfO = 0, newCol, newRow, killedCol, killedRow;

    for (int r = 0; r < rowNo; r++)
        for (int c = 0; c < colNo; c++)
        {
            if (Map[r][c] != 'o')
                continue;
            NumberOfO++;
            for (int m = 0; m < 4; m++)
            {
                newCol = move[m][1] + c;
                newRow = move[m][0] + r;
                killedRow = move[m][0] / 2 + r;
                killedCol = move[m][1] / 2 + c;

                if (movePlayer(Map, r, c, move[m], rowNo, colNo))
                {
                    if (hungerGame(Map, move, answer))
                    {
                        answer.push_back(moveLog(r, c, m));
                        return true;
                    }
                    Map[r][c] = 'o';
                    Map[newRow][newCol] = '#';
                    Map[killedRow][killedCol] = 'o';
                }
            }
        }
    if (NumberOfO == 1)
        return true;
    return false;
}
bool movePlayer(vector<vector<char>> &Map, int r, int c, int move[], int rowNo, int colNo)
{
    int newCol = move[1] + c,
        newRow = move[0] + r,
        killedRow = move[0] / 2 + r,
        killedCol = move[1] / 2 + c;

    if (newRow >= rowNo || newCol >= colNo ||
        newCol < 0 || newRow < 0 ||
        Map[newRow][newCol] != '#' || Map[killedRow][killedCol] != 'o')
        return false;

    Map[killedRow][killedCol] = Map[r][c] = '#';
    Map[newRow][newCol] = 'o';
    return true;
}