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
#define offset 300

struct User {
	char u_state[10] = "�û�";		//�û���״̬
	char u_id[5] = { 'U' };			//�û���ID
	char u_name[11] = { '0' };		//�û�������
	char u_phone[21] = { '0' };		//�û��ĵ绰
	char u_money[100] = { '0' };	//�û������
	char u_adress[41] = { '0' };	//�û��ĵ�ַ
	char u_password[21] = { '0' };	//�û�������
	char u_bid[100] = { '0' };		//�û�����
	char credibility[100] = { '0' };	//�û�������
	int count=0;					//������Ʒ��
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
	char g_time[100] = { '0' };		//��Ʒ�ϼܵ�ʱ��
	char g_seller[5] = { 'U' };		//��Ʒ���ҵ�ID
	char g_number[20] = { '0' };	//��Ʒ������
	char g_message[201] = { '0' };	//��Ʒ��Ϣ	
	char endtime[100] = { '0' };	//����ʱ��
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
	char state[10] = { '0' };		//״̬
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
	Good* a_goods_begin;			//��Ʒ��ʼ
	Good* a_goods_end;				//��Ʒ����
	User* a_users_begin;			//�û���ʼ
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
	void Get_Bid(User*user);						//��ȡ����
	void Change_Bid(User*user);			//�޸ľ���
	void Remove_Bid(User*user);			//ȡ������
	void Bid_nemu(User* user);			//�˵�
	User* user_buyer;					//ָ����ǰ����û�
	Good* goods_message_buyer_begin;	//��ȡ��Ʒ��Ϣ
	Good* goods_message_buyer_end;		//��ȡ��Ʒ��Ϣ
	Good* now_good;						//��ȡ��Ʒ��Ϣ
	Order* orders_message_buyer;		//��ȡ������Ϣ
	Order* orders_begin_buyer;
	Order* order_end_buyer;
	Bidding* bid_begin;					//��ȡ������Ϣͷ
	Bidding* bid_end;					//��ȡ������Ϣβ
	Bidding* begin;						//���۵���Ʒ
	Bidding* end;						//���۵���Ʒ
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


bool compare(char time1[], char time2[])
{
	int year1 = 0, month1 = 0, day1 = 0, hour1 = 0, minute1 = 0, mis1 = 0;
	int year2 = 0, month2 = 0, day2 = 0, hour2 = 0, minute2 = 0, mis2 = 0;
	int cnt1 = 1, cnt2 = 1;
	int i = 0;
	int j = 0;
	while (cnt1 < 6)
	{
		if (time1[i] == '[')
			i++;
		char str1[10] = { '0' };
		int count = 0;
		while (time1[i]!='-'&&time1[i]!=':'&&time1[i] != ']')
		{
			str1[count] = time1[i];
			i++;
			count++;
		}
		i++;
		if (cnt1 == 1)
			year1 = atoi(str1);
		else if (cnt1 == 2)
			month1 = atoi(str1);
		else if(cnt1==3)
			day1= atoi(str1);
		else if(cnt1==4)
			hour1= atoi(str1);
		else if(cnt1==5)
			minute1= atoi(str1);
		else if(cnt1==6)
			mis1= atoi(str1);
		cnt1++;
	}
	while (cnt2 < 6)
	{
		if (time2[j] == '[')
			j++;
		char str2[10] = { '0' };
		int count = 0;
		while (time2[j] != '-' && time2[j] != ':' && time2[j] != ']')
		{
			str2[count] = time2[j];
			count++;
			j++;
		}
		j++;
		if (cnt2 == 1)
			year2 = atoi(str2);
		else if (cnt2 == 2)
			month2 = atoi(str2);
		else if (cnt2 == 3)
			day2 = atoi(str2);
		else if (cnt2 == 4)
			hour2 = atoi(str2);
		else if (cnt2 == 5)
			minute2 = atoi(str2);
		else if (cnt2 == 6)
			mis2 = atoi(str2);
		cnt2++;
	}
	if (year1 > year2)
		return true;
	else if (year1 < year2)
		return false;
	else
	{
		if (month1 > month2)
			return true;
		else if (month1 < month2)
			return false;
		else
		{
			if (day1 > day2)
				return true;
			else if (day1 < day2)
				return false;
			else
			{
				if (hour1 > hour2)
					return true;
				else if (hour1 < hour2)
					return false;
				else
				{
					if (minute1 > minute2)
						return true;
					else if (minute1 < minute2)
						return false;
					else
					{
						if (mis1 > mis2)
							return true;
						else if (mis1 <= mis2)
							return false;
					}
				}
			}
		}
	}
}
//�Ƚ�ʱ���С��time1>time2,����1;

Bidding* SortList(Bidding* head) {
	if (head == NULL || head->next == NULL)return head;
	Bidding* pos = new Bidding;
	pos = head;
	while (pos->next != NULL)
	{
		Bidding* max = pos->next, * p = pos->next->next;
		while (p != NULL)
		{
			if (p->bid > max->bid)
				max = p;
			p = p->next;
		}
		swap(max->bid, pos->next->bid);
		swap(max->g_id, pos->next->g_id);
		swap(max->number, pos->next->number);
		swap(max->u_id, pos->next->number);
		swap(max->time, pos->next->time);
		swap(max->time, pos->next->time);
		pos = pos->next;
	}
	delete pos;
	return head;
}
