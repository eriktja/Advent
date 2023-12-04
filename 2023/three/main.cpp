#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <sstream>
using namespace std;

uint32_t first(ifstream &stream);
uint32_t second(ifstream &stream);
bool isAdjacent(vector<string> &lines, int row, int startIndex, int endIndex, char symbol);
string positionOfSymbol(vector<string> &lines, int row, int startIndex, int endIndex, char symbol);



int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>", argv[0]);
    }

    ifstream fileinput(argv[1]);

    if (!fileinput.is_open())
    {
        printf("Failed to open file");
        return 1;
    }

    second(fileinput);

    fileinput.close();
    return 0;
}

uint32_t first(ifstream &stream)
{
    string line;
    vector<string> lines;
    vector<uint32_t> number;
    uint32_t sum = 0;
    
    while (getline(stream, line))
    {
        lines.push_back(line);
    }

    int lineSize = lines.size();

    for (int i = 0; i < lineSize; i++)
    {
        string current = lines[i];
        int length = current.size();
        
        for (int j = 0; j < length; j++)
        {
            if (isdigit(current[j]))
            {
                number.push_back((int)current[j] - 48);

                if (j+1 >=length || !isdigit(current[j+1]))
                {
                    if (number.size() > 0 && isAdjacent(lines, i, j - number.size(), j, '.')) 
                    {
                        int combined = 0;
                        int nSize = number.size();
                        for (int k = 0; k < nSize; k++)
                        {
                            combined += number[k] * pow(10, nSize - k - 1);
                        }
                        printf("NUMBER: %d\n", combined);

                        sum += combined;
                        number.clear();
                    }
                }
            }
            if (current[j] == '.')
            {
                number.clear();
            }
        }
    }

    printf("SUM: %d\n", sum);
    return 0;
}

bool isAdjacent(vector<string> &lines, int row, int startIndex, int endIndex, char symbol)
{
    int length = lines.size();

    for (int i = row - 1; i <= row+1; i++)
    {
        if (i >= 0 && i < length)
        {
            for (int j = startIndex; j <= endIndex+1; j++)
            {
                // printf("CHECK: %c @ ROW %d | INDEX: %d \n", lines[i][j], i, j);
                if (j >= 0 && lines[i][j] != symbol && j < lines[i].size())
                {
                    if (!isdigit(lines[i][j]))
                    {
                        printf("DATA: %s | ROW: %d | START: %d | END: %d | ", lines[row].c_str(), row, startIndex, endIndex);
                        return true;
                    }
                }
            }
        }
    }

    return false;
}



uint32_t second(ifstream &stream)
{
    string line;
    vector<string> lines;
    vector<uint32_t> number;
    uint32_t sum = 0;
    unordered_map<string, vector<uint32_t>> symbols;
    
    while (getline(stream, line))
    {
        lines.push_back(line);
    }

    int lineSize = lines.size();

    for (int i = 0; i < lineSize; i++)
    {
        string current = lines[i];
        int length = current.size();
        
        for (int j = 0; j < length; j++)
        {
            if (isdigit(current[j]))
            {
                number.push_back((int)current[j] - 48);

                if (j+1 >=length || !isdigit(current[j+1]))
                {
                    string symbolPos = positionOfSymbol(lines, i, j - number.size(), j, '*');
                    if (number.size() > 0 && symbolPos != "") 
                    {
                        cout << "SYMBOL: " << symbolPos << endl;
                        int combined = 0;
                        int nSize = number.size();
                        for (int k = 0; k < nSize; k++)
                        {
                            combined += number[k] * pow(10, nSize - k - 1);
                        }
                        printf("NUMBER: %d\n", combined);

                        unordered_map<string, vector<uint32_t>>::const_iterator item = symbols.find(symbolPos);
                        if (item == symbols.end())
                        {
                            cout << "NEW" << endl;
                            vector<uint32_t> numbers;   
                            cout << "1" << endl;
                            numbers.push_back(combined);
                            cout << "2" << endl;
                            pair<string, vector<uint32_t>> a = make_pair(symbolPos, numbers);
                            cout << "3" << endl;
                            symbols.insert(a);
                            cout << "4" << endl;
                        }
                        else 
                        {
                            symbols[symbolPos].push_back((uint32_t)combined);
                        }
                        number.clear();
                    }
                }
            }
            if (current[j] == '.')
            {
                number.clear();
            }
        }
    }
    // cout << "END" << endl;

    // pair<string, vector<uint32_t>> it;
    for (auto& it: symbols) {
        if (it.second.size() == 2)
        {
            printf("SYMBOL: %s  | ", it.first.c_str());
            printf("NUMBERS: %d | %d\n", it.second[0], it.second[1]);
            sum += it.second[0] * it.second[1];
        }
    }
    printf("SUM: %d\n", sum);
    return 0;
}

string positionOfSymbol(vector<string> &lines, int row, int startIndex, int endIndex, char symbol)
{
    int length = lines.size();
    stringstream answer;
    for (int i = row - 1; i <= row+1; i++)
    {
        if (i >= 0 && i < length)
        {
            for (int j = startIndex; j <= endIndex+1; j++)
            {
                // printf("CHECK: %c @ ROW %d | INDEX: %d \n", lines[i][j], i, j);
                if (j >= 0 && lines[i][j] != '.' && j < lines[i].size())
                {
                    if (!isdigit(lines[i][j]) && lines[i][j] == symbol)
                    {
                        // printf("FOUND: %c | ROW %d | INDEX %d\n", lines[i][j], i, j);
                        // printf("DATA: %s | ROW: %d | START: %d | END: %d | ", lines[row].c_str(), row, startIndex, endIndex);

                        answer << i << " " << j;
                        return answer.str();
                    }
                }
            }
        }
    }

    return answer.str();
}

// WRONG
//  74613691  LOW  (No idea)
//  75312571  CORRECT. 
// 233770310  HIGH (USED TO MANY NUMBERS)