#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
#include <regex>

using namespace std;

uint32_t first(ifstream &stream);

class Game 
{
    public: 
        int game;
        int blue;
        int red;
        int green;
        bool valid;

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
    int sum = 0;
    int sum2 = 0;
    string line;
    uint32_t currentNumber;
    string currentString;

    uint32_t MAX_RED = 12;
    uint32_t MAX_GREEN = 13;
    uint32_t MAX_BLUE = 14;

    string round; 
    string color;
    vector<Game> gameVector;

    while (getline(stream, line)) 
    {
        int pos = line.find(':');
        
        Game a;
        a.game = stoi(line.substr(5, pos-5));
        a.blue = 0;
        a.green = 0;
        a.red = 0;
        a.valid = true;

        string gameContent = line.substr(pos+1, line.length());
        // printf("SUBSTRING: %s | POS: %d\n",gameContent.c_str(), pos);

        sregex_iterator words_begin(line.begin(), line.end(), color_seperation);
        sregex_iterator words_end;

        // cout << "GAME " << a.game << ": ";
        for (sregex_iterator i = words_begin; i != words_end; ++i) 
        {
            smatch match = *i;
            currentNumber = (stoi)(match[1].str());
            currentString =  match[2].str();

            // cout << "Number: " << currentNumber << ", Color: " << currentString;
            
            if (currentString == "blue") 
            {
                if (currentNumber > MAX_BLUE) 
                {
                    a.valid = false;
                }
                if (currentNumber > a.blue) 
                {
                    a.blue = currentNumber;
                }
            }
            else if (currentString == "red") 
            {
                if (currentNumber > MAX_RED) 
                {
                    a.valid = false;
                }
                if (currentNumber > a.red) 
                {
                    a.red = currentNumber;
                }
            }
            else if (currentString == "green") 
            {
                if (currentNumber > MAX_GREEN) 
                {
                    a.valid = false;
                }
                if (currentNumber > a.green) 
                {
                    a.green = currentNumber;
                }
            }
        }

        if (a.valid) 
        {
            cout << "VALID GAME: "<< a.game<< endl;
            sum += a.game;
        }
        gameVector.push_back(a);     
    }

    int length = gameVector.size();
    for (int i = 0; i < length; i++) 
    {
        Game a = gameVector[i];
        int product = a.blue * a.green * a.red;

        sum2 += product;
    }

    cout << endl << "SUM: " << sum << endl;
    
    cout << endl << "SUM2: " << sum2 << endl;

    return 0;
}
