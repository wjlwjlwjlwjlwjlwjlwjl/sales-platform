#include<iostream>
#include<fstream>
using namespace std;

int select;

struct User {
	bool u_state = true;		//�û���״̬
	char u_id[5] = { 'U' };		//�û���ID
	char u_name[11];			//�û�������
	char u_phone[21];			//�û��ĵ绰
	double u_money = 0;			//�û������
	char u_adress[41];			//�û��ĵ�ַ
	char u_password[21];		//�û�������
	double u_bid = 0;			//�û�����

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
	void User_login();			//�û���¼
	void User_sign_up(bool &flage);		//�û�ע��				//�������
	bool Buyer_or_Seller();		//ѡ���Լ�����һ�������
	void Change_adress();		//�޸��ջ���ַ
	void Change_password();		//�޸ĵ�¼����
	void Change_name();			//�޸��û���
	void Change_phone();		//�޸��ֻ���
	void Search_money();		//������
	void Add_money();			//��ֵ
	void Change_bid();			//�޸ı���
	void Cancel_bid();			//ȡ������
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
	cin >> select;
	
}
//����Աģ�顣
void Users_Module(int st)
{
	bool flage = 0;
	Users user;
	if (st == 2)
	{
		user.User_sign_up(flage);
		if (flage)
			cout << "* * * ��ϲ�㣬�˺�ע��ɹ���* * *";
		else
			cout << "* * * �ܱ�Ǹ���˺Ŵ���ʧ�ܣ�* * *";
	}
	else
	{

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

void Users::User_sign_up(bool &flage)
{
	User someone;
	ofstream outfile;
	outfile.open("C:/Users/2931582547/Desktop/my program/user.txt", ios::app);
	outfile << endl;
	cout << "���������������";
	cin >> someone.u_name;
	cout << "��������ĵ绰���룺";
	cin >> someone.u_phone;
	cout << "��������ĵ�ַ��";
	cin >> someone.u_adress;
	cout << "�봴��������룺";
	cin >> someone.u_password;
	someone.u_id[1] = 1+ '0';
	someone.u_id[2] = 2 + '0';
	someone.u_id[3] = 3 + '0';
	outfile << someone.u_id << "      ";
	outfile << someone.u_name << "      ";
	outfile << someone.u_phone << "    ";
	outfile << someone.u_adress << "         ";
	outfile << someone.u_money << "             ";
	if (someone.u_state)
		outfile << "����"<<"       ";
	else
		outfile << "�쳣"<<"       ";
	outfile << "*" << someone.u_password;
	outfile.close();
	flage = 1;
}
//ID����ʵ�ֲ�����ȫ�����뷽ʽ����ȷ����Ϣƥ�䲻���ơ�

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
		cin >> select;
		while (cin.fail()) 
		{
			cerr << "����������������룺";
			cin.clear();
			cin.ignore();
			cin >> select;
		}
		switch (select)
		{
		case 1:Administrator_Module(); break;
		case 2:Users_Module(2); break;
		case 3:Users_Module(3); break;
		case 4:exit(0); break;
		default:cout << "Incorrectly entered command" << endl; break;
		}
		break;
	}
	return 0;
}
//�Ƚ����ơ�