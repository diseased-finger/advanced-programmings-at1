// This C++ program seems to implement a basic hash table and provides a menu-driven interface.
// It uses a Hasher class to calculate hash values and NodeList to manage the hash table.

#include <string>
#include <iostream>
#include "HashQuestions.h"
#include "Hasher.h"

// The Start function serves as the entry point of the program.
int HashQuestions::Start() {
    // Create a NodeList to store unsigned integers (hash values).
    NodeList<unsigned int>* hashedList = new NodeList<unsigned int>();

    // Create a Hasher object to calculate hash values.
    Hasher* hasher = new Hasher();

    while (true) {
        std::cout << std::endl;
        // Display the menu and get the user's choice.
        int option = GetInput<int>("Please enter an option:\n1 - Insert\n2 - List\n3 - Search\n4 - Quit\n");
        std::cout << std::endl;
        switch (option) {
            case 1: {
                // Call the InsertIntoList function to insert a value into the hash table.
                InsertIntoList(hashedList, hasher);
                break;
            }
            case 2: {
                // Call the LoopList function to list the elements in the hash table.
                LoopList(hashedList);
                break;
            }
            case 3: {
                // Call the Search function to search for a value in the hash table.
                bool foundValue = Search(hashedList, hasher);
                printf(foundValue ? "That word was found in the list!" : "That word doesn't exist");
                break;
            }
            case 4: {
                // Deallocate memory for the NodeList and exit the program.
                delete hashedList;
                delete hasher;
                return 0;
            }
            default: {
                printf("That is an invalid option. Please enter a number between 1 - 4");
                break;
            }
        }
    }

    return 0;
}

// The Search function searches for a value in the hash table.
bool HashQuestions::Search(NodeList<unsigned int>* list, Hasher* hasher) {
    // Get a query string from the user.
    std::string query = std::move(GetInput<std::string>("Enter Query: "));

    // Calculate the hash value for the query string.
    unsigned int hashedQuery = hasher->Hash(&query.at(0), query.size());

    // Iterate through the hash table to find a match.
    Node<unsigned int>* n = list->GetFirst();
    int size = 0;
    while (n != nullptr) {
        unsigned int derefData = *(n->GetData());
        if (derefData == hashedQuery) {
            return true; // Match found.
        }
        n = n->GetNextNode();
    }
    return false; // No match found.
}

// A template function for getting user input.
template <typename T>
T HashQuestions::GetInput(const std::string& message) {
    std::cout << message;
    T output;
    std::cin >> output;
    return output;
}

// The InsertIntoList function inserts a hash value into the hash table.
void HashQuestions::InsertIntoList(NodeList<unsigned int>* list, Hasher* hasher) {
    // Get a string from the user to insert into the hash table.
    std::string strToInsert = std::move(GetInput<std::string>("Enter string to insert into the list: "));

    // Calculate the hash value for the string.
    unsigned int hash = hasher->Hash(&strToInsert.at(0), strToInsert.size());

    // Print the hash value (for demonstration purposes).
    std::cout << hash << std::endl;

    // Insert the hash value into the hash table.
    list->Insert(new Node<unsigned int>(hash));
}

// The LoopList function lists elements in the hash table.
void HashQuestions::LoopList(NodeList<unsigned int> *list) {
    // Iterate through the hash table and print its elements.
    Node<unsigned int>* n = list->GetFirst();
    int size = 0;
    while (n != nullptr) {
        unsigned int derefData = *(n->GetData());
        std::cout << "Element [" << size << "] = " << derefData << "\n";
        n = n->GetNextNode();
    }
}
