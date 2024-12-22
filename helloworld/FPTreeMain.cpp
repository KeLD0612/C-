#include "FPTree.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FPTree;
class FPNode;
int main(){
    FPTree hehe;
    std::vector<std::vector<std::string>> transactions = {
        {"a", "b", "c"},
        {"a", "c"},
        {"a", "b", "d"},
        {"b", "c", "d"}
    };
    int minSupport = 2;

    hehe.buildTree(transactions,minSupport);

    std::cout << "====================================\n";

    hehe.printfConsole();
    return 0;
}