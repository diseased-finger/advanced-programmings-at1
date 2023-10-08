//
// Created by jedsaxon on 8/10/23.
//

#include <string>
#include <iostream>
#include "HashQuestions.h"
#include "Hasher.h"

int HashQuestions::Start() {
    Hasher *hasher = new Hasher();

    // Initialise a table with 100,000 elements -> hashes will be stored as indexes
    int maxKeys = 100000;
    std::string* keys[maxKeys];

    for (int i = 0; i < maxKeys; i++) {
        keys[i] = nullptr;
    }

    // Get user input, and perform actions based on it (do you really want these comments???)
    while (true)
    {
        printf("Select Option:\n\t1 - Add Element\n\t2 - Search\n\t3 - Quit\n");
        int option = 0;
        std::cin >> option;

        switch (option) {
            case 1: {
                printf("Type to add element: ");
                std::string input;
                std::cin >> input;

                unsigned int hash = hasher->StringToHash(input, maxKeys);
                keys[hash] = &input;

                break;
            }
            case 2: {
                printf("Enter text to search: ");
                std::string input;
                std::cin >> input;

                unsigned int hash = hasher->StringToHash(input, maxKeys);
                std::string* value = keys[hash];

                if (value != nullptr) {
                    printf("Value Found: %s\n", value->c_str());
                } else {
                    printf("Value does not exist in the hash table\n");
                }

                break;
            }
            case 3: {
                printf("Quitting\n");
                return 0;
            }
            default: {
                printf("Invalid Option\n");
                break;
            }
        }
    }

    return 0;
}
