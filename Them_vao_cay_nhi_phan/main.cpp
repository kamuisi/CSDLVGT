/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <bits/stdc++.h>
using namespace std;

	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
	}

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        Node *x = new Node(data);
        if(root == NULL)
        {
            root = x;   
            return root;
        }
        Node *m = root;
        while(m != NULL)
        {
            if(x->data > m->data)
            {
                if(m->right != NULL)
                {
                    m = m ->right;
                }
                else
                {
                    m->right = x;
                    break;
                }
            }
            else if(x->data < m->data)
            {
                if(m->left != NULL)
                {
                    m = m ->left;
                }
                else
                {
                    m->left = x;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        return root;
    }
}; 

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.preOrder(root);

    return 0;
}