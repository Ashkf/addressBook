#include <iostream>
#include "mainFunction.h"

#include "Struct.h"
#include "IOFunction.h"


int IsExist(AddressBook *p_aBook, string name)
{
	/*��ѯͨѶ¼���Ƿ���ڸ������������򷵻ض�Ӧ��Ԫ���±�*/
	for (size_t i = 0; i < (*p_aBook).m_addressSize; i++)
	{
		if ((*p_aBook).personArray[i].m_name == name)
		{
			cout << "[info] ����Ŀ��������" << endl;
			return i;//�ҵ�������Ŀ���������е��±ꡣ
		}
	}
	return -1;//δ�ҵ������� -1��
}
void AddPerson(AddressBook *p_aBook)
{
	//�ж�ͨѶ¼�Ƿ��Ѿ�װ��
	if ((*p_aBook).m_addressSize >= MAX_PERSON) {
		cout << "[WARN] ͨѶ¼�Ѿ�װ������~" << endl; return;
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		(*p_aBook).personArray[(*p_aBook).m_addressSize].m_name = FetchPersonInfo("name");
		//�Ա�
		int tmp_gender = -1;
		cout << "[hint] �������Ա�" << endl; //��ʾ�����ʽ
		cout << "[hint]   1...��" << endl;
		cout << "[hint]   2...Ů" << endl;
		while (true)
		{//�ж��Ƿ���ȷ�����Ա�
			cout << "> �Ա�";
			cin >> tmp_gender;
			if (tmp_gender == 1 || tmp_gender == 2) {
				(*p_aBook).personArray[(*p_aBook).m_addressSize].m_gender = tmp_gender; break;
			}
			cout << "[hint] �������������ԣ�" << endl;
		}
		//����
		int tmp_age = 0;
		cout << "[hint] ���������䣺"; cin >> tmp_age;
		(*p_aBook).personArray[(*p_aBook).m_addressSize].m_age = tmp_age;
		//��ϵ�绰
		(*p_aBook).personArray[(*p_aBook).m_addressSize].m_phone = FetchPersonInfo("phone");
		//��ַ
		(*p_aBook).personArray[(*p_aBook).m_addressSize].m_address = FetchPersonInfo("address");

		cout << "[info] �����...ok!" << endl;
		(*p_aBook).m_addressSize++;
	}

};
void ShowPerson(AddressBook *p_aBook, int id)
{
	//��ѯ����
	string m_name = (*p_aBook).personArray[id].m_name;
	int m_gender = (*p_aBook).personArray[id].m_gender;
	int m_age = (*p_aBook).personArray[id].m_age;
	string m_phone = (*p_aBook).personArray[id].m_phone;
	string m_address = (*p_aBook).personArray[id].m_address;

	//���
	cout << "\t" << m_name
		<< "\t" << (m_gender == 1 ? "��" : "Ů")
		<< "\t" << m_age
		<< "\t" << m_phone
		<< "\t" << m_address << endl;
	cout << "---------------------------------------------------------" << endl;
}
void ShowPersons(AddressBook *p_aBook)
{
	//�ж�ͨѶ¼�����Ƿ�Ϊ��
	if ((*p_aBook).m_addressSize <= 0) {
		PromptError("û����ϵ�˵ļ�¼"); return;
	}

	ShowTable();
	//����ͨѶ¼�����ϵ��
	for (size_t i = 0; i < (*p_aBook).m_addressSize; i++)
	{
		ShowPerson(p_aBook, i);
	}
	cout << "\t\t\t\t\t\t�ܼ�:" << (*p_aBook).m_addressSize << endl;
	cout << "===========================================================" << endl;
}
void DeletPerson(AddressBook *p_aBook)
{
	int r_isExist = IsExist(p_aBook, GetTargetName("��������Ҫɾ������ϵ��������"));
	if (r_isExist == -1) {
		PromptError("���޴���"); return;
	}
	else
	{
		/*
		*	�� r_isExist = 2; m_addressSize = 7
		*		0 1 2 3 4 5 6
		*			^
		*	���� 3 ��Ԫ�ظ��Ƶ��� 2 ��Ԫ��
		*	ֻ��Ҫ�ظ� m_addressSize - 1 ��
		*	��Ϊ���һ��Ԫ�ز���Ҫ���
		*/
		PromptMessage("ɾ����");
		for (size_t i = r_isExist; i < (*p_aBook).m_addressSize - 1; i++)
		{
			//����ǰ��
			(*p_aBook).personArray[i] = (*p_aBook).personArray[i + 1];
		}
		cout << "...";
		(*p_aBook).m_addressSize--;//���� ͨѶ¼�е���Ա����
		cout << "ok" << endl;
	}
}
void SearchPerson(AddressBook *p_aBook)
{
	/*
	 * �������������Ƿ���ڣ�
	 * �������򾯸��û�
	 * �����򷵻�Ԫ���±��������
	*/
	int r_isExist = IsExist(p_aBook, GetTargetName("��������ҵ���ϵ��������"));
	if (r_isExist == -1)
	{
		PromptError("���޴���!");
	}
	else
	{
		ShowTable();
		ShowPerson(p_aBook, r_isExist);
	}
}
void ModifyPerson(AddressBook *p_aBook)
{
	/*���ҵ�Ŀ����ϵ��
	*	�������򾯸沢�˳�
	*	����������޸���Ŀ�˵�
	*/
	int r_isExist = IsExist(p_aBook, GetTargetName("��������Ҫ�޸ĵ���ϵ��������"));
	if (r_isExist == -1)
	{
		PromptError("���޴���!"); return;
	}

	/*�޸���ϵ����Ϣ*/
	while (true)
	{
		system("cls");//����
		ShowModifyMean();//�����޸���Ŀ�˵�
		switch (GetUserSelection("�������޸����͵ı�ţ�"))
		{
		case 1://1. ����
			(*p_aBook).personArray[r_isExist].m_name = FetchPersonInfo("name");
			break;
		case 2://2. �Ա�
		{
			int tmp_gender = -1;
			cout << "[hint] �������Ա�" << endl; //��ʾ�����ʽ
			cout << "[hint]   1...��" << endl;
			cout << "[hint]   2...Ů" << endl;
			while (true)
			{//�ж��Ƿ���ȷ�����Ա�
				cout << "> �Ա�";
				cin >> tmp_gender;
				if (tmp_gender == 1 || tmp_gender == 2) {
					(*p_aBook).personArray[r_isExist].m_gender = tmp_gender; break;
				}
				cout << "[hint] �������������ԣ�" << endl;
			}
		}
		break;
		case 3://3. ����
		{
			int tmp_age = 0;
			cout << "[hint] ���������䣺"; cin >> tmp_age;
			(*p_aBook).personArray[r_isExist].m_age = tmp_age;
		}
		break;
		case 4://4. �绰
			(*p_aBook).personArray[r_isExist].m_phone = FetchPersonInfo("phone");
			break;
		case 5://5. סַ
			(*p_aBook).personArray[r_isExist].m_address = FetchPersonInfo("address");
			break;
		case 0:
			PromptMessage("�˳��޸���ϵ�˹��ܡ�"); return;
		default:
			PromptError("��������ȷ�Ĺ���ѡ�");
			break;
		}
	}
}
void CleanPersons(AddressBook *p_aBook)
{
	PromptMessage("ȷ�����������ϵ����");
	cout << "ȷ��������1��ȡ��������0��";
	int confirm = 0;
	cin >> confirm;
	if (confirm)
	{
		(*p_aBook).m_addressSize = 0;
		PromptMessage("��ȫ����գ�");
	}
}