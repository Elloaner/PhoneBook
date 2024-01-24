#include "phonebook.h"
#include "Contacts.h"

using namespace std;

int main()
{
    Contacts phonebook(20);
    short select{};
    PhoneBook Alex;
    Alex.FullNameSetter("Alex Miller");
    Alex.HomeNumberSetter("963-825");
    Alex.WorkNumberSetter("088-247-155-121");
    Alex.MobileNumberSetter("044-927-825-051");
    Alex.AdditionalInformationSetter("Friend");

    do
    {
        system("cls");
        cout << "\t\tSelect operation :" << endl;
        cout << "1 - Add new contact" << endl;
        cout << "2 - Delete contact" << endl;
        cout << "3 - Search contact" << endl;
        cout << "4 - Show all contacts" << endl;
        cout << "5 - Exit" << endl;
        cin >> select;
        system("cls");

        if (select == 1)
        {
            char FullName[50]{}, HomeNumber[50]{}, WorkNumber[50]{}, MobileNumber[50], AdditionalInformation[50]{};
            cout << "Enter full name : ";
            cin >> FullName;
            cout << "Enter home number : ";
            cin >> HomeNumber;
            cout << "Enter work number : ";
            cin >> WorkNumber;
            cout << "Enter mobile number : ";
            cin >> MobileNumber;
            cout << "Enter additional information : ";
            cin >> AdditionalInformation;
            PhoneBook contact{ FullName, HomeNumber, WorkNumber, MobileNumber, AdditionalInformation };
            phonebook.AddContact(contact);
        }
        else if (select == 2)
        {
            cout << "Enter index of contact you want to delete : ";
            int index{};
            cin >> index;
            phonebook.DeleteContact(index);
        }
        else if (select == 3)
        {
            cout << "Enter full name to search contact : ";
            char fullname[50];
            cin >> fullname;
            phonebook.SearchContact(fullname);
        }
        else if (select == 4)
        {
            phonebook.ShowAllContacts();
        }

    } while (select != 5);

    return 0;
}
