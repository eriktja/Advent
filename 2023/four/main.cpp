#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

uint32_t first(ifstream &stream);

typedef struct {
    uint32_t cardName;
    vector<uint32_t> numbers;
} Card;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("USAGE: %s <filename>\n", argv[0]);
    }

    ifstream fileinput(argv[1]);

    first(fileinput);

    return 0;
}

uint32_t first(ifstream &stream)
{
    string line;

    while(getline(stream, line))
    {
        cout << line << endl;

        int delimPos = line.find(':');
        if (delimPos)
        {
            cout << line.substr(0, delimPos) << endl;
        }
    }

    return 0;
}