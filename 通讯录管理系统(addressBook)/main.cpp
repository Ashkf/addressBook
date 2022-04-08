#include <iostream>
#include <string>
#include <cstdlib>
#include "Struct.h"
#include "IOFunction.h"
#include "mainFunction.h"
using namespace std;

int main()
{
	/*��ʼ��ͨѶ¼*/
	AddressBook addressBook;
	addressBook.m_addressSize = 0;
	/*������*/
	while (true)
	{
		/*��ʾ�˵�*/
		ShowMean();
		/*�����û����������Ӧ����ģ��*/
		switch (GetUserSelection("�����빦�ܱ�ţ�"))
		{
		case 1:		//1. �����ϵ��
			AddPerson(&addressBook);
			break;
		case 2:		//2. ��ʾ������ϵ��
			ShowPersons(&addressBook);
			break;
		case 3:		//3. ɾ����ϵ��
			DeletPerson(&addressBook);
			break;
		case 4:		//4. ������ϵ��
			SearchPerson(&addressBook);
			break;
		case 5:		//5. �޸���ϵ��
			ModifyPerson(&addressBook);
			break;
		case 6:		//6. �����ϵ��
			CleanPersons(&addressBook);
			break;
		case 0:		//0. �˳�ϵͳ
			PromptMessage("��ӭ�´�ʹ�á�"); return 0;
			break;
		default:	//������ʾ
			PromptError("��������ȷ�Ĺ���ѡ�");
			break;
		}
		/*��ͣȻ������*/
		system("pause");
		system("cls");
	}
}
