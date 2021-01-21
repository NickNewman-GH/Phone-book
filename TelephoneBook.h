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
public:
	void addContact(string surname, string phoneNumber, string profile = DEFAULT_PROFILE);
	string findContactNumber(string surname);
	void showContact(string surname);
	void removeContact(string surname);
	void clear();
	bool isContactInBook(string surname);
	void changeContactNumber(string surname, string phoneNumber);
	void changeContactProfile(string surname, string profile);
	void removeContactProfile(string surname);
	void addProfileToContact(string surname, string profile);
	void upload(string filename);
};