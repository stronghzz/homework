#pragma once
#include <iostream>
using namespace std;
typedef struct Node
{
	int val;
	struct Node* left;
	struct Node* right;
};

// ǰ�����
void PreorderTraversal(Node *root) {
	if (root == NULL) {
		// ����
		return;
	}

	printf("%d ", root->val);		// ��
	PreorderTraversal(root->left);	// ǰ�����������
	PreorderTraversal(root->right);	// ǰ�����������
}

// �������
void InorderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}

	InorderTraversal(root->left);
	printf("%d ", root->val);
	InorderTraversal(root->right);
}

// �������
void PostorderTraversal(Node *root) {
	// ��ֹ����
	if (root == NULL) {
		return;
	}

	// ���ƵĹ���
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
	printf("%d ", root->val);
}


int GetNodeCount(Node *root) {
	// ��ֹ������ʲô��
	if (root == NULL) {
		return 0;
	}
	// ���ƹ�ʽ��ʲô��
	return GetNodeCount(root->left) + GetNodeCount(root->right) + 1;
}

int GetHeight(Node *root) {
	if (root == NULL) {
		return 0;
	}

	int left = GetHeight(root->left);
	int right = GetHeight(root->right);

	return (left > right ? left : right) + 1;
}