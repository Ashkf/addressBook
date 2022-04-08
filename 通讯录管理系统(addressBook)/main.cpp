#include <iostream>
#include <string>
#include <cstdlib>
#include "Struct.h"
#include "IOFunction.h"
#include "mainFunction.h"
using namespace std;

int main()
{
	/*初始化通讯录*/
	AddressBook addressBook;
	addressBook.m_addressSize = 0;
	/*主程序*/
	while (true)
	{
		/*显示菜单*/
		ShowMean();
		/*根据用户输入采用相应功能模块*/
		switch (GetUserSelection("请输入功能编号："))
		{
		case 1:		//1. 添加联系人
			AddPerson(&addressBook);
			break;
		case 2:		//2. 显示所有联系人
			ShowPersons(&addressBook);
			break;
		case 3:		//3. 删除联系人
			DeletPerson(&addressBook);
			break;
		case 4:		//4. 查找联系人
			SearchPerson(&addressBook);
			break;
		case 5:		//5. 修改联系人
			ModifyPerson(&addressBook);
			break;
		case 6:		//6. 清空联系人
			CleanPersons(&addressBook);
			break;
		case 0:		//0. 退出系统
			PromptMessage("欢迎下次使用。"); return 0;
			break;
		default:	//错误提示
			PromptError("请输入正确的功能选项。");
			break;
		}
		/*暂停然后清屏*/
		system("pause");
		system("cls");
	}
}
