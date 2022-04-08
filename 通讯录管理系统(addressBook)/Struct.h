#pragma once
using namespace std;
#define MAX_PERSON 1000

struct Person
{
	/*
		联系人结构体
		包含 姓名、性别、年龄、联系电话、地址
	*/
	string m_name;
	int m_gender;//1:男 2:女
	int m_age;
	string m_phone;
	string m_address;
};
struct AddressBook
{
	/*
		通讯录结构体
		包含 联系人数组、当前包含联系人个数
	*/
	Person personArray[MAX_PERSON];
	int m_addressSize;
};
