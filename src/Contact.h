//
// Created by jedsaxon on 3/09/23.
//

#ifndef ADVANCED_PROGRAMMINGS_AT1_CONTACT_H
#define ADVANCED_PROGRAMMINGS_AT1_CONTACT_H

#include <string>
#include <utility>

class Contact {
private:
    int age;
    std::string firstName;
    std::string lastName;
public:
    /// Read the function name
    Contact(std::string newFirstName, std::string newLastName, int newAge);

    /// Read the function name
    std::string ToString();

    // Return const to clearly communicate that the variable shouldn't be touched, and to enforce the idea that the
    // class's state canont be modified unless you call the SET methods.

    /// Read the function name
    int GetAge() const;

    /// Read the function name
    std::string GetFirstName() const;

    /// Read the function name
    std::string GetLastName() const;

    /// Read the function name
    void SetAge(int newAge);

    /// Read the function name
    void SetFirstName(std::string newFirstName);

    /// Read the function name
    void SetLastName(std::string newLastName);
};


#endif //ADVANCED_PROGRAMMINGS_AT1_CONTACT_H