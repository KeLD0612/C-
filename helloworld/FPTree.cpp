#include "FPNode.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory>

class FPNode;

class FPTree {
private:
    std::shared_ptr<FPNode> root;
    std::map<std::string, int> headerTable;
public:
    FPTree(){
        root = std::make_shared<FPNode>("null");
    }
    // inut transaction by vecter in vectee, and minSuport
    void buildTree(const std::vector<std::vector<std::string>>& transactions, int minsup){
        //add to headerTable fillter
        for(const auto& transaction : transactions ){
            for(const auto& item : transaction){
                headerTable[item]++;
            }
        }
        // fillter item in headerTable by MinSupport
        for(auto item = headerTable.begin(); item != headerTable.end();){
            if(item->second < minsup){
                item = headerTable.erase(item);
            }
            else{
                ++item;
            }
        }
        // fillter back transaction by headerTable
        for(const auto& transaction : transactions){
            std::vector<std::string> fillteredTransaction;
            for(const auto& item : transaction){
                if(headerTable.find(item) != headerTable.end())
                    fillteredTransaction.push_back(item);
            }
            inserTransaction(fillteredTransaction);
        }
    }
    // add node to tree
    void inserTransaction(const std::vector<std::string>& fillteredTransaction) {
        auto currentNode = root;
        for(const auto& item : fillteredTransaction){
            // add node too tree (key value)
            currentNode = currentNode->addChild(item);
            // add valude too that node (value of Key)
            currentNode->incrementCount();
        }
    }
    
    // View tree (base on Depth first search)
    void ViewTree(const std::shared_ptr<FPNode>& Node,int depth = 0) const{
        for(int i = 0; i<depth;++i)
            std::cout << " ";
        std::cout << Node->item << " (" << Node->count << " )\n";
        for(const auto& [key, child] : Node->children){
            ViewTree(child, depth++);
        }
    }

    // call view Tree
    void printfConsole() const{
        ViewTree(root);
    }
};