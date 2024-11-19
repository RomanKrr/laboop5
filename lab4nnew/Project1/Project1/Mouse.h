#pragma once
#include"InputDevice.h"
#include"Device.h"
#include <vector>

class Mouse : public Device, public InputDevice
{
public:
	int dpi;
	bool wireless;
	int batteryLevel;

	Mouse(string n, string b, int y, string dV, string sT, int d, bool w, int bL);

	using Device::displayInfo;
	using Device::showDeviceCount;

	void displayMouseInfo();

	static void Service_Dinamic(vector<Mouse*>& mice);

	string getDeviceType() const override {
		return "Mouse"; 
	}

	void toggleWirelessMode() {
		wireless = !wireless;
		cout << (wireless ? "Now using wireless mode." : "Now using wired mode.") << endl;
	}

	void updateDPI(int dpi) {
		if (dpi < 0) throw invalid_argument("DPI cannot be negative.");
		this->dpi = dpi;
		cout << "DPI updated to: " << dpi << endl;
	}


	void checkBatteryStatus() {
		if (wireless) {
			cout << "Battery level: " << batteryLevel << "%" << endl;
			if (batteryLevel < 20) {
				cout << "Warning: Battery is low!" << endl;
			}
		}
		else {
			cout << "Wired mouse - no battery required." << endl;
		}
		cout << endl;

	}

	void connect() override {
		cout << "Mouse connected." << endl;
	}
	virtual ~Mouse();
};


