#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<windows.h>
#include<stdio.h>
#include "stdlib.h"
#include <tchar.h>
#include<graphics.h>
#include<conio.h>
using namespace std;

int option;

struct User {
	char u_state = '1';		//用户的状态
	char u_id[5] = { 'U' };		//用户的ID
	char u_name[11]={'0'};			//用户的名字
	char u_phone[21]={'0'};			//用户的电话
	char u_money[100] = {'0'};			//用户的余额
	char u_adress[41]={'0'};			//用户的地址
	char u_password[21]={'0'};		//用户的密码
	char u_bid[100] = {'0'};			//用户出价
	User* next;					//用于创建存储文件中用户信息的链表
};
//定义用户结构，用于存储用户的信息。
struct Good {
	int g_state = 1;			//商品的状态，1表示在售；2表示已售空；3表示下架；
	char g_id[5] = { 'M' };		//商品的ID
	char g_name[21];			//商品名称
	double g_price = 0;			//商品的底价
	char g_time[20];			//商品上架的时间
	char g_seller[5];			//商品卖家的ID
	int g_number;				//商品的余量
	char g_message[201];		//商品信息	
	bool g_progress;			//商品的竞拍进程（24小时结束）
};
//定义商品的结构，存储商品的信息。
struct Order {
	char o_id[5] = { 'T' };		//订单ID
	char good_id[5] = { 'M' };	//商品ID
	double o_price = 0;			//订单价格
	char o_time[20];			//订单时间
	int o_number;				//订单数量
	char seller_id[5] = { 'U' };//卖家ID
	char buyer_id[5] = { 'U' };	//买家ID
};
//定义订单的结构，存储订单的信息。
class Administrator
{
public:
	void A_menu();			//管理员界面
	void all_goods();		//查看所有的商品
	void search_goods(char id[]);	//搜索商品
	void remove_goods(char id[]);	//下架商品
	void all_orders();		//查看所有订单
	void all_users();		//查看所有用户
	void ban_user(char id[]);		//封禁用户
	void cancel();			//注销

private:
	char a_name[11];
	char a_password[21];
};
//管理员类。
class Users
{
public:
	bool User_login();			//用户登录
	void User_sign_up();		//用户注册	
	void Search_message();		//查看信息
	void Change_message();		//修改信息
	void Store_message();		//保存信息
	void Change_adress();		//修改收货地址
	void Change_password();		//修改登录密码
	void Change_name();			//修改用户名
	void Change_phone();		//修改手机号
	void Add_money();			//充值
	void Change_bid();			//修改报价
	void Cancel_bid();			//取消报价
	void Get_Users_Message();   //从文件中获取信息
	void Update_message();		//更新文件中的信息
	void User_Menu();			//用户功能菜单
	void Information_Module();	//信息模块
	void Buyers_Module();		//买家模块
	void Sellers_Module();		//卖家模块
	User* users_message;		//用于读取文件中的信息
	User* now_user;				//用于指向当前用户
};
//用户类。
class Buyers :public Users 
{

};
//买家类。
class Sellers :public Users 
{

};
//卖家类。
void Administrator_Module()
{
	system("cls");
	cout << "================================================================================================" << endl;
	cout << "  1.查看所有的商品  2.搜索商品  3.下架商品  4.查看所有订单  5.查看所有用户  6.封禁用户  7.注销" << endl;
	cout << "================================================================================================" << endl;
	cout << "请输入操作：";
	cin >> option;
	
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
		system("cls");
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
		system("cls");
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

}
//买家模块。
void Users::Sellers_Module()
{

}
//卖家模块。
void Main_Menu() 
{
	cout << "====================================================" << endl;
	cout << "  1.管理员登录  2.用户注册  3.用户登录  4.退出程序" << endl;
	cout << "====================================================" << endl;
	cout << "请输入操作：";
}
//主页面菜单。
void Bid_results()
{

}
//竞拍结果。
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
	User* a;
	l:
	cout << "请输入你的姓名：";
	cin >> someone->u_name;
	a = users_message;
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
	fstream outfile("user.txt", ios::app);
	if (!outfile)
	{
		cout << "* * * 很遗憾，用户注册失败！* * *" << endl;
		exit(0);
	}
	if (someone != NULL)
	{
		outfile << someone->u_name << " " << someone->u_phone << " " << someone->u_adress << " " << someone->u_password << " " << someone->u_money << " " << someone->u_state << " ";
		delete someone;
	}
	cout << "* * * 恭喜您，用户注册成功！* * *" << endl;
	delete a;
	outfile.close();
}
//ID分配实现并不完全，对齐方式不明确，信息匹配不完善。		
void  Users::Get_Users_Message()
{
	int i = 0;
	User* p, * q;
	p = new User;
	users_message = new User;
	users_message->next = NULL;
	q = users_message;
	ifstream infile("user.txt", ios::in | ios::binary);
	if (!infile)
	{
		cout << "用户信息文件不存在！" << endl; 
		system("cls");
		exit(0);
	}
	while (!infile.eof())
	{
		infile >> p->u_name >> p->u_phone >> p->u_adress >> p->u_password >> p->u_money >> p->u_state;
		if (infile.fail())
			break;
		p->next = NULL;
		q->next = p;
		q = q->next;
		p = new User;
		i++;
	}
	q->next = NULL;
	if (i == 0) {
		cout << "用户信息为空" << endl;
		system("cls");
	}
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
	p = this->users_message;					
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
	delete p, q;
}
void Users::User_Menu()
{
	system("cls");
	cout << "===================================================" << endl;
	cout << "  1.我是买家 2.我是卖家 3.个人信息管理 4.注销登录" << endl;
	cout << "===================================================" << endl;
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
	cout << "请输入新的用户名：";
	cin >> now_user->u_name;
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
	p = this->users_message->next;
	fstream outfile("user.txt", ios::out);
	if (!outfile)
	{
		cout << "* * * 很遗憾，数据保存失败！* * *" << endl;
		exit(0);
	}
	if (p == NULL)
		outfile << 9;
	while (p != NULL)
	{
	outfile << p->u_name << " " << p->u_phone << " " << p->u_adress << " " << p->u_password << " " << p->u_money << " " << p->u_state << " ";
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

void Administrator::A_menu()
{
	system("cls");
	cout << "================================================================================================" << endl;
	cout << "  1.查看所有的商品  2.搜索商品  3.下架商品  4.查看所有订单  5.查看所有用户  6.封禁用户  7.注销" << endl;
	cout << "================================================================================================" << endl;
	cout << "请输入操作：";
}

int main() {
	while (true)
	{
		system("cls");
		Main_Menu();
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
		case 1:Administrator_Module(); break;
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



