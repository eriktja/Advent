#include <iostream> 
#include <fstream>
#include <string.h>
#include <regex>

using namespace std;
uint32_t first(ifstream &stream);
uint32_t second(ifstream &stream);
uint32_t third(ifstream &stream);
uint32_t fourth(ifstream &stream);
typedef struct {
    std::string str;
    uint32_t num;
} loopup_t;

loopup_t gTable[] = {
    { std::string("1"), 1 },
    { std::string("2"), 2 },
    { std::string("3"), 3 },
    { std::string("4"), 4 },
    { std::string("5"), 5 },
    { std::string("6"), 6 },
    { std::string("7"), 7 },
    { std::string("8"), 8 },
    { std::string("9"), 9 },
    { std::string("one"), 1 },
    { std::string("two"), 2 },
    { std::string("three"), 3 },
    { std::string("four"), 4 },
    { std::string("five"), 5 },
    { std::string("six"), 6 },
    { std::string("seven"), 7 },
    { std::string("eight"), 8 },
    { std::string("nine"), 9 },
};

uint32_t match(const std::string &slice) {
    string word = string(slice);
    // cout << word << "\n";
    for (size_t i = 0; i < 18; ++i) {
        if (gTable[i].str == word) {
            return gTable[i].num;;
        }
    }
    return UINT32_MAX; 
}


int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        cout << "Usage: %s <filename>\n", argv[0];
    }


    ifstream inputfile(argv[1]);
    string line;

    if (!inputfile.is_open())
    {
        cout << "Failed to open input file\n";
    }

    fourth(inputfile);

    inputfile.close();

    return 0;
}


uint32_t first(ifstream &stream)
{
    uint32_t sum = 0;
    uint32_t first = -1;
    uint32_t last = -1;
    uint32_t numb = 0;

    string line;
    while ( getline(stream, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (isdigit(line[i]) && first == -1)
            {
                first = (int)line[i] -48;
            }
            if (isdigit(line[line.length() - 1 - i]) && last == -1)
            {
                last = (int)line[line.length() - 1 - i] - 48;
            }
            if (first != -1 && last != -1)
            {

                numb = first * 10 + last;
                sum += numb;

                first = -1;
                last = -1;
                break;
            }

        }
    }

    printf("SUM: %d\n", sum);

    return 0;
}

uint32_t second(ifstream &stream)
{
    uint32_t sum = 0;
    uint32_t first = -1;
    uint32_t last = -1;
    uint32_t numb = 0;
    uint32_t matchnum;
    string line;
    while ( getline(stream, line))
    {
        first = -1;
        last = -1;
        numb = 0;
        for (int i = 0; i < line.length(); i++)
        {
            if (isdigit(line[i]) && first == -1)
            {
                first = (int)line[i] -48;
            }
            else if (first == -1)
            {
                int length = line.length();
                int start = i;
                int end = 3;
                
                matchnum = UINT32_MAX;
                while (start <= end && start < length) 
                {
                    // printf("B  START: %d, END: %d, STRING: %s\n", start, end, line.substr(start, end).c_str());
                    matchnum = match(line.substr(start, end));
                    if (matchnum != UINT32_MAX)
                    {
                        // printf("FIRST: Got a str match: %d\n", matchnum);
                        first = matchnum;
                        start = end;
                    }
                    start++;
                    if (start == end && end < 6)
                    {
                        end++;
                        start = 0;
                    }
                }
            }

            if (isdigit(line[line.length() - 1 - i]) && last == -1)
            {
                last = (int)line[line.length() - 1 - i] - 48;
            }
            else if (last == -1)
            {
                int end = 2;
                int start = line.length() - end - i;
                matchnum = UINT32_MAX;
                while (end <= 6 && start > 0) 
                {
                    // printf("E  START: %d, END: %d\n", start, end);
                    // printf("B  START: %d, END: %d, STRING: %s\n", start, end, line.substr(start, end).c_str());
                    matchnum = match(line.substr(start, end));

                    if (matchnum != UINT32_MAX)
                    {
                        // printf("LAST: Got a str match: %d\n", matchnum);
                        last = matchnum;
                        end = start;
                    }
                    start--;
                    end++;
                }
            }

            if (first != -1 && last != -1)
            {

                numb = first * 10 + last;

                printf("NUMBERS: %d%d\n", first,last);

                sum += numb;

                first = -1;
                last = -1;
                break;
            }

        }
    }

    printf("SUM: %d\n", sum);

    return 0;
}

uint32_t fourth(ifstream &stream)
{
    uint32_t sum = 0;
    uint32_t first = -1;
    uint32_t last = -1;
    uint32_t numb = 0;
    uint32_t matchnum;
    string line;
    uint32_t length;

    while ( getline(stream, line))
    {
        first = -1;
        last = -1;
        numb = 0;
        length = line.length();

        for (int i = 0; i < length; i++)
        {
                for (int j = 0; j < length; j++)
                {
                    // printf("B  START: %d, END: %d, STRING: %s\n", i, j, line.substr(i, j).c_str());
                    matchnum = UINT32_MAX;
                    matchnum = match(line.substr(i, j));
                    if (matchnum != UINT32_MAX)
                    {
                        // printf("FIRST: Got a str match: %d\n", matchnum);
                        if (first == -1)
                        {
                            first = matchnum;
                        }
                        last = matchnum;
                        // printf("FIRST=%d :: LAST=%d\n", first, last);
                    }

                    // printf("E  START: %d, END: %d, STRING: %s\n", length-j, i, line.substr(length-j, i).c_str());
                    // matchnum = match(line.substr(length-j, i));
                    // if (matchnum != UINT32_MAX && last != -1)
                    // {
                    //     printf("LAST: Got a str match: %d\n", matchnum);
                    //     last = matchnum;
                    //     j = length;
                    //     i = length;
                    // }
                    // // if (first != -1 && last != -1)
                    // {
                    //     j = length;
                    //     i = length;
                    // }
                }

            
        }
        if (first != -1 && last != -1)
        {

            numb = first * 10 + last;

            printf("NUMBERS: %d%d\n", first,last);

            sum += numb;

            first = -1;
            last = -1;
        }

    }

    printf("SUM: %d\n", sum);

    return 0;
}

uint32_t third(ifstream &stream) {
    uint32_t sum = 0;
    string line;

    while (getline(stream, line)) {
        regex reg("([a-zA-Z]*)(\\d+)([a-zA-Z]*)"); // Regex pattern to find words and digits

        smatch match;
        if (std::regex_search(line, match, reg)) {
            // Extract the first and last digits/spelled-out digits
            int first = match[2].str()[0] - '0'; // Convert char to int
            int last = match[2].str().back() - '0'; // Convert char to int

            sum += first * 10 + last;
        }
    }

    cout << "SUM: " << sum << endl;
    return sum;
}