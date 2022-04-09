# APIs

## A: mainFunction

### A0: int IsExist(AddressBook *p_aBook, string name)

功能：检查通讯录中是否存在某个联系人。

参数：传入参数为`通讯录指针`和`联系人姓名`。

返回：存在则返回对应联系人的元素下标，不存在则返回`-1`。

### A1: void AddPerson(AddressBook*p_aBook)

功能：向通讯录中增加联系人。

参数：传入参数为`通讯录指针`。

返回：无返回。

描述：开启添加联系人工作流程。

+ 判断通讯录是否装满
  + 是: 警告
  + 否：
    + 添加联系人的姓名、性别、年龄、联系电话、地址

### A2: void ShowPerson(AddressBook *p_aBook, int id)

功能：向控制台输出一位联系人的信息。

参数：传入参数为`通讯录指针`和联系人在通讯录中`personArray` 数组中的下标。

返回：无返回。

描述：先查询，再输出。

### A3: void ShowPersons(AddressBook*p_aBook)

功能：向控制台输出**所有**联系人的信息。

参数：传入参数为`通讯录指针`。

返回：无返回。

描述：先判断通讯录是否为空，在输出。

### A4: void DeletPerson(AddressBook *p_aBook)

功能：删除通讯录中某位联系人信息。

参数：传入参数为`通讯录指针`。

返回：无返回。

描述：先查询是否存在该联系人，查到后将此联系人之后的元素统一前移一位。

### A5: void SearchPerson(AddressBook*p_aBook)

功能：查找并向控制台输出一位联系人的信息。

参数：传入参数为`通讯录指针`。

返回：无返回。

描述：先查询，再输出。

### A6: void ModifyPerson(AddressBook *p_aBook)

功能：修改某位联系人的信息。

参数：传入参数为`通讯录指针`。

返回：无返回。

描述：

+ 先查询是否存在该位联系人
  + 不存在：警告查无此人
  + 存在：弹出联系人信息类型菜单

### A7: void CleanPersons(AddressBook*p_aBook)

功能：逻辑清空通讯录。

参数：传入参数为`通讯录指针`。

返回：无返回。

描述：通讯录的 `m_addressSize` 属性归0。

## B: IOFunction

### B1: void ShowMean()

### B2: void ShowModifyMean()

### B3: string FetchPersonInfo(string)

### B4: void ShowTable()

### B5: string GetTargetName(string)

### B6: void PromptError(string)

### B7: int GetUserSelection(string)

### B8: void PromptMessage(string)
