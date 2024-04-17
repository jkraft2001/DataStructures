// CS400HuffmanCodingNew.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <unordered_map>

// TODO: Huffman tree node
struct Node {
    
    
    



    
};

// TODO: Comparison struct for priority queue
struct CompareNodes {
    





};





// TODO: Function to build the Huffman tree
Node* buildHuffmanTree(const std::unordered_map<char, int>& frequencies) {
    




















}

// TDO: Function to traverse the Huffman tree and generate codes
void generateHuffmanCodes(Node* root, std::string code, std::unordered_map<char, std::string>& codes) {
    














}

// hw7
// TODO: Function to perform Huffman coding on the input string
std::string huffmanEncode(const std::string& input) {
    

















    
}

// hw8
// TODO: Function to perform Huffman decoding on the encoded string
std::string huffmanDecode(const std::string& encodedString, Node* root) {
    


















}


int main() {
    std::string input = "ABBCCCDDDD";

    std::unordered_map<char, int> frequencies;
    for (char c : input) {
        frequencies[c]++;
    }

    Node* root = buildHuffmanTree(frequencies);
    std::unordered_map<char, std::string> codes;
    generateHuffmanCodes(root, "", codes);

    // print codes 
    for (auto i : codes) {
        std::cout << "key: " << i.first << "\tvalue: " << i.second << std::endl;
    }

    std::string encodedString = huffmanEncode(input);
    std::cout << "Encoded string: " << encodedString << std::endl;

    std::string decodedString = huffmanDecode(encodedString, root);
    std::cout << "Decoded string: " << decodedString << std::endl;

    delete root;
    return 0;
}

