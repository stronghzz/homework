/***********************************************************************************
Filename: duanxinuart1.c
Prozessor: 80C51 family

***********************************************************************************/
#include <ioCC2530.h>
#include "duanxinuart1.h"
#include "hal_board_cfg.h"
#include "hal_defs.h"
#include "hal_types.h"
#define uint unsigned int
#define uchar unsigned char

extern int readflag=0;
extern  unsigned char *duanxinStr;

void  delay_50ms(uint t)
 {
	uint j;
	for(;t>0;t--)
	for(j=6245;j>0;j--);
}
/*****************************************
//uart1��ʼ��
*****************************************/
void InitUart1(void)
{	
 // CLKCONCMD &= ~0x40;                          //����ϵͳʱ��ԴΪ32MHZ����
 // while(CLKCONSTA & 0x40);                     //�ȴ������ȶ�
 // CLKCONCMD &= ~0x47;                          //����ϵͳ��ʱ��Ƶ��Ϊ32MHZ
  
  P1SEL |= 0xc0; //1100 0000  0Ϊ��ͨ�ڣ�1Ϊ���� P1 6TX 7RX ΪUART1
  P2DIR=0X40;
  U1CSR |= 0x80;
  PERCFG |= 0x02;
  //HAL_BOARD_INIT();//�弶��ʼ��
  U1GCR =9;    //BAUD_E = 9  //19200 
  U1BAUD = 59;  //BAUD_M =59   �����ʼ��㹫ʽ (256+BAUD_M)
  //UART_SETUP(1, 19200, HIGH_STOP);  // ��������
  UTX1IF=1;
  URX1IF=0;
  U1UCR |=0x82;

  U1CSR |= 0X40;				//�������
  IEN0 |= 0x88;				//�����жϣ������ж�
  
}

/*********************************************************************
 * �������ƣ�senduart_a_byte
 * ��    �ܣ�����һ���ַ�
 * ��ڲ�����c  ���͵��ַ�
 * ���ڲ�������
 * �� �� ֵ����
 ********************************************************************/
uint8 senduart_a_byte(char c)  
{
  /*if(c == '\n')  
 {
    while(!UTX1IF);
   U1DBUF = 0x0d;   
 }*/
  
   while (!UTX1IF);
   UTX1IF = 0;
   return(U1DBUF = c);
}


/*********************************************************************
 * �������ƣ�read_a_byte
 * ��    �ܣ�����һ���ַ�
 * ��ڲ�������
 * ���ڲ�����
 * �� �� ֵ�����յ��ַ�
 ********************************************************************/
//uint8 read_a_byte( )  
//{
 
//   char b;
//   if(URX1IF)
//   {
//     b=U1DBUF;
//     readflag=1;
//     URX1IF = 0;
//   }
//   return (b);
//}

/*********************************************************************
 * �������ƣ�printsuart
 * ��    �ܣ�����һ���ַ�
 * ��ڲ�����s         �ַ���ָ��
 * ���ڲ�������
 * �� �� ֵ����
 ********************************************************************/
void printsuart(char *s)
{
 //uint8 i = 0;
 
  while(*s)//while(s[i] != '\0')    // �ж��ַ����Ƿ����
  {
    senduart_a_byte(*s);// ����һ�ֽ�
    s++;
  }
 
}

/*********************************************************************
 * �������ƣ�readinstr
 * ��    �ܣ�����һ���ַ�
 * ��ڲ�������
 * ���ڲ�������
 * �� �� ֵ���ַ���
 ********************************************************************/
//void readinstr( )
//{

//  if(URX1IF)
 //  {
 //   *duanxinStr= U1DBUF; //�����ַ�
 //   URX1IF=0; //��URX1IF
 //    readflag=1;
 //  }
 //while(*duanxinStr!= '\0') //�ж��Ƿ����ַ�����β��
 //{
 //  while(!URX1IF); //������ж��ַ��Ƿ�����
 // duanxinStr++; //�ַ���ָ���һ
 // *duanxinStr= U1DBUF; //�����ַ�
 //  URX1IF=0; //��URX1IF
 //}
//}


/*****************************************
//uart1����
*****************************************/

char message[]={"Warning:the gas leak!"};

char AT_CMGF[]={"AT+CMGF=1"};//���ö��ŵĸ�ʽΪPDU��ʽ
char AT_CSCA[]={"AT+CSCA=\"+8613800290500\""};//�����ƶ��������ĺ���
char AT_CMGS[]={"AT+CMGS=\"1252018700443632\""};//���Ͷ���ָ���Ҫ���ն��ŵ��ֻ�����,ע��Ҫ����Ϊ�ַ�����\0��
char  call_number[]={"ATD15191897096;"};
//char s1=0x0D;
//char s2=0x0A;
void send_call(void)
{
	printsuart(call_number);
        senduart_a_byte(0x0D);
        senduart_a_byte(0x0A);
}
void send_cmgf(void)
{
	printsuart(AT_CMGF);
        senduart_a_byte(0x0D);
        senduart_a_byte(0x0A);
}
void send_csca(void)
{
	printsuart(AT_CSCA);
        senduart_a_byte(0x0D);
        senduart_a_byte(0x0A);
}
void send_cmgs(void)
{
	printsuart(AT_CMGS);
        senduart_a_byte(0x0D);
        senduart_a_byte(0x0A);
}
void sendmessage(void)
{
	printsuart(message);
        //delay_50ms(30);
	senduart_a_byte(0x1A);
        senduart_a_byte(0x0D);
        senduart_a_byte(0x0A);
}


/*****************************************
//uart1����
*****************************************/ 
	


