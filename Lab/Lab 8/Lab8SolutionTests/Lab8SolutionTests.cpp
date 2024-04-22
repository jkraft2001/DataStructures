// CS400Lab8StringFrequency.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
// TODO: include the header file for std::stringstream
#include <sstream>

using namespace std;

// Prints frequencies of 
// individual words in str
void printFrequencies(const std::string& str)
{

    // TODO:
    // declaring map of <string, int> type, 
    // each word is mapped to its frequency
    unordered_map<string, int> fq;

    // TODO:
    // breaking input into word using 
    // string stream
    // Used for breaking words
    stringstream ss(str);

    // TODO:
    // To store individual words
    string word;

    // TODO:
    // now iterating over word, freq pair 
    // and printing them in <, > format
    while (ss >> word) {
        fq[word]++;
    }

    for (const auto& pair : fq) {
        cout << "(" << pair.first << ", " << pair.second << ")\n";
    }
}

// Test code
int main()
{
    std::string str = "do not let trouble trouble you do";
    cout << str << endl;
    printFrequencies(str);
    return 0;
}


// your output: 
// (you, 1)
// (do, 2)
// (let, 1)
// (not, 1)
// (trouble, 2)