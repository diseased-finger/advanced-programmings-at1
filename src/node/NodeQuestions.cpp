//
// Created by jedsaxon on 11/09/23.
//

#include <iostream>
#include "NodeQuestions.h"
#include "ContactList.h"

int NodeQuestions::Start() {
    Node<Contact>* node4 = new Node<Contact>(Contact("Foo4", "Bar4", 60));
    Node<Contact>* node2 = new Node<Contact>(Contact("Foo2", "Bar2", 40));
    Node<Contact>* node5 = new Node<Contact>(Contact("Foo5", "Bar5", 70));
    Node<Contact>* node1 = new Node<Contact>(Contact("Foo1", "Bar1", 30));
    Node<Contact>* node3 = new Node<Contact>(Contact("Foo3", "Bar3", 50));
    Node<Contact>* node6 = new Node<Contact>(Contact("Foo6", "Bar6", 80));

    ContactList* list = new ContactList();

    list->Insert(node4);
    list->Insert(node2);
    list->Insert(node5);
    list->Insert(node1);
    list->Insert(node3);
    list->Insert(node6);

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
        int option = GetNumberFromUser("Enter Option: ", "Please select a value between 1 and 8", 1, 8);
        std::cout << "\n";

        switch (option) {
            case 1: {
                Node<Contact>* newNode = CreateNode();
                list->Insert(newNode);
                continue;
            }
            case 2: {
                list->LoopThroughNodes();
                continue;
            }
            case 3: {
                list->LoopThroughNodesReverse();
                continue;
            }
            case 4: {
                list->Search();
                continue;
            }
            case 7: {
                std::cout << "Sorting...\n";
                list->Sort();
                continue;
            }
            case 8: {
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

Node<Contact>* NodeQuestions::CreateNode() {
    std::string firstName;
    std::string lastName;
    int age;

    std::cout << "Inserting New Element1\n" << "Enter First Name: ";
    std::cin >> firstName;
    std::cout << "Enter Last Name: ";
    std::cin >> lastName;

    age = GetNumberFromUser("Enter Age: ", "Please select a valid age between 0 - 100", 0, 100);

    return new Node<Contact>(Contact(firstName, lastName, age));
}
