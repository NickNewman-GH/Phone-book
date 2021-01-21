#include "TelephoneBook.h"

int main()
{
    TelephoneBook book;
    book.addContact("Ivanov", "+79996784294", "Father");
    book.addContact("Korolev", "+79679444552", "Friend");
    book.addContact("Sidorov", "+79649795610");
    book.addContact("Lyutenberg", "+79991234567");
    cout << book.findContactNumber("Korolev") << "\n";
    book.showContact("Korolev");
    book.changeContactNumber("Korolev", "+77896785522");
    book.showContact("Korolev");
    book.showContact("Lyutenberg");
    book.addProfileToContact("Lyutenberg", "Uncle");
    book.showContact("Lyutenberg");
    book.changeContactProfile("Lyutenberg", "Brother");
    book.showContact("Lyutenberg");
    book.removeContactProfile("Lyutenberg");
    book.showContact("Lyutenberg");
    cout << book.isContactInBook("Lyutenberg") << "\n";
    book.removeContact("Lyutenberg");
    cout << book.isContactInBook("Lyutenberg") << "\n";
    book.upload("file.txt");
    book.clear();
}