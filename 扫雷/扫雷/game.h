#ifndef _GAME_H__
#define _GAME_H__



#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define ROW 11
#define COL 11
#define rows 9
#define cols 9
#define Count 10 //�׵ĸ���

void menu();//�˵�
void Inie_mine(char	 mine[ROW][COL], char show[ROW][COL]);//��ʼ������
void Display(char show[ROW][COL]);
void Set_mine(char mine[ROW][COL]);//�����׵�λ��
void Sweep(char mine[ROW][COL], char show[ROW][COL]);//��ʼɨ��
int Get_num(char mine[ROW][COL], int x, int y);//�����׵ĸ���

#endif //_GAME_H__
