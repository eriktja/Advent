#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

// Function to convert spelled-out digits to numbers
int convertToNumber(const std::string& word) {
    static std::unordered_map<std::string, int> wordToNumber = {
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
        {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };

    if (wordToNumber.find(word) != wordToNumber.end()) {
        return wordToNumber[word];
    }
    return -1; // Return -1 if word not found (not a spelled-out digit)
}

// Function to calculate the sum of calibration values
int calculateCalibrationSum(const std::string& document) {
    int sum = 0;
    size_t pos = 0;
    while (pos != std::string::npos) {
        pos = document.find_first_of("0123456789", pos); // Find the first digit

        if (pos != std::string::npos) {
            size_t end_pos = document.find_first_not_of("abcdefghijklmnopqrstuvwxyz", pos);
            std::string substring = document.substr(pos, end_pos - pos);

            // If the substring contains a spelled-out digit, convert it
            int digit = convertToNumber(substring);

            // If not a spelled-out digit, parse the character as an integer
            if (digit == -1) {
                digit = document[pos] - '0';
            }

            // Find the last digit
            size_t last_digit_pos = document.find_last_of("0123456789", end_pos);
            if (last_digit_pos != std::string::npos) {
                int last_digit = document[last_digit_pos] - '0';
                sum += digit * 10 + last_digit; // Combine first and last digits
            }
            pos = end_pos;
        }
    }
    return sum;
}

using namespace std;
int main() {
    // Your input document as a string
    ifstream inputfile("input.txt");
    string line;

    if (!inputfile.is_open())
    {
        cout << "Failed to open input file\n";
    }
    while (getline(inputfile, line)) {
        int calibrationSum = calculateCalibrationSum(line);
        std::cout << "Sum of calibration values: " << calibrationSum << std::endl;
    }
    inputfile.close();
    return 0;
}
