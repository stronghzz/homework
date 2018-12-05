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

			ListNode *cur = p1, *next;
			while (cur != p2) {
				next = cur->next;
				free(cur);
			}

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


#if 0	// �ҵ������ཻ����Ĺ������

int GetLength(ListNode *head) {
	int len = 0;
	ListNode *cur = head;
	while (cur != NULL) {
		cur = cur->next;
		len++;
	}

	return len;
}

ListNode * GetCommon(ListNode *p1, ListNode *p2)
{
	int len1 = GetLength(p1);
	int len2 = GetLength(p2);
	ListNode *longer, *shorter;
	int diff;	// ���Ȳ�
	if (len1 >= len2) {
		longer = p1;
		shorter = p2;
		diff = len1 - len2;
	}
	else {
		longer = p2;
		shorter = p1;
		diff = len2 - len1;
	}

	// ���ó����� diff ��
	for (int i = 0; i < diff; i++) {
		longer = longer->next;
	}

	while (longer != shorter) {	// �Ƚϲ��� val�����ǽ���ַ
		longer = longer->next;
		shorter = shorter->next;
	}

	return longer;
}

#endif

#if 0	// �ж��Ƿ����
bool hasCycle(struct ListNode *head) {
	struct ListNode *fast = head;
	struct ListNode *slow = head;

	do {
		if (fast == NULL) {
			break;
		}
		fast = fast->next;
		if (fast == NULL) {
			break;
		}
		fast = fast->next;
		slow = slow->next;
	} while (fast != slow);

	if (fast == NULL) {
		return false;
	}
	else {
		return true;
	}
}
#endif

#if 0	// ����������

/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     struct RandomListNode *next;
*     struct RandomListNode *random;
* };
*/

struct RandomListNode * CreateNode(int label)
{
	struct RandomListNode *p = (struct RandomListNode *)
		malloc(sizeof(struct RandomListNode));
	p->label = label;
	p->next = p->random = NULL;
	return p;
}

struct RandomListNode *copyRandomList(struct RandomListNode *head)
{
	// 1. ����ԭ�������µĽ������ϵĽ����
	struct RandomListNode *oldNode = head;
	while (oldNode != NULL) {
		struct RandomListNode *newNode = CreateNode(oldNode->label);
		newNode->next = oldNode->next;
		oldNode->next = newNode;

		oldNode = oldNode->next->next;
	}

	// ���� random ָ��
	oldNode = head;
	while (oldNode != NULL) {
		struct RandomListNode *newNode = oldNode->next;
		if (oldNode->random != NULL) {
			newNode->random = oldNode->random->next;
		}

		oldNode = oldNode->next->next;
	}

	// ��һ����������������
	oldNode = head;
	struct RandomListNode *newHead = head->next;
	while (oldNode != NULL) {
		struct RandomListNode *newNode = oldNode->next;
		oldNode->next = newNode->next;
		if (oldNode->next != NULL) {
			newNode->next = oldNode->next->next;
		}
		else {
			newNode->next = NULL;	// ����ԭ������ NULL
		}

		oldNode = oldNode->next;
	}

	return newHead;
}
#endif