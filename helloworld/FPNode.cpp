#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <memory>

class FPNode : public std::enable_shared_from_this<FPNode> {
public: 
    std::string item;
    int count; // Frequency of the item
    std::shared_ptr<FPNode> parent;
    std::unordered_map<std::string, std::shared_ptr<FPNode>> children;

    // Constructor
    FPNode(std::string item, std::shared_ptr<FPNode> parent = nullptr)
        : item(std::move(item)), count(0), parent(std::move(parent)) {}

    // Add a child node
    std::shared_ptr<FPNode> addChild(const std::string& childItem) {
        if (children.find(childItem) == children.end()) {
            children[childItem] = std::make_shared<FPNode>(childItem, shared_from_this());
        }
        return children[childItem];
    }

    // Increment the count of the node
    void incrementCount(int value = 1) {
        count += value;
    }
};
