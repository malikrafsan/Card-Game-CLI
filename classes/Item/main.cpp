#include "TypedNonTool.hpp"
#include "Tool.hpp"

#include <iostream>

using namespace std;

int main(){
    Tool pickaxe1 = Tool(1, "IRON SWORD", "IRON");
    pickaxe1.use();
    pickaxe1.use();
    pickaxe1.describe();
    
    Item *oakPlank = new TypedNonTool(2, "OAK_PLANK","PLANK", "OAK");
    oakPlank->describe();

    Item *birchLog = new TypedNonTool(3, "BIRCH_LOG", "LOG", "BIRCH");
    birchLog->describe();


    Item *craftingTable = new NonTool(4, "CRAFTING_TABLE");
    craftingTable->describe();


    NonTool *stick = new NonTool(5, "STICK");
    stick->describe();

    NonTool otherStick = *stick;
    otherStick.describe();
    cout << pickaxe1.isTool << endl;

    Item *item = otherStick.clone();
    otherStick.describe();

    Item *pickaxeClone = pickaxe1.clone();
    pickaxeClone->describe();

    pickaxe1.use();
    pickaxeClone->use();

    pickaxe1.describe();
    pickaxeClone->describe();
}