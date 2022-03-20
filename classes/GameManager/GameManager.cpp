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
        string type = temp[2];
        string itemType = temp[3];
        mpNameId[name] = id;
        if(itemType=="TOOL") {
            tools.insert(name);
        } else if(itemType=="NONTOOL" && type=="-") {
            nonTools.insert(name);
        } else if(itemType=="NONTOOL") {
            typedNonTools.insert({name,type});
        } else {
            ;
        }
        // perlu ada exception id bukan int, 1 line kurang dari 4 kata ga?
        // kalo mau yg selain 24 item awal, kyknya bisa cek name gak ada di set 27 terus bikin sendiri
    }
    for(string name: tools) {
        Tool* tool = new Tool(mpNameId[name],name);
        mpIdItem[mpNameId[name]] = tool;
    }    
    for(string name: nonTools) {
        NonTool* nonTool = new NonTool(mpNameId[name],name);
        mpIdItem[mpNameId[name]] = nonTool;
    }
    for(auto [name,type]: typedNonTools) {
        TypedNonTool* typedNonTool = new TypedNonTool(mpNameId[name],name,type);
        mpIdItem[mpNameId[name]] = typedNonTool;
    }
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
            moveCommand(command);
        } else if(command[0]=="CRAFT") {

        } else if(command[0]=="USE") {
            useCommand(command);
        } else if(command[0]=="EXPORT") {
            exportCommand(command);
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
        inventory.remove(command[1], qty);
    } else {
        ;
    }
}

void GameManager::moveCommand(vector<string> command) {
    if((int)command.size()>=4) {
        int ctTarget = stoi(command[2]);
        if(ctTarget+3==(int)command.size()) {
            bool srcInvValid, srcCrfValid, allTargetInvValid, allTargetCrfValid;
            srcInvValid = inventory.isInvSlotValid(command[1], ctTarget);
            srcCrfValid = craft->isCrfSlotValid(command[1], ctTarget);
            allTargetInvValid = true;
            allTargetCrfValid = true;
            // dapetin item src dulu atau keluarin exception command move ga valid
            // cek canBeAdded inventory sm craft.
            for(int i=3;i<(int)command.size();i++) {
                allTargetInvValid &= inventory.isInvSlotValid(command[i]);
                allTargetCrfValid &= craft->isCrfSlotValid(command[i]);
            }

            if(srcInvValid && allTargetInvValid) {
                if(ctTarget==1) {
                    // numpuk sampe target 64
                } else {
                    ;
                }
            } else if(srcInvValid && allTargetCrfValid) {
                Item* item = inventory[command[1]]; // atau inventory.getItem(INV_SLOT_ID)
                bool flag=true;
                for(int i=3;i<(int)command.size();i++) {
                    flag &= craft->canBeAdded(item,command[i],1); // asumsi craft_slot_id beda semua hmm
                }
                if(flag) {
                    inventory.remove(command[1],ctTarget);
                    for(int i=3;i<(int)command.size();i++) {
                        craft->addItem(item, command[i], 1); // harus bisa nambah item berdasarkan slot_id
                    }
                } else {
                    ;
                }
            } else if(srcCrfValid && allTargetInvValid) {
                if(ctTarget==1) {
                    // ini dari Craft dipindah 1 atau pindah semua atau pindah sebisa mungkin.
                    // kalo pindah 1 aja
                    if(craft->canBeRemoved(1)) {
                        Item* item = (*craft)[command[1]]; // atau craft->getItem(CRF_SLOT_ID)
                        if(inventory.canBeAdded(item,command[3],1)) {
                            craft->remove(command[1],1);
                            inventory.addItem(item, command[3], 1);
                        }
                    }
                } else {
                    ;
                }
            } else {
                ;
            }
        } else {
            ;
        }
    } else {
        ;
    }
}

void GameManager::craftCommand(vector<string> command) {

}

void GameManager::useCommand(vector<string> command) {
    if((int)command.size()==2) {
        inventory.use(command[1]);
    } else {
        ;
    }
}

void GameManager::exportCommand(vector<string> command) {
    if((int)command.size()==2) {
        fileManager.write(command[1], inventory.exportInventory());
    } else {
        ;
    }
}