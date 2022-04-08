#include <iostream>
#include "mainFunction.h"

#include "Struct.h"
#include "IOFunction.h"


int IsExist(AddressBook *p_aBook, string name)
{
	/*查询通讯录中是否存在该姓名，存在则返回对应的元素下标*/
	for (size_t i = 0; i < (*p_aBook).m_addressSize; i++)
	{
		if ((*p_aBook).personArray[i].m_name == name)
		{
			cout << "[info] 存在目标姓名。" << endl;
			return i;//找到，返回目标在数组中的下标。
		}
	}
	return -1;//未找到，返回 -1。
}
void AddPerson(AddressBook *p_aBook)
{
	//判断通讯录是否已经装满
	if ((*p_aBook).m_addressSize >= MAX_PERSON) {
		cout << "[WARN] 通讯录已经装不下啦~" << endl; return;
	}
	else
	{
		//添加具体联系人

		//姓名
		(*p_aBook).personArray[(*p_aBook).m_addressSize].m_name = FetchPersonInfo("name");
		//性别
		int tmp_gender = -1;
		cout << "[hint] 请输入性别：" << endl; //提示输入格式
		cout << "[hint]   1...男" << endl;
		cout << "[hint]   2...女" << endl;
		while (true)
		{//判断是否正确输入性别
			cout << "> 性别：";
			cin >> tmp_gender;
			if (tmp_gender == 1 || tmp_gender == 2) {
				(*p_aBook).personArray[(*p_aBook).m_addressSize].m_gender = tmp_gender; break;
			}
			cout << "[hint] 输入有误，请重试：" << endl;
		}
		//年龄
		int tmp_age = 0;
		cout << "[hint] 请输入年龄："; cin >> tmp_age;
		(*p_aBook).personArray[(*p_aBook).m_addressSize].m_age = tmp_age;
		//联系电话
		(*p_aBook).personArray[(*p_aBook).m_addressSize].m_phone = FetchPersonInfo("phone");
		//地址
		(*p_aBook).personArray[(*p_aBook).m_addressSize].m_address = FetchPersonInfo("address");

		cout << "[info] 添加中...ok!" << endl;
		(*p_aBook).m_addressSize++;
	}

};
void ShowPerson(AddressBook *p_aBook, int id)
{
	//查询数据
	string m_name = (*p_aBook).personArray[id].m_name;
	int m_gender = (*p_aBook).personArray[id].m_gender;
	int m_age = (*p_aBook).personArray[id].m_age;
	string m_phone = (*p_aBook).personArray[id].m_phone;
	string m_address = (*p_aBook).personArray[id].m_address;

	//输出
	cout << "\t" << m_name
		<< "\t" << (m_gender == 1 ? "男" : "女")
		<< "\t" << m_age
		<< "\t" << m_phone
		<< "\t" << m_address << endl;
	cout << "---------------------------------------------------------" << endl;
}
void ShowPersons(AddressBook *p_aBook)
{
	//判断通讯录内容是否为空
	if ((*p_aBook).m_addressSize <= 0) {
		PromptError("没有联系人的记录"); return;
	}

	ShowTable();
	//遍历通讯录里的联系人
	for (size_t i = 0; i < (*p_aBook).m_addressSize; i++)
	{
		ShowPerson(p_aBook, i);
	}
	cout << "\t\t\t\t\t\t总计:" << (*p_aBook).m_addressSize << endl;
	cout << "===========================================================" << endl;
}
void DeletPerson(AddressBook *p_aBook)
{
	int r_isExist = IsExist(p_aBook, GetTargetName("请输入想要删除的联系人姓名："));
	if (r_isExist == -1) {
		PromptError("查无此人"); return;
	}
	else
	{
		/*
		*	若 r_isExist = 2; m_addressSize = 7
		*		0 1 2 3 4 5 6
		*			^
		*	将第 3 个元素复制到第 2 个元素
		*	只需要重复 m_addressSize - 1 次
		*	因为最后一个元素不需要填充
		*/
		PromptMessage("删除中");
		for (size_t i = r_isExist; i < (*p_aBook).m_addressSize - 1; i++)
		{
			//数据前移
			(*p_aBook).personArray[i] = (*p_aBook).personArray[i + 1];
		}
		cout << "...";
		(*p_aBook).m_addressSize--;//更新 通讯录中的人员总数
		cout << "ok" << endl;
	}
}
void SearchPerson(AddressBook *p_aBook)
{
	/*
	 * 根据姓名查找是否存在，
	 * 不存在则警告用户
	 * 存在则返回元素下标用以输出
	*/
	int r_isExist = IsExist(p_aBook, GetTargetName("请输入查找的联系人姓名："));
	if (r_isExist == -1)
	{
		PromptError("查无此人!");
	}
	else
	{
		ShowTable();
		ShowPerson(p_aBook, r_isExist);
	}
}
void ModifyPerson(AddressBook *p_aBook)
{
	/*查找到目标联系人
	*	不存在则警告并退出
	*	存在则进入修改项目菜单
	*/
	int r_isExist = IsExist(p_aBook, GetTargetName("请输入想要修改的联系人姓名："));
	if (r_isExist == -1)
	{
		PromptError("查无此人!"); return;
	}

	/*修改联系人信息*/
	while (true)
	{
		system("cls");//清屏
		ShowModifyMean();//弹出修改项目菜单
		switch (GetUserSelection("请输入修改类型的编号："))
		{
		case 1://1. 姓名
			(*p_aBook).personArray[r_isExist].m_name = FetchPersonInfo("name");
			break;
		case 2://2. 性别
		{
			int tmp_gender = -1;
			cout << "[hint] 请输入性别：" << endl; //提示输入格式
			cout << "[hint]   1...男" << endl;
			cout << "[hint]   2...女" << endl;
			while (true)
			{//判断是否正确输入性别
				cout << "> 性别：";
				cin >> tmp_gender;
				if (tmp_gender == 1 || tmp_gender == 2) {
					(*p_aBook).personArray[r_isExist].m_gender = tmp_gender; break;
				}
				cout << "[hint] 输入有误，请重试：" << endl;
			}
		}
		break;
		case 3://3. 年龄
		{
			int tmp_age = 0;
			cout << "[hint] 请输入年龄："; cin >> tmp_age;
			(*p_aBook).personArray[r_isExist].m_age = tmp_age;
		}
		break;
		case 4://4. 电话
			(*p_aBook).personArray[r_isExist].m_phone = FetchPersonInfo("phone");
			break;
		case 5://5. 住址
			(*p_aBook).personArray[r_isExist].m_address = FetchPersonInfo("address");
			break;
		case 0:
			PromptMessage("退出修改联系人功能。"); return;
		default:
			PromptError("请输入正确的功能选项。");
			break;
		}
	}
}
void CleanPersons(AddressBook *p_aBook)
{
	PromptMessage("确认清空所有联系人吗？");
	cout << "确认则输入1，取消则输入0：";
	int confirm = 0;
	cin >> confirm;
	if (confirm)
	{
		(*p_aBook).m_addressSize = 0;
		PromptMessage("已全部清空！");
	}
}