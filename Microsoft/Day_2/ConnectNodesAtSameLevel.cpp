#include<bits/stdc++.h> 
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size(); // size of queue at each level
            for(int i = 0; i < size; i++){
                Node* item = q.front();
                if(size - 1 == i) //reach to the last node of the queue, that is where we need to insert NULL
                    item -> next = NULL; //insert NULL to the end pointer
                q.pop();
                
                //if there's no last value then point previous value to the next node
                if(size - 1!= i)
                    item -> next = q.front();
                
                if(item -> left != NULL)
                    q.push(item -> left);
                if(item -> right != NULL)
                    q.push(item -> right);
            }
        }
        return root;
    }
};

int main(){
    Solution ss;
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    root -> left -> left -> left = new Node(8);
    root -> left -> left -> right = new Node(9);
    root -> left -> right -> left = new Node(10);
    root -> left -> right -> right = new Node(11);
    root -> right -> left -> left = new Node(12);
    root -> right -> left -> right = new Node(13);
    root -> right -> right -> left = new Node(14);
    root -> right -> right -> right = new Node(15);
    ss.connect(root);
    return 0;
}