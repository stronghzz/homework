#pragma once
#include <stdio.h>
#include <assert.h>
// ��������
typedef int SDataType;

// ���þ�̬˳���ʵ��ջ
#define MAX_LEN	(100)

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