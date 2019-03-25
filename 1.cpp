#include <iostream>
#include <string>
#include <vector>
using namespace std;
void antiCheat(string student);
void getInputs(vector<string> &students);
void solve(vector<string> &students);
int main()
{
        vector<string> students;
        getInputs(students);
        solve(students);
        return 0;
}

void antiCheat(string student)
{
        if (student.length() <= 1)
        {
                cout << student[0];
                return;
        }
        char last = student[student.length() - 1];
        student.pop_back();
        antiCheat(student);
        if (last != student[student.length() - 1])
                cout << last;
}
void getInputs(vector<string> &students)
{
        string temp;
        while (cin >> temp)
                students.push_back(temp);
}
void solve(vector<string> &students)
{
        for (int i = 0; i < students.size(); i++)
        {
                antiCheat(students[i]);
                cout << endl;
        }
}
