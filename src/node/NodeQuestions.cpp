// This C++ code appears to be a console-based program that manages a list of contacts using a custom class 'Node' and 'ContactList'.
// Users can insert, list, search, and perform other operations on contacts.

#include <iostream>            // Include the input/output stream library.
#include "NodeQuestions.h"     // Include the header file for NodeQuestions class.
#include "ContactList.h"       // Include the header file for the ContactList class.

// Implementation of the Start function in the NodeQuestions class.
int NodeQuestions::Start() {
    // Create several 'Node' objects with 'Contact' data and set up a 'ContactList'.
    Node<Contact>* node4 = new Node<Contact>(Contact("Foo4", "Bar4", 60));
    Node<Contact>* node2 = new Node<Contact>(Contact("Foo2", "Bar2", 40));
    Node<Contact>* node5 = new Node<Contact>(Contact("Foo5", "Bar5", 70));
    Node<Contact>* node1 = new Node<Contact>(Contact("Foo1", "Bar1", 30));
    Node<Contact>* node3 = new Node<Contact>(Contact("Foo3", "Bar3", 50));
    Node<Contact>* node6 = new Node<Contact>(Contact("Foo6", "Bar6", 80));

    ContactList* list = new ContactList(); // Create a ContactList.

    // Insert the created nodes into the ContactList.
    list->Insert(node4);
    list->Insert(node2);
    list->Insert(node5);
    list->Insert(node1);
    list->Insert(node3);
    list->Insert(node6);

    // Display a menu for user interaction.
    std::cout << "Select Option" << std::endl
              << "1: Insert Element" << std::endl
              << "2: Loop Through Elements" << std::endl
              << "3: Loop Through Elements in Reverse" << std::endl
              << "4: Search" << std::endl
              << "5: [Deprecated] Min Age" << std::endl
              << "6: [Deprecated] Max Age" << std::endl
              << "7: Sort By Age" << std::endl
              << "8: Exit" << std::endl;

    while (true) {
        std::cout << "\n";
        // Get user input for selecting an option within a specified range (1-8).
        int option = GetNumberFromUser("Enter Option: ", "Please select a value between 1 and 8", 1, 8);
        std::cout << "\n";

        switch (option) {
            case 1: {
                // Create a new 'Node' using user input and insert it into the ContactList.
                Node<Contact>* newNode = CreateNode();
                list->Insert(newNode);
                continue;
            }
            case 2: {
                // Loop through and display the elements in the ContactList.
                list->LoopThroughNodes();
                continue;
            }
            case 3: {
                // Loop through and display the elements in reverse order.
                list->LoopThroughNodesReverse();
                continue;
            }
            case 4: {
                // Search for a contact based on age.
                list->Search();
                continue;
            }
            case 7: {
                // Sort the contacts by age.
                std::cout << "Sorting...\n";
                list->Sort();
                continue;
            }
            case 8: {
                // Exit the program, releasing memory used by the ContactList.
                std::cout << "Exiting" << std::endl;
                list->~ContactList();
                return 0;
            }
            default: {
                std::cout << "That is an invalid option" << std::endl;
            }
        }
    }
}

// Helper function to get a valid number input from the user within a specified range.
int NodeQuestions::GetNumberFromUser(const std::string &message, const std::string &errorMessage, int min, int max) {
    while (true) {
        int option = 0;
        std::cout << message;
        std::cin >> option;

        if (option < min || option > max) {
            std::cout << errorMessage << std::endl;
            continue;
        }

        return option;
    }
}

// Helper function to create a new 'Node' with 'Contact' data based on user input.
Node<Contact>* NodeQuestions::CreateNode() {
    std::string firstName;
    std::string lastName;
    int age;

    std::cout << "Inserting New Element\n" << "Enter First Name: ";
    std::cin >> firstName;
    std::cout << "Enter Last Name: ";
    std::cin >> lastName;

    // Get the age from the user, ensuring it's within a valid range (0-100).
    age = GetNumberFromUser("Enter Age: ", "Please select a valid age between 0 - 100", 0, 100);

    // Create a new 'Node' with 'Contact' data and return it.
    return new Node<Contact>(Contact(firstName, lastName, age));
}
