#pragma once
#include "phonebook.h"

using namespace std;

class Contacts
{
private:
	PhoneBook* contacts;
	int quantity;
	int size;
public:
	Contacts(int q = 50)
	{
		contacts = new PhoneBook[q];
		this->quantity = q;
		size = 0;
	}
	~Contacts() { delete[] contacts; }
	
	void AddContact(const PhoneBook& contact)
	{
		if (size < quantity)
		{
			contacts[size++] = contact;
		}
		else
		{
			int tmpQuantity = quantity * 2;
			PhoneBook* tmpContact = new PhoneBook[tmpQuantity];
			for (int i = 0; i < size; i++)
			{
				tmpContact[i] = contacts[i];
			}
			delete[] contacts; contacts = tmpContact;
			quantity = tmpQuantity; contacts[size++] = contact;
		}
	}

	void DeleteContact(int num)
	{
		if (num >= 0 && num < size)
		{
			PhoneBook* tmpContact = new PhoneBook[size - 1];
			for (int i = 0, j = 0; i < size; i++)
			{
				if (i != num)
				{
					tmpContact[j++] = contacts[i];
				}
			}
			delete[] contacts;
			contacts = tmpContact;
			size--;
		}
	}

	void ShowAllContacts()
	{
		for (int i = 0; i < size; i++)
		{
			contacts[i].ShowContact(i);
		}
	}

	void SearchContact(const char* FullName)
	{
		for (int i = 0; i < size; i++)
		{
			if (strcmp(contacts[i].FullNameGetter(), FullName) == 0)
			{
				contacts[i].ShowContact(i);
			}
		}
	}
};