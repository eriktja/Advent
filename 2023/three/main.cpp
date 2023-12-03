#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

uint32_t first(ifstream &stream);
bool isAdjacent(vector<string> &lines, int row, int startIndex, int endIndex);

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

    first(fileinput);

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
                    if (number.size() > 0 && isAdjacent(lines, i, j - number.size(), j)) 
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

bool isAdjacent(vector<string> &lines, int row, int startIndex, int endIndex)
{
    int length = lines.size();

    for (int i = row - 1; i <= row+1; i++)
    {
        if (i >= 0 && i < length)
        {
            for (int j = startIndex; j <= endIndex+1; j++)
            {
                // printf("CHECK: %c @ ROW %d | INDEX: %d \n", lines[i][j], i, j);
                if (j >= 0 && lines[i][j] != '.' && j < lines[i].size())
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
            // If (current[j] == '*')
            // Check adjacent for two numbers 
            // first = 0
            // second = 0;
            // sum += first x second; (hvis en av de er null så blir det jo null. #Winning)
            // Hva hvis det er tre tall??? Faen
            //// Finn first, og second. Om Det er en tredje. Continue

        }
    }

    printf("SUM: %d\n", sum);
    return 0;
}