#include<bits/stdc++.h>
using namespace std;

struct node
{
	int val;
	int treeSize;
	node* left;
	node* right;
}

node* head;

void insert(node* start, int value)
{

}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if(i == 0)
		{
			head = new node();
			head.val = a;
			head.treeSize = 1;
		}
		else insert(head, a);
	}
}