#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode* left, *right;
    MinHeapNode(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

void printCodes(struct MinHeapNode* root, string str) {
    if (root == nullptr) {
        return;
    }
    if (root->data != '$') {
        cout << root->data << ": " << str << endl;
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

struct compare {
    bool operator()(MinHeapNode* a, MinHeapNode* b) {
        return (a->freq > b->freq);
    }
};

void HuffmanCode(vector<char>& data, vector<int>& freq) {
    int size = data.size();
    struct MinHeapNode *left, *right, *temp;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; i++) {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        temp = new MinHeapNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        minHeap.push(temp);
    }
    printCodes(minHeap.top(), "");
}

int main() {
    vector<char> data;
    vector<int> freq;

    int numCharacters;

    cout << "Enter the number of characters: ";
    cin >> numCharacters;

    for (int i = 0; i < numCharacters; i++) {
        char character;
        int frequency;
        cout << "Enter character " << i + 1 << ": ";
        cin >> character;
        cout << "Enter frequency for " << character << ": ";
        cin >> frequency;
        data.push_back(character);
        freq.push_back(frequency);
    }

    HuffmanCode(data, freq);
    return 0;
}
