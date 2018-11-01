#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)//��ʼ������
{
	int j = 0;
	int i = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)//��ӡ����
{
	int i = 0;
	int j = 0;
	for (i = 0;i<row;i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
			
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}

			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)//�����
{
	int   x = 0;
	int   y = 0;
	printf("�����-��\n");
	while (1)
	{
		char ch = '0';
		printf("���������꣺\n");
		scanf("%d%d", &x, &y);
		while ((ch = getchar()) && ch == EOF)
		{

		}
		
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			else
			{
				printf("���걻ռ��,���������룺");
			}
		}
		else
		{
			printf("����Ϸ����꣡\n");
		}
	}
}
void ComputerMove(char board[ROW][COL],int row,int  col) //������
{
	int x = 0;
	int y = 0;
	printf("������-��\n");
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '*';
			break;
		}
	}

}
int IsFull(char board[ROW][COL], int row, int  col)//�ж������Ƿ�����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;  
}
char IsWin(char board[ROW][COL], int row, int  col)//�ж���Ӯ
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for(j = 0;j<col;j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3] && board[i][j + 3] == board[i][j + 4] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	for (j = 0; j < row; j++)
	{
		for (i = 0; i<col; i++)
		{
			if (board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j] && board[i + 2][j] == board[i + 3][j] && board[i + 3][j] == board[i + 4][j] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j<col; j++)
		{
			if (board[i][j] == board[i+1][j + 1] && board[i+1][j + 1] == board[i+2][j + 2] == board[i + 3][j+3] && board[i + 3][j+3] == board[i + 4][j+4] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	if (IsFull(board, ROW, COL) == 1)
	{
		return 'Q';//ƽ��
	}
	return ' ';
}