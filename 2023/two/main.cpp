#include <fstream>
#include <iostream>

using namespace std;

uint32_t first(ifstream stream);
class Game 
{
    public: 
        int game;
        int blue;
        int red;
        int green;

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

    Game a = Game(1, 2, 3, 4);

    inputfile.close();
    return 0;
}

uint32_t first(ifstream stream)
{
    uint32_t sum;
    string line;


    return 0;
}

