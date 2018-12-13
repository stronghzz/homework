

#if 0
// ��������
typedef char SDataType;

// ���þ�̬˳���ʵ��ջ
#define MAX_LEN	(1000000)

typedef struct {
	SDataType	array[MAX_LEN];
	int			top;	// ְ�����ԭ���� size
}	Stack;


void StackInit(Stack *stack) {
	stack->top = 0;
}

void StackDestroy(Stack *stack) {
	stack->top = 0;
}

// ��ɾ�Ĳ�
// ֻ�ܴ�ջ������
void StackPush(Stack *stack, SDataType val) {
	assert(stack);
	assert(stack->top < MAX_LEN);

	stack->array[stack->top] = val;
	stack->top++;
}

// ֻ�ܴ�ջ��ɾ��
void StackPop(Stack *stack) {
	assert(stack);
	assert(stack->top > 0);

	stack->top--;
}

// ����ջ��Ԫ��
SDataType StackTop(Stack *stack) {
	assert(stack);
	assert(stack->top > 0);

	return stack->array[stack->top - 1];
}

// �ж��Ƿ�Ϊ��
int StackEmpty(const Stack *stack) {
	return stack->top == 0 ? 1 : 0;
}

// ����ջ�����ݸ���
int StackSize(const Stack *stack) {
	return stack->top;
}

bool isValid(char* s) {
	char *p = s;
	Stack stack;
	StackInit(&stack);
	while (*p != '\0') {
		switch (*p) {
		case '{':
		case '[':
		case '(':
			StackPush(&stack, *p);
			break;
		case '}':
		case ']':
		case ')': {
			if (StackEmpty(&stack)) {
				// ����������������
				return false;
			}

			char left = StackTop(&stack);
			StackPop(&stack);
			if (!((left == '(' && *p == ')')
				|| (left == '[' && *p == ']')
				|| (left == '{' && *p == '}'))) {

				// �������Ų�ƥ��
				return false;
			}
		}
				  break;
		}

		p++;
	}

	if (!StackEmpty(&stack)) {
		// �����Ŷ���������
		return false;
	}

	return true;
}

#endif


#if 0
typedef int QDataType;

// �õ�����ʵ�ֶ���

// ����Ľ��
typedef struct QNode {
	QDataType val;
	struct QNode *next;
}	QNode;

// ����
typedef struct Queue {
	QNode *front;	// ָ������ĵ�һ����㣬�������Ϊ�գ� == NULL
	QNode *rear;	// ָ����������һ����㣬�������Ϊ�գ� == NULL
	int size;		// ��ʾ���������ݸ���
}	Queue;

// ��ʼ��/����
void QueueInit(Queue *queue) {
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

void QueueDestroy(Queue *queue) {
	QNode *next;
	for (QNode *cur = queue->front; cur != NULL; cur = next) {
		next = cur->next;
		free(cur);
	}

	queue->front = queue->rear = NULL;
	queue->size = 0;
}

// ��ɾ�Ĳ�
void QueuePush(Queue *queue, QDataType val) {
	// ������
	QNode *node = (QNode *)malloc(sizeof(QNode));
	assert(node);
	node->val = val;
	node->next = NULL;
	queue->size++;

	if (queue->rear == NULL) {
		queue->front = queue->rear = node;
	}
	else {
		queue->rear->next = node;
		queue->rear = node;
	}
}

void QueuePop(Queue *queue) {
	assert(queue->size > 0);
	queue->size--;

	QNode *old_front = queue->front;
	queue->front = queue->front->next;
	free(old_front);

	if (queue->front == NULL) {
		queue->rear = NULL;
	}
}

QDataType QueueFront(const Queue *queue) {
	assert(queue->size > 0);

	return queue->front->val;
}

// �� / size
int QueueEmpty(const Queue *queue) {
	return queue->size == 0 ? 1 : 0;
}

typedef struct {
	int max_size;
	Queue queue;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
	MyStack * stack = (MyStack *)malloc(sizeof(MyStack));
	assert(stack);
	stack->max_size = maxSize;
	QueueInit(&(stack->queue));

	return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	// obj->queue.size ��Ч���ݸ���
	// obj->max_size ������ݸ���
	assert(obj->queue.size < obj->max_size);

	QueuePush(&(obj->queue), x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	assert(obj->queue.size > 0);
	// ��Ҫ�ȱ����� size����ѭ�������У�size�ڲ��ϱ仯
	int size = obj->queue.size;
	for (int i = 0; i < size - 1; i++) {
		int x = QueueFront(&(obj->queue));
		QueuePop(&(obj->queue));
		QueuePush(&(obj->queue), x);
	}

	int x = QueueFront(&(obj->queue));
	QueuePop(&(obj->queue));
	return x;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	assert(obj->queue.size > 0);
	// ��Ҫ�ȱ����� size����ѭ�������У�size�ڲ��ϱ仯
	int size = obj->queue.size;
	for (int i = 0; i < size - 1; i++) {
		int x = QueueFront(&(obj->queue));
		QueuePop(&(obj->queue));
		QueuePush(&(obj->queue), x);
	}

	int x = QueueFront(&(obj->queue));
	QueuePop(&(obj->queue));
	QueuePush(&(obj->queue), x);

	return x;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&(obj->queue));
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&(obj->queue));
}

/**
* Your MyStack struct will be instantiated and called as such:
* struct MyStack* obj = myStackCreate(maxSize);
* myStackPush(obj, x);
* int param_2 = myStackPop(obj);
* int param_3 = myStackTop(obj);
* bool param_4 = myStackEmpty(obj);
* myStackFree(obj);
*/
#endif

#if 0
class MyQueue {
private:
	stack<int>  stack_a;
	stack<int>  stack_b;
public:
	/** Initialize your data structure here. */
	MyQueue() {
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		stack_a.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (stack_b.empty()) {
			int size = stack_a.size();
			for (int i = 0; i < size; i++) {
				int x = stack_a.top();
				stack_a.pop();
				stack_b.push(x);
			}
		}

		int x = stack_b.top();
		stack_b.pop();
		return x;
	}

	/** Get the front element. */
	int peek() {
		if (stack_b.empty()) {
			int size = stack_a.size();
			for (int i = 0; i < size; i++) {
				int x = stack_a.top();
				stack_a.pop();
				stack_b.push(x);
			}
		}

		int x = stack_b.top();
		return x;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return stack_a.empty() && stack_b.empty();
	}
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue obj = new MyQueue();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.peek();
* bool param_4 = obj.empty();
*/

#endif
//#include <stdio.h>
//#include <stdlib.h>
//void example(char arr[])
//{
//	printf("%d\n", sizeof(arr));
//	return;
//}
//
//
//
//int main()
//{
//	char arr[] = "hello,bit";
//	printf("%d\n", sizeof(arr)/sizeof(arr[0]));
//	example(arr);
//
//	system("pause");
//	return 0;
//}
//
