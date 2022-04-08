#include "IOFunction.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void ShowMean()
{
	/*
		======================
		----通讯录管理系统----
		======================
		> 1. 添加联系人
		> 2. 显示联系人
		> 3. 删除联系人
		> 4. 查找联系人
		> 5. 修改联系人
		> 6. 清空联系人
		> 0. 退出系统
		======================
		============ V0.1.0 ==
	*/
	cout << "======================" << endl;
	cout << "----通讯录管理系统----" << endl;
	cout << "======================" << endl;
	cout << "> 1. 添加联系人" << endl;
	cout << "> 2. 显示联系人" << endl;
	cout << "> 3. 删除联系人" << endl;
	cout << "> 4. 查找联系人" << endl;
	cout << "> 5. 修改联系人" << endl;
	cout << "> 6. 清空联系人" << endl;
	cout << "> 0. 退出系统" << endl;
	cout << "======================" << endl;
	cout << "============ V0.1.0 ==" << endl;
}
void ShowTable()
{
	system("cls");
	cout << "=========================当前联系人========================" << endl;
	cout << "\t" << "姓名" << "\t" << "性别"
		<< "\t" << "年龄" << "\t" << "电话"
		<< "\t\t" << "住址" << endl;
	cout << "---------------------------------------------------------" << endl;
}
int GetUserSelection(string hint)
{
	int selection = 0;
	cout << "[hint] " << hint;
	cin >> selection;
	return selection;
}
string GetTargetName(string hint)
{
	string name;
	/*IO获取查找人姓名*/
	cout << "[hint] " << hint << endl;
	cout << "> 姓名：";
	cin >> name;
	return name;
}
void PromptError(string info)
{
	cout << "[WARN] " << info << endl;
	return;
}
void PromptMessage(string hint)
{
	cout << "[info] " << hint << endl;
}
void ShowModifyMean()
{
	cout << "----------------------" << endl;
	cout << "----修改联系人信息----" << endl;
	cout << "----------------------" << endl;
	cout << "> 1. 姓名" << endl;
	cout << "> 2. 性别" << endl;
	cout << "> 3. 年龄" << endl;
	cout << "> 4. 电话" << endl;
	cout << "> 5. 住址" << endl;
	cout << "> 0. 退出" << endl;
	cout << "----------------------" << endl;
}
string FetchPersonInfo(string inpute_type)
{
	if (inpute_type == "name")
	{
		string tmp_name = "NULL";
		cout << "[hint] 请输入姓名："; cin >> tmp_name;
		return tmp_name;
	}
	if (inpute_type == "gender")
	{
	}
	if (inpute_type == "age")
	{
	}
	if (inpute_type == "phone")
	{
		string tmp_phone = "NULL";
		cout << "[hint] 请输入联系电话："; cin >> tmp_phone;
		return tmp_phone;
	}
	if (inpute_type == "address")
	{
		string tmp_address = "NULL";
		cout << "[hint] 请输入地址："; cin >> tmp_address;
		return tmp_address;
	}
}