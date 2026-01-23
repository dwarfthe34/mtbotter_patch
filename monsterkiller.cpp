#include <iostream>
#include <cmath>
#include <list>
#include "src/mtbotter.h"
using namespace std;

bool got_sigint = false;

class MonsterKiller : public MtBotter {
    public:
    MonsterKiller():MtBotter("testbot",
                      string(""),
                      string("127.0.0.1"),
                      string("127.0.0.1"),
                      30420,
                      false){}
    private:
    void onRemoveNode(short pos[]) {}
    void onAddNode(short pos[]) {}
    void onChatMessage(unsigned char type, wstring sender, wstring message) {}
    void onConnect() {
        cout << "[] Connected!" << endl;
    }
    void onDisconnect(string reason) {}
    void onInventoryUpdate() {}
    void onPlayerMove(float pos[]) {}
    void onTime(unsigned short t){}

    void run() {
        unsigned i = 0;
        list<SomeObject> objs;
        SomeObject obj;
        bool got_wanted;
        while (!got_sigint) {
    		move(FORWARD);  // flag to move forward
    		step(0.1f);     // send updates to the server
		}

        }

};

int main() {
    MonsterKiller *mk = new MonsterKiller();
    mk->connect();
    mk->start();
    return 0;
}
