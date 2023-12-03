#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

uint32_t first(ifstream &stream);
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

    while (getline(stream, line)) 
    {
        int pos = line.find(':');
        
        Game a;
        a.game = stoi(line.substr(5, pos-5));

        

    }

    return 0;
}

