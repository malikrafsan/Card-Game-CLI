#ifndef _TERMINAL_MANAGER_
#define _TERMINAL_MANAGER_

#include<vector>
#include<string>

using namespace std;

class TerminalManager {
    private:
    public:
    TerminalManager();
    //! ask command to forward it to GameManager
    vector<string> readCommand();
};

#endif