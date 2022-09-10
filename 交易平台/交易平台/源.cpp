#include<iostream>
#include<fstream>
using namespace std;

int select;

struct User {
	bool u_state = true;		//用户的状态
	char u_id[5] = { 'U' };		//用户的ID
	char u_name[11];			//用户的名字
	char u_phone[21];			//用户的电话
	double u_money = 0;			//用户的余额
	char u_adress[41];			//用户的地址
	char u_password[21];		//用户的密码
	double u_bid = 0;			//用户出价

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
	void User_login();			//用户登录
	void User_sign_up(bool &flage);		//用户注册				//部分完成
	bool Buyer_or_Seller();		//选择自己是买家还是卖家
	void Change_adress();		//修改收货地址
	void Change_password();		//修改登录密码
	void Change_name();			//修改用户名
	void Change_phone();		//修改手机号
	void Search_money();		//检查余额
	void Add_money();			//充值
	void Change_bid();			//修改报价
	void Cancel_bid();			//取消报价
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
	cin >> select;
	
}
//管理员模块。
void Users_Module(int st)
{
	bool flage = 0;
	Users user;
	if (st == 2)
	{
		user.User_sign_up(flage);
		if (flage)
			cout << "* * * 恭喜你，账号注册成功！* * *";
		else
			cout << "* * * 很抱歉，账号创建失败！* * *";
	}
	else
	{

	}
}
//用户模块。
void Buyers_Module()
{

}
//买家模块。
void Sellers_Module()
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

void Users::User_sign_up(bool &flage)
{
	User someone;
	ofstream outfile;
	outfile.open("C:/Users/2931582547/Desktop/my program/user.txt", ios::app);
	outfile << endl;
	cout << "请输入你的姓名：";
	cin >> someone.u_name;
	cout << "请输入你的电话号码：";
	cin >> someone.u_phone;
	cout << "请输入你的地址：";
	cin >> someone.u_adress;
	cout << "请创建你的密码：";
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
		outfile << "正常"<<"       ";
	else
		outfile << "异常"<<"       ";
	outfile << "*" << someone.u_password;
	outfile.close();
	flage = 1;
}
//ID分配实现并不完全，对齐方式不明确，信息匹配不完善。

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
		cin >> select;
		while (cin.fail()) 
		{
			cerr << "输入错误，请重新输入：";
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
//比较完善。