#pragma once
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string DEFAULT_PROFILE = "undefined";

class TelephoneBookException {};

class TelephoneBook
{
	map < string, vector <string> > book;
	vector <vector <string>> otherContacts;
public:
	void addContact(string surname, string phoneNumber, string profile = DEFAULT_PROFILE);
	string findContactNumbers(string surname);
	void showContact(string surname);
	void removeContact(string surname, string phoneNumber);
	void clear();
	bool isContactInBook(string surname);
	void changeContactNumber(string surname, string prevPhoneNumber, string phoneNumber);
	void changeContactProfile(string surname, string phoneNumber, string profile);
	void removeContactProfile(string surname, string phoneNumber);
	void addProfileToContact(string surname, string phoneNumber, string profile);
	void upload(string filename);
};