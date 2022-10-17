#include"Commodity Auction Platform.h"

void Users::Buyers_Module()
{
	Buyers* user = new Buyers;
	user->user_buyer = now_user;
	Auction_group* group = new Auction_group;
	group->nowuser = now_user;
	system("cls");
	cout << "======================================================================================================================" << endl;
	cout << "  1.�鿴��Ʒ�б� 2.���뾺��Ⱥ�� 3.������Ʒ 4.������Ʒ 5.���뾺�� 6.�鿴��ʷ���� 7.�鿴��Ʒ��ϸ��Ϣ 8.�����û�������" << endl;
	cout << "======================================================================================================================" << endl;
	strcpy(now_user->u_state, "���");
	Update_message();
	option = 0;
	cout << "���������:";
	cin >> option;
	l:
	while (cin.fail())
	{
		cerr << "�����������������:";
		cin.clear();
		cin.ignore();
		cin >> option;
	}
	switch (option)
	{
	case 1:user->Search_all_Goods();
		cout << "���������:";
		cin >> option;
		user->Buyer_nemu();
		goto l;
	case 2:group->Join_Group_Menu();
		cout << "���������:";
		cin >> option;
		user->Buyer_nemu();
		goto l;
	case 3:user->Search_Good();
		cout << "���������:";
		cin >> option;
		user->Buyer_nemu();
		goto l;
	case 4:user->Buy_Good(); 
		cout << "���������:";
		cin >> option;
		user->Buyer_nemu();
		goto l;
	case 5:user->Bid_nemu(now_user);
		cout << "���������:";
		cin >> option;
		user->Buyer_nemu();
		goto l;
	case 6:user->B_Histroy_Orders();
		cout << "���������:";
		cin >> option;
		user->Buyer_nemu();
		goto l;
	case 7:user->Good_Message(); 
		cout << "���������:";
		cin >> option;
		user->Buyer_nemu();
		goto l;
	case 8:User_Menu(); 
		break;
	default:cout << "����ָ�����" << endl; break;
	}
}
//���ģ�顣
void Users::Sellers_Module()
{
	//Get_Users_Message();
	Sellers* user = new Sellers;
	user->user_seller = now_user;
	Auction_group *group = new Auction_group;
	group->nowuser = now_user;
	system("cls");
	cout << "=======================================================================================================" << endl;
	cout << "  1.������Ʒ 2.�鿴������Ʒ 3.�޸���Ʒ��Ϣ 4.�¼���Ʒ 5.�鿴��ʷ���� 6.���뾺��Ⱥ�� 7.�����û�������" << endl;
	cout << "=======================================================================================================" << endl;
	strcpy(now_user->u_state, "����");
	Update_message();
	option = 0;
	cout << "���������:";
	cin >> option;
	l:
	while (cin.fail())
	{
		cerr << "�����������������:";
		cin.clear();
		cin.ignore();
		cin >> option;
	}
	switch (option)
	{
	case 1:user->List_Good(now_user);
		cout << "���������:";
		cin >> option;
		user->Seller_nemu();
		goto l;
	case 2:user->Listed_Good(now_user);
		cout << "���������:";
		cin >> option;
		user->Seller_nemu();
		goto l;
	case 3:user->Change_Good_Message(); 
		cout << "���������:";
		cin >> option;
		user->Seller_nemu();
		goto l;
	case 4:user->Remove_Good(now_user);
		cout << "���������:";
		cin >> option;
		user->Seller_nemu();
		goto l;
	case 5:user->S_Histroy_Orders(); 
		cout << "���������:";
		cin >> option;
		user->Seller_nemu();
		goto l;
	case 6:group->Join_Group_Menu(); 
		cout << "���������:";
		cin >> option;
		user->Seller_nemu();
		goto l;
	case 7:User_Menu(); break;
	default:cout << "����ָ�����" << endl; break;
	}
}
//����ģ�顣
void Users::Information_Module()
{
	system("cls");
	cout << "==================================================" << endl;
	cout << "  1.�鿴��Ϣ 2.�޸���Ϣ 3.��ֵ 4.�����û�������" << endl;
	cout << "==================================================" << endl;
	int opt = 0;
	cout << "���������:";
	cin >> opt;
	l:
	while (cin.fail())
	{
		cerr << "�����������������:";
		cin.clear();
		cin.ignore();
		cin >> opt;
	}
	//Get_Users_Message();
	switch (opt)
	{
	case 1:Search_message();
		cout << "���������:";
		cin >> opt;
		User_nemu();
		goto l;
	case 2:Change_message();
		cout << "���������:";
		cin >> opt;
		User_nemu();
		goto l;
	case 3:Add_money(); 
		cout << "���������:";
		cin >> opt;
		User_nemu();
		goto l;
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
	strcpy(someone->credibility, "10");
	fstream outfile("user.txt", ios::app);
	if (!outfile)
	{
		cout << "* * * ���ź����û�ע��ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	if (someone != NULL)
	{
		outfile << someone->u_id << " " << someone->u_name << " " << someone->u_phone << " " << someone->u_adress << " " << someone->u_password << " " << someone->u_state << " " << someone->u_money <<" "<<someone->credibility << endl;
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
		ofstream file("user.txt");
		if (file)
			file.close();
		else
		{
			cout << "�ļ�����ʧ�ܣ�" << endl;
			exit(-1);
		}
	}
	while (!infile.eof())
	{
		infile >> p->u_id >> p->u_name >> p->u_phone >> p->u_adress >> p->u_password >> p->u_state >> p->u_money >> p->credibility;
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
	cout << "�������û�����";
	cin >> someone.u_name;
	cout << "���������룺";
	cin >> someone.u_password;
	User* p, * q;
	p = this->users_begin;
	q = new User;
	if (p == NULL)
	{
		cout << "* * * ���ź�����½ʧ�ܣ�* * *" << endl;
		return false;
	}
	while (p->next != NULL)
	{
		if (strcmp(p->next->u_name, someone.u_name) == 0)
		{
			flage = 1;
			q = p->next;
			break;
		}
		p = p->next;
	}
	if (flage == 0)
	{
		cout << "* * * �û��������ڣ�* * *" << endl;
		return false;
	}
	if (strcmp(q->u_password, someone.u_password) == 0)
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
	delete p;
}
void Users::User_Menu()
{
	system("cls");
	cout << "===================================================" << endl;
	cout << "  1.������� 2.�������� 3.������Ϣ���� 4.ע����¼" << endl;
	cout << "===================================================" << endl;
	cout << "�����������";
	int opt = 0;
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
	case 4:break;
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
	default:cout << "��Ч������"; break;
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
	char name[11] = { '0' };
l:
	cout << "�������µ��û�����";
	cin >> name;
	//Get_Users_Message();
	User* a;
	a = users_begin;
	while (a->next != NULL)
	{
		a = a->next;
		if (strcmp(name, a->u_name) == 0)
		{
			cout << "�û����ظ�������������" << endl;
			goto l;
		}
	}
	strcpy(now_user->u_name, name);
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
	p = this->users_begin;
	fstream outfile("user.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * ���ź������ݱ���ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	while (p->next != NULL)
	{
		p = p->next;
		outfile << p->u_id << " " << p->u_name << " " << p->u_phone << " " << p->u_adress << " " << p->u_password << " " << p->u_state << " " << p->u_money << " " << p->credibility << endl;
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
	loadimage(0, "collect_money.jpg", 490, 670);
	system("pause");
	closegraph();
	sprintf(str, "%.1lf", atof(now_user->u_money) + money);
	strcpy(now_user->u_money, str);
	Update_message();
	cout << "��ϲ������ֵ�ɹ���" << endl;
}
void Users::User_nemu()
{
	system("cls");
	cout << "==================================================" << endl;
	cout << "  1.�鿴��Ϣ 2.�޸���Ϣ 3.��ֵ 4.�����û�������" << endl;
	cout << "==================================================" << endl;
}

void Sellers::List_Good(User* p)
{
	Get_Goods_Message();
	user_seller = p;
	Good* newgood = new Good;
	newgood->cnt = goods_message_seller_end->cnt;
	char opt = '0';
	cout << "��������Ʒ����:";
	cin >> newgood->g_name;
	cout << "��������Ʒ�۸�:";
	cin >> newgood->g_price;
	cout << "��������Ʒ����:";
	cin >> newgood->g_number;
	cout << "��������Ʒ����:";
	cin >> newgood->g_message;
	cout << "��������Ʒ����:";
	cin >> newgood->g_type;
	cout << endl;
	if (strcmp(newgood->g_type, "ֱ��") != 0 && strcmp(newgood->g_type, "����") != 0)
	{
		cout << "����ʧ�ܣ�" << endl;
		return;
	}
	newgood->cnt++;
	newgood->g_id[1] = newgood->cnt / 100 + '0';
	newgood->g_id[2] = (newgood->cnt % 100) / 10 + '0';
	newgood->g_id[3] = newgood->cnt % 10 + '0';
	if (cin.fail())
	{
		cerr << "������Ʒʧ�ܣ�";
		Seller_nemu();
		return;
	}
	cout << "��ȷ�Ϸ�������Ʒ��Ϣ����" << endl;
	cout << "***********************************************" << endl;
	cout << "��Ʒ����:" << newgood->g_name << endl;
	cout << "��Ʒ�۸�:" << newgood->g_price << endl;
	cout << "��Ʒ����:" << newgood->g_number << endl;
	cout << "��Ʒ����:" << newgood->g_message << endl;
	cout << "��Ʒ����:" << newgood->g_time << endl;
	cout << "***********************************************" << endl;
	cout << endl;
	cout << "��ȷ��Ҫ������Ʒ��(y/n) ";
	cin >> opt;
	if (opt == 'y')
	{
		cout << "ȷ�Ϸ�����Ʒ" << endl;
		time_t now;
		time(&now);
		struct tm* tempTime = localtime(&now);
		strftime(newgood->g_time, 80, "[%Y-%m-%d-%H:%M:%S]", tempTime);
		if (strcmp(newgood->g_type, "����") == 0)
		{
			now += offset;
			tempTime = localtime(&now);
			strftime(newgood->endtime, 80, "[%Y-%m-%d-%H:%M:%S]", tempTime);
		}
		else
			strcpy(newgood->endtime, "forever");
	}
	else
	{
		cout << "ȡ��������Ʒ" << endl;
		return;
		//exit(0);
	}
	fstream outfile("good.txt", ios::app);
	if (!outfile)
	{
		cout << "* * * ���ź�����Ʒ����ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	if (newgood != NULL)
	{
		outfile << newgood->g_id << " " << newgood->g_name << " " << newgood->g_price << " " <<newgood->g_time<<" " << newgood->g_number << " " << newgood->g_message << " " << user_seller->u_id << " " << newgood->g_state <<" "<<newgood->g_type <<" " <<newgood->endtime<< endl;
		cout << "* * * ��ϲ����������Ʒ�ɹ���* * *" << endl;
		cout << "����Ʒ��IDΪ��";
		cout << newgood->g_id << endl;
		delete newgood;
	}
	outfile.close();
}
void Sellers::Listed_Good(User* w)
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
	cout << "  ��ƷID	����	�۸�	�ϼ�ʱ��	����	����ID	  ��Ʒ״̬	��Ʒ����" << endl;
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(p->g_seller, w->u_id) == 0)
		{
			cout << p->g_id << "  " << p->g_name << "  " << p->g_price << "         " <<p->g_time<< "       " << p->g_number << "  " << p->g_seller << "  " << p->g_state << " " << p->g_type << endl;
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
	int opt;
	int flage = 0;
	opt = 0;
	Get_Goods_Message();
	Good* change_good = new Good;
	Good* p;
	p = goods_message_seller_begin;
	cout << "�����뱻�޸���Ʒ��ID��";
	cin >> change_good->g_id;
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(change_good->g_id, p->g_id) == 0)
		{
			if (strcmp(user_seller->u_id, p->g_seller) == 0)
			{
				flage = 1;
				change_good = p;
			}
			else
			{
				cout << "�ⲻ������������Ʒ����û��Ȩ���޸��������ԣ��볢���������롣" << endl;
				goto l;
			}
		}
	}
	if (flage == 0)
	{
		cout << "δ�ҵ�����Ʒ" << endl;
		exit(0);
	}
	cout << "��ѡ����Ҫ�޸ĵ���Ʒ���ԣ�1.��Ʒ���� 2.��Ʒ�۸� 3.��Ʒ��Ϣ 4.��Ʒ��������";
	cin >> opt;
	while (cin.fail())
	{
		cerr << "������������³���" << endl;
		cin.clear();
		cin.ignore();
		cout << "��ѡ����Ҫ�޸ĵ���Ʒ���ԣ�1.��Ʒ���� 2.��Ʒ�۸� 3.��Ʒ��Ϣ 4.��Ʒ��������";
		cin >> opt;
	}
	switch (opt)
	{
	case 1:
		cout << "�����뱻�޸���Ʒ�����ƣ�";
		cin >> change_good->g_name;
		Updata_Goods_Message();
		break;
	case 2:
		cout << "�����뱻�޸���Ʒ�ļ۸�";
		cin >> change_good->g_price;
		Updata_Goods_Message();
		break;
	case 3:
		cout << "�����뱻�޸���Ʒ����Ϣ��";
		cin >> change_good->g_message;
		Updata_Goods_Message();
		break;
	case 4:
		cout << "�����뱻�޸���Ʒ��������";
		cin >> change_good->g_number;
		Updata_Goods_Message();
		break;
	default:cout << "��Ч������"; break;
	}
l:
	cout << "��ѡ���Ƿ�����޸ģ�1.�����޸� 2.�����޸Ĳ�������Ϣ�������" << endl;
	opt = 0;
	cin >> opt;
	switch (opt)
	{
	case 1:Change_Good_Message(); break;
	case 2:
		Get_Users_Message();
		now_user = user_seller;
		Sellers_Module();
		break;
	default:cout << "��Ч������"; break;
	}
}
void Sellers::Remove_Good(User* p)
{
	Get_Goods_Message();
	user_seller = p;
	int flage = 0;
	Good* oldgood = new Good;
	Good* q = new Good;
	Good* temp = q;
	q = goods_message_seller_begin;
	char opt = '0';
	cout << "������Ҫ�¼ܵ���ƷID��";
	cin >> oldgood->g_id;
	//cout << endl;
	if (cin.fail())
	{
		cerr << "�¼���Ʒʧ�ܣ�";
		//exit(0);
		return;
	}
	while (q->next != NULL)
	{
		temp = q;
		q = q->next;
		if (strcmp(q->g_id, oldgood->g_id) == 0)
		{
			oldgood = q;
			flage = 1;
			if (strcmp(q->g_seller, user_seller->u_id) != 0)
				flage = 2;
			break;
		}
	}
	if (flage == 0)
	{
		cout << "û���ҵ�����Ʒ" << endl;
		return;
		//exit(0);
	}
	else if (flage == 2)
	{
		cout << "����Ʒ�����������ģ���û��Ȩ���޸�����" << endl;
		return;
		//exit(0);
	}
	cout << "��ȷ��Ҫ�¼ܸ���Ʒ��" << endl;
	cout << "********************************************************************" << endl;
	cout << "��ƷID" << "  " << "��Ʒ����" << "  " << "��Ʒ�۸�" << "  " << "��Ʒ����" << "  " << "����ID" << "  " << "��Ʒ״̬" <<" "<<"��Ʒ����"<< endl;
	cout << oldgood->g_id << "  " << oldgood->g_name << "  " << oldgood->g_price << "  "<<oldgood->g_time<<"  " << oldgood->g_number << "  " << user_seller->u_id << "  " << oldgood->g_state << " " << oldgood->g_type << endl;
	cout << "********************************************************************" << endl;
	cout << endl;
	cout << "��ѡ��(y/n) ";
	cin >> opt;
	if (opt == 'y')
	{
		cout << "�¼ܳɹ�" << endl;
		strcpy(oldgood->g_state, "�¼�");
	}
	else
	{
		cout << "�¼�ʧ��" << endl;
		return;
		//exit(0);
	}
	temp->next = q->next;
	delete oldgood;
	Updata_Goods_Message();
	delete temp;
}
void Sellers::S_Histroy_Orders()
{
	Get_Orders_Message();
	Order* p = new Order;
	p = orders_begin_seller;
	cout << "********************************************************************" << endl;
	cout << "����ID   ��ƷID   ���׵���   ����   ����ʱ��   ����ID   ���ID" << endl;
	while (p->next != NULL)
	{
		p = p->next;
		if(strcmp(p->seller_id,user_seller->u_id)==0)
			cout << p->o_id << "  " << p->good_id << "  " << p->o_price << "  " << p->o_number << "  " << p->o_time << "  " << p->seller_id << "  " << p->buyer_id << endl;
	}
	cout << "********************************************************************" << endl;
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
		ofstream file("good.txt");
		if (file)
			file.close();
		else
		{
			cout << "�ļ�����ʧ��" << endl;
			exit(-1);
		}
	}
	while (!infile.eof())
	{

		infile >> p->g_id >> p->g_name >> p->g_price >> p->g_time >> p->g_number >> p->g_message >> p->g_seller >> p->g_state >> p->g_type >> p->endtime;
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
	int i = 0;
	Order* p, * q;
	p = new Order;
	orders_begin_seller = new Order;
	order_end_seller = new Order;
	order_end_seller->next = NULL;
	q = orders_begin_seller;
	ifstream infile("order.txt", ios::in | ios::binary);
	if (!infile)
	{
		ofstream file("order.txt");
		if (file)
			file.close();
		else
		{
			cout << "�ļ�����ʧ��" << endl;
			exit(-1);
		}
	}
	while (!infile.eof())
	{
		infile >> p->o_id >> p->good_id >> p->o_price >> p->o_number >> p->o_time >> p->seller_id >> p->buyer_id;
		if (infile.fail())
			break;
		p->next = NULL;
		q->next = p;
		q = q->next;
		i++;
		p = new Order;
	}
	order_end_seller = q;
	q->next = NULL;
	infile.close();
	delete p;

}
void Sellers::Updata_Goods_Message()
{
	Good* p;
	p = this->goods_message_seller_begin->next;
	fstream outfile("good.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * ���ź������ݱ���ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	while (p != NULL)
	{
		outfile << p->g_id << " " << p->g_name << " " << p->g_price << " "<<p->g_time<<" " << p->g_number << " " << p->g_message << " " << p->g_seller << " " << p->g_state <<" "<<p->g_type<<" "<<p->endtime<< endl;
		p = p->next;
	}
	outfile.close();
}
void Sellers::Seller_nemu()
{
	system("cls");
	cout << "=======================================================================================================" << endl;
	cout << "  1.������Ʒ 2.�鿴������Ʒ 3.�޸���Ʒ��Ϣ 4.�¼���Ʒ 5.�鿴��ʷ���� 6.���뾺��Ⱥ�� 7.�����û�������" << endl;
	cout << "=======================================================================================================" << endl;
}

void Buyers::Search_all_Goods()
{
	Get_Goods_Message();
	cout << "********************************************************************************" << endl;
	cout << "  ��ƷID	����	�۸�	�ϼ�ʱ��	����	����ID	  ��Ʒ״̬   ��Ʒ����   ����ʱ��" << endl;
	Good* p = goods_message_buyer_begin;
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(p->g_state,"����")==0 || strcmp(p->g_state,"�ۿ�")==0)
			cout << p->g_id << "  " << p->g_name << "  " << p->g_price << "         " << p->g_time << "     " << p->g_number << "  " << p->g_seller << "  " << p->g_state <<"  " << p->g_type <<"  "<<p->endtime <<endl;
	}
	cout << "********************************************************************************" << endl;
}
void Buyers::Buy_Good()
{
	Get_Goods_Message();
	Get_Orders_Message();
	Order* o = new Order;
	order_end_buyer->next = new Order;
	o = order_end_buyer->next;
	int flage = 0;
	cout << "����������Ҫ�������Ʒ��ID:";
	char id[5] = { 'M' };
	int n = 0;
	cin >> id;
	cout << "�����빺������:";
	cin >> n;
	Good* p = goods_message_buyer_begin;
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(p->g_id, id) == 0)
		{
			flage = 1;
			break;
		}
	}
	if (flage == 0)
	{
		cout << "û���ҵ�����Ʒ" << endl;
		Buyer_nemu();
		return;
	}
	if (strcmp(p->g_type, "ֱ��") != 0)
	{
		cout << "����Ʒ������ֱ�ۣ�" << endl;
		return;
	}
	Get_Users_Message();
	User* t = users_begin;
	while (t->next != NULL)
	{
		t = t->next;
		if (t == user_buyer)
			break;
	}
	double money, price;
	int number;
	money = strtod(user_buyer->u_money, NULL);
	price = strtod(p->g_price, NULL);
	number = atoi(p->g_number);
	char str[100];
	cout << "��ȷ���Ƿ񻨷�" << price*n << "Ԫ������"<<n<<"������Ʒ" << endl;
	cout << "***********************************************" << endl;
	cout << "��ƷID:" << p->g_id << endl;
	cout << "��Ʒ����:" << p->g_name << endl;
	cout << "��Ʒ�۸�:" << p->g_price << endl;
	cout << "��Ʒ����:" << p->g_number << endl;
	cout << "�ϼ�ʱ��:" << p->g_time << endl;
	cout << "��Ʒ����:" << p->g_message << endl;
	cout << "��Ʒ����:" << p->g_seller << endl;
	cout << "***********************************************" << endl;
	cout << endl;
	char opt = '0';
	cout << "��ѡ��(y/n):";
	cin >> opt;
	if (opt == 'y')
	{
		if (strcmp(p->g_state,"�ۿ�")==0)
		{
			cout << "��Ʒ���ۿ�" << endl;
		}
		else if (strcmp(p->g_state,"�¼�") == 0)
		{
			cout << "��Ʒ���¼�" << endl;
		}
		else if (number < n)
		{
			cout << "��Ʒ��������" << endl;
		}
		else if (money >= price*n&&strcmp(p->g_state,"����")==0 && number >= n)
		{
			money -= price*n;
			sprintf(str, "%.1lf\t",money);
			strcpy(t->u_money, str);
			number -= n;
			if (number == 0)
				strcpy(p->g_state, "�ۿ�");
			_itoa(number, p->g_number, 10);
			Update_message();
			Good* q;
			q = this->goods_message_buyer_begin->next;
			fstream outfile("good.txt", ios::out);
			if (!outfile)
			{
				cout << "* * * ���ź������ݱ���ʧ�ܣ�* * *" << endl;
				exit(0);
			}
			while (q != NULL)
			{
				outfile << q->g_id << " " << q->g_name << " " << q->g_price << " " << q->g_time << " " << q->g_number << " " << q->g_message << " " << p->g_seller << " " << q->g_state << " " << q->g_type << endl;
				q = q->next;
			}
			outfile.close();
			o->cnt++;
			o->o_id[1] = o->cnt / 100 + '0';
			o->o_id[2] = (o->cnt % 100) / 10 + '0';
			o->o_id[3] = o->cnt % 10 + '0';
			_itoa(n, o->o_number, 10);
			strcpy(o->buyer_id, user_buyer->u_id);
			strcpy(o->seller_id, p->g_seller);
			time_t now;
			time(&now);
			struct tm* tempTime = localtime(&now);
			strftime(o->o_time, 80, "[%Y-%m-%d-%H:%M:%S]", tempTime);
			strcpy(o->o_price, p->g_price);
			strcpy(o->good_id, p->g_id);
			order_end_buyer = o;
			o->next = NULL;
			Store_Orders();
			cout << "����ɹ�" << endl;
		}
		else
		{
			cout << "����" << endl;
			//exit(0);
		}
	}
	else
	{
		cout << "�ɹ�ȡ������" << endl;
	}
}
void Buyers::Search_Good()
{
	Get_Goods_Message();
	char input[20] = { '0' };
	Good* p = goods_message_buyer_begin;
	cout << "����������Ҫ��������Ʒ��ID������:";
	cin >> input;
	int count = 0;
	if (input[0] == 'M')
	{
		while (p->next != NULL)
		{
			p = p->next;
			if ((strcmp(p->g_state,"����")==0 || strcmp(p->g_state,"�ۿ�")==0) && strcmp(input, p->g_id) == 0)
			{
				count++;
				if (count == 1)
				{
					cout << "********************************************************************************" << endl;
					cout << "  ��ƷID	����	�۸�	�ϼ�ʱ��	����	����ID	  ��Ʒ״̬    ��Ʒ����" << endl;
				}
				cout << p->g_id << "  " << p->g_name << "  " << p->g_price << "         " << p->g_time << "     " << p->g_number << "  " << p->g_seller << "  " << p->g_state << p->g_type << endl;
			}
		}
		cout << "********************************************************************************" << endl;
	}
	else
	{
		while (p->next != NULL)
		{
			int next[MAXLEN];
			int nextval[MAXLEN];
			p = p->next;
			SString T, S;
			T.ch[0] = '#';
			S.ch[0] = '#';
			if (strlen(input) >= strlen(p->g_name))
			{
				for (int i = 0; i < strlen(input); i++)
				{
					S.ch[i + 1] = input[i];
				}
				S.length = strlen(input);
				for (int i = 0; i < strlen(p->g_name); i++)
				{
					T.ch[i + 1] = p->g_name[i];
				}
				T.length = strlen(p->g_name);
			}
			else
			{
				for (int i = 0; i < strlen(input); i++)
				{
					T.ch[i + 1] = input[i];
				}
				T.length = strlen(input);
				for (int i = 0; i < strlen(p->g_name); i++)
				{
					S.ch[i + 1] = p->g_name[i];
				}
				S.length = strlen(p->g_name);
			}
			get_next(T, next);
			get_nextval(T, nextval);
			if ((strcmp(p->g_state,"����")==0 || strcmp(p->g_state,"�ۿ�")==0) && Index_KMP(S, T, 1, nextval) != 0)
			{
				count++;
				if (count == 1)
				{
					cout << "********************************************************************************" << endl;
					cout << "  ��ƷID	����	�۸�	�ϼ�ʱ��	����	����ID	  ��Ʒ״̬    ��Ʒ����" << endl;
				}
				cout << p->g_id << "  " << p->g_name << "  " << p->g_price << "         " << p->g_time << "     " << p->g_number << "  " << p->g_seller << "  " << p->g_state << p->g_type <<endl;
			}
		}
		cout << "********************************************************************************" << endl;
	}
}
void Buyers::Good_Message()
{
	Get_Goods_Message();
	Good* p = goods_message_buyer_begin;
	char id[5] = { 'M' };
	cout << "����������Ҫ�鿴����Ʒ��ID:";
	cin >> id;
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(id, p->g_id)==0)
		{
			cout << "***********************************************" << endl;
			cout << "��ƷID:" << p->g_id << endl;
			cout << "��Ʒ����:" << p->g_name << endl;
			cout << "��Ʒ�۸�:" << p->g_price << endl;
			cout << "��Ʒ����:" << p->g_number << endl;
			cout << "�ϼ�ʱ��:" << p->g_time << endl;
			cout << "��Ʒ����:" << p->g_message << endl;
			cout << "��Ʒ����:" << p->g_seller << endl;
			cout << "***********************************************" << endl;
		}
	}
}
void Buyers::B_Histroy_Orders()
{
	Get_Orders_Message();
	Order* p = new Order;
	p = orders_begin_buyer;
	cout << "********************************************************************" << endl;
	cout << "����ID   ��ƷID   ���׵���   ����   ����ʱ��   ����ID   ���ID" << endl;
	while (p->next != NULL)
	{
		p = p->next;
		if(strcmp(p->buyer_id,user_buyer->u_id)==0)
			cout << p->o_id << "  " << p->good_id << "  " << p->o_price << "  " << p->o_number << "  " << p->o_time << "  " << p->seller_id << "  " << p->buyer_id << endl;
	}
	cout << "********************************************************************" << endl;
}
void Buyers::Get_Goods_Message()
{
	int i = 0;
	Good* p, * q;
	p = new Good;
	goods_message_buyer_begin = new Good;
	goods_message_buyer_begin->next = NULL;
	q = goods_message_buyer_begin;
	ifstream infile("good.txt", ios::in | ios::binary);
	if (!infile)
	{
		ofstream file("good.txt");
		if (file)
			file.close();
		else
		{
			cout << "�ļ�����ʧ��" << endl;
			exit(-1);
		}
	}
	while (!infile.eof())
	{

		infile >> p->g_id >> p->g_name >> p->g_price >> p->g_time >> p->g_number >> p->g_message >> p->g_seller >> p->g_state >> p->g_type >> p->endtime;
		if (infile.fail())
			break;
		p->next = NULL;
		q->next = p;
		q = q->next;
		p = new Good;
		i++;
	}
	goods_message_buyer_end = q;
	q->next = NULL;
	infile.close();
	delete p;
}
void Buyers::Get_Orders_Message()
{
	int i = 0;
	Order* p, * q;
	p = new Order;
	orders_begin_buyer = new Order;
	order_end_buyer = new Order;
	order_end_buyer->next = NULL;
	q = orders_begin_buyer;
	ifstream infile("order.txt", ios::in | ios::binary);
	if (!infile)
	{
		ofstream file("order.txt");
		if (file)
			file.close();
		else
		{
			cout << "�ļ�����ʧ��" << endl;
			exit(-1);
		}
	}
	while (!infile.eof())
	{
		infile >> p->o_id >> p->good_id >> p->o_price >> p->o_number >> p->o_time >> p->seller_id >> p->buyer_id;
		if (infile.fail())
			break;
		p->next = NULL;
		q->next = p;
		q = q->next;
		i++;
		p = new Order;
	}
	order_end_buyer = q;
	if (i == 0)
	{
		order_end_buyer->o_id[1] = '0';
		order_end_buyer->o_id[2] = '0';
		order_end_buyer->o_id[3] = '0';
	}
	order_end_buyer->cnt = (order_end_buyer->o_id[1] - '0') * 100 + (order_end_buyer->o_id[2] - '0') * 10 + (order_end_buyer->o_id[3] - '0');
	q->next = NULL;
	infile.close();
	delete p;
}
void Buyers::Store_Orders()
{
	Order* p = new Order;
	p = this->orders_begin_buyer->next;
	fstream outfile("order.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * ���ź������ݱ���ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	while (p != NULL)
	{
		outfile << p->o_id << " " << p->good_id << " " << p->o_price << " " << p->o_number << " " << p->o_time << " " << p->seller_id << " " << p->buyer_id << endl;
		p = p->next;
	}
	outfile.close();
}
void Buyers::Buyer_nemu()
{
	system("cls");
	cout << "======================================================================================================================" << endl;
	cout << "  1.�鿴��Ʒ�б� 2.���뾺��Ⱥ�� 3.������Ʒ 4.������Ʒ 5.���뾺�� 6.�鿴��ʷ���� 7.�鿴��Ʒ��ϸ��Ϣ 8.�����û�������" << endl;
	cout << "======================================================================================================================" << endl;
}
void Buyers::Bid(User*user)
{
	Get_Bid(user);
	Get_Goods_Message();
	user_buyer = user;
	Bidding* newbid = new Bidding;
	bid_end->next = new Bidding;
	newbid = bid_end->next;
	cout << "��������Ҫ���۵���Ʒ��ID:";
	cin >> newbid->g_id;
	cout << "���������ĳ���:";
	cin >> newbid->bid;
	cout << "��������Ҫ���ĵ���Ʒ����:";
	cin >> newbid->number;
	time_t now;
	time(&now);
	struct tm* tempTime = localtime(&now);
	strftime(newbid->time, 80, "[%Y-%m-%d-%H:%M:%S]", tempTime);
	Good* g = new Good;
	g = goods_message_buyer_begin;
	int flage = 0;
	while (g->next != NULL)
	{
		g = g->next;
		if (strcmp(g->g_id, newbid->g_id) == 0)
		{
			flage = 1;
			break;
		}
	}
	if (flage == 0)
	{
		cout << "û���ҵ�����Ʒ��" << endl;
		return;
	}
	if (compare(newbid->time, g->endtime))
	{
		cout << "�Ѿ���������Ʒ�ľ���ʱ��!" << endl;
		return;
	}
	if (strcmp(g->g_type, "����") != 0)
	{
		cout << "����Ʒ�����ھ��ģ�" << endl;
		return;
	}
	double money = 0, price = 0;
	int num1 = 0, num2 = 0;
	num1 = atoi(newbid->number);
	num2 = atoi(g->g_number);
	money = atof(newbid->bid);
	price = atof(g->g_price);
	if (money<price || num1>num2)
	{
		cout << "����ʧ��!" << endl;
		return;
	}
	cout << "���뾺�ĳɹ�!" << endl;
	user->count++;
	strcpy(newbid->u_id, user_buyer->u_id);
	bid_end = bid_end->next;
	bid_end->next = NULL;
	Bidding* p = new Bidding;
	p = bid_begin->next;
	fstream outfile("bidding.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * ���ź������ݱ���ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	while (p != NULL)
	{
		outfile << p->g_id << " " << p->u_id << " " << p->bid << " " << p->number <<" "<<p->time <<" "<<p->state<< endl;
		p = p->next;
	}
	outfile.close();
}
void Buyers::Bid_nemu(User* user)
{
	Users* u = new Users;
	u->Get_Users_Message();
	u->now_user = user;
	int opt = 0;
	system("cls");
	cout << "====================================================" << endl;
	cout << "  1.������Ʒ 2.�޸ľ��� 3.ȡ������ 4.���������ҳ" << endl;
	cout << "====================================================" << endl;
	cout << "��Ŀǰ������" << user->count << "����Ʒ�ľ���" << endl;
	char str[100] = { '0' };
	int choose=0;
	time_t now;
	time(&now);
	struct tm* tempTime = localtime(&now);
	strftime(str, 80, "[%Y-%m-%d-%H:%M:%S]", tempTime);
	if (user->cnt > 0)
	{
		Get_Bid(user);
		Bidding* p = new Bidding;
		p = SortList(bid_begin);
		while (p->next != NULL)
		{
			p = p->next;
			if (strcmp(p->u_id, user->u_id) == 0&&strcmp(p->state,"������")==0)
			{
				if (compare(str, p->time))
				{
					cout << "��ϲ���ɹ����ĵ�IDΪ" << p->g_id << "����Ʒ������ѡ���Ƿ�֧����Ʒ�ķ���: 1.֧�� 2.ȡ�� (���ȡ���Ļ���ʹ������������)" << endl;
					cout << "���������:";
					cin >> choose;
					if (choose == 1)
					{

					}
					else
					{
						int c = atoi(user->credibility);
						c--;
						sprintf(user->credibility, "%d", c);
						u->Update_message();
					}
				}
			}
		}
	}



	cout << "���������:";
	cin >> opt;
lm:

	while (cin.fail())
	{
		cerr << "����������������룺";
		cin.clear();
		cin.ignore();
		cin >> opt;
	}
	switch (opt)
	{
	case 1:Bid(user);
		cout << "���������:";
		cin >> opt;
		goto lm;
	case 2:Change_Bid(user);
		cout << "���������:";
		cin >> opt;
		goto lm;
	case 3:Remove_Bid(user);
		cout << "���������:";
		cin >> opt;
		goto lm;
	case 4:u->Buyers_Module();
		break;
	default:cout << "����ָ�����" << endl; break;
	}
	goto lm;
}
void Buyers::Get_Bid(User*user)
{
	Bidding* p, * q;
	p = new Bidding;
	bid_begin = new Bidding;
	bid_end = new Bidding;
	bid_end->next = NULL;
	q = bid_begin;
	Bidding* a, * b;
	a = new Bidding;
	begin = new Bidding;
	end = new Bidding;
	end->next = NULL;
	b = begin;
	ifstream infile("bidding.txt", ios::in | ios::binary);
	if (!infile)
	{
		ofstream file("bidding.txt");
		if (file)
			file.close();
		else
		{
			cout << "�ļ�����ʧ��" << endl;
			exit(-1);
		}
	}
	while (!infile.eof())
	{
		infile >> p->g_id >> p->u_id >> p->bid >> p->number >> p->time >> p->state;
		if (infile.fail())
			break;
		if (strcmp(p->u_id, user->u_id) == 0)
		{
			a = p;
			a->next = NULL;
			b->next = a;
			b = b->next;
			a = new Bidding;
		}
		p->next = NULL;
		q->next = p;
		q = q->next;
		p = new Bidding;
	}
	end = b;
	b->next = NULL;
	bid_end = q;
	q->next = NULL;
	infile.close();
	delete p;
}
void Buyers::Change_Bid(User* user)
{
	Get_Bid(user);
	Bidding* b = new Bidding;
	b = bid_begin;
	char id[5] = { 'M' };
	char bid[100] = { '0' };
	cout << "��������Ҫ�޸ĳ��۵���ƷID:";
	cin >> id;
	bool flage = 0;
	while (b->next != NULL)
	{
		b = b->next;
		if (strcmp(b->g_id, id) == 0&&strcmp(b->u_id,user->u_id)==0)
		{
			flage = 1;
			break;
		}
	}
	if (flage == 0)
	{
		cout << "��û�и���Ʒ�ľ��ۣ�" << endl;
		return;
	}
	cout << "���������޸ĺ�ľ���:";
	cin >> bid;
	Get_Goods_Message();
	Good* g = new Good;
	g = goods_message_buyer_begin;
	while (g->next != NULL)
	{
		g = g->next;
		if (strcmp(g->g_id, b->g_id) == 0)
			break;
	}
	strcpy(b->bid, bid);
	double money = 0, price = 0;
	money = atof(b->bid);
	price = atof(g->g_price);
	if (money<price)
	{
		cout << "�޸ľ���ʧ��!" << endl;
		return;
	}
	cout << "�޸ĳɹ�!" << endl;
	Bidding* p = new Bidding;
	p = bid_begin->next;
	fstream outfile("bidding.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * ���ź������ݱ���ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	while (p != NULL)
	{
		outfile << p->g_id << " " << p->u_id << " " << p->bid << " " << p->number << " " << p->time <<" "<<p->state<< endl;
		p = p->next;
	}
	outfile.close();
}
void Buyers::Remove_Bid(User* user)
{
	Get_Bid(user);
	Bidding* b = new Bidding;
	Bidding* temp = new Bidding;
	b = bid_begin;
	temp = bid_begin;
	char id[5] = { 'M' };
	cout << "��������Ҫȡ�����۵���ƷID:";
	cin >> id;
	bool flage = 0;
	while (b->next != NULL)
	{
		b = b->next;
		if (strcmp(b->g_id, id) == 0&&strcmp(b->u_id,user->u_id)==0)
		{
			flage = 1;
			break;
		}
		temp = b;
	}
	if (flage == 0)
	{
		cout << "��û�и���Ʒ�ľ��ۣ�" << endl;
		return;
	}
	cout << "ȡ�����۳ɹ���" << endl;
	temp->next = b->next;
	b = NULL;
	delete b;
	Bidding* p = new Bidding;
	p = bid_begin->next;
	fstream outfile("bidding.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * ���ź������ݱ���ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	while (p != NULL)
	{
		outfile << p->g_id << " " << p->u_id << " " << p->bid << " " << p->number << " " << p->time << " "<<p->state<<endl;
		p = p->next;
	}
	outfile.close();
}

void Administrator::all_goods()
{
	Achieve_Goods_Message();
	cout << "********************************************************************************" << endl;
	cout << "  ��ƷID	����	�۸�	�ϼ�ʱ��	����	����ID	  ��Ʒ״̬    ����ʱ��" << endl;
	Good* p = a_goods_begin;
	while (p->next != NULL)
	{
		p = p->next;
		cout << p->g_id << "  " << p->g_name << "  " << p->g_price << "         " << p->g_number << "  " << p->g_seller << "  " << p->g_state <<"  "<<p->endtime <<endl;
	}
	cout << "********************************************************************************" << endl;
}
void Administrator::search_goods()
{
	Achieve_Goods_Message();
	char input[20] = { '0' };
	Good* p = a_goods_begin;
	cout << "����������Ҫ��������Ʒ��ID������:";
	cin >> input;
	int count = 0;
	if (input[0] == 'M')
	{
		while (p->next != NULL)
		{
			p = p->next;
			if ((strcmp(p->g_state,"����")==0 || strcmp(p->g_state,"�ۿ�")==0) && strcmp(input, p->g_id) == 0)
			{
				count++;
				if (count == 1)
				{
					cout << "********************************************************************************" << endl;
					cout << "  ��ƷID	����	�۸�	�ϼ�ʱ��	����	����ID	  ��Ʒ״̬    ��Ʒ����" << endl;
				}
				cout << p->g_id << "  " << p->g_name << "  " << p->g_price << "         " << p->g_time << "     " << p->g_number << "  " << p->g_seller << "  " << p->g_state << p->g_type << endl;
			}
		}
		cout << "********************************************************************************" << endl;
	}
	else
	{
		while (p->next != NULL)
		{
			int next[MAXLEN];
			int nextval[MAXLEN];
			p = p->next;
			SString T, S;
			T.ch[0] = '#';
			S.ch[0] = '#';
			if (strlen(input) >= strlen(p->g_name))
			{
				for (int i = 0; i < strlen(input); i++)
				{
					S.ch[i + 1] = input[i];
				}
				S.length = strlen(input);
				for (int i = 0; i < strlen(p->g_name); i++)
				{
					T.ch[i + 1] = p->g_name[i];
				}
				T.length = strlen(p->g_name);
			}
			else
			{
				for (int i = 0; i < strlen(input); i++)
				{
					T.ch[i + 1] = input[i];
				}
				T.length = strlen(input);
				for (int i = 0; i < strlen(p->g_name); i++)
				{
					S.ch[i + 1] = p->g_name[i];
				}
				S.length = strlen(p->g_name);
			}
			get_next(T, next);
			get_nextval(T, nextval);
			if ((strcmp(p->g_state,"����")==0 || strcmp(p->g_state,"�ۿ�")==0) && Index_KMP(S, T, 1, nextval) != 0)
			{
				count++;
				if (count == 1)
				{
					cout << "********************************************************************************" << endl;
					cout << "  ��ƷID	����	�۸�	�ϼ�ʱ��	����	����ID	  ��Ʒ״̬    ��Ʒ����" << endl;
				}
				cout << p->g_id << "  " << p->g_name << "  " << p->g_price << "         " << p->g_time << "     " << p->g_number << "  " << p->g_seller << "  " << p->g_state << p->g_type << endl;
			}
		}
		cout << "********************************************************************************" << endl;
	}
}
void Administrator::remove_goods()
{
	Achieve_Goods_Message();
	int flage = 0;
	Good* oldgood = new Good;
	Good* q = new Good;
	Good* temp = q;
	q = a_goods_begin;
	char opt = '0';
	cout << "������Ҫ�¼ܵ���ƷID:";
	cin >> oldgood->g_id;
	//cout << endl;
	if (cin.fail())
	{
		cerr << "�¼���Ʒʧ�ܣ�";
		//exit(0);
		return;
	}
	while (q->next != NULL)
	{
		temp = q;
		q = q->next;
		if (strcmp(q->g_id, oldgood->g_id) == 0)
		{
			oldgood = q;
			flage = 1;
		}
	}
	if (flage == 0)
	{
		cout << "û���ҵ�����Ʒ" << endl;
		//exit(0);
		return;
	}
	cout << "��ȷ��Ҫ�¼ܸ���Ʒ��" << endl;
	cout << "********************************************************************" << endl;
	cout << "��ƷID" << "  " << "��Ʒ����" << "  " << "��Ʒ�۸�" << "  " << "��Ʒ����" << "  " << "����ID" << "  " << "��Ʒ״̬" << endl;
	cout << oldgood->g_id << "  " << oldgood->g_name << "  " << oldgood->g_price << "  " << oldgood->g_number << "  " << oldgood->g_seller << "  " << oldgood->g_state << endl;
	cout << "********************************************************************" << endl;
	cout << endl;
	cout << "��ѡ��(y/n) ";
	cin >> opt;
	if (opt == 'y')
	{
		cout << "�¼ܳɹ�" << endl;
	}
	else
	{
		cout << "�¼�ʧ��" << endl;
		//exit(0);
		return;
	}
	temp->next = q->next;
	delete oldgood;
	Updata_Goods();
	delete temp;
}
void Administrator::all_orders()
{
	Buyers* p = new Buyers;
	p->Get_Orders_Message();
	Order* q = new Order;
	q = p->orders_begin_buyer;
	cout << "********************************************************************" << endl;
	cout << "����ID   ��ƷID   ���׵���   ����   ����ʱ��   ����ID   ���ID" << endl;
	while (q->next != NULL)
	{
		q = q->next;
		cout << q->o_id << "  " << q->good_id << "  " << q->o_price << "  " << q->o_number << "  " << q->o_time << "  " << q->seller_id << "  " << q->buyer_id << endl;
	}
	cout << "********************************************************************" << endl;
}
void Administrator::all_users()
{
	Achieve_Users_Message();
	User* p = a_users_begin->next;
	cout << "*************************************************************************" << endl;
	cout << "�û�ID" << "  " << "�û���" << "  " << "��ϵ��ʽ" << "  " << "��ַ" << "  " << "Ǯ�����" << "  " << "�û�״̬" << endl;
	while (p != NULL)
	{
		cout << p->u_id << " " << p->u_name << " " << p->u_phone << " " << p->u_adress << " " << p->u_money << " " << p->u_state <<" "<<p->credibility<< endl;
		p = p->next;
	}
	cout << "*************************************************************************" << endl;
}
void Administrator::ban_user()
{
	int flage = 0;
	char opt = '0';
	Achieve_Users_Message();
	User* id = new User;
	User* p = new User;
	User* tp = new User;
	tp = a_users_begin;
	p = a_users_begin->next;
	cout << "������Ҫ������û�ID:";
	cin >> id->u_id;
	while (p != NULL)
	{
		if (strcmp(p->u_id, id->u_id) == 0)
		{
			flage = 1;
			break;
		}
		tp = p;
		p = p->next;
	}
	if (flage == 0)
	{
		cout << "û���ҵ����û���" << endl;
		//exit(0);
		return;
	}
	cout << "ȷ��Ҫ������û���" << endl;
	cout << "*************************************************************************" << endl;
	cout << "�û�ID" << "  " << "�û���" << "  " << "��ϵ��ʽ" << "  " << "��ַ" << "  " << "Ǯ�����" << "  " << "�û�״̬" << "  " << "�û�����" << endl;
	cout << p->u_id << " " << p->u_name << " " << p->u_phone << " " << p->u_adress << " " << p->u_money << " " << p->u_state << " " << p->credibility << endl;
	cout << "*************************************************************************" << endl;
	cout << "��ѡ��(y/n)��";
	cin >> opt;
	cout << endl;
	if (opt == 'y')
		cout << "����ɹ�" << endl;
	else
	{
		cout << "���ȡ��" << endl;
		//exit(0);
		return;
	}
	strcpy(p->u_state, "���");
	User* a = new User;
	//Achieve_Users_Message();
	a = this->a_users_begin;
	tp->next = p->next;
	tp = tp->next;
	tp = NULL;
	fstream outfile1("user.txt", ios::out);
	if (!outfile1)
	{
		cout << "* * * ���ź������ݱ���ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	while (a->next != NULL)
	{
		a = a->next;
		outfile1 << a->u_id << " " << a->u_name << " " << a->u_phone << " " << a->u_adress << " " << a->u_password << " " << a->u_state << " " << a->u_money <<" "<<a->credibility<< endl;
	}
	outfile1.close();
	Achieve_Goods_Message();
	Good* q = new Good;
	q = a_goods_begin->next;
	Good* temp = new Good;
	temp = a_goods_begin;
	while (q != NULL)
	{
		if (strcmp(q->g_seller, id->u_id) == 0)
		{
			Good* t = new Good;
			t = q;
			if (q->next == NULL)
			{
				q = q->next;
				temp->next = NULL;
				delete t;
			}
			else
			{
				temp->next = q->next;
				q = q->next;
				delete t;
			}
		}
		else
		{
			temp = q;
			q = q->next;
		}
	}
	Good* b = new Good;
	b = this->a_goods_begin->next;
	fstream outfile2("good.txt", ios::out);
	if (!outfile2)
	{
		cout << "* * * ���ź������ݱ���ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	while (b != NULL)
	{
		outfile2 << b->g_id << " " << b->g_name << " " << b->g_price << " " << b->g_number << " " << b->g_message << " " << b->g_seller << " " << b->g_state << endl;
		b = b->next;
	}
	outfile2.close();
}
void Administrator::Achieve_Goods_Message()
{
	int i = 0;
	Good* p, * q;
	p = new Good;
	a_goods_begin = new Good;
	a_goods_begin->next = NULL;
	q = a_goods_begin;
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

		infile >> p->g_id >> p->g_name >> p->g_price >>p->g_time>> p->g_number >> p->g_message >> p->g_seller >> p->g_state>>p->g_type;
		if (infile.fail())
			break;
		p->next = NULL;
		q->next = p;
		q = q->next;
		p = new Good;
		i++;
	}
	a_goods_end = q;
	q->next = NULL;
	infile.close();
	delete p;
}
void Administrator::Updata_Goods()
{
	Good* p;
	p = this->a_goods_begin->next;
	fstream outfile("good.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * ���ź������ݱ���ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	while (p != NULL)
	{
		outfile << p->g_id << " " << p->g_name << " " << p->g_price << " " <<p->g_time<<" " << p->g_number << " " << p->g_message << " " << p->g_seller << " " << p->g_state<<" "<<p->g_type << endl;
		p = p->next;
	}
	outfile.close();
}
void Administrator::Achieve_Users_Message()
{
	int i = 0;
	User* p, * q;
	p = new User;
	a_users_begin = new User;
	a_users_end = new User;
	a_users_begin->next = NULL;
	q = a_users_begin;
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
		infile >> p->u_id >> p->u_name >> p->u_phone >> p->u_adress >> p->u_password >> p->u_state >> p->u_money >> p->credibility;
		if (infile.fail())
			break;
		p->next = NULL;
		q->next = p;
		q = q->next;
		i++;
		p = new User;
	}
	a_users_end = q;
	q->next = NULL;
	infile.close();
	delete p;
}
void Administrator::Updata_Users()
{
	User* p = new User;
	Achieve_Users_Message();
	p = this->a_users_begin->next;
	fstream outfile("user.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * ���ź������ݱ���ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	while (p != NULL)
	{
		outfile << p->u_id << " " << p->u_name << " " << p->u_phone << " " << p->u_adress << " " << p->u_password << " " << p->u_state << " " << p->u_money <<" "<<p->credibility << endl;
		p = p->next;
	}
	outfile.close();
}
void Administrator::Admin_nemu()
{
	system("cls");
	cout << "================================================================================================" << endl;
	cout << "  1.�鿴���е���Ʒ  2.������Ʒ  3.�¼���Ʒ  4.�鿴���ж���  5.�鿴�����û�  6.����û�  7.ע��" << endl;
	cout << "================================================================================================" << endl;
}

void Auction_group::Send_Message()
{
	//Display_History_Message();
	Message* p = new Message;
	end->next = new Message;
	p = end->next;
	char buf[200];
	time_t now;
	time(&now);
	struct tm* tempTime = localtime(&now);
	strftime(p->nowtime, 80, "[%Y-%m-%d-%H:%M:%S]", tempTime);
	cin >> p->content;
	strcpy(p->name, nowuser->u_name);
	end = p;
	end->next = NULL;
	Store_Message();
	Cout_Message();
}
void Auction_group::Withdraw_Message()
{

}
/*void Auction_group::Assign_Goods(Message* q)
{
	Display_History_Message();
	Message* p = new Message;
	p = q;
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(p->good_id, q->good_id) == 0)
		{
			Buyers* user = new Buyers;
			User* t = new User;
			user->Get_Users_Message();
			t = user->users_begin;
			while (t->next != NULL)
			{
				t = t->next;
				if (strcmp(t->u_name, q->name) == 0)
					break;
			}
			Good* a = new Good;
			Buyers* good = new Buyers;
			good->Get_Goods_Message();
			a = good->goods_message_buyer_begin;
			while (a->next != NULL)
			{
				a = a->next;
				if (strcmp(a->g_id, q->good_id) == 0)
					break;
			}
			double money, price;
			int number;
			money = strtod(t->u_money, NULL);
			price = strtod(p->bid, NULL);
			number = atoi(a->g_number);
			number--;
			money -= price;
		}
	}
}*/
void Auction_group::Display_History_Message()
{
	Message* p, * q;
	p = new Message;
	start = new Message;
	end = new Message;
	q = start;
	ifstream infile("message.txt", ios::in | ios::binary);
	if (!infile)
	{
		ofstream file("message.txt");
		if (file)
			file.close();
		else
		{
			cout << "�ļ�����ʧ��" << endl;
			exit(-1);
		}
	}
	while (!infile.eof())
	{
		infile >> p->name >> p->nowtime >> p->content;
		if (infile.fail())
			break;
		q->next = new Message;
		q->next = p;
		q = q->next;
		q->next = NULL;
		p = new Message;
	}
	end = q;
	end->next = NULL;
	infile.close();
	delete p;
}
void Auction_group::Join_Group_Menu()
{
	Cout_Message();	
	int opt = 0;
	Buyers* buyer = new Buyers;
	Sellers* seller = new Sellers;
	Display_History_Message();
	while (true)
	{
		opt = 0;
		cin >> opt;
		while (cin.fail())
		{
			cerr << "�����������������:";
			cin.clear();
			cin.ignore();
			cin >> opt;
		}
		switch (opt)
		{
		case 1:
			Send_Message();
			break;
		case 2:Withdraw_Message(); break;
		case 3:
			if (strcmp(nowuser->u_state,"���")==0)
				Join_Auction();
			else
				cout << "��û�в��뾺�ĵ�Ȩ�ޣ�" << endl;
			break;
		case 4:
			if (strcmp(nowuser->u_state,"����")==0)
				Send_Goods();
			else
				cout << "��û��Ȩ�޷���������Ʒ��" << endl;
			break;
		case 5:
			if (strcmp(nowuser->u_state,"���")==0)
			{
				User* p = nowuser;
				buyer->Get_Users_Message();
				buyer->now_user = p;
				buyer->Buyers_Module();
			}
			else if (strcmp(nowuser->u_state,"����")==0)
			{
				User* p = nowuser;
				seller->Get_Users_Message();
				seller->now_user = p;
				seller->Sellers_Module();
			}
			else
				cout << "����ָ�����" << endl;
			break;
		default:cout << "����ָ�����" << endl; break;
		}
	}
}
//nowuser��Ҫ��ֵ��ʱ��
void Auction_group::Store_Message()
{
	Message* p = new Message;
	p = this->start;
	fstream outfile("message.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * ���ź������ݱ���ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	while (p->next != NULL)
	{
		p = p->next;
		outfile << p->name << " " << p->nowtime << " " <<p->content<<endl;
	}
	outfile.close();
}
void Auction_group::Send_Goods()
{
	Sellers* member = new Sellers;
	member->user_seller = nowuser;
	member->Get_Goods_Message();
	Good* newgood = new Good;
	newgood->cnt = member->goods_message_seller_end->cnt;
	char opt = '0';
	cout << "��������Ҫ��������Ʒ���ƣ�";
	cin >> newgood->g_name;
	cout << "��������Ҫ��������Ʒ�׼ۣ�";
	cin >> newgood->g_price;
	cout << "��������Ҫ��������Ʒ������";
	cin >> newgood->g_number;
	cout << "��������Ҫ��������Ʒ������";
	cin >> newgood->g_message;
	newgood->cnt++;
	newgood->g_id[1] = newgood->cnt / 100 + '0';
	newgood->g_id[2] = (newgood->cnt % 100) / 10 + '0';
	newgood->g_id[3] = newgood->cnt % 10 + '0';
	strcpy(newgood->g_type, "����");
	strcpy(newgood->g_state, "����");
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
	cout << "��ȷ��Ҫ������Ʒ����������(y/n) ";
	cin >> opt;
	if (opt == 'y')
	{
		cout << "ȷ�Ϸ�����Ʒ" << endl;
		time_t now;
		time(&now);
		struct tm* tempTime = localtime(&now);
		strftime(newgood->g_time, 80, "[%Y-%m-%d-%H:%M:%S]", tempTime);
	}
	else
	{
		cout << "ȡ��������Ʒ" << endl;
		return;
	}
	fstream outfile("good.txt", ios::app);
	if (!outfile)
	{
		cout << "* * * ���ź�����Ʒ����ʧ�ܣ�* * *" << endl;
		return;
	}
	if (newgood != NULL)
	{
		outfile << newgood->g_id << " " << newgood->g_name << " " << newgood->g_price << " " << newgood->g_time << " " << newgood->g_number << " " << newgood->g_message << " " << member->user_seller->u_id << " " << newgood->g_state << " " << newgood->g_type << endl;
		cout << "* * * ��ϲ����������Ʒ�ɹ���* * *" << endl;
		cout << "����Ʒ��IDΪ��";
		cout << newgood->g_id;
	}
	outfile.close();
	Sleep(500);
	system("cls");
	cout << "		��ӭ��������Ⱥ�ģ�					  " << endl;
	cout << "	 �����ʹ�õ�ָ��: 1.������Ϣ 2.���� 3.�������� 4.����������Ʒ 5.�˳�Ⱥ��		 " << endl;
	Message* b = new Message;
	end->next = new Message;
	b = end->next;
	char buf[400] = { '0' };
	strcpy(b->name, member->user_seller->u_name);
	strcpy(b->nowtime, newgood->g_time);
	strcat(buf, "****");
	strcat(buf, "������Ʒ��Ϣ**��ƷID:");
	strcat(buf, newgood->g_id);
	strcat(buf, "**��Ʒ����:");
	strcat(buf, newgood->g_name);
	strcat(buf, "**��Ʒ�۸�:");
	strcat(buf, newgood->g_price);
	strcat(buf, "**��Ʒ����:");
	strcat(buf, newgood->g_number);
	strcat(buf, "**��Ʒ��Ϣ:");
	strcat(buf, newgood->g_message);
	strcat(buf, "****");
	for (int i = 0; i < strlen(buf); i++)
	{
		b->content[i] = buf[i+1];
	}
	b->next = NULL;
	Store_Message();
	Display_History_Message();
	Message* t = new Message;
	t = start;
	while (t->next != NULL)
	{
		t = t->next;
		cout << t->nowtime << "\t" << "from user--" << t->name << "(goup-sent):\n";
		cout << t->content << endl;
	}
	delete newgood;
}
void Auction_group::Join_Auction()
{
	Display_History_Message();
	Message* p = new Message;
	User* u = new User;
	Order* o = new Order;
	Good* g = new Good;
	Buyers* b = new Buyers;
	Sellers* s = new Sellers;
	p = end;
	end->next = new Message;
	p = p->next;
	int num = 0;
	char id[5] = { 'M' };
	cout << "��������Ҫ��������Ʒ��ID:";
	cin >> id;
	cout << "��������Ҫ����������:";
	cin >> num;
	b->Get_Users_Message();
	u = b->users_begin;
	bool flage = 0;
	while (u->next != NULL)
	{
		u = u->next;
		if (strcmp(u->u_id, nowuser->u_id) == 0)
		{
			flage = 1;
			break;
		}
	}
	if (flage == 0)
	{
		cout << "�����û�ʧ��" << endl;
		return;
	}
	flage = 0;
	s->Get_Goods_Message();
	b->Get_Orders_Message();
	b->order_end_buyer->next = new Order;
	o = b->order_end_buyer->next;
	g = s->goods_message_seller_begin;
	while (g->next != NULL)
	{
		g = g->next;
		if (strcmp(g->g_id, id) == 0)
		{
			flage = 1;
			break;
		}
	}
	if (flage == 0)
	{
		cout << "������Ʒʧ��" << endl;
		return;
	}
	if (strcmp(g->g_type, "����") != 0)
	{
		cout << "����Ʒ������������" << endl;
		return;
	}
	double u_money = 0, g_money = 0;
	u_money = atof(u->u_money);
	g_money = atof(g->g_price);
	int number = 0;
	number = atoi(g->g_number);
	char str1[100] = { '0' };
	char str2[100] = { '0' };
	if (u_money >= num * g_money&&number-num>=0)
	{
		sprintf(str1, "%.1lf", u_money - num * g_money);
		sprintf(str2, "%d", number-num);
		strcpy(g->g_number, str2);
		strcpy(u->u_money, str1);
		if (number == 0)
			strcpy(g->g_state, "�ۿ�");
		b->Update_message();
		s->Updata_Goods_Message();
	}
	else
	{
		cout << "����ʧ��" << endl;
		return;
	}
	time_t now;
	time(&now);
	struct tm* tempTime = localtime(&now);
	strftime(p->nowtime, 20, "[%H:%M:%S]", tempTime);
	strftime(o->o_time, 20, "[%H:%M:%S]", tempTime);
	char str[100];
	sprintf(str, "%d", num);
	strcpy(p->name, nowuser->u_name);
	strcpy(p->content, "�ɹ�����");
	strcat(p->content, str);
	strcat(p->content, "��");
	strcat(p->content, id);
	p->next = NULL;
	Message* q = new Message;
	q = this->start;

	o->cnt++;
	o->o_id[1] = o->cnt / 100 + '0';
	o->o_id[2] = (o->cnt % 100) / 10 + '0';
	o->o_id[3] = o->cnt % 10 + '0';
	_itoa(num, o->o_number, 10);
	strcpy(o->buyer_id, nowuser->u_id);
	strcpy(o->seller_id, g->g_seller);
	strcpy(o->o_price, g->g_price);
	strcpy(o->good_id, g->g_id);
	b->order_end_buyer = o;
	o->next = NULL;
	b->Store_Orders();

	fstream outfile("message.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * ���ź������ݱ���ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	while (q->next != NULL)
	{
		q = q->next;
		outfile << q->name << " " << q->nowtime << " "<<q->content<<endl;
	}
	outfile.close();
	Cout_Message();
}
void Auction_group::Cout_Message()
{
	system("cls");
	cout << "		��ӭ��������Ⱥ�ģ�					  " << endl;
	cout << "	 �����ʹ�õ�ָ��: 1.������Ϣ 2.���� 3.�������� 4.����������Ʒ 5.�˳�Ⱥ��		 " << endl;
	Display_History_Message();
	Message* p = new Message;
	p = start;
	while (p->next != NULL)
	{
		p = p->next;
		//if (strcmp(p->good_id, "0") == 0) {
		cout << p->nowtime << "\t" << "from user--" << p->name << "(goup-sent):\n";
		cout << p->content << endl;
	}
}

void Users_Module(int st)
{
	int flage = 0;
	Users user;
	User* somebody = new User;
	if (st == 2)
	{
		user.User_sign_up();
		//system("cls");
		cout << "��ѡ���Ƿ����ڵ�¼:1.��¼ 2.�˳�" << endl;
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
			Sleep(1000);
		else
		{
			cout << "��ѡ���Ƿ����µ�½:1.���µ�½ 2.�˳�" << endl;
			cin >> flage;
			if (flage == 1)
			{
				system("cls");
				cout << "====================================================" << endl;
				cout << "  1.����Ա��¼  2.�û�ע��  3.�û���¼  4.�˳�����" << endl;
				cout << "====================================================" << endl;
				goto login;
			}
			else
				return;
		}
		user.User_Menu();
	}
}
//�û�ģ�顣

bool Administrator_Module()
{
	Administrator admin;
	cout << "���������Ա����:";
	cin >> admin.a_name;
	cout << "����������:";
	cin >> admin.a_password;
	if (strcmp(admin.a_name, "admin") == 0 && strcmp(admin.a_password, "123456") == 0)
	{
		cout << "-----��½�ɹ�-----" << endl;
		Sleep(1000);
	}
	else
	{
		cout << "-----������󣬵�½ʧ�ܣ��������˵�-----" << endl;
		Sleep(1000);
		return false;
	}
	system("cls");
	cout << "================================================================================================" << endl;
	cout << "  1.�鿴���е���Ʒ  2.������Ʒ  3.�¼���Ʒ  4.�鿴���ж���  5.�鿴�����û�  6.����û�  7.ע��" << endl;
	cout << "================================================================================================" << endl;
	cout << "���������:";
	cin >> option;
	l:
	while (cin.fail())
	{
		cerr << "�����������������:";
		cin.clear();
		cin.ignore();
		cin >> option;
	}
	switch (option)
	{
	case 1:admin.all_goods();
		cout << "���������:";
		cin >> option;
		admin.Admin_nemu();
		goto l;
	case 2:admin.search_goods();
		cout << "���������:";
		cin >> option;
		admin.Admin_nemu();
		goto l;
	case 3:admin.remove_goods();
		cout << "���������:";
		cin >> option;
		admin.Admin_nemu();
		goto l;
	case 4:admin.all_orders(); 
		cout << "���������:";
		cin >> option;
		admin.Admin_nemu();
		goto l;
	case 5:admin.all_users(); 
		cout << "���������:";
		cin >> option;
		admin.Admin_nemu();
		goto l;
	case 6:admin.ban_user(); 
		cout << "���������:";
		cin >> option;
		admin.Admin_nemu();
		goto l;
	case 7:break;
	default:
		cout << "����ָ�����" << endl; 
		exit(-1);
	}
	return true;
}
//����Աģ�顣

int main() {
	while (true)
	{
		lm:
		system("cls");
		cout << "====================================================" << endl;
		cout << "  1.����Ա��¼  2.�û�ע��  3.�û���¼  4.�˳�����" << endl;
		cout << "====================================================" << endl;
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
		case 1:
			if (Administrator_Module() == false)
			{
				goto lm;
			}
			else {
				break;
			}
		case 2:Users_Module(2); break;
		case 3:Users_Module(3); break;
		case 4:exit(0); break;
		default:cout << "����ָ�����" << endl; break;
		}
		goto lm;
		break;
	}
	return 0;
}
//�Ƚ����ơ�





