
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TNode {
    int key;
    TNode *left, *right;
};

typedef TNode* TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTree(pre, in, preB+1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB+i-inB+1, preE, i+1,inE);
	} return root;
}

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}
int Height(TREE root)
{
	if(root == NULL)
	{
		return 0;
	}
	return 1 + max(Height(root ->left), Height(root -> right));
}
void Fun(TREE root)
{
	if(root == NULL) 
	{
		cout << "Empty Tree\n";
		return;
	}
	int l_lenght = 0, r_lenght = 0;
	l_lenght = Height(root->left);
	r_lenght = Height(root->right);
	
	if(l_lenght > r_lenght) cout << -1 << endl;
	else if(l_lenght < r_lenght) cout << 1 << endl;
	else cout << 0 << endl;
}

int main() {
    vector<int> duyetNLR;
    vector<int> duyetLNR;
    Input(duyetNLR);
    Input(duyetLNR);
    int Num=duyetNLR.size()-1;
    TREE root = CreateTree(duyetNLR, duyetLNR, 0, Num, 0, Num);
    Fun(root);
    return 0;
}
