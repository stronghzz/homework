
#if 0
int GetLength(struct ListNode *head) {
	int len = 0;
	struct ListNode *cur = head;
	while (cur != NULL) {
		len++;
		cur = cur->next;
	}

	return len;
}

struct ListNode* middleNode(struct ListNode* head) {
	int steps = GetLength(head) / 2;
	struct ListNode *middle = head;
	while (steps--) {
		middle = middle->next;
	}

	return middle;
}
#endif

#if 0
// ˫��������� -�� ����ָ�뷨
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode *fast = head;
	struct ListNode *slow = head;

	while (fast != NULL) {
		fast = fast->next;
		if (fast == NULL) {
			break;
		}

		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}
#endif

#if 0
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode *p = pListHead;
	while (p != NULL && k--) {
		p = p->next;
	}

	if (p == NULL) {
		return NULL;
	}

	while (p != NULL) {
		pListHead = pListHead->next;
		p = p->next;
	}

	return pListHead;
}
#endif

// ɾ���������ظ��Ľ��
#if 0

ListNode * deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL) {
		return NULL;
	}

	ListNode *p0 = NULL;
	ListNode *p1 = pHead;
	ListNode *p2 = pHead->next;

	while (p2 != NULL) {
		if (p1->val != p2->val) {
			p0 = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else {
			while (p2 != NULL && p2->val == p1->val) {
				p2 = p2->next;
			}
			// 1. p2 �ߵ������β
			// 2. p2 ��������ȵ�ֵ��
			if (p2 == NULL) {
				if (p0 != NULL) {
					p0->next = p2;	// NULL
				}
				else {
					return NULL;
				}
				break;
			}

			if (p0 != NULL) {
				p0->next = p2;
			}
			else {
				pHead = p2;
			}
			p1 = p2;
			p2 = p2->next;
		}
	}

	return pHead;
}

#endif

#if 0

ListNode * deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL) {
		return NULL;
	}

	ListNode *p0 = NULL;
	ListNode *p1 = pHead;
	ListNode *p2 = pHead->next;

	while (p2 != NULL) {
		if (p1->val != p2->val) {
			p0 = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else {
			while (p2 != NULL && p2->val == p1->val) {
				p2 = p2->next;
			}
			// 1. p2 �ߵ������β
			// 2. p2 ��������ȵ�ֵ��
			if (p2 == NULL) {
				if (p0 != NULL) {
					p0->next = p2;	// NULL
				}
				else {
					return NULL;
				}
				break;
			}

			if (p0 != NULL) {
				p0->next = p2;
			}
			else {
				pHead = p2;
			}
			p1 = p2;
			p2 = p2->next;
		}
	}

	return pHead;
}

#endif

#if 0

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL) {
		return l2;
	}

	if (l2 == NULL) {
		return l1;
	}

	struct ListNode *p1 = l1;
	struct ListNode *p2 = l2;
	struct ListNode *r = NULL;
	struct ListNode *rtail = NULL;	// r ��������һ�����

	while (p1 != NULL && p2 != NULL) {
		if (p1->val <= p2->val) {
			// β�� p1 �� r ��
			if (rtail == NULL) {
				r = rtail = p1;
			}
			else {
				rtail->next = p1; rtail = rtail->next;
			}
			p1 = p1->next;
		}
		else {
			// β�� p2 �� r ��
			if (rtail == NULL) {
				r = rtail = p2;
			}
			else {
				rtail->next = p2; rtail = p2;
			}
			p2 = p2->next;
		}
	}

	// p1 ���� p2 Ϊ��
	if (p1 == NULL) {
		// �� p2 �������� r �ĺ���
		rtail->next = p2;
	}
	else {
		// �� p1 �������� r �ĺ���
		rtail->next = p1;
	}

	return r;
}

#endif

#if 0

ListNode* partition(ListNode* pHead, int x) {
	// ������ֳ� 3 ����
	ListNode *lt = NULL;	// �� x С
	ListNode *ltTail = NULL; // С�����һ�����
	ListNode *eq = NULL;	// �� x ���
	ListNode *eqTail = NULL; // ������һ�����
	ListNode *gt = NULL;	// �� x ��
	ListNode *gtTail = NULL; // ������һ�����

	ListNode *cur = pHead;
	while (cur != NULL) {
		if (cur->val < x) {
			// lt �������Ϊ�գ�û�н��
			// lt ����Ϊ�գ�lt ����ָ���һ�����
			// ltTail ��Ϊ�գ�ָ�����һ�����
			if (lt == NULL) {
				// ��һ�����
				// �� cur �嵽��������
				// ������ֻ��һ�����
				lt = ltTail = cur;
			}
			else {
				// β��
				ltTail->next = cur;
				// ltTail ��ɵ����ڶ������
				ltTail = ltTail->next;
			}
		}
		else if (cur->val == x) {
			if (eq == NULL) {
				eq = eqTail = cur;
			}
			else {
				eqTail->next = cur;
				eqTail = eqTail->next;
			}
		}
		else {
			if (gt == NULL) {
				gt = gtTail = cur;
			}
			else {
				gtTail->next = cur;
				gtTail = gtTail->next;
			}
		}
		cur = cur->next;
	}
}

#endif
