#pragma once
using namespace std;
#define MAX_PERSON 1000

struct Person
{
	/*
		��ϵ�˽ṹ��
		���� �������Ա����䡢��ϵ�绰����ַ
	*/
	string m_name;
	int m_gender;//1:�� 2:Ů
	int m_age;
	string m_phone;
	string m_address;
};
struct AddressBook
{
	/*
		ͨѶ¼�ṹ��
		���� ��ϵ�����顢��ǰ������ϵ�˸���
	*/
	Person personArray[MAX_PERSON];
	int m_addressSize;
};
