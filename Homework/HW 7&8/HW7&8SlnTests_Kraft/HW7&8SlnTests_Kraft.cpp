#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// Huffman tree node
struct Node {
    char data;
    int frequency;
    Node* left, * right;
    Node(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparison struct for priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

// Function to build the Huffman tree
Node* buildHuffmanTree(const unordered_map<char, int>& frequencyMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto& pair : frequencyMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Merge nodes until there is only one node left in the queue
    while (pq.size() != 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* merged = new Node('$', left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    // The remaining node is the root of the Huffman tree
    return pq.top();
}

// Function to traverse the Huffman tree and generate codes
void generateHuffmanCodes(Node* root, string code, unordered_map<char, string>& codes) {
    if (root == nullptr) return;

    if (root->data != '$') {
        codes[root->data] = code;
    }

    generateHuffmanCodes(root->left, code + "0", codes);
    generateHuffmanCodes(root->right, code + "1", codes);
}

// Function to perform Huffman coding on the input string
string huffmanEncode(const string& input) {
    unordered_map<char, int> frequencyMap;
    for (char c : input) {
        frequencyMap[c]++;
    }

    Node* root = buildHuffmanTree(frequencyMap);
    unordered_map<char, string> codes;
    generateHuffmanCodes(root, "", codes);

    string encodedString = "";
    for (char c : input) {
        encodedString += codes[c];
    }

    // Free memory
    delete root;

    return encodedString;
}

// Function to perform Huffman decoding on the encoded string
string huffmanDecode(const string& encodedString, Node* root) {
    string decodedString = "";
    Node* current = root;
    for (char bit : encodedString) {
        if (bit == '0') {
            current = current->left;
        }
        else {
            current = current->right;
        }

        if (current->left == nullptr && current->right == nullptr) {
            decodedString += current->data;
            current = root;
        }
    }
    return decodedString;
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

    // Free memory
    delete root;

    return 0;
}
