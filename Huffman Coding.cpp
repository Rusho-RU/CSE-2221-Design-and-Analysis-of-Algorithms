#include <bits/stdc++.h>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq){
        this->ch = ch;
        this->freq = freq;
        this->right = this->left = NULL;
    }
};

struct cmp{
    bool operator()(Node* left, Node* right){
        return left->freq > right->freq;
    }
};

void printEncode(Node* head, string encode){
    if(!head)
        return;

    if(head->ch != '#')
        cout<<head->ch<<" : "<<encode<<endl;

    printEncode(head->left, encode + '0');
    printEncode(head->right, encode + '1');
    return;
}

void codeHuffman(char ch[], int freq[], int numOfChar){
    Node *left, *right, *head;

    priority_queue<Node*, vector<Node*>, cmp>minHeap;

    for(int i=0; i<numOfChar; i++)
        minHeap.push(new Node(ch[i], freq[i]));

    while(minHeap.size()>1){
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        head = new Node('#', left->freq + right->freq);
        head->left = left;
        head->right = right;

        minHeap.push(head);
    }
    printEncode(minHeap.top(), "");
}

int main(){
    int numOfChar;
    scanf("%d",&numOfChar);

    char ch[numOfChar];
    int freq[numOfChar];

    for(int i=0; i<numOfChar; i++)
        scanf(" %c %d",&ch[i], &freq[i]);

    codeHuffman(ch, freq, numOfChar);
}
