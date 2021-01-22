#include "TelephoneBook.h"

map <string, vector <string>> ::iterator it;

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

	it = book.begin();
	for (int i = 0; it != book.end(); it++, i++) {
		if (it->first == surname) {
			if (profile == "undefined") {
				otherContacts.push_back({ it->first, it->second[0] });
				break;
			}
			else {
				otherContacts.push_back({ it->first, it->second[0], it->second[1] });
				break;
			}
		}
	}

	book[surname] = phoneAndProfile;
}

//Найти номер контакта по имени контакта

string TelephoneBook::findContactNumbers(string surname) {

	string forReturn;

	it = book.find(surname);

	if (it == book.end()) {
		cout << "Contact '" << surname << "' is not found\n";
		return "undefined";
	}
	else {
		forReturn = it->second[0];
		for (int i = 0; i < otherContacts.size(); i++) {
			if (otherContacts[i][0] == surname) {
				forReturn += ("; " + otherContacts[i][1]);
			}
		}
		return forReturn;
	}
}

//Вывести информацию о контакте консоль

void TelephoneBook::showContact(string surname) {

	it = book.find(surname);

	if (it == book.end()) {
		throw TelephoneBookException{};
	}
	else if (it->second.size() > 1){
		cout << "Contact name: " << it->first << "\nThis person is: " << it->second[1] << "\nPhone number: " << it->second[0] << "\n";
	}
	else {
		cout << "Contact name: " << it->first << "\nPhone number: " << it->second[0] << "\n";
	}

	for (int i = 0; i < otherContacts.size(); i++) {
		if (otherContacts[i][0] == surname) {
			if (otherContacts[i].size() > 2) {
				cout << "Contact name: " << otherContacts[i][0] << "\nThis person is: " << otherContacts[i][2] << "\nPhone number: " << otherContacts[i][1] << "\n";
			}
			else {
				cout << "Contact name: " << otherContacts[i][0] << "\nPhone number: " << otherContacts[i][1] << "\n";
			}
		}
	}
}

//Удалить контакт

void TelephoneBook::removeContact(string surname, string phoneNumber) {

	it = book.find(surname);

	if (it == book.end()) {
		throw TelephoneBookException{};
	}
	else {
		if (it->second[0] == phoneNumber) {
			book.erase(it);
		}
		else {
			for (int i = 0; i < otherContacts.size(); i++) {
				if (otherContacts[i][0] == surname and otherContacts[i][1]==phoneNumber) {
					otherContacts.erase(otherContacts.begin() + i);
					break;
				}
			}
		}
	}
}

//Полностью очистить книгу

void TelephoneBook::clear() {

	for (int i = book.size(); i != 0; i--) {
		it = book.begin();
		book.erase(it);
	}
	otherContacts.clear();
}

//Проверить, есть ли контакт в книге

bool TelephoneBook::isContactInBook(string surname) {

	it = book.find(surname);

	if (it == book.end()) {
		for (int i = 0; i < otherContacts.size(); i++) {
			if (otherContacts[i][0] == surname) {
				return true;
			}
		}
		return false;
	}
	else {
		return true;
	}
}

//Изменить номер контакта

void TelephoneBook::changeContactNumber(string surname, string prevPhoneNumber, string phoneNumber) {
	
	//--TODO--
	//phoneCheck(phoneNumber);

	it = book.find(surname);

	if (it == book.end()) {
		throw TelephoneBookException{};
	}
	else {
		if (it->second[0] == prevPhoneNumber) {
			it->second[0] = phoneNumber;
		}
		else {
			for (int i = 0; i < otherContacts.size(); i++) {
				if (otherContacts[i][0] == surname and otherContacts[i][1] == prevPhoneNumber) {
					otherContacts[i][1] = phoneNumber;
					break;
				}
			}
		}
	}
}

//Изменить доп. информацию (то, кем этот человек тебе приходится)

void TelephoneBook::changeContactProfile(string surname, string phoneNumber, string profile) {

	it = book.find(surname);

	if (it == book.end()) {
		for (int i = 0; i < otherContacts.size(); i++) {
			if (otherContacts[i][0] == surname and otherContacts[i][1] == phoneNumber) {
				if (otherContacts.size() > 2) {
					otherContacts[i][2] = profile;
					break;
				}
				else {
					throw TelephoneBookException{};
				}
			}
			if (i == otherContacts.size()) {
				throw TelephoneBookException{};
			}
		}
	}
	else if (it->second.size() < 2){
		if (it->second[0] != phoneNumber) {
			for (int i = 0; i < otherContacts.size(); i++) {
				if (otherContacts[i][0] == surname and otherContacts[i][1] == phoneNumber) {
					if (otherContacts.size() > 2) {
						otherContacts[i][2] = profile;
						break;
					}
					else {
						throw TelephoneBookException{};
					}
				}
				if (i == otherContacts.size()) {
					throw TelephoneBookException{};
				}
			}
		}
		else {
			throw TelephoneBookException{};
		}
	}
	else {
		if (it->second[0] != phoneNumber) {
			for (int i = 0; i < otherContacts.size(); i++) {
				if (otherContacts[i][0] == surname and otherContacts[i][1] == phoneNumber) {
					if (otherContacts.size() > 2) {
						otherContacts[i][2] = profile;
						break;
					}
					else {
						throw TelephoneBookException{};
					}
				}
				if (i == otherContacts.size()) {
					throw TelephoneBookException{};
				}
			}
		}
		else {
			it->second[1] = profile;
		}
	}
}

//Убрать доп. информацию у контакта

void TelephoneBook::removeContactProfile(string surname, string phoneNumber) {

	it = book.find(surname);

	if (it == book.end()) {
		for (int i = 0; i < otherContacts.size(); i++) {
			if (otherContacts[i][0] == surname and otherContacts[i][1] == phoneNumber) {
				if (otherContacts.size() > 2) {
					otherContacts[i] = { otherContacts[i][0], otherContacts[i][1] };
					break;
				}
				else {
					throw TelephoneBookException{};
				}
			}
			if (i == otherContacts.size()) {
				throw TelephoneBookException{};
			}
		}
	}
	else if (it->second.size() < 2) {
		if (it->second[0] != phoneNumber) {
			for (int i = 0; i < otherContacts.size(); i++) {
				if (otherContacts[i][0] == surname and otherContacts[i][1] == phoneNumber) {
					if (otherContacts.size() > 2) {
						otherContacts[i] = { otherContacts[i][0], otherContacts[i][1] };
						break;
					}
					else {
						throw TelephoneBookException{};
					}
				}
				if (i == otherContacts.size()) {
					throw TelephoneBookException{};
				}
			}
		}
		else {
			throw TelephoneBookException{};
		}
	}
	else {
		if (it->second[0] != phoneNumber) {
			for (int i = 0; i < otherContacts.size(); i++) {
				if (otherContacts[i][0] == surname and otherContacts[i][1] == phoneNumber) {
					if (otherContacts.size() > 2) {
						otherContacts[i] = { otherContacts[i][0], otherContacts[i][1] };
						break;
					}
					else {
						throw TelephoneBookException{};
					}
				}
				if (i == otherContacts.size()) {
					throw TelephoneBookException{};
				}
			}
		}
		else {
			it->second = { it->second[0] };
		}
	}
}

//Добавить доп. информацию к контакту

void TelephoneBook::addProfileToContact(string surname, string phoneNumber, string profile) {

	it = book.find(surname);

	if (it == book.end()) {
		for (int i = 0; i < otherContacts.size(); i++) {
			if (otherContacts[i][0] == surname and otherContacts[i][1] == phoneNumber) {
				if (otherContacts.size() < 3) {
					otherContacts[i] = { otherContacts[i][0], otherContacts[i][1], profile };
					break;
				}
				else {
					throw TelephoneBookException{};
				}
			}
			if (i == otherContacts.size()) {
				throw TelephoneBookException{};
			}
		}
	}
	else if (it->second.size() > 1) {
		if (it->second[0] != phoneNumber) {
			for (int i = 0; i < otherContacts.size(); i++) {
				if (otherContacts[i][0] == surname and otherContacts[i][1] == phoneNumber) {
					if (otherContacts.size() < 3) {
						otherContacts[i] = { otherContacts[i][0], otherContacts[i][1], profile };
						break;
					}
					else {
						throw TelephoneBookException{};
					}
				}
				if (i == otherContacts.size()) {
					throw TelephoneBookException{};
				}
			}
		}
		else {
			throw TelephoneBookException{};
		}
	}
	else {
		if (it->second[0] != phoneNumber) {
			for (int i = 0; i < otherContacts.size(); i++) {
				if (otherContacts[i][0] == surname and otherContacts[i][1] == phoneNumber) {
					if (otherContacts.size() < 3) {
						otherContacts[i] = { otherContacts[i][0], otherContacts[i][1], profile };
						break;
					}
					else {
						throw TelephoneBookException{};
					}
				}
				if (i == otherContacts.size()) {
					throw TelephoneBookException{};
				}
			}
		}
		else {
			it->second = { it->second[0],profile };
		}
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

	it = book.begin();

	for (int i = 0; it != book.end(); i++, it++) {

		file << "Contact name: " << it->first;
		if (it->second.size() > 1) {
			file << "\nThis person is: " << it->second[1];
		}
		file << "\nPhone number: " << it->second[0] << "\n\n";

		for (int i = 0; i < otherContacts.size(); i++) {
			if (otherContacts[i][0] == it->first) {
				file << "Contact name: " << otherContacts[i][0];
				if (otherContacts[i].size() > 2) {
					file << "\nThis person is: " << otherContacts[i][2];
				}
				file << "\nPhone number: " << otherContacts[i][1] << "\n\n";
			}
		}
	}
}