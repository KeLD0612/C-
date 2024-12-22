#ifndef FPTREE_H
#define FPTREE_H

#include "FPNode.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory>

class FPTree {
private:
    std::shared_ptr<FPNode> root;
    std::map<std::string, int> headerTable;

public:
    FPTree();
    void buildTree(const std::vector<std::vector<std::string>>& transactions, int minsup);
    void inserTransaction(const std::vector<std::string>& fillteredTransaction);
    void ViewTree(const std::shared_ptr<FPNode>& Node, int depth = 0) const;
    void printfConsole() const;
};

#endif
