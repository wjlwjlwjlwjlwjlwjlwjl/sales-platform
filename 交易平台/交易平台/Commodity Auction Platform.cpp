#include"Commodity Auction Platform.h"

void Sellers::List_Good(User*p)
{
	Get_Goods_Message();
	user_seller = p;
	Good* newgood=new Good;
	newgood->cnt = goods_message_seller_end->cnt;
	char opt = '0';
	cout << "请输入商品名称：";
	cin >> newgood->g_name;
	cout << "请输入商品价格：";
	cin >> newgood->g_price;
	cout << "请输入商品数量：";
	cin >> newgood->g_number;
	cout << "请输入商品描述：";
	cin >> newgood->g_message;
	cout << endl;
	newgood->cnt++;
	newgood->g_id[1] = newgood->cnt / 100 + '0';
	newgood->g_id[2] = (newgood->cnt % 100) / 10 + '0';
	newgood->g_id[3] = newgood->cnt % 10 + '0';
	if (cin.fail())
	{
		cerr << "发布商品失败！";
		exit(0);
	}
	cout << "请确认发布的商品信息无误！" << endl;
	cout << "***********************************************" << endl;
	cout << "商品名称：" << newgood->g_name << endl;
	cout << "商品价格：" << newgood->g_price << endl;
	cout << "商品数量：" << newgood->g_number << endl;
	cout << "商品描述：" << newgood->g_message << endl;
	cout << "***********************************************" << endl;
	cout << endl;
	cout << "您确认要发布商品吗？(y/n) ";
	cin >> opt;
	if (opt == 'y')
	{
		cout << "确认发布商品"<<endl;
	}
	else
	{
		cout << "取消发布商品"<<endl;
		exit(0);
	}
	fstream outfile("good.txt", ios::app);
	if (!outfile)
	{
		cout << "* * * 很遗憾，商品发布失败！* * *" << endl;
		exit(0);
	}
	if (newgood != NULL)
	{
		outfile << newgood->g_id << " " << newgood->g_name << " " << newgood->g_price << " " << newgood->g_number << " " << newgood->g_message <<" " << user_seller->u_id << " " << newgood->g_state << endl;
		cout << "* * * 恭喜您，发布商品成功！* * *" << endl;
		cout << "该商品的ID为：";
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
		cout << "* * * 未发布任何商品 * * *" << endl;
		Sleep(2000);
		exit(0);
	}
	cout << "********************************************************************************" << endl;
	cout << "  商品ID	名称	价格	上架时间	数量	卖家ID	  商品状态" << endl;
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
	cout << "请输入被修改商品的ID：";
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
				cout << "这不是您发布的商品，您没有权限修改它的属性，请尝试重新输入。"<<endl;
				goto l;
			}
		}
	}
	if (flage == 0)
	{
		cout << "未找到此商品" << endl;
		exit(0);
	}
	cout << "请选择你要修改的商品属性（1.商品名称 2.商品价格 3.商品信息 4.商品数量）：";
	cin >> opt;
	while (cin.fail())
	{
		cerr << "输入错误，请重新尝试" << endl;
		cin.clear();
		cin.ignore();
		cout << "请选择你要修改的商品属性（1.商品名称 2.商品价格 3.商品信息 4.商品数量）：";
		cin >> opt;
	}
	switch (opt)
	{
	case 1:
		cout << "请输入被修改商品的名称：";
		cin >> change_good->g_name;
		Updata_Goods_Message();
		break;
	case 2:
		cout << "请输入被修改商品的价格：";
		cin >> change_good->g_price;
		Updata_Goods_Message();
		break;
	case 3:
		cout << "请输入被修改商品的信息：";
		cin >> change_good->g_message;
		Updata_Goods_Message();
		break;
	case 4:
		cout << "请输入被修改商品的数量：";
		cin >> change_good->g_number;
		Updata_Goods_Message();
		break;
	default:cout << "无效操作！"; break;
	}
	l:
	cout << "请选择是否继续修改：1.继续修改 2.保存修改并返回信息管理界面" << endl;
	opt = 0;
	cin >> opt;
	switch (opt)
	{
	case 1:Change_Good_Message(); break;
	case 2:
		now_user = user_seller;
		Sellers_Module(); 
		break;
	default:cout << "无效操作！"; break;
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
	cout << "请输入要下架的商品ID：";
	cin >> oldgood->g_id;
	cout << endl;
	if (cin.fail())
	{
		cerr << "下架商品失败！";
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
		cout << "没有找到该商品" << endl;
		exit(0);
	}
	else if (flage == 2)
	{
		cout << "该商品不是您发布的，您没有权限修改它！" << endl;
		exit(0);
	}
	cout << "请确认要下架该商品吗？" << endl;
	cout << "********************************************************************" << endl;
	cout << "商品ID" << "  " << "商品名称" << "  " << "商品价格" << "  " << "商品数量" << "  " << "卖家ID" << "  " << "商品状态" << endl;
	cout << oldgood->g_id << "  " << oldgood->g_name << "  " << oldgood->g_price << "  " << oldgood->g_number << "  " << user_seller->u_id << "  " << oldgood->g_state << endl;
	cout << "********************************************************************" << endl;
	cout << endl;
	cout << "请选择(y/n) ";
	cin >> opt;
	if (opt == 'y')
	{
		cout << "下架成功" << endl;
		oldgood->g_state = '3';
	}
	else
	{
		cout << "下架失败" << endl;
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
		cout << "商品信息文件不存在！" << endl;
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
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
	cout << "  商品ID	名称	价格	上架时间	数量	卖家ID	  商品状态" << endl;
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
		cout << "商品信息文件不存在！" << endl;
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
	cout << "  商品ID	名称	价格	上架时间	数量	卖家ID	  商品状态" << endl;
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
	cout << "请输入";




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
	cout << "请输入要下架的商品ID：";
	cin >> oldgood->g_id;
	cout << endl;
	if (cin.fail())
	{
		cerr << "下架商品失败！";
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
		cout << "没有找到该商品" << endl;
		exit(0);
	}
	cout << "请确认要下架该商品吗？" << endl;
	cout << "********************************************************************" << endl;
	cout << "商品ID" << "  " << "商品名称" << "  " << "商品价格" << "  " << "商品数量" << "  " << "卖家ID" << "  " << "商品状态" << endl;
	cout << oldgood->g_id << "  " << oldgood->g_name << "  " << oldgood->g_price << "  " << oldgood->g_number << "  " << oldgood->g_seller << "  " << oldgood->g_state << endl;
	cout << "********************************************************************" << endl;
	cout << endl;
	cout << "请选择(y/n) ";
	cin >> opt;
	if (opt == 'y')
	{
		cout << "下架成功" << endl;
	}
	else
	{
		cout << "下架失败" << endl;
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
	cout << "用户ID" << "  " << "用户名" << "  " << "联系方式" << "  " << "地址" << "  " << "钱包余额" << "  " << "用户状态" << endl;
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
	cout << "请输入要封禁的用户ID：";
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
		cout << "没有找到该用户！" << endl;
		exit(0);
	}
	cout << "确认要封禁该用户吗？" << endl;
	cout << "*************************************************************************" << endl;
	cout << "用户ID" << "  " << "用户名" << "  " << "联系方式" << "  " << "地址" << "  " << "钱包余额" << "  " << "用户状态" << endl;
	cout << p->u_id << " " << p->u_name << " " << p->u_phone << " " << p->u_adress << " " << p->u_money << " " << p->u_state << endl;
	cout << "*************************************************************************" << endl;
	cout << "请选择(y/n)：";
	cin >> opt;
	if (opt == 'y')
		cout << "封禁成功" << endl;
	else
	{
		cout << "封禁取消" << endl;
		exit(0);
	}
	p->u_state = '2';
	User* a = new User;
	//Achieve_Users_Message();
	a = this->a_users_begin->next;
	fstream outfile1("user.txt", ios::out);
	if (!outfile1)
	{
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
		cout << "商品信息文件不存在！" << endl;
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
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
		cout << "用户信息文件不存在！" << endl;
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
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
		cout << "信息文件不存在！" << endl;
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
	cout << "			欢迎来到竞拍群聊！					  " << endl;
	cout << "	 你可以使用的指令: 1.发送信息 2.撤回 3.参与竞拍 4.退出群聊		 " << endl;
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
			cerr << "输入错误，请重新输入:";
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
				cout << "您没有参与竞拍的权限！" << endl;
			break;
		case 4:
			if (nowuser->u_state == '1')
				buyer->Buyers_Module();
			else if (nowuser->u_state == '2')
				seller->Sellers_Module();
			else
				cout << "输入指令错误！" << endl;
			break;
		default:cout << "输入指令错误！" << endl; break;
		}
	}
}
//nowuser需要赋值，时间
void Auction_group::Store_Message()
{
	Message* p = new Message;
	p = this->start;
	fstream outfile("message.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
	cout << "请输入管理员姓名：";
	cin >> admin.a_name;
	cout << "请输入密码：";
	cin >> admin.a_password;
	if (strcmp(admin.a_name, "admin") == 0 && strcmp(admin.a_password, "123456") == 0)
		cout << "-----登陆成功-----" << endl;
	else
	{
		cout << "-----密码错误，登陆失败，返回主菜单-----" << endl;
		Sleep(1000);
		return false;
	}
	system("cls");
	cout << "================================================================================================" << endl;
	cout << "  1.查看所有的商品  2.搜索商品  3.下架商品  4.查看所有订单  5.查看所有用户  6.封禁用户  7.注销" << endl;
	cout << "================================================================================================" << endl;
	cout << "请输入操作：";
	cin >> option;
	while (cin.fail())
	{
		cerr << "输入错误，请重新输入：";
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
		cout << "输入指令错误！" << endl; 
		exit(-1);
	}
	return true;
}
//管理员模块。
void Users_Module(int st)
{
	int flage = 0;
	Users user;
	User* somebody=new User;
	if (st == 2)
	{
		user.User_sign_up();
		//system("cls");
		cout << "请选择是否现在登录：1.登录 2.退出"<<endl;
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
			cout << "请选择是否重新登陆：1.重新登陆 2.退出"<<endl;
			cin >> flage;
			if (flage == 1)
				goto login;
			else
				exit(0);
		}
		user.User_Menu();
	}
}
//用户模块。
void Users::Buyers_Module()
{
	Buyers* user = new Buyers;
	user->user_buyer = now_user;
	user->nowuser = now_user;
	system("cls");
	cout << "================================================================================================" << endl;
	cout << "  1.查看商品列表 2.加入竞拍群聊 3.搜索商品 4.查看历史订单 5.查看商品详细信息 6.返回用户主界面" << endl;
	cout << "================================================================================================" << endl;
	now_user->u_state = '1';
	Update_message();
	option = 0;
	cout << "请输入操作：";
	cin >> option;
	while (cin.fail())
	{
		cerr << "输入错误，请重新输入：";
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
	default:cout << "输入指令错误！" << endl; break;
	}
}
//买家模块。
void Users::Sellers_Module()
{
	Sellers* user=new Sellers;
	user->user_seller = now_user;
	system("cls");
	cout << "=======================================================================================================" << endl;
	cout << "  1.发布商品 2.查看发布商品 3.修改商品信息 4.下架商品 5.查看历史订单 6.加入竞拍群聊 7.返回用户主界面" << endl;
	cout << "=======================================================================================================" << endl;
	now_user->u_state = '2';
	Update_message();
	option = 0;
	cout << "请输入操作：";
	cin >> option;
	while (cin.fail())
	{
		cerr << "输入错误，请重新输入：";
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
	default:cout << "输入指令错误！" << endl; break;
	}
}
//卖家模块。
void Users::Information_Module()
{
	system("cls");
	cout << "==================================================" << endl;
	cout << "  1.查看信息 2.修改信息 3.充值 4.返回用户主界面" << endl;
	cout << "==================================================" << endl;
	int opt = 0;
	cout << "请输入操作：";
	cin >> opt;
	while (cin.fail())
	{
		cerr << "输入错误，请重新输入：";
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
	default:cout << "无效命令！"; break;
	}
}
//用户模块函数



void Users::User_sign_up()
{
	Get_Users_Message();
	User* someone = new User;
	someone->cnt = users_end->cnt;
	User* a;
	l:
	cout << "请输入你的姓名：";
	cin >> someone->u_name;
	a = users_begin;
	while (a->next != NULL)
	{
		a = a->next;
		if (strcmp(someone->u_name, a->u_name) == 0)
		{
			cout << "用户名重复，请重新输入" << endl;
			goto l;
		}
	}
	cout << "请输入你的电话号码：";
	cin >> someone->u_phone;
	cout << "请输入你的地址：";
	cin >> someone->u_adress;
	cout << "请创建你的密码：";
	cin >> someone->u_password;
	someone->cnt++;
	someone->u_id[1] = someone->cnt / 100 + '0';
	someone->u_id[2] = (someone->cnt % 100) / 10 + '0';
	someone->u_id[3] = someone->cnt % 10 + '0';
	fstream outfile("user.txt", ios::app);
	if (!outfile)
	{
		cout << "* * * 很遗憾，用户注册失败！* * *" << endl;
		exit(0);
	}
	if (someone != NULL)
	{
		outfile << someone->u_id<<" "<< someone->u_name << " " << someone->u_phone << " " << someone->u_adress << " " << someone->u_password << " " << someone->u_state << " " << someone->u_money << endl;
		cout << "* * * 恭喜您，用户注册成功！* * *" << endl;
		cout << "系统为您生成的ID为：";
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
		cout << "用户信息文件不存在！" << endl; 
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
}						//读取有问题
bool Users::User_login()
{
	Get_Users_Message();
	now_user = new User;
	User someone;
	int flage = 0;
	cout<< "请输入用户名：";
	cin >> someone.u_name;
	cout << "请输入密码：";
	cin >> someone.u_password;
	User* p, * q;
	p = this->users_begin;
	q = new User;
	if (p == NULL)
	{
		cout << "* * * 很遗憾，登陆失败！* * *"<<endl;
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
		cout << "* * * 用户名不存在！* * *"<<endl;
		return false;
	}
	if (strcmp(q->u_password,someone.u_password)==0)
	{
		cout << "* * * 恭喜您，登陆成功！* * *" << endl;
		now_user = q;
		return true;
	}
	else
	{
		cout << "* * * 密码错误！* * *" << endl;
		return false;
	}
	delete p;
}
void Users::User_Menu()
{
	system("cls");
	cout << "===================================================" << endl;
	cout << "  1.我是买家 2.我是卖家 3.个人信息管理 4.注销登录" << endl;
	cout << "===================================================" << endl;
	cout << "请输入操作：";
	int opt=0;
	cin >> opt;
	while (cin.fail())
	{
		cerr << "输入错误，请重新输入：";
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
	default:cout << "输入指令错误！" << endl; break;
	}
}
void Users::Search_message()
{
	cout << "*************************************" << endl;
	cout << "用户名：" << now_user->u_name << endl;
	cout << "联系方式：" << now_user->u_phone << endl;
	cout << "地址：" << now_user->u_adress << endl;
	cout << "钱包余额：" << now_user->u_money << endl;
	cout << "*************************************" << endl;
}
void Users::Change_message()
{
	int opt;
	remake:
	opt = 0;
	cout << "请选择你要修改的属性（1.用户名 2.联系方式 3.地址 4.登录密码）：";
	cin >> opt;
	while (cin.fail())
	{
		cerr << "输入错误，请重新尝试" << endl;
		cin.clear();
		cin.ignore();
		cout << "请选择你要修改的属性（1.用户名 2.联系方式 3.地址 4.登录密码）：";
		cin >> opt;
	}
	switch (opt)
	{
	case 1:Change_name(); break;
	case 2:Change_phone(); break;
	case 3:Change_adress(); break;
	case 4:Change_password(); break;
	default:cout << "无效操作！";break;
	}
	cout << "请选择是否继续修改：1.继续修改 2.保存修改并返回信息管理界面" << endl;
	opt = 0;
	cin >> opt;
	switch (opt)
	{
	case 1:goto remake;
	case 2:Information_Module(); break;
	default:cout << "无效操作！"; break;
	}
}
void Users::Change_name()
{
	char name[11] = { '0' };
	l:
	cout << "请输入新的用户名：";
	cin >> name;
	//Get_Users_Message();
	User* a;
	a = users_begin;
	while (a->next != NULL)
	{
		a = a->next;
		if (strcmp( name, a->u_name) == 0)
		{
			cout << "用户名重复，请重新输入" << endl;
			goto l;
		}
	}
	strcpy(now_user->u_name,name);
	Update_message();
}
void Users::Change_phone()
{
	cout << "请输入新的联系方式：";
	cin >> now_user->u_phone;
	Update_message();
}
void Users::Change_adress()
{
	cout << "请输入新地址：";
	cin >> now_user->u_adress;
	Update_message();
}
void Users::Change_password()
{
	cout << "请输入新的密码：";
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
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
	cout << "请输入充值金额：";
	cin >> money;
	initgraph(490, 670);
	loadimage(0, "collect_money.jpg",490,670);
	system("pause");
	closegraph();
	sprintf(str, "%.1lf\t", atof(now_user->u_money) + money);
	strcpy(now_user->u_money, str);
	Update_message();
	cout << "恭喜您，充值成功！" << endl;
}



void Auction_Module()
{

}
//竞拍模块


int main() {
	while (true)
	{
		lm:
		system("cls");
		cout << "====================================================" << endl;
		cout << "  1.管理员登录  2.用户注册  3.用户登录  4.退出程序" << endl;
		cout << "====================================================" << endl;
		cout << "请输入操作：";
		cin >> option;
		while (cin.fail()) 
		{
			cerr << "输入错误，请重新输入：";
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
		default:cout << "输入指令错误！" << endl; break;
		}
		break;
	}
	return 0;
}
//比较完善。





