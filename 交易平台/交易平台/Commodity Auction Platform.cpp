#include"Commodity Auction Platform.h"

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
				cout << "�ⲻ������������Ʒ����û��Ȩ���޸��������ԣ��볢���������롣"<<endl;
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
		now_user = user_seller;
		Sellers_Module(); 
		break;
	default:cout << "��Ч������"; break;
	}
}
void Sellers::Remove_Good(User*p)
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
	cout << endl;
	if (cin.fail())
	{
		cerr << "�¼���Ʒʧ�ܣ�";
		exit(0);
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
		exit(0);
	}
	else if (flage == 2)
	{
		cout << "����Ʒ�����������ģ���û��Ȩ���޸�����" << endl;
		exit(0);
	}
	cout << "��ȷ��Ҫ�¼ܸ���Ʒ��" << endl;
	cout << "********************************************************************" << endl;
	cout << "��ƷID" << "  " << "��Ʒ����" << "  " << "��Ʒ�۸�" << "  " << "��Ʒ����" << "  " << "����ID" << "  " << "��Ʒ״̬" << endl;
	cout << oldgood->g_id << "  " << oldgood->g_name << "  " << oldgood->g_price << "  " << oldgood->g_number << "  " << user_seller->u_id << "  " << oldgood->g_state << endl;
	cout << "********************************************************************" << endl;
	cout << endl;
	cout << "��ѡ��(y/n) ";
	cin >> opt;
	if (opt == 'y')
	{
		cout << "�¼ܳɹ�" << endl;
		oldgood->g_state = '3';
	}
	else
	{
		cout << "�¼�ʧ��" << endl;
		exit(0);
	}
	temp->next = q->next;
	delete oldgood;
	Updata_Goods_Message();
	delete temp;
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
		outfile << p->g_id << " " << p->g_name << " " <<p->g_price << " " << p->g_number << " " << p->g_message << " " << user_seller->u_id << " " <<p->g_state << endl;
		p = p->next;
	}
	outfile.close();
}

void Buyers::Search_all_Goods()
{
	Get_Goods_Message();
	cout << "********************************************************************************" << endl;
	cout << "  ��ƷID	����	�۸�	�ϼ�ʱ��	����	����ID	  ��Ʒ״̬" << endl;
	Good* p = goods_message_buyer_begin;
	while (p->next != NULL)
	{
		p = p->next;
		if(p->g_state=='1'||p->g_state=='2')
			cout << p->g_id << "  " << p->g_name << "  " << p->g_price << "         " << p->g_number << "  " << p->g_seller << "  " << p->g_state << endl;
	}
	cout << "********************************************************************************" << endl;
}
void Buyers::Bid_Good()
{

}
void Buyers::Search_Good()
{

}
void Buyers::Good_Message()
{

}
void Buyers::B_Histroy_Orders()
{

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
	goods_message_buyer_end = q;
	q->next = NULL;
	infile.close();
	delete p;
}
void Buyers::Get_Orders_Message()
{

}


void Administrator::all_goods()
{
	Achieve_Goods_Message();
	cout << "********************************************************************************" << endl;
	cout << "  ��ƷID	����	�۸�	�ϼ�ʱ��	����	����ID	  ��Ʒ״̬" << endl;
	Good* p = a_goods_begin;
	while (p->next != NULL)
	{
		p = p->next;
		cout << p->g_id << "  " << p->g_name << "  " << p->g_price << "         " << p->g_number << "  " << p->g_seller << "  " << p->g_state << endl;
	}
	cout << "********************************************************************************" << endl;
}
void Administrator::search_goods()
{
	Achieve_Goods_Message();
	cout << "������";




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
	cout << "������Ҫ�¼ܵ���ƷID��";
	cin >> oldgood->g_id;
	cout << endl;
	if (cin.fail())
	{
		cerr << "�¼���Ʒʧ�ܣ�";
		exit(0);
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
		exit(0);
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
		exit(0);
	}
	temp->next = q->next;
	delete oldgood;
	Updata_Goods();
	delete temp;
}
void Administrator::all_orders()
{

}
void Administrator::all_users()
{
	Achieve_Users_Message();
	User* p = a_users_begin->next;
	cout << "*************************************************************************" << endl;
	cout << "�û�ID" << "  " << "�û���" << "  " << "��ϵ��ʽ" << "  " << "��ַ" << "  " << "Ǯ�����" << "  " << "�û�״̬" << endl;
	while (p != NULL)
	{
		cout << p->u_id << " " << p->u_name << " " << p->u_phone << " " << p->u_adress << " " << p->u_money << " " << p->u_state << endl;
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
	p=a_users_begin->next;
	cout << "������Ҫ������û�ID��";
	cin >> id->u_id;
	while (p != NULL)
	{
		if (strcmp(p->u_id,id->u_id) == 0)
		{
			flage = 1;
			break;
		}
		p = p->next;
	}
	if (flage == 0)
	{
		cout << "û���ҵ����û���" << endl;
		exit(0);
	}
	cout << "ȷ��Ҫ������û���" << endl;
	cout << "*************************************************************************" << endl;
	cout << "�û�ID" << "  " << "�û���" << "  " << "��ϵ��ʽ" << "  " << "��ַ" << "  " << "Ǯ�����" << "  " << "�û�״̬" << endl;
	cout << p->u_id << " " << p->u_name << " " << p->u_phone << " " << p->u_adress << " " << p->u_money << " " << p->u_state << endl;
	cout << "*************************************************************************" << endl;
	cout << "��ѡ��(y/n)��";
	cin >> opt;
	if (opt == 'y')
		cout << "����ɹ�" << endl;
	else
	{
		cout << "���ȡ��" << endl;
		exit(0);
	}
	p->u_state = '2';
	User* a = new User;
	//Achieve_Users_Message();
	a = this->a_users_begin->next;
	fstream outfile1("user.txt", ios::out);
	if (!outfile1)
	{
		cout << "* * * ���ź������ݱ���ʧ�ܣ�* * *" << endl;
		exit(0);
	}
	while (a != NULL)
	{
		outfile1 << a->u_id << " " << a->u_name << " " << a->u_phone << " " << a->u_adress << " " << a->u_password << " " << a->u_state << " " << a->u_money << endl;
		a = a->next;
	}
	outfile1.close();

	Achieve_Goods_Message();
	Good* q = new Good;
	q = a_goods_begin->next;
	Good* temp = new Good;
	temp = a_goods_begin;
	while (q!= NULL)
	{
		if ( strcmp(q->g_seller, id->u_id) == 0)
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
	Good* b=new Good;
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

		infile >> p->g_id >> p->g_name >> p->g_price >> p->g_number >> p->g_message >> p->g_seller >> p->g_state;
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
		outfile << p->g_id << " " << p->g_name << " " << p->g_price << " " << p->g_number << " " << p->g_message << " " << p->g_seller << " " << p->g_state << endl;
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
		infile >> p->u_id >> p->u_name >> p->u_phone >> p->u_adress >> p->u_password >> p->u_state >> p->u_money;
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
		outfile << p->u_id << " " << p->u_name << " " << p->u_phone << " " << p->u_adress << " " << p->u_password << " " << p->u_state << " " << p->u_money << endl;
		p = p->next;
	}
	outfile.close();
}


void Auction_group::Send_Message()
{

}
void Auction_group::Withdraw_Message()
{

}
void Auction_group::Assign_Goods()
{

}
void Auction_group::Display_History_Message()
{
	Message* p, * q;
	p = new Message;
	start = new Message;
	end = new Message;
	start->next = NULL;
	q = start;
	ifstream infile("message.txt", ios::in | ios::binary);
	if (!infile)
	{
		cout << "��Ϣ�ļ������ڣ�" << endl;
		Sleep(2000);
		system("cls");
		exit(0);
	}
	while (!infile.eof())
	{
		infile >> p->people->u_name >> p->time >> p->content;
		if (infile.fail())
			break;
		p->next = NULL;
		q->next = p;
		q = q->next;
		p = new Message;
	}
	end = q;
	q->next = NULL;
	infile.close();
	delete p;
}
void Auction_group::Join_Group_Menu()
{
	system("cls");
	cout << "			��ӭ��������Ⱥ�ģ�					  " << endl;
	cout << "	 �����ʹ�õ�ָ��: 1.������Ϣ 2.���� 3.���뾺�� 4.�˳�Ⱥ��		 " << endl;
	int opt = 0;
	Buyers* buyer=new Buyers;
	Sellers* seller = new Sellers;
	seller->now_user = nowuser;
	buyer->now_user = nowuser;
	Display_History_Message();
	Message* p = new Message;
	p = start;
	while (p->next != NULL)
	{
		p = p->next;
		cout << std::left << setw(20) << p->people->u_name << ":" << p->content << std::right << setw(20) << p->time << endl;
	}
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
			p->next = new Message;
			cin >> p->next->content;
			p = p->next;
			p->next = NULL;
			cout << std::left << setw(20) << p->time << std::right << setw(20) << p->people->u_name << ":" << p->content << endl;
			break;
		case 2:Withdraw_Message(); break;
		case 3:
			if (nowuser->u_state == '1')
				buyer->Bid_Good();
			else
				cout << "��û�в��뾺�ĵ�Ȩ�ޣ�" << endl;
			break;
		case 4:
			if (nowuser->u_state == '1')
				buyer->Buyers_Module();
			else if (nowuser->u_state == '2')
				seller->Sellers_Module();
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
	while (p != NULL)
	{
		outfile << p->people << " " << p->time << " " << p->content << endl;
	}
	outfile.close();
}


bool Administrator_Module()
{
	Administrator admin;
	cout << "���������Ա������";
	cin >> admin.a_name;
	cout << "���������룺";
	cin >> admin.a_password;
	if (strcmp(admin.a_name, "admin") == 0 && strcmp(admin.a_password, "123456") == 0)
		cout << "-----��½�ɹ�-----" << endl;
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
	case 1:admin.all_goods(); break;
	case 2:admin.search_goods(); break;
	case 3:admin.remove_goods(); break;
	case 4:admin.all_orders(); break;
	case 5:admin.all_users(); break;
	case 6:admin.ban_user(); break;
	case 7:exit(0);
	default:
		cout << "����ָ�����" << endl; 
		exit(-1);
	}
	return true;
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
	Buyers* user = new Buyers;
	user->user_buyer = now_user;
	user->nowuser = now_user;
	system("cls");
	cout << "================================================================================================" << endl;
	cout << "  1.�鿴��Ʒ�б� 2.���뾺��Ⱥ�� 3.������Ʒ 4.�鿴��ʷ���� 5.�鿴��Ʒ��ϸ��Ϣ 6.�����û�������" << endl;
	cout << "================================================================================================" << endl;
	now_user->u_state = '1';
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
	case 1:user->Search_all_Goods(); break;
	case 2:user->Join_Group_Menu(); break;
	case 3:user->Search_Good(); break;
	case 4:user->B_Histroy_Orders(); break;
	case 5:user->Good_Message(); break;
	case 6:User_Menu(); break;
	default:cout << "����ָ�����" << endl; break;
	}
}
//���ģ�顣
void Users::Sellers_Module()
{
	Sellers* user=new Sellers;
	user->user_seller = now_user;
	system("cls");
	cout << "=======================================================================================================" << endl;
	cout << "  1.������Ʒ 2.�鿴������Ʒ 3.�޸���Ʒ��Ϣ 4.�¼���Ʒ 5.�鿴��ʷ���� 6.���뾺��Ⱥ�� 7.�����û�������" << endl;
	cout << "=======================================================================================================" << endl;
	now_user->u_state = '2';
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
	case 1:user->List_Good(now_user); break;
	case 2:user->Listed_Good(now_user); break;
	case 3:user->Change_Good_Message(); break;
	case 4:user->Remove_Good(now_user); break;
	case 5:user->S_Histroy_Orders(); break;
	case 6:user->Join_Group_Menu(); break;
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
	cout << "�����������";
	cin >> opt;
	while (cin.fail())
	{
		cerr << "����������������룺";
		cin.clear();
		cin.ignore();
		cin >> opt;
	}
	//Get_Users_Message();
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
	delete p;
}
void Users::User_Menu()
{
	system("cls");
	cout << "===================================================" << endl;
	cout << "  1.������� 2.�������� 3.������Ϣ���� 4.ע����¼" << endl;
	cout << "===================================================" << endl;
	cout << "�����������";
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
		if (strcmp( name, a->u_name) == 0)
		{
			cout << "�û����ظ�������������" << endl;
			goto l;
		}
	}
	strcpy(now_user->u_name,name);
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



void Auction_Module()
{

}
//����ģ��


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
		break;
	}
	return 0;
}
//�Ƚ����ơ�





