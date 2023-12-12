#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int first(ifstream &stream);
int compareHands(vector<int> &h1, vector<int> &h2);
typedef struct
{
    vector<int> cards;
    int bid;
    int kind;
} Hand;



int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("USAGE: %s <filename>\n", argv[0]);
    }

    ifstream fileinput(argv[1]);

    if (!fileinput.is_open())
    {
        printf("Failed to open file, %s\n", argv[1]);
        return 1;
    }

    first(fileinput);

    return 0;
}

int first(ifstream &stream)
{

    map<char, int> cards;
    cards['2'] = 2;
    cards['3'] = 3;
    cards['4'] = 4;
    cards['5'] = 5;
    cards['6'] = 6;
    cards['7'] = 7;
    cards['8'] = 8;
    cards['9'] = 9;
    cards['T'] = 10;
    cards['J'] = 11;
    cards['Q'] = 12;
    cards['K'] = 13;
    cards['A'] = 14;

    int sum = 0;
    string line;
    regex handReg(R"((\w+)\s(\d+))");

    vector<Hand> hands;
    vector<Hand> ranked;

    while(getline(stream, line))
    {

        sregex_iterator start(line.begin(), line.end(), handReg);
        sregex_iterator end;

        for (sregex_iterator i = start; i != end; i++)
        {
            smatch m = *i;
            Hand a;
            string handStr = m[1].str();

            a.bid = stoi(m[2].str());

            for (int j = 0; j < handStr.size(); j++)
            {
                a.cards.push_back(cards[handStr[j]]);
            }

            // sort(a.cards.begin(), a.cards.end(), greater<int>());

            hands.push_back(a);
        }
    }


    for (int i = 0; i < hands.size(); i++)
    {
        
        for (int j = 0; j < hands.size(); j++)
        {
            compareHands(hands[i].cards, hands[j].cards);
        }
    }


    return 0;
}

int compareHands(vector<int> &h1, vector<int> &h2)
{
    for (int i = 0; i < h1.size(); i++)
    {
    }

    return 0;
}