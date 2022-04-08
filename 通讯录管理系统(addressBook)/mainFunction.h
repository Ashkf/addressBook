#pragma once
#include "Struct.h"

int IsExist(AddressBook *p_aBook, string name);
void AddPerson(AddressBook *p_aBook);
void ShowPerson(AddressBook *p_aBook, int id);
void ShowPersons(AddressBook *p_aBook);
void DeletPerson(AddressBook *p_aBook);
void SearchPerson(AddressBook *p_aBook);
void ModifyPerson(AddressBook *p_aBook);
void CleanPersons(AddressBook *p_aBook);

