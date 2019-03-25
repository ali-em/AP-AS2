#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
void split(string sentence, int start, vector<string> source, string answer);
void readFile(vector<string> &words);
void getInputs(vector<string> &sentences);
void solve(vector<string> &sentences, vector<string> &words);

int main()
{
    string answer;
    vector<string> words, sentences;
    readFile(words);
    getInputs(sentences);
    solve(sentences, words);
}

void split(string sentence, int start, vector<string> source, string answer)
{
    if (start == sentence.size())
        cout << answer << endl;
    string word;

    for (int n = 1; (n + start) <= sentence.size(); n++)
    {
        word = sentence.substr(start, n);

        if (find(source.begin(), source.end(), word) != source.end())
            split(sentence, start + n, source, answer + word + (start + n != sentence.size() ? " " : ""));
    }
}

void readFile(vector<string> &words)
{
    string temp;
    ifstream wordsFile("words.txt");
    while (getline(wordsFile, temp))
        words.push_back(temp);
    wordsFile.close();
}
void getInputs(vector<string> &sentences)
{
    string temp;
    while (getline(cin, temp))
        sentences.push_back(temp);
}
void solve(vector<string> &sentences, vector<string> &words)
{
    string answer = "";
    for (int i = 0; i < sentences.size(); i++)
    {
        split(sentences[i], 0, words, answer);

        cout << "***" << endl;
    }
}