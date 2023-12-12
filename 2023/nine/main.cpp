#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int first(ifstream &stream);

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


        }
    }
}

int rec(vector<int> &numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {

    }
}