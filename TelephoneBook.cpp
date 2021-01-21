#include "TelephoneBook.h"

//bool phoneCheck(string phoneNumber) {
//
//}

//Добавление контакта

void TelephoneBook::addContact(string surname, string phoneNumber, string profile) {

	//--TODO--
	//phoneCheck(phoneNumber);

	vector <string> phoneAndProfile;

	if (profile == "undefined") {
		phoneAndProfile = { phoneNumber };
	}
	else {
		phoneAndProfile = { phoneNumber,profile };
	}

	book[surname] = phoneAndProfile;
}

//Найти номер контакта по имени контакта

string TelephoneBook::findContactNumber(string surname) {

	map <string, vector <string>> ::iterator it = book.find(surname);

	if (it == book.end()) {
		cout << "Contact '" << surname << "' is not found\n";
		return "undefined";
	}
	else {
		return it->second[0];
	}
}

//Вывести информацию о контакте консоль

void TelephoneBook::showContact(string surname) {
	map <string, vector <string>> ::iterator it = book.find(surname);
	if (it == book.end()) {
		throw TelephoneBookException{};
	}
	else if (it->second.size() > 1){
		cout << "Contact name: " << it->first << "\nThis person is: " << it->second[1] << "\nPhone number: " << it->second[0] << "\n";
	}
	else {
		cout << "Contact name: " << it->first << "\nPhone number: " << it->second[0] << "\n";
	}
}

//Удалить контакт

void TelephoneBook::removeContact(string surname) {

	map <string, vector <string>> ::iterator it = book.find(surname);

	if (it == book.end()) {
		throw TelephoneBookException{};
	}
	else {
		book.erase(it);
	}
}

//Полностью очистить книгу

void TelephoneBook::clear() {

	map <string, vector <string>> ::iterator it;

	for (int i = book.size(); i != 0; i--) {
		it = book.begin();
		book.erase(it);
	}
}

//Проверить, есть ли контакт в книге

bool TelephoneBook::isContactInBook(string surname) {

	map <string, vector <string>> ::iterator it = book.find(surname);

	if (it == book.end()) {
		return false;
	}
	else {
		return true;
	}
}

//Изменить номер контакта

void TelephoneBook::changeContactNumber(string surname, string phoneNumber) {
	
	//--TODO--
	//phoneCheck(phoneNumber);

	map <string, vector <string>> ::iterator it = book.find(surname);

	if (it == book.end()) {
		throw TelephoneBookException{};
	}
	else {
		it->second[0] = phoneNumber;
	}
}

//Изменить доп. информацию (то, кем этот человек тебе приходится)

void TelephoneBook::changeContactProfile(string surname, string profile) {

	map <string, vector <string>> ::iterator it = book.find(surname);

	if (it == book.end()) {
		throw TelephoneBookException{};
	}
	else if (it->second.size() < 2){
		throw TelephoneBookException{};
	}
	else {
		it->second[1] = profile;
	}
}

//Убрать доп. информацию у контакта

void TelephoneBook::removeContactProfile(string surname) {

	map <string, vector <string>> ::iterator it = book.find(surname);

	if (it == book.end()) {
		throw TelephoneBookException{};
	}
	else if (it->second.size() < 2) {
		throw TelephoneBookException{};
	}
	else {
		it->second = { it->second[0] };
	}
}

//Добавить доп. информацию к контакту

void TelephoneBook::addProfileToContact(string surname, string profile) {

	map <string, vector <string>> ::iterator it = book.find(surname);

	if (it == book.end()) {
		throw TelephoneBookException{};
	}
	else if (it->second.size() > 1) {
		throw TelephoneBookException{};
	}
	else {
		it->second = { it->second[0],profile };
	}
}

//Загрузить книгу в файл

void TelephoneBook::upload(string filename) {

	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Can't open the file for writing";
		file.close();
		throw TelephoneBookException{};
	}

	map <string, vector <string>> ::iterator it = book.begin();

	for (int i = 0; it != book.end(); i++, it++) {
		file << "Contact name: " << it->first;
		if (it->second.size() > 1) {
			file << "\nThis person is: " << it->second[1];
		}
		file << "\nPhone number: " << it->second[0] << "\n\n";
	}
}
