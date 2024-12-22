#ifndef FPNODE_H
#define FPNODE_H

#include <string>
#include <memory>
#include <unordered_map>


class FPNode {
public:
    std::string item;
    int count; 
    std::shared_ptr<FPNode> parent;
    std::unordered_map<std::string, std::shared_ptr<FPNode>> children;

    FPNode(std::string item);

    std::shared_ptr<FPNode> addChild(const std::string& childItem);

    void incrementCount();
};

#endif
