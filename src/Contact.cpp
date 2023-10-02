// This C++ code defines the 'Contact' class, which appears to represent contact information.
// It includes member functions for setting and getting contact attributes and a 'ToString' function to create a formatted string representation of a contact.

#include "Contact.h" // Include the Contact class definition.

// Include necessary C++ standard library headers.
#include <utility>   // Utility header for std::move
#include <string>    // String header for string manipulation

// Definition of the 'ToString' member function.
std::string Contact::ToString() {
    // Construct and return a formatted string representing the contact.
    return firstName + " " + lastName + ", " + std::to_string(age) + " years old.";
}

// Setter function to update the first name of the contact.
void Contact::SetFirstName(std::string newFirstName) {
    firstName = std::move(newFirstName); // Use std::move to efficiently transfer ownership of the string.
}

// Setter function to update the last name of the contact.
void Contact::SetLastName(std::string newLastName) {
    lastName = std::move(newLastName); // Use std::move to efficiently transfer ownership of the string.
}

// Setter function to update the age of the contact.
void Contact::SetAge(int newAge) {
    age = newAge;
}

// Getter function to retrieve the first name of the contact (const version).
std::string Contact::GetFirstName() const {
    return firstName;
}

// Getter function to retrieve the last name of the contact (const version).
std::string Contact::GetLastName() const {
    return lastName;
}

// Getter function to retrieve the age of the contact (const version).
int Contact::GetAge() const {
    return age;
}

// Constructor to initialize a Contact object with provided values for first name, last name, and age.
Contact::Contact(std::string newFirstName, std::string newLastName, int newAge) {
    // Use std::move to efficiently transfer ownership of the string values.
    firstName = std::move(newFirstName);
    lastName = std::move(newLastName);
    age = newAge;
}
