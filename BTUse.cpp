#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

int height(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	/*
	if (height(root->left) > height(root->right)) {
		return height(root->left) + 1;
	} else {
		return height(root->right) + 1;
	}
	*/
	return 1 + max(height(root->left), height(root->right));
}

class hd {
	public;
	int height;
	int diameter;
};

void diameter3(BinaryTreeNode<int>* root, int& h, int& d) {
	if (root == NULL) {
		 h = 0;
		 d = 0;
		 return;
	}
	int lh,rh,ld,rd;
	diameter3(root->left, lh, ld);
	diameter3(root->right, rh, rd);
	h = max(lh, rh) + 1;
	d = max(lh + rh, max(ld, rd));
}

bool search(BinaryTreeNode<int>* root, int element) {
	if (root == NULL) {
		return false;
	}
	if (root->data == element) {
		return true;
	} else if (root->data < element) {
		return search(root->right, element);
	} else {
		return search(root->left, element);
	}

}
class BSTReturn {
	public:
		bool isBST;
		int min;
		int max;
		BSTReturn(bool isBST,
				int min,
				int max):isBST(isBST), min(min), max(max) {
		}
}

Node<int>* bstToLL(BinaryTreeNode<int>* root) {

}

bool isBST4(BinaryTreeNode<int>* root,
		int minimum = INT_MIN, int maximum = INT_MAX) {
	if (root == NULL) {
		return true;
	}
	if (root->data < minimum || root->data > maximum) {
		return false;
	}
	return isBST4(root->left, minimum, root->data - 1) &&
		isBST4(root->right, root->data, maximum);
}

bool isBST3(BinaryTreeNode<int>* root, int& prev) {
	if (root == NULL) {
		return true;
	}
	if (!isBST3(root->left, prev)) {
		return false;
	}
	if (root->data < prev) {
		return false;
	}
	prev = root->data;
	if (!isBST3(root->right, prev)) {
		return false;
	}
	return true;
}

BSTReturn isBST2(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		BSTReturn b(true, INT_MAX, INT_MIN);
		return b;
	}

	BSTReturn leftAns = isBST2(root->left);
	BSTReturn rightAns = isBST2(root->right);
	int minimum = min(root->data,
			min(leftAns.min, rightAns.min));
	int maximum = max(root->data,
			max(leftAns.max, rightAns.max));
	bool bst = (root->data > leftAns.max &&
			root->data <= rightAns.min &&
			leftAns.isBST && rightAns.isBST);

	BSTReturn b(bst, minimum, maximum);
	return b;
}
int max(BinaryTreeNode<int>*root)
{
    if(root==NULL){
        return INT_MIN;
    }
    int max=INT_MIN;
    if(root->data>max){
        max=root->data;
    }
    return max;
}

bool isBST(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return true;
	}
	if (root->data <= max(root->left) ||
			root->data > min(root->right)) {
		return false;
	}
	return isBST(root->right) && isBST(root->left);
}

hd diameter2(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		hd ans;
		ans.height = 0;
		ans.diameter = 0;
		return ans;
	}
	hd leftAns = diameter2(root->left);
	hd rightAns = diameter2(root->right);
	int h = max(leftAns.height, rightAns.height) + 1;
	int d = max(leftAns.height + rightAns.height,
			max(leftAns.diameter, rightAns.diameter));
	hd output;
	output.height = h;
	output.diameter = d;
	return output;
}

int diameter(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	int lh = height(root->left);
	int rh = height(root->right);
	int ld = diameter(root->left);
	int rd = diameter(root->right);
	return max(lh + rh, max(ld, rd));
}

void preorder(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << endl;
	preorder(root->left);
	preorder(root->right);
}

void inorder(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << endl;
	inorder(root->right);
}

void print(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data  << ":";
	if (root->left != NULL) {
		cout << "L:" << root->left->data << ",";
	}

	if (root->right != NULL) {
		cout << "R:" << root->right->data;
	}
	cout << endl;
	print(root->left);
	print(root->right);
}

int numNodes(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + numNodes(root->left) + numNodes(root->right);
}


BinaryTreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	root->left = takeInput();
	root->right = takeInput();
	return root;
}

void printpaths(BinaryTreeNode<int> *root,vector<int> &v)
{
    if(root==NULL){
        return;
    }
    if(root->left==NULL&&root->right==NULL){
        v.push_back(root->data);
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        v.pop_back();
        return;
    }
    v.push(root->data);
    printpaths(root->left, v);
    printpaths(root->right, v);
    v.pop_back();

}


// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
int main() {
	BinaryTreeNode<int>* root = takeInput();
	print(root);
	delete root;
}

