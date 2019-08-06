#pragma once
#define _CRT_SECURE_NO_WARNINGS


#include "CreatTree.h"



//�������
void Inorder(Node *root)
{
	if (root == NULL) {
		return;
	}

	Inorder(root->left);
	printf("%d ", root->val);
	Inorder(root->right);
}
void Preorder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ",root->val);
	Preorder(root->left);
	Preorder(root->right);
}

// ������˼·
int n;
void GetSize(Node *root) {
	if (root == NULL) {
		return;
	}

	GetSize(root->left);
	n++;
	GetSize(root->right);
}

// ���Ƶ�˼·
int GetSize2(Node *root) {
	if (root == NULL) {
		return 0;
	}

	return GetSize2(root->left)
		+ GetSize2(root->right)
		+ 1;
}

// Ҷ�ӽ�����
int leaf_n;
void GetLeafSize(Node *root) {
	if (root == NULL) {
		return;
	}

	if (root->left == NULL && root->right == NULL) {
		leaf_n++;
	}

	GetLeafSize(root->left);
	GetLeafSize(root->right);
}

// ���Ƶ�˼·
int GetLeafSize2(Node *root) {
	if (root == NULL) {
		return 0;
	}

	if (root->left == NULL && root->right == NULL) {
		return 1;
	}

	return GetLeafSize2(root->left) + GetLeafSize2(root->right);
}

int LevelK(Node *root, int k) {
	if (root == NULL) {
		return 0;
	}

	if (k == 1) {
		return 1;
	}

	return LevelK(root->left, k - 1) + LevelK(root->right, k - 1);
}


// �����в��� val ֵ������ val һ�����ظ�
// ���Ҵ��������жϸ��������ǣ�ȥ�������ң�������û�ҵ�������������
// ���ذ��� val �Ľ���ַ��û�ҵ����� NULL
Node * Find(Node *root, char val) {
	if (root == NULL) {
		return NULL;
	}

	// ���жϸ�
	if (root->val == val) {
		return root;
	}

	// ȥ��������
	Node *r = Find(root->left, val);
	if (r != NULL) {
		return r;
	}
	// û�ҵ�
	// �ж���������û���ҵ�
	// �����Ƿ�ȥ��������
	r = Find(root->right, val);
	if (r != NULL) {
		return r;
	}

	// ������Ҳû�ҵ�
	return NULL;
}


#include <queue>
// �������
void LevelOrderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}

	// �������У������д������������ Node *
	// �����ռ�
	// ģ��
	queue<Node *> q;

	q.push(root);

	while (!q.empty()) {
		Node * node = q.front();	// ȡ���׽��
		q.pop();					// �������׽��
		printf("%c ", node->val);

		if (node->left != NULL) {
			q.push(node->left);
		}

		if (node->right != NULL) {
			q.push(node->right);
		}
	}
}

bool IsCompleteTree(Node *root) {
	if (root == NULL) {
		return true;
	}

	// �������У������д������������ Node *
	// �����ռ�
	// ģ��
	queue<Node *> q;

	q.push(root);

	while (1) {
		Node * node = q.front();	// ȡ���׽��
		q.pop();					// �������׽��
		if (node == NULL) {
			// �ڲ�������Ĺ����������ս��
			break;
		}
		q.push(node->left);
		q.push(node->right);
	}

	// ���ʣ�½������û�зǿս��
	while (!q.empty()) {
		Node *node = q.front(); q.pop();
		if (node != NULL) {
			return false;
		}
	}

	return true;
}

#include <stack>
// ǰ������ǵݹ�
void PreorderTraversalNoR(Node *root) {
	stack<Node *>	s;	// ջ
	Node *cur = root;
	Node *top = NULL;

	while (cur != NULL || !s.empty()) {
		// һ·����Ĺ���
		while (cur != NULL) {
			printf("%c ", cur->val);
			s.push(cur);
			cur = cur->left;
		}

		// һ������������ NULL
		// ����ջ����ʣ���������
		top = s.top();	s.pop();
		//top = StackTop(&s); StackPop(&s);

		cur = top->right;
	}
}

void InorderTraversalNoR(Node *root) {
	stack<Node *>	s;	// ջ
	Node *cur = root;
	Node *top = NULL;

	while (cur != NULL || !s.empty()) {
		// һ·����Ĺ���
		while (cur != NULL) {
			// ��һ�������Ľ���λ��
			s.push(cur);
			cur = cur->left;
		}

		// һ������������ NULL
		// ����ջ����ʣ���������
		top = s.top();	s.pop();
		//top = StackTop(&s); StackPop(&s);
		// �ڶ��������ĵط�
		printf("%c ", top->val);

		cur = top->right;
	}
}


void PostorderTraversalNoR(Node *root) {
	stack<Node *>	s;	// ջ
	Node *cur = root;
	Node *top = NULL;
	Node *last = NULL;

	while (cur != NULL || !s.empty()) {
		// һ·����Ĺ���
		while (cur != NULL) {
			// ��һ�������Ľ���λ��
			s.push(cur);
			cur = cur->left;
		}

		// һ������������ NULL
		// ����ջ����ʣ���������
		top = s.top();
		if (top->right == NULL) {
			printf("%c ", top->val);
			s.pop();
			last = top;
		}
		else if (top->right == last) {
			printf("%c ", top->val);
			s.pop();
			last = top;
		}
		else {
			cur = top->right;
		}
	}
}


#if 0
long long sum(int n) {
	if (n == 1) {
		return 1;
	}

	return sum(n - 1) + n;
}
#endif





//
//char buff[100 * 10000];
//int index;
//
//
//void PreorderBracket(struct Node *root) {
//	if (root == NULL) {
//		return;
//	}
//
//	index += sprintf(buff + index, "(");
//	index += sprintf(buff + index, "%d", root->val);
//	if (root->left == NULL && root->right == NULL) {
//		index += sprintf(buff + index, ")");
//		return;
//	}
//
//	if (root->left != NULL && root->right == NULL) {
//		PreorderBracket(root->left);
//		index += sprintf(buff + index, ")");
//		return;
//	}
//
//	if (root->left == NULL && root->right != NULL) {
//		index += sprintf(buff + index, "()");
//		PreorderBracket(root->right);
//		index += sprintf(buff + index, ")");
//		return;
//	}
//
//	PreorderBracket(root->left);
//	PreorderBracket(root->right);
//	index += sprintf(buff + index, ")");
//}
//
//char * tree2str(struct Node *root) {
//	memset(buff, 0x0, 100 * 10000);
//	index = 0;
//	PreorderBracket(root);
//
//	buff[index - 1] = 0;
//	return buff + 1;
//}




