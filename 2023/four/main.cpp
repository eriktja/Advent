#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include "../../../../../../usr/include/c++/11/bits/stream_iterator.h"


using namespace std;

uint32_t first(ifstream &stream);

typedef struct {
    uint32_t cardName;
} Card;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("USAGE: %s <filename>\n", argv[0]);
    }

    ifstream fileinput(argv[1]);

    first(fileinput);

    // string s = "What is the right way to split a string into a vector of strings";
    

    return 0;
}

uint32_t first(ifstream &stream)
{
    string line;
    uint32_t sum = 0;
    int gameNumber = 1;
    while(getline(stream, line))
    {

        int colonSplit = line.find(':');
        if (colonSplit)
        {
            string allNumbers = line.substr(colonSplit, line.size() - colonSplit);
            
            int barSplit = allNumbers.find('|');

            if (barSplit)
            {
                vector<uint32_t> winningNumberVector;
                vector<uint32_t> submittedNumberVector;
                stack<uint32_t> temp;
                string winningNumbers = allNumbers.substr(0, barSplit);

                // GATHER WINNING NUMBERS
                for (int i = 0; i < winningNumbers.size(); i++)
                {
                    if (isdigit(winningNumbers[i]))
                    {
                        temp.push((int)winningNumbers[i] - 48);
                    }
                    else if (!temp.empty())
                    {
                        uint32_t lol = 0;
                        uint32_t multiplier = 1;
                        while (!temp.empty())
                        {
                            lol +=  temp.top() * multiplier;
                            multiplier *= 10;
                            temp.pop();
                        }
                        winningNumberVector.push_back(lol);
                    }
                }
                if (!temp.empty())
                {
                    uint32_t lol = 0;
                    uint32_t multiplier = 1;
                    while (!temp.empty())
                    {
                        lol +=  temp.top() * multiplier;
                        multiplier *= 10;
                        temp.pop();
                    }
                    winningNumberVector.push_back(lol);
                }

                // PRINT WINNING NUMBERS
                // cout << "GAME " << gameNumber << ": ";
                // for (int i = 0; i < winningNumberVector.size(); i++)
                // {
                //     cout << winningNumberVector[i] << ", ";
                // }
                // cout << endl;

                string submittedNumbers = allNumbers.substr(barSplit, allNumbers.size() - barSplit);

                for (int i = 0; i < submittedNumbers.size(); i++)
                {
                    if (isdigit(submittedNumbers[i]))
                    {
                        temp.push((int)submittedNumbers[i] - 48);
                    }
                    else if (!temp.empty())
                    {
                        uint32_t lol = 0;
                        uint32_t multiplier = 1;
                        while (!temp.empty())
                        {
                            lol +=  temp.top() * multiplier;
                            multiplier *= 10;
                            temp.pop();
                        }
                        submittedNumberVector.push_back(lol);
                    }
                }
                if (!temp.empty())
                {
                    uint32_t lol = 0;
                    uint32_t multiplier = 1;
                    while (!temp.empty())
                    {
                        lol +=  temp.top() * multiplier;
                        multiplier *= 10;
                        temp.pop();
                    }
                    submittedNumberVector.push_back(lol);
                }

                if (gameNumber == 3)
                {
                    for (int i = 0; i < winningNumberVector.size(); i++)
                    {
                        cout << winningNumberVector[i] << " ";
                    }
                    cout << " | ";

                    for (int i = 0; i < submittedNumberVector.size(); i++)
                    {
                        cout << submittedNumberVector[i] << " ";
                    }
                    cout << endl;
                }

                uint32_t count = 0;

                for (int i = 0; i < submittedNumberVector.size(); i++)
                {
                    for (int j = 0; j < winningNumberVector.size(); j++)
                    {
                        if (submittedNumberVector[i] == winningNumberVector[j])
                        {
                            if (count == 0)
                            {
                                count = 1;
                            }
                            else 
                            {   
                                count *= 2;
                            }
                        }
                    }
                }

                cout << "COUNT: " << count << endl;
                sum += count;
            }

        }

        gameNumber++;
    }

    cout << "SUM: " << sum << endl;
    return 0;
}