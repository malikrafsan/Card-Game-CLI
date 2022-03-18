#include "TypedNonTool.hpp"
#include "Tool.hpp"

#include <iostream>

using namespace std;

int main(){
    Pickaxe pickaxe1 = Pickaxe(1, "Gold");
    pickaxe1.use();
    pickaxe1.use();
    pickaxe1.describe();
    cout << pickaxe1.exportItem().first << ":" << pickaxe1.exportItem().second << endl;
    
    Item *oakPlank = new Plank(2, "Oak Plank", "Oak");
    oakPlank->describe();

    Log *birchLog = new Log(3, "Birch");
    birchLog->describe();


    Item *otherBirchLog = new Log(*birchLog);
    otherBirchLog->describe();



    Item *craftingTable = new NonTool(4, "Crafting Table");
    craftingTable->describe();


    Stick *stick = new Stick(5);
    stick->describe();

    Stick otherStick = *stick;
    otherStick.describe();
    cout << pickaxe1.isTool << endl;
}