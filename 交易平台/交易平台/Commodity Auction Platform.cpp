#include"Commodity Auction Platform.h"

void Users::Buyers_Module()
{
	Buyers* user = new Buyers;
	user->user_buyer = now_user;
	Auction_group* group = new Auction_group;
	group->nowuser = now_user;
	system("cls");
	cout << "======================================================================================================================" << endl;
	cout << "  1.查看商品列表 2.加入竞拍群聊 3.搜索商品 4.购买商品 5.参与竞拍 6.查看历史订单 7.查看商品详细信息 8.返回用户主界面" << endl;
	cout << "======================================================================================================================" << endl;
	strcpy(now_user->u_state, "买家");
	Update_message();
	option = 0;
	cout << "请输入操作:";
	cin >> option;
	l:
	while (cin.fail())
	{
		cerr << "输入错误，请重新输入:";
		cin.clear();
		cin.ignore();
		cin >> option;
	}
	switch (option)
	{
	case 1:user->Search_all_Goods();
		cout << "请输入操作:";
		cin >> option;
		user->Buyer_nemu();
		goto l;
	case 2:group->Join_Group_Menu();
		cout << "请输入操作:";
		cin >> option;
		user->Buyer_nemu();
		goto l;
	case 3:user->Search_Good();
		cout << "请输入操作:";
		cin >> option;
		user->Buyer_nemu();
		goto l;
	case 4:user->Buy_Good(); 
		cout << "请输入操作:";
		cin >> option;
		user->Buyer_nemu();
		goto l;
	case 5:user->Bid_nemu(now_user);
		cout << "请输入操作:";
		cin >> option;
		user->Buyer_nemu();
		goto l;
	case 6:user->B_Histroy_Orders();
		cout << "请输入操作:";
		cin >> option;
		user->Buyer_nemu();
		goto l;
	case 7:user->Good_Message(); 
		cout << "请输入操作:";
		cin >> option;
		user->Buyer_nemu();
		goto l;
	case 8:User_Menu(); 
		break;
	default:cout << "输入指令错误！" << endl; break;
	}
}
//买家模块。
void Users::Sellers_Module()
{
	//Get_Users_Message();
	Sellers* user = new Sellers;
	user->user_seller = now_user;
	Auction_group *group = new Auction_group;
	group->nowuser = now_user;
	system("cls");
	cout << "=======================================================================================================" << endl;
	cout << "  1.发布商品 2.查看发布商品 3.修改商品信息 4.下架商品 5.查看历史订单 6.加入竞拍群聊 7.返回用户主界面" << endl;
	cout << "=======================================================================================================" << endl;
	strcpy(now_user->u_state, "卖家");
	Update_message();
	option = 0;
	cout << "请输入操作:";
	cin >> option;
	l:
	while (cin.fail())
	{
		cerr << "输入错误，请重新输入:";
		cin.clear();
		cin.ignore();
		cin >> option;
	}
	switch (option)
	{
	case 1:user->List_Good(now_user);
		cout << "请输入操作:";
		cin >> option;
		user->Seller_nemu();
		goto l;
	case 2:user->Listed_Good(now_user);
		cout << "请输入操作:";
		cin >> option;
		user->Seller_nemu();
		goto l;
	case 3:user->Change_Good_Message(); 
		cout << "请输入操作:";
		cin >> option;
		user->Seller_nemu();
		goto l;
	case 4:user->Remove_Good(now_user);
		cout << "请输入操作:";
		cin >> option;
		user->Seller_nemu();
		goto l;
	case 5:user->S_Histroy_Orders(); 
		cout << "请输入操作:";
		cin >> option;
		user->Seller_nemu();
		goto l;
	case 6:group->Join_Group_Menu(); 
		cout << "请输入操作:";
		cin >> option;
		user->Seller_nemu();
		goto l;
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
	cout << "请输入操作:";
	cin >> opt;
	l:
	while (cin.fail())
	{
		cerr << "输入错误，请重新输入:";
		cin.clear();
		cin.ignore();
		cin >> opt;
	}
	//Get_Users_Message();
	switch (opt)
	{
	case 1:Search_message();
		cout << "请输入操作:";
		cin >> opt;
		User_nemu();
		goto l;
	case 2:Change_message();
		cout << "请输入操作:";
		cin >> opt;
		User_nemu();
		goto l;
	case 3:Add_money(); 
		cout << "请输入操作:";
		cin >> opt;
		User_nemu();
		goto l;
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
	strcpy(someone->credibility, "10");
	fstream outfile("user.txt", ios::app);
	if (!outfile)
	{
		cout << "* * * 很遗憾，用户注册失败！* * *" << endl;
		exit(0);
	}
	if (someone != NULL)
	{
		outfile << someone->u_id << " " << someone->u_name << " " << someone->u_phone << " " << someone->u_adress << " " << someone->u_password << " " << someone->u_state << " " << someone->u_money <<" "<<someone->credibility << endl;
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
		ofstream file("user.txt");
		if (file)
			file.close();
		else
		{
			cout << "文件创建失败！" << endl;
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
}						//读取有问题
bool Users::User_login()
{
	Get_Users_Message();
	now_user = new User;
	User someone;
	int flage = 0;
	cout << "请输入用户名：";
	cin >> someone.u_name;
	cout << "请输入密码：";
	cin >> someone.u_password;
	User* p, * q;
	p = this->users_begin;
	q = new User;
	if (p == NULL)
	{
		cout << "* * * 很遗憾，登陆失败！* * *" << endl;
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
		cout << "* * * 用户名不存在！* * *" << endl;
		return false;
	}
	if (strcmp(q->u_password, someone.u_password) == 0)
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
	int opt = 0;
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
	case 4:break;
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
	default:cout << "无效操作！"; break;
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
		if (strcmp(name, a->u_name) == 0)
		{
			cout << "用户名重复，请重新输入" << endl;
			goto l;
		}
	}
	strcpy(now_user->u_name, name);
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
	p = this->users_begin;
	fstream outfile("user.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
	cout << "请输入充值金额：";
	cin >> money;
	initgraph(490, 670);
	loadimage(0, "collect_money.jpg", 490, 670);
	system("pause");
	closegraph();
	sprintf(str, "%.1lf", atof(now_user->u_money) + money);
	strcpy(now_user->u_money, str);
	Update_message();
	cout << "恭喜您，充值成功！" << endl;
}
void Users::User_nemu()
{
	system("cls");
	cout << "==================================================" << endl;
	cout << "  1.查看信息 2.修改信息 3.充值 4.返回用户主界面" << endl;
	cout << "==================================================" << endl;
}

void Sellers::List_Good(User* p)
{
	Get_Goods_Message();
	user_seller = p;
	Good* newgood = new Good;
	newgood->cnt = goods_message_seller_end->cnt;
	char opt = '0';
	cout << "请输入商品名称:";
	cin >> newgood->g_name;
	cout << "请输入商品价格:";
	cin >> newgood->g_price;
	cout << "请输入商品数量:";
	cin >> newgood->g_number;
	cout << "请输入商品描述:";
	cin >> newgood->g_message;
	cout << "请输入商品类型:";
	cin >> newgood->g_type;
	cout << endl;
	if (strcmp(newgood->g_type, "直售") != 0 && strcmp(newgood->g_type, "竞拍") != 0)
	{
		cout << "发布失败！" << endl;
		return;
	}
	newgood->cnt++;
	newgood->g_id[1] = newgood->cnt / 100 + '0';
	newgood->g_id[2] = (newgood->cnt % 100) / 10 + '0';
	newgood->g_id[3] = newgood->cnt % 10 + '0';
	if (cin.fail())
	{
		cerr << "发布商品失败！";
		Seller_nemu();
		return;
	}
	cout << "请确认发布的商品信息无误！" << endl;
	cout << "***********************************************" << endl;
	cout << "商品名称:" << newgood->g_name << endl;
	cout << "商品价格:" << newgood->g_price << endl;
	cout << "商品数量:" << newgood->g_number << endl;
	cout << "商品描述:" << newgood->g_message << endl;
	cout << "商品类型:" << newgood->g_time << endl;
	cout << "***********************************************" << endl;
	cout << endl;
	cout << "您确认要发布商品吗？(y/n) ";
	cin >> opt;
	if (opt == 'y')
	{
		cout << "确认发布商品" << endl;
		time_t now;
		time(&now);
		struct tm* tempTime = localtime(&now);
		strftime(newgood->g_time, 80, "[%Y-%m-%d-%H:%M:%S]", tempTime);
		if (strcmp(newgood->g_type, "竞拍") == 0)
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
		cout << "取消发布商品" << endl;
		return;
		//exit(0);
	}
	fstream outfile("good.txt", ios::app);
	if (!outfile)
	{
		cout << "* * * 很遗憾，商品发布失败！* * *" << endl;
		exit(0);
	}
	if (newgood != NULL)
	{
		outfile << newgood->g_id << " " << newgood->g_name << " " << newgood->g_price << " " <<newgood->g_time<<" " << newgood->g_number << " " << newgood->g_message << " " << user_seller->u_id << " " << newgood->g_state <<" "<<newgood->g_type <<" " <<newgood->endtime<< endl;
		cout << "* * * 恭喜您，发布商品成功！* * *" << endl;
		cout << "该商品的ID为：";
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
		cout << "* * * 未发布任何商品 * * *" << endl;
		Sleep(2000);
		exit(0);
	}
	cout << "********************************************************************************" << endl;
	cout << "  商品ID	名称	价格	上架时间	数量	卖家ID	  商品状态	商品类型" << endl;
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
				cout << "这不是您发布的商品，您没有权限修改它的属性，请尝试重新输入。" << endl;
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
		Get_Users_Message();
		now_user = user_seller;
		Sellers_Module();
		break;
	default:cout << "无效操作！"; break;
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
	cout << "请输入要下架的商品ID：";
	cin >> oldgood->g_id;
	//cout << endl;
	if (cin.fail())
	{
		cerr << "下架商品失败！";
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
		cout << "没有找到该商品" << endl;
		return;
		//exit(0);
	}
	else if (flage == 2)
	{
		cout << "该商品不是您发布的，您没有权限修改它！" << endl;
		return;
		//exit(0);
	}
	cout << "请确认要下架该商品吗？" << endl;
	cout << "********************************************************************" << endl;
	cout << "商品ID" << "  " << "商品名称" << "  " << "商品价格" << "  " << "商品数量" << "  " << "卖家ID" << "  " << "商品状态" <<" "<<"商品类型"<< endl;
	cout << oldgood->g_id << "  " << oldgood->g_name << "  " << oldgood->g_price << "  "<<oldgood->g_time<<"  " << oldgood->g_number << "  " << user_seller->u_id << "  " << oldgood->g_state << " " << oldgood->g_type << endl;
	cout << "********************************************************************" << endl;
	cout << endl;
	cout << "请选择(y/n) ";
	cin >> opt;
	if (opt == 'y')
	{
		cout << "下架成功" << endl;
		strcpy(oldgood->g_state, "下架");
	}
	else
	{
		cout << "下架失败" << endl;
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
	cout << "订单ID   商品ID   交易单价   数量   交易时间   卖家ID   买家ID" << endl;
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
			cout << "文件创建失败" << endl;
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
			cout << "文件创建失败" << endl;
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
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
	cout << "  1.发布商品 2.查看发布商品 3.修改商品信息 4.下架商品 5.查看历史订单 6.加入竞拍群聊 7.返回用户主界面" << endl;
	cout << "=======================================================================================================" << endl;
}

void Buyers::Search_all_Goods()
{
	Get_Goods_Message();
	cout << "********************************************************************************" << endl;
	cout << "  商品ID	名称	价格	上架时间	数量	卖家ID	  商品状态   商品类型   结束时间" << endl;
	Good* p = goods_message_buyer_begin;
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(p->g_state,"在售")==0 || strcmp(p->g_state,"售空")==0)
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
	cout << "请输入您想要购买的商品的ID:";
	char id[5] = { 'M' };
	int n = 0;
	cin >> id;
	cout << "请输入购买数量:";
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
		cout << "没有找到该商品" << endl;
		Buyer_nemu();
		return;
	}
	if (strcmp(p->g_type, "直售") != 0)
	{
		cout << "该商品不用于直售！" << endl;
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
	cout << "请确认是否花费" << price*n << "元来购买"<<n<<"件该商品" << endl;
	cout << "***********************************************" << endl;
	cout << "商品ID:" << p->g_id << endl;
	cout << "商品名称:" << p->g_name << endl;
	cout << "商品价格:" << p->g_price << endl;
	cout << "商品数量:" << p->g_number << endl;
	cout << "上架时间:" << p->g_time << endl;
	cout << "商品描述:" << p->g_message << endl;
	cout << "商品卖家:" << p->g_seller << endl;
	cout << "***********************************************" << endl;
	cout << endl;
	char opt = '0';
	cout << "请选择(y/n):";
	cin >> opt;
	if (opt == 'y')
	{
		if (strcmp(p->g_state,"售空")==0)
		{
			cout << "商品已售空" << endl;
		}
		else if (strcmp(p->g_state,"下架") == 0)
		{
			cout << "商品已下架" << endl;
		}
		else if (number < n)
		{
			cout << "商品余量不足" << endl;
		}
		else if (money >= price*n&&strcmp(p->g_state,"在售")==0 && number >= n)
		{
			money -= price*n;
			sprintf(str, "%.1lf\t",money);
			strcpy(t->u_money, str);
			number -= n;
			if (number == 0)
				strcpy(p->g_state, "售空");
			_itoa(number, p->g_number, 10);
			Update_message();
			Good* q;
			q = this->goods_message_buyer_begin->next;
			fstream outfile("good.txt", ios::out);
			if (!outfile)
			{
				cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
			cout << "购买成功" << endl;
		}
		else
		{
			cout << "余额不足" << endl;
			//exit(0);
		}
	}
	else
	{
		cout << "成功取消购买！" << endl;
	}
}
void Buyers::Search_Good()
{
	Get_Goods_Message();
	char input[20] = { '0' };
	Good* p = goods_message_buyer_begin;
	cout << "请输入您想要搜索的商品的ID或名称:";
	cin >> input;
	int count = 0;
	if (input[0] == 'M')
	{
		while (p->next != NULL)
		{
			p = p->next;
			if ((strcmp(p->g_state,"在售")==0 || strcmp(p->g_state,"售空")==0) && strcmp(input, p->g_id) == 0)
			{
				count++;
				if (count == 1)
				{
					cout << "********************************************************************************" << endl;
					cout << "  商品ID	名称	价格	上架时间	数量	卖家ID	  商品状态    商品类型" << endl;
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
			if ((strcmp(p->g_state,"在售")==0 || strcmp(p->g_state,"售空")==0) && Index_KMP(S, T, 1, nextval) != 0)
			{
				count++;
				if (count == 1)
				{
					cout << "********************************************************************************" << endl;
					cout << "  商品ID	名称	价格	上架时间	数量	卖家ID	  商品状态    商品类型" << endl;
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
	cout << "请输入您想要查看的商品的ID:";
	cin >> id;
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(id, p->g_id)==0)
		{
			cout << "***********************************************" << endl;
			cout << "商品ID:" << p->g_id << endl;
			cout << "商品名称:" << p->g_name << endl;
			cout << "商品价格:" << p->g_price << endl;
			cout << "商品数量:" << p->g_number << endl;
			cout << "上架时间:" << p->g_time << endl;
			cout << "商品描述:" << p->g_message << endl;
			cout << "商品卖家:" << p->g_seller << endl;
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
	cout << "订单ID   商品ID   交易单价   数量   交易时间   卖家ID   买家ID" << endl;
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
			cout << "文件创建失败" << endl;
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
			cout << "文件创建失败" << endl;
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
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
	cout << "  1.查看商品列表 2.加入竞拍群聊 3.搜索商品 4.购买商品 5.参与竞拍 6.查看历史订单 7.查看商品详细信息 8.返回用户主界面" << endl;
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
	cout << "请输入您要竞价的商品的ID:";
	cin >> newbid->g_id;
	cout << "请输入您的出价:";
	cin >> newbid->bid;
	cout << "请输入您要竞拍的商品数量:";
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
		cout << "没有找到该商品！" << endl;
		return;
	}
	if (compare(newbid->time, g->endtime))
	{
		cout << "已经超过该商品的竞拍时限!" << endl;
		return;
	}
	if (strcmp(g->g_type, "竞拍") != 0)
	{
		cout << "该商品不用于竞拍！" << endl;
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
		cout << "竞拍失败!" << endl;
		return;
	}
	cout << "参与竞拍成功!" << endl;
	user->count++;
	strcpy(newbid->u_id, user_buyer->u_id);
	bid_end = bid_end->next;
	bid_end->next = NULL;
	Bidding* p = new Bidding;
	p = bid_begin->next;
	fstream outfile("bidding.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
	cout << "  1.竞拍商品 2.修改竞价 3.取消竞价 4.返回买家首页" << endl;
	cout << "====================================================" << endl;
	cout << "您目前参与了" << user->count << "件商品的竞拍" << endl;
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
			if (strcmp(p->u_id, user->u_id) == 0&&strcmp(p->state,"进行中")==0)
			{
				if (compare(str, p->time))
				{
					cout << "恭喜您成功竞拍到ID为" << p->g_id << "的商品，请您选择是否支付商品的费用: 1.支付 2.取消 (如果取消的话会使您的信誉受损)" << endl;
					cout << "请输入操作:";
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



	cout << "请输入操作:";
	cin >> opt;
lm:

	while (cin.fail())
	{
		cerr << "输入错误，请重新输入：";
		cin.clear();
		cin.ignore();
		cin >> opt;
	}
	switch (opt)
	{
	case 1:Bid(user);
		cout << "请输入操作:";
		cin >> opt;
		goto lm;
	case 2:Change_Bid(user);
		cout << "请输入操作:";
		cin >> opt;
		goto lm;
	case 3:Remove_Bid(user);
		cout << "请输入操作:";
		cin >> opt;
		goto lm;
	case 4:u->Buyers_Module();
		break;
	default:cout << "输入指令错误！" << endl; break;
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
			cout << "文件创建失败" << endl;
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
	cout << "请输入您要修改出价的商品ID:";
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
		cout << "您没有该商品的竞价！" << endl;
		return;
	}
	cout << "请输入您修改后的竞价:";
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
		cout << "修改竞价失败!" << endl;
		return;
	}
	cout << "修改成功!" << endl;
	Bidding* p = new Bidding;
	p = bid_begin->next;
	fstream outfile("bidding.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
	cout << "请输入您要取消出价的商品ID:";
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
		cout << "您没有该商品的竞价！" << endl;
		return;
	}
	cout << "取消出价成功！" << endl;
	temp->next = b->next;
	b = NULL;
	delete b;
	Bidding* p = new Bidding;
	p = bid_begin->next;
	fstream outfile("bidding.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
	cout << "  商品ID	名称	价格	上架时间	数量	卖家ID	  商品状态    结束时间" << endl;
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
	cout << "请输入您想要搜索的商品的ID或名称:";
	cin >> input;
	int count = 0;
	if (input[0] == 'M')
	{
		while (p->next != NULL)
		{
			p = p->next;
			if ((strcmp(p->g_state,"在售")==0 || strcmp(p->g_state,"售空")==0) && strcmp(input, p->g_id) == 0)
			{
				count++;
				if (count == 1)
				{
					cout << "********************************************************************************" << endl;
					cout << "  商品ID	名称	价格	上架时间	数量	卖家ID	  商品状态    商品类型" << endl;
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
			if ((strcmp(p->g_state,"在售")==0 || strcmp(p->g_state,"售空")==0) && Index_KMP(S, T, 1, nextval) != 0)
			{
				count++;
				if (count == 1)
				{
					cout << "********************************************************************************" << endl;
					cout << "  商品ID	名称	价格	上架时间	数量	卖家ID	  商品状态    商品类型" << endl;
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
	cout << "请输入要下架的商品ID:";
	cin >> oldgood->g_id;
	//cout << endl;
	if (cin.fail())
	{
		cerr << "下架商品失败！";
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
		cout << "没有找到该商品" << endl;
		//exit(0);
		return;
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
	cout << "订单ID   商品ID   交易单价   数量   交易时间   卖家ID   买家ID" << endl;
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
	cout << "用户ID" << "  " << "用户名" << "  " << "联系方式" << "  " << "地址" << "  " << "钱包余额" << "  " << "用户状态" << endl;
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
	cout << "请输入要封禁的用户ID:";
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
		cout << "没有找到该用户！" << endl;
		//exit(0);
		return;
	}
	cout << "确认要封禁该用户吗？" << endl;
	cout << "*************************************************************************" << endl;
	cout << "用户ID" << "  " << "用户名" << "  " << "联系方式" << "  " << "地址" << "  " << "钱包余额" << "  " << "用户状态" << "  " << "用户信誉" << endl;
	cout << p->u_id << " " << p->u_name << " " << p->u_phone << " " << p->u_adress << " " << p->u_money << " " << p->u_state << " " << p->credibility << endl;
	cout << "*************************************************************************" << endl;
	cout << "请选择(y/n)：";
	cin >> opt;
	cout << endl;
	if (opt == 'y')
		cout << "封禁成功" << endl;
	else
	{
		cout << "封禁取消" << endl;
		//exit(0);
		return;
	}
	strcpy(p->u_state, "封禁");
	User* a = new User;
	//Achieve_Users_Message();
	a = this->a_users_begin;
	tp->next = p->next;
	tp = tp->next;
	tp = NULL;
	fstream outfile1("user.txt", ios::out);
	if (!outfile1)
	{
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
		cout << "用户信息文件不存在！" << endl;
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
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
	cout << "  1.查看所有的商品  2.搜索商品  3.下架商品  4.查看所有订单  5.查看所有用户  6.封禁用户  7.注销" << endl;
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
			cout << "文件创建失败" << endl;
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
			cerr << "输入错误，请重新输入:";
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
			if (strcmp(nowuser->u_state,"买家")==0)
				Join_Auction();
			else
				cout << "您没有参与竞拍的权限！" << endl;
			break;
		case 4:
			if (strcmp(nowuser->u_state,"卖家")==0)
				Send_Goods();
			else
				cout << "您没有权限发布竞拍商品！" << endl;
			break;
		case 5:
			if (strcmp(nowuser->u_state,"买家")==0)
			{
				User* p = nowuser;
				buyer->Get_Users_Message();
				buyer->now_user = p;
				buyer->Buyers_Module();
			}
			else if (strcmp(nowuser->u_state,"卖家")==0)
			{
				User* p = nowuser;
				seller->Get_Users_Message();
				seller->now_user = p;
				seller->Sellers_Module();
			}
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
	cout << "请输入需要抢购的商品名称：";
	cin >> newgood->g_name;
	cout << "请输入需要抢购的商品底价：";
	cin >> newgood->g_price;
	cout << "请输入需要抢购的商品数量：";
	cin >> newgood->g_number;
	cout << "请输入需要抢购的商品描述：";
	cin >> newgood->g_message;
	newgood->cnt++;
	newgood->g_id[1] = newgood->cnt / 100 + '0';
	newgood->g_id[2] = (newgood->cnt % 100) / 10 + '0';
	newgood->g_id[3] = newgood->cnt % 10 + '0';
	strcpy(newgood->g_type, "抢购");
	strcpy(newgood->g_state, "在售");
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
	cout << "您确认要将此商品用于抢购吗？(y/n) ";
	cin >> opt;
	if (opt == 'y')
	{
		cout << "确认发布商品" << endl;
		time_t now;
		time(&now);
		struct tm* tempTime = localtime(&now);
		strftime(newgood->g_time, 80, "[%Y-%m-%d-%H:%M:%S]", tempTime);
	}
	else
	{
		cout << "取消发布商品" << endl;
		return;
	}
	fstream outfile("good.txt", ios::app);
	if (!outfile)
	{
		cout << "* * * 很遗憾，商品发布失败！* * *" << endl;
		return;
	}
	if (newgood != NULL)
	{
		outfile << newgood->g_id << " " << newgood->g_name << " " << newgood->g_price << " " << newgood->g_time << " " << newgood->g_number << " " << newgood->g_message << " " << member->user_seller->u_id << " " << newgood->g_state << " " << newgood->g_type << endl;
		cout << "* * * 恭喜您，发布商品成功！* * *" << endl;
		cout << "该商品的ID为：";
		cout << newgood->g_id;
	}
	outfile.close();
	Sleep(500);
	system("cls");
	cout << "		欢迎来到竞拍群聊！					  " << endl;
	cout << "	 你可以使用的指令: 1.发送信息 2.撤回 3.参与抢购 4.发布竞拍商品 5.退出群聊		 " << endl;
	Message* b = new Message;
	end->next = new Message;
	b = end->next;
	char buf[400] = { '0' };
	strcpy(b->name, member->user_seller->u_name);
	strcpy(b->nowtime, newgood->g_time);
	strcat(buf, "****");
	strcat(buf, "抢购商品信息**商品ID:");
	strcat(buf, newgood->g_id);
	strcat(buf, "**商品名称:");
	strcat(buf, newgood->g_name);
	strcat(buf, "**商品价格:");
	strcat(buf, newgood->g_price);
	strcat(buf, "**商品数量:");
	strcat(buf, newgood->g_number);
	strcat(buf, "**商品信息:");
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
	cout << "请输入您要抢购的商品的ID:";
	cin >> id;
	cout << "请输入您要抢购的数量:";
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
		cout << "查找用户失败" << endl;
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
		cout << "查找商品失败" << endl;
		return;
	}
	if (strcmp(g->g_type, "抢购") != 0)
	{
		cout << "该商品不用于抢购！" << endl;
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
			strcpy(g->g_state, "售空");
		b->Update_message();
		s->Updata_Goods_Message();
	}
	else
	{
		cout << "抢购失败" << endl;
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
	strcpy(p->content, "成功抢购");
	strcat(p->content, str);
	strcat(p->content, "件");
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
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
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
	cout << "		欢迎来到竞拍群聊！					  " << endl;
	cout << "	 你可以使用的指令: 1.发送信息 2.撤回 3.参与抢购 4.发布竞拍商品 5.退出群聊		 " << endl;
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
		cout << "请选择是否现在登录:1.登录 2.退出" << endl;
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
			cout << "请选择是否重新登陆:1.重新登陆 2.退出" << endl;
			cin >> flage;
			if (flage == 1)
			{
				system("cls");
				cout << "====================================================" << endl;
				cout << "  1.管理员登录  2.用户注册  3.用户登录  4.退出程序" << endl;
				cout << "====================================================" << endl;
				goto login;
			}
			else
				return;
		}
		user.User_Menu();
	}
}
//用户模块。

bool Administrator_Module()
{
	Administrator admin;
	cout << "请输入管理员姓名:";
	cin >> admin.a_name;
	cout << "请输入密码:";
	cin >> admin.a_password;
	if (strcmp(admin.a_name, "admin") == 0 && strcmp(admin.a_password, "123456") == 0)
	{
		cout << "-----登陆成功-----" << endl;
		Sleep(1000);
	}
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
	cout << "请输入操作:";
	cin >> option;
	l:
	while (cin.fail())
	{
		cerr << "输入错误，请重新输入:";
		cin.clear();
		cin.ignore();
		cin >> option;
	}
	switch (option)
	{
	case 1:admin.all_goods();
		cout << "请输入操作:";
		cin >> option;
		admin.Admin_nemu();
		goto l;
	case 2:admin.search_goods();
		cout << "请输入操作:";
		cin >> option;
		admin.Admin_nemu();
		goto l;
	case 3:admin.remove_goods();
		cout << "请输入操作:";
		cin >> option;
		admin.Admin_nemu();
		goto l;
	case 4:admin.all_orders(); 
		cout << "请输入操作:";
		cin >> option;
		admin.Admin_nemu();
		goto l;
	case 5:admin.all_users(); 
		cout << "请输入操作:";
		cin >> option;
		admin.Admin_nemu();
		goto l;
	case 6:admin.ban_user(); 
		cout << "请输入操作:";
		cin >> option;
		admin.Admin_nemu();
		goto l;
	case 7:break;
	default:
		cout << "输入指令错误！" << endl; 
		exit(-1);
	}
	return true;
}
//管理员模块。

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
		goto lm;
		break;
	}
	return 0;
}
//比较完善。





