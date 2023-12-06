#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
#include <regex>

using namespace std;

uint32_t first(ifstream &stream);
bool isPossible(string line);
class Game 
{
    public: 
        int game;
        int blue;
        int red;
        int green;

    Game(){}
    Game(int game, int blue, int red, int green):game(game),blue(blue),red(red),green(green){}

};

regex const color_seperation(R"((\d+)\s+(\w+))");

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
    }

    ifstream inputfile(argv[1]);

    if (!inputfile.is_open())
    {
        printf("Failed to open input file\n");
    }

    uint32_t a = first(inputfile);

    inputfile.close();
    return 0;
}

uint32_t first(ifstream &stream)
{
    uint32_t sum;
    string line;

    uint32_t MAX_RED = 12;
    uint32_t MAX_BLUE = 13;
    uint32_t MAX_GREEN = 14;

    string round; 
    string color;


    while (getline(stream, line)) 
    {
        int pos = line.find(':');
        
        Game a;
        a.game = stoi(line.substr(5, pos-5));

        string gameContent = line.substr(pos+1, line.length());
        // printf("SUBSTRING: %s | POS: %d\n",gameContent.c_str(), pos);

        sregex_iterator words_begin(line.begin(), line.end(), color_seperation);
        sregex_iterator words_end;

        cout << "GAME " << a.game << ": ";
        for (sregex_iterator i = words_begin; i != words_end; ++i) {
            smatch match = *i;
            cout << "Number: " << match[1] << ", Color: " << match[2];
        }

        cout << endl;
    }

    return 0;
}

bool isPossible(string line)
{
    uint32_t MAX_RED = 12;
    uint32_t MAX_BLUE = 13;
    uint32_t MAX_GREEN = 14;

    vector<uint32_t> number;

    return false;

}
