#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<stdio.h>
#include "stdlib.h"
#include <tchar.h>
#include<graphics.h>
#include<conio.h>
#include<map>
#include<time.h>
#include<ctime>
using namespace std;
int option;
#define MAXLEN 200
struct User {
	char u_state[10] = "�û�";		//�û���״̬
	char u_id[5] = { 'U' };			//�û���ID
	char u_name[11] = { '0' };		//�û�������
	char u_phone[21] = { '0' };		//�û��ĵ绰
	char u_money[100] = { '0' };	//�û������
	char u_adress[41] = { '0' };	//�û��ĵ�ַ
	char u_password[21] = { '0' };	//�û�������
	char u_bid[100] = { '0' };		//�û�����
	User* next;						//���ڴ����洢�ļ����û���Ϣ������
	int cnt = 1;					//���ڸ��û�����ID
};
//�����û��ṹ�����ڴ洢�û�����Ϣ��
struct Good {
	char g_state[10] = "����";		//��Ʒ��״̬��1��ʾ���ۣ�2��ʾ���ۿգ�3��ʾ�¼ܣ�
	char g_type[10] ="ֱ��";		//��Ʒ�Ǿ���0����ֱ������1������2
	char g_id[5] = { 'M' };			//��Ʒ��ID
	char g_name[21] = { '0' };		//��Ʒ����
	char g_price[100] = { '0' };	//��Ʒ�ĵ׼�
	char g_time[20] = { '0' };		//��Ʒ�ϼܵ�ʱ��
	char g_seller[5] = { 'U' };		//��Ʒ���ҵ�ID
	char g_number[20] = { '0' };	//��Ʒ������
	char g_message[201] = { '0' };	//��Ʒ��Ϣ	
	char g_progress[20] = { '0' };	//��Ʒ�ľ��Ľ��̣�24Сʱ������
	Good* next;						//���ڴ����洢�ļ�����Ʒ��Ϣ������
	int cnt = 1;					//���ڸ���Ʒ����ID
};
//������Ʒ�Ľṹ���洢��Ʒ����Ϣ��
struct Order {
	char o_id[5] = { 'T' };			//����ID
	char good_id[5] = { 'M' };		//��ƷID
	char o_price[100] = { '0' };	//�����۸�
	char o_time[20] = { '0' };		//����ʱ��
	char o_number[20] = { '0' };	//��������
	char seller_id[5] = { 'U' };	//����ID
	char buyer_id[5] = { 'U' };		//���ID
	Order* next;					//���ڴ����洢�ļ��ж�����Ϣ������
	int cnt = 1;					//���ڸ���������ID
};
//���嶩���Ľṹ���洢��������Ϣ��
struct Message
{
	char content[400] = {'0'};		//��Ϣ������
	char nowtime[20] = { '0' };		//��Ϣ��ʱ��
	char name[11] = { '0' };		//����Ϣ����
	Message* next;					//��һ����Ϣ
};
//������Ϣ�Ľṹ�����ڴ�������Ⱥ��Ϣ�����洢������Ϣ
struct Bidding
{
	char g_id[5] = { 'M' };			//��ƷID
	char u_id[5] = { 'U' };			//�û�ID
	char bid[100] = { '0' };		//�û�����
	char number[5] = { '0' };		//����
	char time[100] = { '0' };		//ʱ��
	Bidding* next;
};


class Users//:public Sellers,public Buyers
{
public:
	bool User_login();			//�û���¼
	void User_sign_up();		//�û�ע��	
	void Search_message();		//�鿴��Ϣ
	void Change_message();		//�޸���Ϣ
	void Change_adress();		//�޸��ջ���ַ
	void Change_password();		//�޸ĵ�¼����
	void Change_name();			//�޸��û���
	void Change_phone();		//�޸��ֻ���
	void Add_money();			//��ֵ
	void Get_Users_Message();   //��user�ļ��л�ȡ��Ϣ
	void Update_message();		//�����ļ��е���Ϣ
	void User_Menu();			//�û����ܲ˵�
	void Information_Module();	//��Ϣģ��
	void Buyers_Module();		//���ģ��
	void Sellers_Module();		//����ģ��
	void User_nemu();			//�˵�
	User* users_begin;		//���ڶ�ȡ�ļ��е���Ϣ
	User* users_end;		//���ڶ�ȡ�ļ��е���Ϣ
	User* now_user;				//����ָ��ǰ�û�
};
//�û��ࡣ



class Administrator//:public Auction_group
{
public:
	void all_goods();				//�鿴���е���Ʒ
	void search_goods();			//������Ʒ
	void remove_goods();			//�¼���Ʒ
	void all_orders();				//�鿴���ж���
	void all_users();				//�鿴�����û�
	void ban_user();				//����û�
	void Achieve_Goods_Message();	//��ȡ��Ʒ��Ϣ
	void Updata_Goods();			//������Ʒ��Ϣ
	void Achieve_Users_Message();	//��ȡ�û���Ϣ
	void Updata_Users();			//�����û���Ϣ
	void Delete_Message();			//ɾ����Ϣ
	void Admin_nemu();				//�˵�
	Good* a_goods_begin;				//��Ʒ��ʼ
	Good* a_goods_end;				//��Ʒ����
	User* a_users_begin;				//�û���ʼ
	User* a_users_end;				//�û�����
	char a_name[11];
	char a_password[21];
};
//����Ա�ࡣ
class Buyers :public Users//,public Auction_group
{
public:
	void Search_all_Goods();			//�鿴��Ʒ�б�
	void Buy_Good();					//������Ʒ
	void Search_Good();					//������Ʒ
	void Good_Message();				//�鿴��Ʒ��ϸ��Ϣ
	void B_Histroy_Orders();			//�鿴��ʷ����
	void Get_Goods_Message();			//��good�ļ��л�ȡ��Ϣ
	void Get_Orders_Message();			//��order�ļ��л�ȡ��Ϣ
	void Store_Orders();				//�洢������Ϣ
	void Buyer_nemu();					//�˵�
	void Bid(User*user);				//����
	void Get_Bid();						//��ȡ����
	void Change_Bid(User*user);					//�޸ľ���
	void Remove_Bid(User*user);					//ȡ������
	User* user_buyer;					//ָ����ǰ����û�
	Good* goods_message_buyer_begin;	//��ȡ��Ʒ��Ϣ
	Good* goods_message_buyer_end;		//��ȡ��Ʒ��Ϣ
	Good* now_good;						//��ȡ��Ʒ��Ϣ
	Order* orders_message_buyer;		//��ȡ������Ϣ
	Order* orders_begin_buyer;
	Order* order_end_buyer;
	Bidding* bid_begin;					//��ȡ������Ϣͷ
	Bidding* bid_end;					//��ȡ������Ϣβ
};
//����ࡣ
class Sellers :public Users//,public Auction_group
{
public:
	void List_Good(User* p);		//������Ʒ
	void Listed_Good(User* w);	//�鿴������Ʒ
	void Change_Good_Message();	//�޸���Ʒ��Ϣ
	void Remove_Good(User*p);			//�¼���Ʒ
	void S_Histroy_Orders();		//�鿴��ʷ����
	void Get_Goods_Message();			//��good�ļ��л�ȡ��Ϣ
	void Get_Orders_Message();			//��order�ļ��л�ȡ��Ϣ
	void Updata_Goods_Message();		//�����ļ��е���Ʒ��Ϣ
	void Seller_nemu();					//�˵�
	User* user_seller;					//ָ�������û�
	Good* goods_message_seller_begin;	//��ȡ��Ʒ��Ϣ
	Good* goods_message_seller_end;		//��ȡ��Ʒ��Ϣ
	Good* now_good;						//ָ��ǰ��Ʒ
	Order* orders_message_seller;		//��ȡ��Ʒ��Ϣ
	Order* orders_begin_seller;
	Order* order_end_seller;
};
//�����ࡣ

class Auction_group
{
public:
	void Send_Message();			//������Ϣ
	void Withdraw_Message();		//�涨�û�ֻ�ܳ���2�����ڵ���Ϣ
	void Assign_Goods(Message* q);			//�����������������Ʒ���۳���ؽ��
	void Display_History_Message();	//��ʾ��ʷ��Ϣ
	void Store_Message();			//�洢��Ϣ
	void Join_Group_Menu();			//����Ⱥ��ҳ��
	void Send_Goods();				//����������Ʒ
	void Join_Auction();			//���뾺��
	void Cout_Message();			//���
	void Sort_bid(Message* q);		//�������
	Message* start;					//��Ϣͷ
	Message* end;					//��Ϣβ
	Message* now;					//��ǰ��Ϣ
	User* nowuser;					//��ǰ�û�
	Message* sort;
};


typedef struct
{
	char ch[MAXLEN + 1];	
	int length;			
}SString;
//KMP
int Index_KMP(SString S, SString T, int pos,int nextval[])
{
	int i = pos;	
	int j = 1;	

	while (i <= S.length && j <= T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j])	
		{
			++i;
			++j;
		}
		else				
		{
			j = nextval[j];
		}
	}
	if (j > T.length) return i - T.length;	
	else return 0;						
}
void get_next(SString T, int next[])
{
	int i = 1;
	int j = 0;	
	next[1] = 0;

	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else		
		{
			j = next[j];
		}
	}
}
void get_nextval(SString T, int nextval[])
{
	int i = 1;	
	int j = 0;	
	nextval[1] = 0;

	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])	
		{
			++i;
			++j;

			if (T.ch[i] != T.ch[j])
			{
				nextval[i] = j;
			}
			else
				nextval[i] = nextval[j];
		}
		else		
		{
			j = nextval[j];
		}
	}
}

/*class Sort {
public:
	void bubbleSort(Message* head, int n) {
		double b1,b2;
		if (!head || !head->next) return;
		for (int i = 0; i < n; ++i) {
			auto pre = head;
			auto cur = head->next;
			bool flag = 0;
			for (int j = 0; j < n - i - 1; ++j) {
				b1=strtod(pre->bid, NULL);
				b2 = strtod(cur->bid, NULL);
				if (cur != NULL && b1 > b2) {
					swap(pre, cur);
					flag = 1;
				}
				pre = pre->next;
				cur = cur->next;
			}
			if (!flag)   break;
		}
	}
	Message* sortList(Message* head) {
		auto p = head;
		int n = 0; // ��¼�ڵ����
		while (p != NULL) {
			++n;
			p = p->next;
		}
		bubbleSort(head, n);
		return head;
	}
};

*/


/*
void xy(int y, int x)
{
	COORD  coord;
	coord.X = x;
	coord.Y = y;
	HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(a, coord);
}*/