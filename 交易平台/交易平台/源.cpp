#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<windows.h>
#include<stdio.h>
#include "stdlib.h"
#include <tchar.h>
#include<graphics.h>
#include<conio.h>
#include<map>
using namespace std;

int option;

struct User {
	char u_state = '1';		//�û���״̬
	char u_id[5] = { 'U' };		//�û���ID
	char u_name[11]={'0'};			//�û�������
	char u_phone[21]={'0'};			//�û��ĵ绰
	char u_money[100] = {'0'};			//�û������
	char u_adress[41]={'0'};			//�û��ĵ�ַ
	char u_password[21]={'0'};		//�û�������
	char u_bid[100] = {'0'};			//�û�����
	User* next;					//���ڴ����洢�ļ����û���Ϣ������
	int cnt = 1;				//���ڸ��û�����ID
};
//�����û��ṹ�����ڴ洢�û�����Ϣ��
struct Good {
	char g_state = '1';			//��Ʒ��״̬��1��ʾ���ۣ�2��ʾ���ۿգ�3��ʾ�¼ܣ�
	char g_id[5] = { 'M' };		//��Ʒ��ID
	char g_name[21]={'0'};			//��Ʒ����
	char g_price[100] = {'0'};			//��Ʒ�ĵ׼�
	char g_time[20]={'0'};			//��Ʒ�ϼܵ�ʱ��
	char g_seller[5]={'U'};			//��Ʒ���ҵ�ID
	char g_number[20]={'0'};				//��Ʒ������
	char g_message[201]={'0'};		//��Ʒ��Ϣ	
	char g_progress[20] = {'0'};			//��Ʒ�ľ��Ľ��̣�24Сʱ������
	Good* next;
	int cnt = 1;
};
//������Ʒ�Ľṹ���洢��Ʒ����Ϣ��
struct Order {
	char o_id[5] = { 'T' };		//����ID
	char good_id[5] = { 'M' };	//��ƷID
	char o_price[100] = {'0'};			//�����۸�
	char o_time[20]={'0'};			//����ʱ��
	char o_number[20]={'0'};				//��������
	char seller_id[5] = { 'U' };//����ID
	char buyer_id[5] = { 'U' };	//���ID
};
//���嶩���Ľṹ���洢��������Ϣ��
class Administrator
{
public:
	void A_menu();			//����Ա����
	void all_goods();		//�鿴���е���Ʒ
	void search_goods(char id[]);	//������Ʒ
	void remove_goods(char id[]);	//�¼���Ʒ
	void all_orders();		//�鿴���ж���
	void all_users();		//�鿴�����û�
	void ban_user(char id[]);		//����û�
	void cancel();			//ע��

private:
	char a_name[11];
	char a_password[21];
};
//����Ա�ࡣ

class Buyers
{
public:
	void Search_all_Goods();			//�鿴��Ʒ�б�
	void Buy_Good();					//������Ʒ
	void Search_Good();					//������Ʒ
	void Good_Message();				//�鿴��Ʒ��ϸ��Ϣ
	void B_Histroy_Orders();			//�鿴��ʷ����
	void Get_Goods_Message();			//��good�ļ��л�ȡ��Ϣ
	void Get_Orders_Message();			//��order�ļ��л�ȡ��Ϣ
	User* user_buyer;					//ָ����ǰ����û�
	Good* goods_message_buyer;			//��ȡ��Ʒ��Ϣ
	Order* orders_message_buyer;		//��ȡ������Ϣ
};
//����ࡣ
class Sellers
{
public:
	void List_Good(User*p);				//������Ʒ
	void Listed_Good(User*w);					//�鿴������Ʒ
	void Change_Good_Message();			//�޸���Ʒ��Ϣ
	void Remove_Good();					//�¼���Ʒ
	void S_Histroy_Orders();			//�鿴��ʷ����
	void Get_Goods_Message();			//��good�ļ��л�ȡ��Ϣ
	void Get_Orders_Message();			//��order�ļ��л�ȡ��Ϣ
	User* user_seller;					//ָ�������û�
	Good* goods_message_seller_begin;	//��ȡ��Ʒ��Ϣ
	Good* goods_message_seller_end;		//��ȡ��Ʒ��Ϣ
	Order* orders_message_seller;		//��ȡ��Ʒ��Ϣ
};
//�����ࡣ

class Users:public Buyers,public Sellers
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

void Sellers::List_Good(User*p)
{
	Get_Goods_Message();
	user_seller = p;
	Good* newgood=new Good;
	newgood->cnt = goods_message_seller_end->cnt;
	char opt = '0';
	cout << "��������Ʒ���ƣ�";
	cin >> newgood->g_name;
	cout << "��������Ʒ�۸�";
	cin >> newgood->g_price;
	cout << "��������Ʒ������";
	cin >> newgood->g_number;
	cout << "��������Ʒ������";
	cin >> newgood->g_message;
	cout << endl;
	newgood->cnt++;
	newgood->g_id[1] = newgood->cnt / 100 + '0';
	newgood->g_id[2] = (newgood->cnt % 100) / 10 + '0';
	newgood->g_id[3] = newgood->cnt % 10 + '0';
	if (cin.fail())
	{
		cerr << "������Ʒʧ�ܣ�";
		exit(0);
	}
	cout << "��ȷ�Ϸ�������Ʒ��Ϣ����" << endl;
	cout << "***********************************************" << endl;
	cout << "��Ʒ���ƣ�" << newgood->g_name << endl;
	cout << "��Ʒ�۸�" << newgood->g_price << endl;
	cout << "��Ʒ������" << newgood->g_number << endl;
	cout << "��Ʒ������" << newgood->g_message << endl;
	cout << "***********************************************" << endl;
	cout << endl;
	cout << "��ȷ��Ҫ������Ʒ��(y/n) ";
	cin >> opt;
	if (opt == 'y')
	{
		cout << "ȷ�Ϸ�����Ʒ"<<endl;
	}
	else
	{
		cout << "ȡ��������Ʒ"<<endl;
		exit(0);
	}
	fstream outfile("good.txt", ios::app);
	if (!outfile)
	{
		cout << "* * * ���ź�����Ʒ����ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	if (newgood != NULL)
	{
		outfile << newgood->g_id << " " << newgood->g_name << " " << newgood->g_price << " " << newgood->g_number << " " << newgood->g_message <<" " << user_seller->u_id << " " << newgood->g_state << endl;
		cout << "* * * ��ϲ����������Ʒ�ɹ���* * *" << endl;
		cout << "����Ʒ��IDΪ��";
		cout << newgood->g_id;
		delete newgood;
	}
	outfile.close(); 
}
void Sellers::Listed_Good(User*w)
{
	Get_Goods_Message();
	int flage = 0;
	Good* p;
	p = this->goods_message_seller_begin;
	if (p->next == NULL)
	{
		cout << "* * * δ�����κ���Ʒ * * *" << endl;
		Sleep(2000);
		exit(0);
	}
	cout << "********************************************************************************" << endl;
	cout << "  ��ƷID	����	�۸�	�ϼ�ʱ��	����	����ID	  ��Ʒ״̬" << endl;
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(p->g_seller,w->u_id) == 0)
		{
			cout << p->g_id << "  " << p->g_name << "  " << p->g_price << "         " << p->g_number << "  " << p->g_seller << "  " << p->g_state << endl;
			flage = 1;
		}
	}
	if (flage == 0)
		cout << "--------------------------------------------------------------------------------" << endl;
	cout << "********************************************************************************" << endl;
	delete p;
}
void Sellers::Change_Good_Message()
{
	;
}
void Sellers::Remove_Good()
{
	;
}
void Sellers::S_Histroy_Orders()
{
	;
}
void Sellers::Get_Goods_Message()
{
	int i = 0;
	Good* p, * q;
	p = new Good;
	goods_message_seller_begin = new Good;
	goods_message_seller_begin->next = NULL;
	q = goods_message_seller_begin;
	ifstream infile("good.txt", ios::in | ios::binary);
	if (!infile)
	{
		cout << "��Ʒ��Ϣ�ļ������ڣ�" << endl;
		Sleep(2000);
		system("cls");
		exit(0);
	}
	while (!infile.eof())
	{
		infile >> p->g_id >> p->g_name >> p->g_price >> p->g_number >> p->g_message >> p->g_seller >> p->g_state;
		if (infile.fail())
			break;
		p->next = NULL;
		q->next = p;
		q = q->next;
		p = new Good;
		i++;
	}
	goods_message_seller_end = q;
	if (i == 0)
	{
		goods_message_seller_end->g_id[1] = '0';
		goods_message_seller_end->g_id[2] = '0';
		goods_message_seller_end->g_id[3] = '0';
	}
	goods_message_seller_end->cnt = (goods_message_seller_end->g_id[1] - '0') * 100 + (goods_message_seller_end->g_id[2] - '0') * 10 + (goods_message_seller_end->g_id[3] - '0');
	q->next = NULL;
	infile.close();
	delete p;
}
void Sellers::Get_Orders_Message()
{

}



void Administrator_Module()
{
	system("cls");
	cout << "================================================================================================" << endl;
	cout << "  1.�鿴���е���Ʒ  2.������Ʒ  3.�¼���Ʒ  4.�鿴���ж���  5.�鿴�����û�  6.����û�  7.ע��" << endl;
	cout << "================================================================================================" << endl;
	cout << "�����������";
	cin >> option;
	
}
//����Աģ�顣
void Users_Module(int st)
{
	int flage = 0;
	Users user;
	User* somebody=new User;
	if (st == 2)
	{
		user.User_sign_up();
		//system("cls");
		cout << "��ѡ���Ƿ����ڵ�¼��1.��¼ 2.�˳�"<<endl;
		cin >> flage;
		if (flage == 1)
			goto login;
		else
			exit(0);
	}
	else
	{
		flage = 0;
		login:
		//system("cls");
		if (user.User_login())
			Sleep(2000);
		else
		{
			Sleep(2000);
			system("cls");
			cout << "��ѡ���Ƿ����µ�½��1.���µ�½ 2.�˳�"<<endl;
			cin >> flage;
			if (flage == 1)
				goto login;
			else
				exit(0);
		}
		user.User_Menu();
		


	}
}
//�û�ģ�顣
void Users::Buyers_Module()
{
	
}
//���ģ�顣
void Users::Sellers_Module()
{
	system("cls");
	cout << "========================================================================================" << endl;
	cout << "  1.������Ʒ 2.�鿴������Ʒ 3.�޸���Ʒ��Ϣ 4.�¼���Ʒ 5.�鿴��ʷ���� 6.�����û�������" << endl;
	cout << "========================================================================================" << endl;
	now_user->u_state = '0';
	Update_message();
	option = 0;
	cout << "�����������";
	cin >> option;
	while (cin.fail())
	{
		cerr << "����������������룺";
		cin.clear();
		cin.ignore();
		cin >> option;
	}
	switch (option)
	{
	case 1:List_Good(now_user); break;
	case 2:Listed_Good(now_user); break;
	case 3:Change_Good_Message(); break;
	case 4:Remove_Good(); break;
	case 5:S_Histroy_Orders(); break;
	case 6:User_Menu(); break;
	default:cout << "����ָ�����" << endl; break;
	}
}
//����ģ�顣






void Main_Menu() 
{
	cout << "====================================================" << endl;
	cout << "  1.����Ա��¼  2.�û�ע��  3.�û���¼  4.�˳�����" << endl;
	cout << "====================================================" << endl;
	cout << "�����������";
}
//��ҳ��˵���
void Bid_results()
{

}
//���Ľ����
void Users::Information_Module()
{
	system("cls");
	cout << "==================================================" << endl;
	cout << "  1.�鿴��Ϣ 2.�޸���Ϣ 3.��ֵ 4.�����û�������" << endl;
	cout << "==================================================" << endl;
	int opt = 0;
	cout << "�����������";
	cin >> opt;
	while (cin.fail())
	{
		cerr << "����������������룺";
		cin.clear();
		cin.ignore();
		cin >> opt;
	}
	switch (opt)
	{
	case 1:Search_message(); break;
	case 2:Change_message(); break;
	case 3:Add_money(); break;
	case 4:User_Menu(); break;
	default:cout << "��Ч���"; break;
	}
}
//�û�ģ�麯��
void Users::User_sign_up()
{
	Get_Users_Message();
	User* someone = new User;
	someone->cnt = users_end->cnt;
	User* a;
	l:
	cout << "���������������";
	cin >> someone->u_name;
	a = users_begin;
	while (a->next != NULL)
	{
		a = a->next;
		if (strcmp(someone->u_name, a->u_name) == 0)
		{
			cout << "�û����ظ�������������" << endl;
			goto l;
		}
	}
	cout << "��������ĵ绰���룺";
	cin >> someone->u_phone;
	cout << "��������ĵ�ַ��";
	cin >> someone->u_adress;
	cout << "�봴��������룺";
	cin >> someone->u_password;
	someone->cnt++;
	someone->u_id[1] = someone->cnt / 100 + '0';
	someone->u_id[2] = (someone->cnt % 100) / 10 + '0';
	someone->u_id[3] = someone->cnt % 10 + '0';
	fstream outfile("user.txt", ios::app);
	if (!outfile)
	{
		cout << "* * * ���ź����û�ע��ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	if (someone != NULL)
	{
		outfile << someone->u_id<<" "<< someone->u_name << " " << someone->u_phone << " " << someone->u_adress << " " << someone->u_password << " " << someone->u_state << " " << someone->u_money << endl;
		cout << "* * * ��ϲ�����û�ע��ɹ���* * *" << endl;
		cout << "ϵͳΪ�����ɵ�IDΪ��";
		cout << someone->u_id;
		cout << endl;
		Sleep(2000);
	}
	delete someone;
	delete a;
	outfile.close();
}	
void Users::Get_Users_Message()
{
	int i = 0;
	User* p, * q;
	p = new User;
	users_begin = new User;
	users_end = new User;
	users_begin->next = NULL;
	q = users_begin;
	ifstream infile("user.txt", ios::in | ios::binary);
	if (!infile)
	{
		cout << "�û���Ϣ�ļ������ڣ�" << endl; 
		Sleep(2000);
		system("cls");
		exit(0);
	}
	while (!infile.eof())
	{
		infile >> p->u_id>> p->u_name >> p->u_phone >> p->u_adress >> p->u_password >> p->u_state >> p->u_money;
		if (infile.fail())
			break;
		p->next = NULL;
		q->next = p;
		q = q->next;
		i++;
		p = new User;
	}
	users_end = q;
	if (i == 0)
	{
		users_end->u_id[1] = '0';
		users_end->u_id[2] = '0';
		users_end->u_id[3] = '0';
	}
	users_end->cnt = (users_end->u_id[1] - '0') * 100 + (users_end->u_id[2] - '0') * 10 + (users_end->u_id[3] - '0');
	q->next = NULL;
	infile.close();
	delete p;
}						//��ȡ������
bool Users::User_login()
{
	Get_Users_Message();
	now_user = new User;
	User someone;
	int flage = 0;
	cout<< "�������û�����";
	cin >> someone.u_name;
	cout << "���������룺";
	cin >> someone.u_password;
	User* p, * q;
	p = this->users_begin;
	q = new User;
	if (p == NULL)
	{
		cout << "* * * ���ź�����½ʧ�ܣ�* * *"<<endl;
		return false;
	}
	while (p->next != NULL) 
	{
		if (strcmp(p->next->u_name,someone.u_name)==0)
		{
			flage = 1;
			q = p->next;
			break;
		}
		p = p->next;
	}
	if (flage == 0)
	{
		cout << "* * * �û��������ڣ�* * *"<<endl;
		return false;
	}
	if (strcmp(q->u_password,someone.u_password)==0)
	{
		cout << "* * * ��ϲ������½�ɹ���* * *" << endl;
		now_user = q;
		return true;
	}
	else
	{
		cout << "* * * �������* * *" << endl;
		return false;
	}
	delete p, q;
}
void Users::User_Menu()
{
	system("cls");
	cout << "===================================================" << endl;
	cout << "  1.������� 2.�������� 3.������Ϣ���� 4.ע����¼" << endl;
	cout << "===================================================" << endl;
	int opt=0;
	cin >> opt;
	while (cin.fail())
	{
		cerr << "����������������룺";
		cin.clear();
		cin.ignore();
		cin >> opt;
	}
	switch (opt)
	{
	case 1:Buyers_Module(); break;
	case 2:Sellers_Module(); break;
	case 3:Information_Module(); break;
	case 4:exit(0); break;
	default:cout << "����ָ�����" << endl; break;
	}
}
void Users::Search_message()
{
	cout << "*************************************" << endl;
	cout << "�û�����" << now_user->u_name << endl;
	cout << "��ϵ��ʽ��" << now_user->u_phone << endl;
	cout << "��ַ��" << now_user->u_adress << endl;
	cout << "Ǯ����" << now_user->u_money << endl;
	cout << "*************************************" << endl;
}
void Users::Change_message()
{
	int opt;
	remake:
	opt = 0;
	cout << "��ѡ����Ҫ�޸ĵ����ԣ�1.�û��� 2.��ϵ��ʽ 3.��ַ 4.��¼���룩��";
	cin >> opt;
	while (cin.fail())
	{
		cerr << "������������³���" << endl;
		cin.clear();
		cin.ignore();
		cout << "��ѡ����Ҫ�޸ĵ����ԣ�1.�û��� 2.��ϵ��ʽ 3.��ַ 4.��¼���룩��";
		cin >> opt;
	}
	switch (opt)
	{
	case 1:Change_name(); break;
	case 2:Change_phone(); break;
	case 3:Change_adress(); break;
	case 4:Change_password(); break;
	default:cout << "��Ч������";break;
	}
	cout << "��ѡ���Ƿ�����޸ģ�1.�����޸� 2.�����޸Ĳ�������Ϣ�������" << endl;
	opt = 0;
	cin >> opt;
	switch (opt)
	{
	case 1:goto remake;
	case 2:Information_Module(); break;
	default:cout << "��Ч������"; break;
	}
}
void Users::Change_name()
{
	cout << "�������µ��û�����";
	cin >> now_user->u_name;
	Update_message();
}
void Users::Change_phone()
{
	cout << "�������µ���ϵ��ʽ��";
	cin >> now_user->u_phone;
	Update_message();
}
void Users::Change_adress()
{
	cout << "�������µ�ַ��";
	cin >> now_user->u_adress;
	Update_message();
}
void Users::Change_password()
{
	cout << "�������µ����룺";
	cin >> now_user->u_password;
	Update_message();
}
void Users::Update_message()
{
	User* p = new User;
	p = this->users_begin->next;
	fstream outfile("user.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * ���ź������ݱ���ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	if (p == NULL)
		outfile << 9;
	while (p != NULL)
	{
	outfile << p->u_id<<" "<<p->u_name << " " << p->u_phone << " " << p->u_adress << " " << p->u_password << " " << p->u_state << " " << p->u_money << endl;
	p = p->next;
	}
	outfile.close();
}
void Users::Add_money()
{
	double money;
	char str[100];
	cout << "�������ֵ��";
	cin >> money;
	initgraph(490, 670);
	loadimage(0, "collect_money.jpg",490,670);
	system("pause");
	closegraph();
	sprintf(str, "%.1lf\t", atof(now_user->u_money) + money);
	strcpy(now_user->u_money, str);
	Update_message();
	cout << "��ϲ������ֵ�ɹ���" << endl;
}
void Administrator::A_menu()
{
	system("cls");
	cout << "================================================================================================" << endl;
	cout << "  1.�鿴���е���Ʒ  2.������Ʒ  3.�¼���Ʒ  4.�鿴���ж���  5.�鿴�����û�  6.����û�  7.ע��" << endl;
	cout << "================================================================================================" << endl;
	cout << "�����������";
}
int main() {
	while (true)
	{
		system("cls");
		Main_Menu();
		cin >> option;
		while (cin.fail()) 
		{
			cerr << "����������������룺";
			cin.clear();
			cin.ignore();
			cin >> option;
		}
		switch (option)
		{
		case 1:Administrator_Module(); break;
		case 2:Users_Module(2); break;
		case 3:Users_Module(3); break;
		case 4:exit(0); break;
		default:cout << "����ָ�����" << endl; break;
		}
		break;
	}
	return 0;
}
//�Ƚ����ơ�



