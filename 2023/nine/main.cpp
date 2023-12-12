#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int first(ifstream &stream);
int rec(vector<int> &numbers);

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

    fileinput.close();
    return 0;
}

int first(ifstream &stream)
{
    string line;

    int sum = 0;

    regex numR(R"(\d+)");

    while (getline(stream, line))
    {
        sregex_iterator start(line.begin(), line.end(), numR);
        sregex_iterator end;

        vector<int> numbers;

        for(sregex_iterator i = start; i != end; i++)
        {
            smatch m = *i;
            for (int j = 1; j < m.size(); j++)
            {
                numbers.push_back(stoi(m[j].str()));
            }

            int a = rec(numbers);
            cout << "NUMBER: " << a << endl;

            sum += a;

        }
    }

    cout << "SUM: " << sum << endl;
}

int rec(vector<int> &numbers)
{
    bool work = false;
    vector<int> subVector;
    for (int i = 0; i < numbers.size()-1; i++)
    {
        int num = numbers[i+1] - numbers[i];
        if (num != 0)
        {
            work = false;
        }
        subVector.push_back(numbers[i+1] - numbers[i]);
    }
    int last = 0;
    if (work)
    {
        last = rec(subVector);
    }

    int prev = numbers[numbers.size()-2];
    
    return last + prev;
}