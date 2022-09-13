#include<iostream>
#include<fstream>
#include<windows.h>
#include<stdio.h>
using namespace std;

int option;

struct User {
	bool u_state = true;		//�û���״̬
	char u_id[5] = { 'U' };		//�û���ID
	char u_name[11];			//�û�������
	char u_phone[21];			//�û��ĵ绰
	double u_money = 0;			//�û������
	char u_adress[41];			//�û��ĵ�ַ
	char u_password[21];		//�û�������
	double u_bid = 0;			//�û�����
	User* next;					//���ڴ����洢�ļ����û���Ϣ������
};
//�����û��ṹ�����ڴ洢�û�����Ϣ��
struct Good {
	int g_state = 1;			//��Ʒ��״̬��1��ʾ���ۣ�2��ʾ���ۿգ�3��ʾ�¼ܣ�
	char g_id[5] = { 'M' };		//��Ʒ��ID
	char g_name[21];			//��Ʒ����
	double g_price = 0;			//��Ʒ�ĵ׼�
	char g_time[20];			//��Ʒ�ϼܵ�ʱ��
	char g_seller[5];			//��Ʒ���ҵ�ID
	int g_number;				//��Ʒ������
	char g_message[201];		//��Ʒ��Ϣ	
	bool g_progress;			//��Ʒ�ľ��Ľ��̣�24Сʱ������
};
//������Ʒ�Ľṹ���洢��Ʒ����Ϣ��
struct Order {
	char o_id[5] = { 'T' };		//����ID
	char good_id[5] = { 'M' };	//��ƷID
	double o_price = 0;			//�����۸�
	char o_time[20];			//����ʱ��
	int o_number;				//��������
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
class Users
{
public:
	bool User_login();			//�û���¼
	void User_sign_up();		//�û�ע��	

	bool Buyer_or_Seller();		//ѡ���Լ�����һ�������
	void Change_adress();		//�޸��ջ���ַ
	void Change_password();		//�޸ĵ�¼����
	void Change_name();			//�޸��û���
	void Change_phone();		//�޸��ֻ���
	void Search_money();		//������
	void Add_money();			//��ֵ
	void Change_bid();			//�޸ı���
	void Cancel_bid();			//ȡ������
	void Get_Users_Message();   //���ļ��л�ȡ��Ϣ
	void User_Menu();			//�û����ܲ˵�
	User* users_message;		//���ڶ�ȡ�ļ��е���Ϣ
};
//�û��ࡣ
class Buyers :public Users 
{

};
//����ࡣ
class Sellers :public Users 
{

};
//�����ࡣ
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
	if (st == 2)
	{
		user.User_sign_up();
		user.Get_Users_Message();
		system("cls");
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
		user.Get_Users_Message();
		login:
		system("cls");
		if (user.User_login())
			;
		else
		{
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
void Buyers_Module()
{

}
//���ģ�顣
void Sellers_Module()
{

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
void Information_Module()
{

}



//�û�ģ�麯��
void Users::User_sign_up()
{
	User* someone = new User;
	fstream outfile("C:/Users/2931582547/Desktop/my program/user.txt", ios::app);
	cout << "���������������";
	cin >> someone->u_name;
	cout << "��������ĵ绰���룺";
	cin >> someone->u_phone;
	cout << "��������ĵ�ַ��";
	cin >> someone->u_adress;
	cout << "�봴��������룺";
	cin >> someone->u_password;
	if (!outfile)
	{
		cout << "* * * ���ź����û�ע��ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	if (someone != NULL)
	{
		outfile << someone->u_name <<" " << someone->u_phone << " "<<someone->u_adress <<" "<< someone->u_password <<" "<< someone->u_state<<" ";
		delete someone;
	}
	cout << "* * * ��ϲ�����û�ע��ɹ���* * *" << endl;
	outfile.close();
	/*bool flage;
	FILE* fp;
	fp = fopen("C:/Users/2931582547/Desktop/my program/user.txt", "w");
	if (fp == NULL)
		fopen("C:/Users/2931582547/Desktop/my program/user.txt", "w+");
	cout << "���������������";
	cin >> someone->u_name;
	cout << "��������ĵ绰���룺";
	cin >> someone->u_phone;
	cout << "��������ĵ�ַ��";
	cin >> someone->u_adress;
	cout << "�봴��������룺";
	cin >> someone->u_password;
	fprintf(fp, "%s\t%s\t%s\t%s\t%s\n", someone->u_name, someone->u_phone, someone->u_adress, someone->u_password,"����");
	fclose(fp);
	flage = 1;
	if (flage)
	{
		cout << "* * * ��ϲ�㣬�˺�ע��ɹ���* * *" << endl;
	}
	else
		cout << "* * * �ܱ�Ǹ���˺Ŵ���ʧ�ܣ�* * *" << endl;*/
}
//ID����ʵ�ֲ�����ȫ�����뷽ʽ����ȷ����Ϣƥ�䲻���ơ�
void  Users::Get_Users_Message()
{
	int i = 0;
	User* p, * q;
	p = new User;
	users_message = new User;
	q = users_message;
	ifstream infile("C:/Users/2931582547/Desktop/my program/user.txt", ios::in | ios::binary);
	if (!infile)
	{
		cout << "�û���Ϣ�ļ������ڣ�" << endl; 
		system("cls");
		exit(0);
	}
	while (!infile.eof())
	{
		infile >> p->u_name >> p->u_phone >> p->u_adress >> p->u_password >> p->u_state;
		q->next = p;
		q = p;
		p = new User;
		i++;
	}
	q->next = NULL;
	if (i == 0) {
		cout << "�û���ϢΪ��" << endl;
		system("cls");
	}
	delete p;
	delete q;
	infile.close();
}
bool Users::User_login()
{
	User someone;
	int flage = 0;
	cout<< "�������û�����";
	cin >> someone.u_name;
	cout << "���������룺";
	cin >> someone.u_password;
	User* p, * q;
	p = this->users_message;					
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



