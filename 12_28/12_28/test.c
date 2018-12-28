#include "reg52.h"
sbit smg1 = P2 ^ 0;
sbit smg2 = P2 ^ 1;
sbit smg3 = P2 ^ 2;
sbit beep = P2 ^ 3;
sbit key1 = P3 ^ 2;
sbit key2 = P3 ^ 3;
#define smg P1		   

void delay(int xms)
{
	int i, j;
	for (i = xms; i>0; i--)
		for (j = 55; j>0; j--);
}

void Int0Init(void)
{
	EA = 1;
	IT0 = 1;
	EX0 = 1;
}
void Int1Init(void)
{
	EA = 1;
	IT1 = 1;
	EX1 = 1;
}

void Timer0Init(void)
{
	TMOD |= 0X01;
	TH0 = 0xfc;			//����ʱ������ֵ����ʱ1ms
	TL0 = 0x18;
	ET0 = 1;
	EA = 1;
	TR0 = 0;
}


int str[10] = { 0xc0, 0xcf, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90 };
//����ܵ� ʮλ  ��λ  С�����һλ
int i = 0, j = 0, k = 0;
int num1 = 0xc0;
int num2 = 0xc0;
int num3 = 0xc0;
void main()
{
	Timer0Init();
	Int0Init();
	Int1Init();


	while (1)
	{
		smg1 = 1;
		smg2 = 1;
		smg3 = 0;
		smg = num3;
		delay(2);
		smg1 = 1;
		smg2 = 0;
		smg3 = 1;
		smg = num2;
		delay(2);
		smg1 = 0;
		smg2 = 1;
		smg3 = 1;
		smg = num1;
		delay(2);
	}
}


void Int0()	interrupt 0
{
	if (key1 == 0)
	{
		delay(200);
		if (key1 == 0)
		{
			j += 1;
			num2 = str[j];
			if (j == 10)
			{
				j = 0;
				i += 1;
				num2 = str[j];
				num1 = str[i];
			}
			if (i == 10)
			{
				i = 9;
				j = 9;
				num2 = str[j];
				num1 = str[i];
			}
		}
	}
}

void Int_0() interrupt 2
{
	if (key2 == 0)
	{
		delay(200);
		if (key2 == 0)
		{
			TR0 = ~TR0;
		}
	}
}
int m = 100, s = 1000;
void Timer0() interrupt 1
{
	static int n;
	//	TH0 = ( 65536 - 45872 ) / 256;			//����ʱ������ֵ����ʱ20ms
	//	TL0 = ( 65536 - 45872 ) % 256;
	TH0 = 0xfc;			//����ʱ������ֵ����ʱ1ms
	TL0 = 0x18;
	n++;
	if (n == 100)
	{
		// �� i ���¸�ֵ
		n = 0;
		// ���С����λkΪ0��ֵ9�������һ	
		if (k == 0)
		{
			k = 9;
			num3 = str[k];
			// ��С����λ��0��Ϊ9ʱ �����λjΪ0��ֵ9�������һ
			if (j == 0)
			{
				j = 9;
				num2 = str[j];

				// ��С����λ�͸�λ��Ϊ0ʱ ���ʮλi������0���һ ����Ϊ0 �����в���
				if (i != 0)
				{
					i -= 1;
					num1 = str[i];
				}
			}
			else
			{
				j -= 1;
				num2 = str[j];
			}
		}
		else
		{
			k -= 1;
			num3 = str[k];
		}


		if (i == 0 && k == 0)
		{
			if (j == 1 || j == 2 || j == 3)
			{
				while (m--)
				{
					beep = ~beep;
					delay(2);
				}
				m = 100;
			}
			if (j == 0)
			{
				while (s--)
				{
					beep = ~beep;
					delay(1);
				}
				s = 1000;
			}
		}

		// ����ʱ����������	
		if (i == 0 && j == 0 && k == 0)
		{
			num1 = str[0];
			num2 = str[0];
			num3 = str[0];
			TR0 = 0;
		}
	}