#include "TelephoneBook.h"

int main()
{
    TelephoneBook book;
    book.addContact("Ivanov", "+79996784294", "Father");
    book.addContact("Korolev", "+79679444552", "Friend");
    book.addContact("Korolev", "+79674999999", "Friend");
    book.addContact("Sidorov", "+79649795610");
    book.addContact("Korolev", "+79674353532", "Friend");
    book.addContact("Lyutenberg", "+79991234567");
    cout << book.findContactNumbers("Korolev") << "\n";
    book.showContact("Korolev");
    cout << "-------------------------------------------\n";
    book.changeContactProfile("Korolev", "+79674353532", "Brother");
    book.changeContactNumber("Korolev", "+79674353532", "+77896785522");
    book.showContact("Korolev");
    cout << "-------------------------------------------\n";
    book.showContact("Lyutenberg");
    cout << "-------------------------------------------\n";
    book.addProfileToContact("Lyutenberg", "+79991234567", "Uncle");
    book.showContact("Lyutenberg");
    cout << "-------------------------------------------\n";
    book.changeContactProfile("Lyutenberg", "+79991234567", "Brother");
    book.showContact("Lyutenberg");
    cout << "-------------------------------------------\n";
    book.removeContactProfile("Lyutenberg", "+79991234567");
    book.showContact("Lyutenberg");
    cout << "-------------------------------------------\n";
    cout << book.isContactInBook("Lyutenberg") << "\n";
    book.removeContact("Lyutenberg", "+79991234567");
    book.removeContact("Korolev", "+79674999999");
    book.showContact("Korolev");
    cout << "-------------------------------------------\n";
    cout << book.isContactInBook("Lyutenberg") << "\n";
    book.upload("file.txt");
    book.clear();
}