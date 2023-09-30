//
// Created by jedsaxon on 3/09/23.
//

#include "Contact.h"

#include <utility>

std::string Contact::ToString() {
    return firstName + " " + lastName + ", " + std::to_string(age) + " years old.";
}

void Contact::SetFirstName(std::string newFirstName) {
    firstName = std::move(newFirstName);
}

void Contact::SetLastName(std::string newLastName) {
    lastName = std::move(newLastName);
}

void Contact::SetAge(int newAge) {
    age = newAge;
}

std::string Contact::GetFirstName() const {
    return firstName;
}

std::string Contact::GetLastName() const {
    return lastName;
}

int Contact::GetAge() const {
    return age;
}

Contact::Contact(std::string newFirstName, std::string newLastName, int newAge) {
    firstName = std::move(newFirstName);
    lastName = std::move(newLastName);
    age = newAge;
}
