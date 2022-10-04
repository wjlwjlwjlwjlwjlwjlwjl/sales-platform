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
using namespace std;
int option;
struct User {
	char u_state = '1';				//�û���״̬
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
	char g_state = '1';				//��Ʒ��״̬��1��ʾ���ۣ�2��ʾ���ۿգ�3��ʾ�¼ܣ�
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
	char content[30] = { '0' };		//��Ϣ������
	char nowtime[20] = { '0' };		//��Ϣ��ʱ��
	char name[11] = { '0' };		//����Ϣ����
	Message* next;					//��һ����Ϣ
};
//������Ϣ�Ľṹ�����ڴ�������Ⱥ��Ϣ�����洢������Ϣ

class Auction_group
{
public:
	void Send_Message();			//������Ϣ
	void Withdraw_Message();		//�涨�û�ֻ�ܳ���2�����ڵ���Ϣ
	void Assign_Goods();			//�����������������Ʒ���۳���ؽ��
	void Display_History_Message();	//��ʾ��ʷ��Ϣ
	void Store_Message();			//�洢��Ϣ
	void Join_Group_Menu();			//����Ⱥ��ҳ��
	Message* start;					//��Ϣͷ
	Message* end;					//��Ϣβ
	Message* now;					//��ǰ��Ϣ
	User* nowuser;					//��ǰ�û�
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
	void Change_bid();			//�޸ı���
	void Cancel_bid();			//ȡ������
	void Get_Users_Message();   //��user�ļ��л�ȡ��Ϣ
	void Update_message();		//�����ļ��е���Ϣ
	void User_Menu();			//�û����ܲ˵�
	void Information_Module();	//��Ϣģ��
	void Buyers_Module();		//���ģ��
	void Sellers_Module();		//����ģ��
	User* users_begin;		//���ڶ�ȡ�ļ��е���Ϣ
	User* users_end;		//���ڶ�ȡ�ļ��е���Ϣ
	User* now_user;				//����ָ��ǰ�û�
};
//�û��ࡣ



class Administrator:public Auction_group
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
	Good* a_goods_begin;				//��Ʒ��ʼ
	Good* a_goods_end;				//��Ʒ����
	User* a_users_begin;				//�û���ʼ
	User* a_users_end;				//�û�����
	char a_name[11];
	char a_password[21];
};
//����Ա�ࡣ
class Buyers :public Users,public Auction_group
{
public:
	void Search_all_Goods();			//�鿴��Ʒ�б�
	void Bid_Good();					//������Ʒ
	void Search_Good();					//������Ʒ
	void Good_Message();				//�鿴��Ʒ��ϸ��Ϣ
	void B_Histroy_Orders();			//�鿴��ʷ����
	void Get_Goods_Message();			//��good�ļ��л�ȡ��Ϣ
	void Get_Orders_Message();			//��order�ļ��л�ȡ��Ϣ
	User* user_buyer;					//ָ����ǰ����û�
	Good* goods_message_buyer_begin;	//��ȡ��Ʒ��Ϣ
	Good* goods_message_buyer_end;		//��ȡ��Ʒ��Ϣ
	Good* now_good;						//��ȡ��Ʒ��Ϣ
	Order* orders_message_buyer;		//��ȡ������Ϣ
};
//����ࡣ
class Sellers :public Users,public Auction_group
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
	User* user_seller;					//ָ�������û�
	Good* goods_message_seller_begin;	//��ȡ��Ʒ��Ϣ
	Good* goods_message_seller_end;		//��ȡ��Ʒ��Ϣ
	Good* now_good;						//ָ��ǰ��Ʒ
	Order* orders_message_seller;		//��ȡ��Ʒ��Ϣ
};
//�����ࡣ


/*
void xy(int y, int x)
{
	COORD  coord;
	coord.X = x;
	coord.Y = y;
	HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(a, coord);
}*/