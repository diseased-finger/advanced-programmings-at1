cmake_minimum_required(VERSION 3.26)
project(advanced_programmings_at1)

set(CMAKE_CXX_STANDARD 11)

add_executable(advanced_programmings_at1 main.cpp
        src/Contact.cpp
        src/Contact.h
        src/node/Node.cpp
        src/node/Node.h
        src/node/NodeList.cpp
        src/node/NodeList.h
        src/tree/TreeNode.cpp
        src/tree/TreeNode.h
        src/tree/TreeIterator.cpp
        src/tree/TreeIterator.h
        src/node/NodeQuestions.cpp
        src/node/NodeQuestions.h
        src/tree/TreeQuestions.cpp
        src/tree/TreeQuestions.h
        src/hash/Hasher.cpp
        src/hash/Hasher.h
        src/hash/HashQuestions.cpp
        src/hash/HashQuestions.h
        src/node/ContactList.h
        src/node/ContactList.cpp
)
