#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	char val;
	struct Node *left;
	struct Node *right;
}	Node;


typedef struct {
	Node *root;		// �����õ����ĸ����
	int	used;		// �������������õ��� val ����
}	Result;

Result CreateTree(char preorder[], int size) {
	if (size == 0) {
		Result result = {
			 NULL,
			 0
		};

		return result;
	}

	char rootValue = preorder[0];
	if (rootValue == '#') {
		Result result = {
			NULL,
			 1	// �õ��� #
		};

		return result;
	}

	// ���������
	Node *root = (Node *)malloc(sizeof(Node));
	root->val = rootValue;

	// ����������
	Result left_result = CreateTree(preorder + 1, size - 1);
	/*
	left_result.root;	// �����õ��������ĸ����
	left_result.used;	// �����������������õ��� val �ĸ���
	*/
	// ����������
	Result right_result = CreateTree(preorder + 1 + left_result.used, size - 1 - left_result.used);
	root->left = left_result.root;
	root->right = right_result.root;

	Result result = {
		root,
		1 + left_result.used + right_result.used
	};
	return result;
}

void TestCreateTree() {
	char *preorder = "AB#DE###C";
	int size = strlen(preorder);

	Result result = CreateTree(preorder, size);


}