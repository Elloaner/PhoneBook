#include <iostream>
#include <string.h>

using namespace std;

class PhoneBook
{
private:
	char* FullName;
	char HomeNumber[50];
	char WorkNumber[50];
	char MobileNumber[50];
	char AdditionalInformation[50];
public:
	PhoneBook() {}

	PhoneBook(const char* fname, const char* hnumb, const char* wnumb, const char* mnumb, const char* addinf)
	{
		FullName = new char[strlen(fname) + 1];
		strcpy_s(this->FullName, strlen(fname) + 1, fname);
		strcpy_s(HomeNumber, 50, hnumb);
		strcpy_s(WorkNumber, 50, wnumb);
		strcpy_s(MobileNumber, 50, mnumb);
		strcpy_s(AdditionalInformation, 50, addinf);
	}

	~PhoneBook() { delete[] FullName; }

	void FullNameSetter(const char* fname)
	{
		delete[] FullName;
		FullName = new char[strlen(fname + 1)];
		strcpy_s(FullName, strlen(fname) + 1, fname);
	}

	char* FullNameGetter()
	{
		return FullName;
	}

	void HomeNumberSetter(const char* hnum)
	{
		strcpy_s(HomeNumber, 50, hnum);
	}

	void WorkNumberSetter(const char* wnum)
	{
		strcpy_s(WorkNumber, 50, wnum);
	}

	void MobileNumberSetter(const char* mnum)
	{
		strcpy_s(MobileNumber, 50, mnum);
	}

	void AdditionalInformationSetter(const char* addinf)
	{
		strcpy_s(AdditionalInformation, 50, addinf);
	}

	void ShowContact(short number)
	{                                    
		cout << "--------------- " << ++number << " ---------------" << endl;
		cout << "Full name : " << FullName << endl;
		cout << "Home Number : " << HomeNumber << endl;
		cout << "Work Number : " << WorkNumber << endl;
		cout << "Mobile Number : " << MobileNumber << endl;
		cout << "Additional Information : " << AdditionalInformation << endl;
		cout << "--------------------------------" << endl;
	}

};