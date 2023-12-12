#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int first(ifstream &stream);
int compareHands(vector<int> &h1, vector<int> &h2);
int countEqual(const std::vector<int>& vec);
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

    ranked.push_back(hands[0]);
    for (int i = 1; i < hands.size(); i++)
    {
        
        for (int j = 0; j < ranked.size(); j++)
        {
            int c = compareHands(hands[i].cards, ranked[j].cards);

            // if (c == )
        }
    }


    return 0;
}

int countEqual(const vector<int>& vec) 
{
    int count = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[i] == vec[j]) {
                count++;
            }
        }
    }
    return count;
}

int compareHands(vector<int> &h1, vector<int> &h2)
{
    int count1 = countEqual(h1);
    int count2 = countEqual(h2);

    if (count1 == 5 || count2 == 5) {
        return (count1 == count2) ? 0 : (count1 > count2) ? 1 : -1;
    } else if (count1 == 4 || count2 == 4) {
        return (count1 == count2) ? 0 : (count1 > count2) ? 1 : -1;
    } else if (count1 == 3 || count2 == 3) {
        return (count1 == count2) ? 0 : (count1 > count2) ? 1 : -1;
    } else if (count1 == 2 && countEqual(h1) == 2 || count2 == 2 && countEqual(h2) == 2) {
        return (count1 == count2) ? 0 : (count1 > count2) ? 1 : -1;
    } else if (count1 == 2 || count2 == 2) {
        return (count1 == count2) ? 0 : (count1 > count2) ? 1 : -1;
    } else {
        return 0;
    }
}