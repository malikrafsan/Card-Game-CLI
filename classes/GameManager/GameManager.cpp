#include "GameManager.hpp"

GameManager::GameManager() {
    string configPath = "./config";
    string itemConfigPath = configPath + "/item.txt";
    string recipesConfigPath = configPath +"/recipe";
    vector<string> itemConfig = fileManager.readFile(itemConfigPath);
    for(string s : itemConfig) {
        stringstream ss(s);
        string temp[4];
        ss >>temp[0] >>temp[1] >>temp[2] >>temp[3];
        int id = stoi(temp[0]);
        string name = temp[1];
        mpNameId[name] = id;
        // perlu ada exception id bukan int, 1 line kurang dari 4 kata ga?
        // kalo mau yg selain 24 item awal, kyknya bisa cek name gak ada di set 27 terus bikin sendiri
    }
    Stick* stick = new Stick(mpNameId["STICK"]);
    mpIdItem[mpNameId["STICK"]] = stick;
    IronIngot* ironIngot = new IronIngot(mpNameId["IRON_INGOT"]);
    mpIdItem[mpNameId["IRON_INGOT"]] = ironIngot;
    IronNugget* ironNugget = new IronNugget(mpNameId["IRON_NUGGET"]);
    mpIdItem[mpNameId["IRON_NUGGET"]] = ironNugget;
    Diamond* diamond = new Diamond(mpNameId["DIAMOND"]);
    mpIdItem[mpNameId["DIAMOND"]] = diamond;
    Axe* woodenAxe = new Axe(mpNameId["WOODEN_AXE"],"WOODEN");
    mpIdItem[mpNameId["WOODEN_AXE"]] = woodenAxe;
    Axe* stoneAxe = new Axe(mpNameId["STONE_AXE"], "STONE");
    mpIdItem[mpNameId["STONE_AXE"]] = stoneAxe;
    Axe* ironAxe = new Axe(mpNameId["IRON_AXE"],"IRON");
    mpIdItem[mpNameId["IRON_AXE"]] = ironAxe;
    Axe* diamondAxe = new Axe(mpNameId["DIAMOND_AXE"],"DIAMOND");
    mpIdItem[mpNameId["DIAMOND_AXE"]] = diamondAxe;
    Sword* woodenSword = new Sword(mpNameId["WOODEN_SWORD"],"WOODEN");
    mpIdItem[mpNameId["WOODEN_SWORD"]] = woodenSword;
    Sword* stoneSword = new Sword(mpNameId["STONE_SWORD"],"STONE");
    mpIdItem[mpNameId["STONE_SWORD"]] = stoneSword;
    Sword* ironSword = new Sword(mpNameId["IRON_SWORD"],"IRON");
    mpIdItem[mpNameId["IRON_SWORD"]] = ironSword;
    Sword* diamondSword = new Sword(mpNameId["DIAMOND_SWORD"],"DIAMOND");
    mpIdItem[mpNameId["DIAMOND_SWORD"]] = diamondSword;
    Pickaxe* woodenPickaxe = new Pickaxe(mpNameId["WOODEN_PICKAXE"],"WOODEN");
    mpIdItem[mpNameId["WOODEN_PICKAXE"]] = woodenPickaxe;
    Pickaxe* stonePickaxe = new Pickaxe(mpNameId["STONE_PICKAXE"],"STONE");
    mpIdItem[mpNameId["STONE_PICKAXE"]] = stonePickaxe;
    Pickaxe* ironPickaxe = new Pickaxe(mpNameId["IRON_PICKAXE"],"IRON");
    mpIdItem[mpNameId["IRON_PICKAXE"]] = ironPickaxe;
    Pickaxe* diamondPickaxe = new Pickaxe(mpNameId["DIAMOND_PICKAXE"],"DIAMOND");
    mpIdItem[mpNameId["DIAMOND_PICKAXE"]] = diamondPickaxe;
    Stone* cobblestone = new Stone(mpNameId["COBBLESTONE"],"COBBLE");
    mpIdItem[mpNameId["COBBLESTONE"]] = cobblestone;
    Stone* blackstone = new Stone(mpNameId["BLACKSTONE"],"BLACK");
    mpIdItem[mpNameId["BLACKSTONE"]] = blackstone;
    Log* oakLog = new Log(mpNameId["OAK_LOG"],"OAK");
    mpIdItem[mpNameId["OAK_LOG"]] = oakLog;
    Log* spruceLog = new Log(mpNameId["SPRUCE_LOG"],"SPRUCE");
    mpIdItem[mpNameId["SPRUCE_LOG"]] = spruceLog;
    Log* birchLog = new Log(mpNameId["BIRCH_LOG"],"BIRCH");
    mpIdItem[mpNameId["BIRCH_LOG"]] = birchLog;
    Plank* oakPlank = new Plank(mpNameId["OAK_PLANK"],"OAK");
    mpIdItem[mpNameId["OAK_PLANK"]] = oakPlank;
    Plank* sprucePlank = new Plank(mpNameId["SPRUCE_PLANK"],"SPRUCE");
    mpIdItem[mpNameId["SPRUCE_PLANK"]] = sprucePlank;
    Plank* birchPlank = new Plank(mpNameId["BIRCH_PLANK"],"BIRCH");
    mpIdItem[mpNameId["BIRCH_PLANK"]] = birchPlank;    

    vector<Recipe> recipes;
    vector<vector<string>> recipesConfig = fileManager.readFiles(recipesConfigPath);
    for(vector<string> recipeConfig: recipesConfig) {
        recipes.push_back(Recipe(recipeConfig));
    }
    craft = new Craft(recipes, mpIdItem, mpNameId);
}

GameManager::~GameManager() {
    vector<Item*> v;
    for(auto [id,item]: mpIdItem) {
        v.push_back(item);
    }
    for(int i=0;i<(int)v.size();i++) {
        delete v[i];
    }
}

void GameManager::play() {
    bool isExit=false;
    while(!isExit) {
        craft->print();
        inventory.print();
        vector<string> command = terminalManager.readCommand();
        if(command[0]=="GIVE") {
            giveCommand(command);
        } else if(command[0]=="DISCARD") {
            discardCommand(command);
        } else if(command[0]=="MOVE") {

        } else if(command[0]=="CRAFT") {

        } else {
            // throw invalid command exception
        }
    }    
}

void GameManager::giveCommand(vector<string> command) {
    if((int)command.size() == 3) {
        string name = command[1];
        int qty = stoi(command[2]);
        inventory.addItem(mpIdItem[mpNameId[name]], qty);
    } else {
        ;
    }
}

void GameManager::discardCommand(vector<string> command) {
    if((int)command.size() == 3) {
        int qty = stoi(command[2]);
        // inventory.removeItem(command[1], qty);
    }
}