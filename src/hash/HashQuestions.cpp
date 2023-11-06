//
// Created by jedsaxon on 8/10/23.
//

#include <string>
#include <iostream>
#include "HashQuestions.h"
#include "Hasher.h"

int HashQuestions::Start() {
    // Create a new Hasher object
    Hasher *hasher = new Hasher();

    // Define the maximum number of keys in the hash table
    int maxKeys = 100000;

    // Create an array of pointers to strings, initialized to nullptr
    std::string* keys[maxKeys];

    // Initialize each element in the array to nullptr
    for (int i = 0; i < maxKeys; i++) {
        keys[i] = nullptr;
    }

    // Enter a loop to continuously get input from the user
    while (true) {
        // Print a menu of options for the user
        printf("Select Option:\n\t1 - Add Element\n\t2 - Search\n\t3 - Quit\n");

        // Read the user's input
        int option = 0;
        std::cin >> option;

        // Switch statement to handle different user options
        switch (option) {
            case 1: {
                // Prompt the user to enter a string to add
                printf("Type to add element: ");

                // Read the input string
                std::string input;
                std::cin >> input;

                // Calculate the hash value of the input string
                unsigned int hash = hasher->StringToHash(input, maxKeys);

                // Store the input string at the index corresponding to its hash value
                keys[hash] = &input;

                break;
            }
            case 2: {
                // Prompt the user to enter a string to search for
                printf("Enter text to search: ");

                // Read the input string
                std::string input;
                std::cin >> input;

                // Calculate the hash value of the input string
                unsigned int hash = hasher->StringToHash(input, maxKeys);

                // Retrieve the value at the index corresponding to the hash value
                std::string* value = keys[hash];

                // Check if the value exists (i.e., not nullptr)
                if (value != nullptr) {
                    // Print the found value
                    printf("Value Found: %s\n", value->c_str());
                } else {
                    // Print a message indicating the value does not exist
                    printf("Value does not exist in the hash table\n");
                }

                break;
            }
            case 3: {
                // Print a message indicating the program is quitting
                printf("Quitting\n");

                // Return 0 to indicate successful execution
                return 0;
            }
            default: {
                // Print an error message for invalid input
                printf("Invalid Option\n");
                break;
            }
        }
    }

    return 0;
}

