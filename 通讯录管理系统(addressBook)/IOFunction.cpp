#include "IOFunction.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void ShowMean()
{
	/*
		======================
		----ͨѶ¼����ϵͳ----
		======================
		> 1. �����ϵ��
		> 2. ��ʾ��ϵ��
		> 3. ɾ����ϵ��
		> 4. ������ϵ��
		> 5. �޸���ϵ��
		> 6. �����ϵ��
		> 0. �˳�ϵͳ
		======================
		============ V0.1.0 ==
	*/
	cout << "======================" << endl;
	cout << "----ͨѶ¼����ϵͳ----" << endl;
	cout << "======================" << endl;
	cout << "> 1. �����ϵ��" << endl;
	cout << "> 2. ��ʾ��ϵ��" << endl;
	cout << "> 3. ɾ����ϵ��" << endl;
	cout << "> 4. ������ϵ��" << endl;
	cout << "> 5. �޸���ϵ��" << endl;
	cout << "> 6. �����ϵ��" << endl;
	cout << "> 0. �˳�ϵͳ" << endl;
	cout << "======================" << endl;
	cout << "============ V0.1.0 ==" << endl;
}
void ShowTable()
{
	system("cls");
	cout << "=========================��ǰ��ϵ��========================" << endl;
	cout << "\t" << "����" << "\t" << "�Ա�"
		<< "\t" << "����" << "\t" << "�绰"
		<< "\t\t" << "סַ" << endl;
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
	/*IO��ȡ����������*/
	cout << "[hint] " << hint << endl;
	cout << "> ������";
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
	cout << "----�޸���ϵ����Ϣ----" << endl;
	cout << "----------------------" << endl;
	cout << "> 1. ����" << endl;
	cout << "> 2. �Ա�" << endl;
	cout << "> 3. ����" << endl;
	cout << "> 4. �绰" << endl;
	cout << "> 5. סַ" << endl;
	cout << "> 0. �˳�" << endl;
	cout << "----------------------" << endl;
}
string FetchPersonInfo(string inpute_type)
{
	if (inpute_type == "name")
	{
		string tmp_name = "NULL";
		cout << "[hint] ������������"; cin >> tmp_name;
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
		cout << "[hint] ��������ϵ�绰��"; cin >> tmp_phone;
		return tmp_phone;
	}
	if (inpute_type == "address")
	{
		string tmp_address = "NULL";
		cout << "[hint] �������ַ��"; cin >> tmp_address;
		return tmp_address;
	}
}