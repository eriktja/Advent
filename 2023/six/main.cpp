#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;

typedef struct {
    long duration;   // FROM INPUT
    long record;     // FROM INPUT
    int lowest;     // LOWEST TIME TO HOLD THE BUTTON
    int highest;    // HIGHEST TIME TO HOLD THE BUTTON
    int count;      // COUNT OF WINNING ALTERNATIVES (highest - lowest, I guess..)
} Race;

int first(ifstream &stream);
int second(ifstream &stream);
int recoredBeater(Race race);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
    }

    ifstream fileinput(argv[1]);

    if(!fileinput.is_open())
    {
        printf("Failed to open file: %s\n", argv[1]);
        return 1;
    }

    string line;

    second(fileinput);

    return 0;
}


int first(ifstream &stream)
{
    vector<Race> races;
    vector<string> s1;
    string line;
    int sum = 1;
    vector<int> durations;
    vector<int> records;
    regex nums(R"(\d+)");

    while(getline(stream, line))
    {
        s1.push_back(line);
    }
    
    
    sregex_iterator start1(s1[0].begin(), s1[0].end(), nums);
    sregex_iterator end1;

    for (sregex_iterator i = start1; i != end1; i++)
    {
        smatch m = *i;

        for (int i = 0; i < m.size(); i++)
        {
            int num1 = (stoi)(m[i]);
            durations.push_back(num1);
        }
    }
    sregex_iterator start(s1[1].begin(), s1[1].end(), nums);
    sregex_iterator end;

    for (sregex_iterator i = start; i != end; i++)
    {
        smatch m = *i;
        for (int i = 0; i < m.size(); i++)
        {
            int num1 = (stoi)(m[i]);
            records.push_back(num1);
        }
    }

    for (int i = 0; i < durations.size(); i++)
    {
        cout << "DURATION: " << durations[i] << "\t|\tRECORD: " << records[i] << endl;

        Race a;
        a.duration = durations[i];
        a.record = records[i];
        races.push_back(a);

        a.count = recoredBeater(a);
        cout << "COUNT: " << a.count << endl;

        sum *= a.count;
    }

    cout << endl << "SUM: " << sum << endl;

    return 0;
}

int second(ifstream &stream)
{
    Race race;
    vector<string> s1;
    string line;
    int sum = 1;
    string durations;
    string records;
    regex nums(R"(\d+)");

    while(getline(stream, line))
    {
        s1.push_back(line);
    }
    
    
    sregex_iterator start1(s1[0].begin(), s1[0].end(), nums);
    sregex_iterator end1;

    for (sregex_iterator i = start1; i != end1; i++)
    {
        smatch m = *i;

        for (int i = 0; i < m.size(); i++)
        {
            string num1 = m[i].str();
            durations += num1;
        }
    }

    sregex_iterator start(s1[1].begin(), s1[1].end(), nums);
    sregex_iterator end;

    for (sregex_iterator i = start; i != end; i++)
    {
        smatch m = *i;

        for (int i = 0; i < m.size(); i++)
        {
            string num1 = m[i].str();
            records += num1;
        }
        
    }



    race.duration = stol(durations);
    race.record = stol(records);

    cout << race.duration << " " << race.record << endl;


    race.count = recoredBeater(race);
    cout << "COUNT: " << race.count << endl;

    sum = race.count;

    cout << endl << "SUM: " << sum << endl;

    return 0;
}

int recoredBeater(Race race)
{
    int result = 0;
    long sum;
    
    for (int i = 0; i <= race.duration; i++)
    {
        sum = (race.duration - i) * i;
        if (sum > race.record)
        {
            result++;      
            // cout << "GAME: " << race.duration << "  DISTANCE: "  << sum << endl;
        }
    }

    return result;
}