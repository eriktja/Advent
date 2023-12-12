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

    regex numR(R"(-?\d+)");

    while (getline(stream, line))
    {
        sregex_iterator start(line.begin(), line.end(), numR);
        sregex_iterator end;

        vector<int> numbers;

        for(sregex_iterator i = start; i != end; i++)
        {
            smatch m = *i;
            for (int j = 0; j < m.size(); j++)
            {
                int b = stoi(m[j].str());

                cout << " " << b << " ";

                numbers.push_back(b);
            }
        }
        cout << endl << endl;
        int a = rec(numbers);
        numbers.clear();
        // cout << endl << endl << "NUMBER2: " << a << endl;
        sum += a;
    }

    cout << "SUM: " << sum << endl;

    return 0;
}

int rec(vector<int> &numbers)
{
    bool work = false;
    vector<int> subVector;
    for (int i = 0; i < numbers.size()-1; i++)
    {
        int diff =  numbers[i] - numbers[i+1];
        if (diff != 0)
        {
            work = true;
        }

        if (diff < 0)
        {
            diff *= -1;
        }

        cout <<  "NUMBERS: " << numbers[i] << " - " << numbers[i+1] << "  DIFF: " << diff << endl;

        subVector.push_back(diff);
    }
    
    int last = 0;
    if (work)
    {
        last = rec(subVector);
    }

    int prev = numbers[numbers.size()-1];

    // cout << endl << "ADD " << last << " + " << prev << endl;
    
    int result = last + prev;
 
    return result;
}