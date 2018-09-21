#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int value;
	Node* left;
	Node* right;
	Node(int val) : value(val), left(NULL), right(NULL){};
};

void insertNode(Node* head, int val)
{
	if(val < head->value)
	{
		if(head->left == NULL) head->left = new Node(val);
		else insertNode(head->left, val);
	}
	else
	{
		if(head->right == NULL) head->right = new Node(val);
		else insertNode(head->right, val);
	}
}

int tot(Node* head, int counter = 0)
{
	if(head == NULL) return 0;
	return counter + tot(head->left, counter + 1) + tot(head->right, counter + 1);
}

int main()
{
	int N;
	cin >> N;
	Node* head;
	int a;
	cin >> a;
	head = new Node(a);
	for(int i = 1; i < N; i++)
	{
		cin >> a;
		insertNode(head, a);
	}
	cout << tot(head) << endl;
}