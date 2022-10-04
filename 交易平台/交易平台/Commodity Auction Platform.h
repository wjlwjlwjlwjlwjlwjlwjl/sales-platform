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
	char u_state = '1';				//用户的状态
	char u_id[5] = { 'U' };			//用户的ID
	char u_name[11] = { '0' };		//用户的名字
	char u_phone[21] = { '0' };		//用户的电话
	char u_money[100] = { '0' };	//用户的余额
	char u_adress[41] = { '0' };	//用户的地址
	char u_password[21] = { '0' };	//用户的密码
	char u_bid[100] = { '0' };		//用户出价
	User* next;						//用于创建存储文件中用户信息的链表
	int cnt = 1;					//用于给用户分配ID
};
//定义用户结构，用于存储用户的信息。
struct Good {
	char g_state = '1';				//商品的状态，1表示在售；2表示已售空；3表示下架；
	char g_id[5] = { 'M' };			//商品的ID
	char g_name[21] = { '0' };		//商品名称
	char g_price[100] = { '0' };	//商品的底价
	char g_time[20] = { '0' };		//商品上架的时间
	char g_seller[5] = { 'U' };		//商品卖家的ID
	char g_number[20] = { '0' };	//商品的余量
	char g_message[201] = { '0' };	//商品信息	
	char g_progress[20] = { '0' };	//商品的竞拍进程（24小时结束）
	Good* next;						//用于创建存储文件中商品信息的链表
	int cnt = 1;					//用于给商品分配ID
};
//定义商品的结构，存储商品的信息。
struct Order {
	char o_id[5] = { 'T' };			//订单ID
	char good_id[5] = { 'M' };		//商品ID
	char o_price[100] = { '0' };	//订单价格
	char o_time[20] = { '0' };		//订单时间
	char o_number[20] = { '0' };	//订单数量
	char seller_id[5] = { 'U' };	//卖家ID
	char buyer_id[5] = { 'U' };		//买家ID
	Order* next;					//用于创建存储文件中订单信息的链表
	int cnt = 1;					//用于给订单分配ID
};
//定义订单的结构，存储订单的信息。
struct Message
{
	char content[30] = { '0' };		//信息的内容
	char nowtime[20] = { '0' };		//信息的时间
	char name[11] = { '0' };		//发信息的人
	Message* next;					//下一条信息
};
//定义消息的结构，用于创建拍卖群消息链表，存储聊天信息

class Auction_group
{
public:
	void Send_Message();			//发送信息
	void Withdraw_Message();		//规定用户只能撤回2分钟内的信息
	void Assign_Goods();			//根据拍卖结果分配商品并扣除相关金额
	void Display_History_Message();	//显示历史信息
	void Store_Message();			//存储信息
	void Join_Group_Menu();			//拍卖群主页面
	Message* start;					//信息头
	Message* end;					//信息尾
	Message* now;					//当前信息
	User* nowuser;					//当前用户
};



class Users//:public Sellers,public Buyers
{
public:
	bool User_login();			//用户登录
	void User_sign_up();		//用户注册	
	void Search_message();		//查看信息
	void Change_message();		//修改信息
	void Change_adress();		//修改收货地址
	void Change_password();		//修改登录密码
	void Change_name();			//修改用户名
	void Change_phone();		//修改手机号
	void Add_money();			//充值
	void Change_bid();			//修改报价
	void Cancel_bid();			//取消报价
	void Get_Users_Message();   //从user文件中获取信息
	void Update_message();		//更新文件中的信息
	void User_Menu();			//用户功能菜单
	void Information_Module();	//信息模块
	void Buyers_Module();		//买家模块
	void Sellers_Module();		//卖家模块
	User* users_begin;		//用于读取文件中的信息
	User* users_end;		//用于读取文件中的信息
	User* now_user;				//用于指向当前用户
};
//用户类。



class Administrator:public Auction_group
{
public:
	void all_goods();				//查看所有的商品
	void search_goods();			//搜索商品
	void remove_goods();			//下架商品
	void all_orders();				//查看所有订单
	void all_users();				//查看所有用户
	void ban_user();				//封禁用户
	void Achieve_Goods_Message();	//获取商品信息
	void Updata_Goods();			//更新商品信息
	void Achieve_Users_Message();	//获取用户信息
	void Updata_Users();			//更新用户信息
	void Delete_Message();			//删除信息
	Good* a_goods_begin;				//商品开始
	Good* a_goods_end;				//商品结束
	User* a_users_begin;				//用户开始
	User* a_users_end;				//用户结束
	char a_name[11];
	char a_password[21];
};
//管理员类。
class Buyers :public Users,public Auction_group
{
public:
	void Search_all_Goods();			//查看商品列表
	void Bid_Good();					//购买商品
	void Search_Good();					//搜索商品
	void Good_Message();				//查看商品详细信息
	void B_Histroy_Orders();			//查看历史订单
	void Get_Goods_Message();			//从good文件中获取信息
	void Get_Orders_Message();			//从order文件中获取信息
	User* user_buyer;					//指出当前买家用户
	Good* goods_message_buyer_begin;	//读取商品信息
	Good* goods_message_buyer_end;		//读取商品信息
	Good* now_good;						//读取商品信息
	Order* orders_message_buyer;		//读取订单信息
};
//买家类。
class Sellers :public Users,public Auction_group
{
public:
	void List_Good(User* p);		//发布商品
	void Listed_Good(User* w);	//查看发布商品
	void Change_Good_Message();	//修改商品信息
	void Remove_Good(User*p);			//下架商品
	void S_Histroy_Orders();		//查看历史订单
	void Get_Goods_Message();			//从good文件中获取信息
	void Get_Orders_Message();			//从order文件中获取信息
	void Updata_Goods_Message();		//更新文件中的商品信息
	User* user_seller;					//指出卖家用户
	Good* goods_message_seller_begin;	//读取商品信息
	Good* goods_message_seller_end;		//读取商品信息
	Good* now_good;						//指向当前商品
	Order* orders_message_seller;		//读取商品信息
};
//卖家类。


/*
void xy(int y, int x)
{
	COORD  coord;
	coord.X = x;
	coord.Y = y;
	HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(a, coord);
}*/