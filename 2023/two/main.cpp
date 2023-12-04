#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>

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

        while ((pos = gameContent.find(';')) != -1)
        {
            round = gameContent.substr(0, pos);
            // printf("ROUND: %s | SUBSTRING: %s | POS: %d\n",round.c_str(), gameContent.c_str(), pos);   
            gameContent = gameContent.substr(pos+1, gameContent.length());
            cout << "New ROUND: " << round << endl;

            while ((pos = round.find(',')) != -1)
            {
                color = round.substr(0, pos);
                printf("GAME: %d:  %s\n",a.game, color.c_str());
                round = round.substr(pos+1, round.length());

                

                if ((pos = round.find(',')) != -1)
                {
                    color = round;
                }
            }


        }
        
    }

    return sum;
}

bool isPossible(string line)
{
    uint32_t MAX_RED = 12;
    uint32_t MAX_BLUE = 13;
    uint32_t MAX_GREEN = 14;

    vector<uint32_t> number;

    return false;

}
