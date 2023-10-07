#include "src/Contact.h"
#include "src/hash/HashQuestions.h"
#include "src/node/NodeQuestions.h"
#include "src/tree/TreeQuestions.h"

int main() {
    HashQuestions* questions = new HashQuestions();
//    TreeQuestions* questions = new TreeQuestions();
//    NodeQuestions* questions = new NodeQuestions();
    return questions->Start();
}
