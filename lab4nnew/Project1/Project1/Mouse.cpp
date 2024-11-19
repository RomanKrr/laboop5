#include "Mouse.h"
#include <iostream> 
#include <string>
#include <vector>

using namespace std;

void Mouse::Service_Dinamic(vector<Mouse*>& mice) {
    for (auto it = mice.begin(); it != mice.end(); ) {
        if (!(*it)->wireless) {
            delete* it;  
            it = mice.erase(it);
            cout << "Wired mouse removed." << endl;
        }
        else {
            ++it;
        }
    }
}

string defaultDescription = "Default description";
Mouse::Mouse(string n, string b, int y, string dV, string sT, int d, bool w, int bL)
    : Device(n, b, y, dV, sT, true, 100, "Input", 50, defaultDescription), dpi(d), wireless(w), batteryLevel(bL)
{
    //cout << "Mouse Constructor multiple imitation" << endl;
}

Mouse::~Mouse() {
    //cout << "Mouse destructor called." << endl;
}

void Mouse::displayMouseInfo() {
    std::cout << "Mouse: " << name << ", Brand: " << brand << ", DPI: " << dpi   << "\n";

}