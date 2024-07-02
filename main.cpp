/*******************************************************

 * Program Name: <Lab3 Smart Home Solutions>

 * Author: <Junghyun Baik>

 * Date: <March 10, 2023>

 * Description: <Smart-Home Solutions>

 *******************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include "menu (1).h"

using namespace std;

void addRules(vector<string>& rules);
int selectOperator();
int selectSmartDevice();
void selectSmartDevices();
void displayRules(vector<string>& rules);
void displayArgumentForm(vector<string>& rules);
void showDevices();
int getOperator();
void print_device_states();
void set_device_state();
vector<string> logicalArguments;
vector<string> conditionalOperators;

map<int, bool> devices_state = {
    {65, false}, {66, false}, {67, false}, {68, false},
    {69, false}, {70, false}, {71, false}, {72, false},
    {73, false}, {74, false}, {75, false}, {76, false},
    {77, false}, {78, false}, {79, false}, {80, false},
    {81, false}, {82, false}, {83, false}, {84, false},
    {85, false}, {86, false}, {87, false}, {88, false},
    {89, false}, {90, false}
};

/*******************************************************

 * Function Name: <Binary to Demical>

 * Purpose: <Function to convert binary to decimal>

 * Return: <decimal>

 *******************************************************/
int bin_to_dec(string binary) {
    bitset<8> bits(binary);
    return bits.to_ulong();
}


/*******************************************************

 * Function Name: <Binary to Hex>

 * Purpose: <Function to convert binary to hex>

 * Return: <Hex>

 *******************************************************/
string bin_to_hex(string binary) {
    bitset<8> bits(binary);
    return "0x" + bitset<8>(bits.to_ulong()).to_string().substr(4);
}


/*******************************************************

 * Function Name: <on/off>

 * Purpose: <Function to turn a device on/off>

 * Return: <state>

 *******************************************************/
void set_device_state(int code, bool state) {
    devices_state[code] = state;
}

/*******************************************************

 * Function Name: <Main function>

 *******************************************************/
int main() {
    Menu smartMenu("Smart-Home Control Hub");
    smartMenu.addOption("Define rules");
    smartMenu.addOption("Select the Condition");
    smartMenu.addOption("Turn Smart-Device state");
    smartMenu.addOption("Display rules");
    smartMenu.addOption("Show table the device state on");
    smartMenu.addOption("Show table the device state off");
    smartMenu.addOption("Exit");
    
    int input = -1;
    vector<string> rules;
    
    do{
        input = smartMenu.doMenuIndex();
        switch(input){
            case 1:
                addRules(rules);
                break;
            case 2:
                getOperator();
                
                break;
            case 3:
                selectSmartDevices();
                break;
            case 4: {
                // Show summary of the rules
                if (logicalArguments.empty()) {
                    cout << "No logical argument defined yet.\n";
                } else {
                    cout << " Summary of the Rules \n";
                    for (int i = 0; i < conditionalOperators.size(); i++) {
                        cout << logicalArguments[i] << " " << conditionalOperators[i] << " ";
                    }
                    cout << logicalArguments.back() << endl;
                }
                break;
            }
            case 5:
                print_device_states();
                break;
            case 6:
                print_device_states();
                break;
            case 7:
                break;
        }
    }while(input > 0 && input <= 6);
}

void addRules(vector<string>& rules){
    string argument;
    //loop
    for(;;){
        cout << "****** Define Logical Argument ******" << endl;
        cout << "Define a statement: ";
        cin.ignore();
        getline(cin, argument);
        logicalArguments.push_back(argument);
        int oper = getOperator();
        if (oper == 5){
            break;
        }
    }
    
}

int selectOperator() {
    int sel = -1;
    return sel;
}

int getOperator(){
    Menu oper("Select Conditional Operator");
    oper.addOption("AND");  //&&
    oper.addOption("OR");   //||
    oper.addOption("NOT");  //~
    oper.addOption("THEN"); //->
    oper.addOption("Done with rule (Exit)");
    
    return oper.doMenuIndex();
}


int selectSmartDevice(){
    Menu device_menu("List of Smart Devices");
    device_menu.addOption("65 _ Air Purifier");
    device_menu.addOption("66 _ Appliances");
    device_menu.addOption("67 _ Blinds");
    device_menu.addOption("68 _ Computer");
    device_menu.addOption("69 _ Curtains");
    device_menu.addOption("70 _ Door Locks");
    device_menu.addOption("71 _ Door Sensors");
    device_menu.addOption("72 _ Entertainment");
    device_menu.addOption("73 _ Garage Door");
    device_menu.addOption("74 _ Home Sensors");
    device_menu.addOption("75 _ Indoor Plug");
    device_menu.addOption("76 _ Indoor Security Camera");
    device_menu.addOption("77 _ Lawn Sprinkler Controller");
    device_menu.addOption("78 _ Light");
    device_menu.addOption("79 _ Light Bulbs");
    device_menu.addOption("80 _ Meter");
    device_menu.addOption("81 _ Outdoor Security Camera");
    device_menu.addOption("82 _ Oven");
    device_menu.addOption("83 _ Robot Vacuum");
    device_menu.addOption("84 _ Siren");
    device_menu.addOption("85 _ Smart Lock");
    device_menu.addOption("86 _ Smoke & CO2 Detectors");
    device_menu.addOption("87 _ Speaker");
    device_menu.addOption("88 _ Thermostats");
    device_menu.addOption("89 _ Video Doorbell");
    device_menu.addOption("90 _ Window Sensors");
    
    return device_menu.doMenuIndex();
    
}

void selectSmartDevices(){
    // select one or more devices
    int index = -1;
    char ch = 'N';
    while(true){
        index = selectSmartDevice();
        cout << "Turn more Devices on (Y/N) : ";
        cin >> ch;
        if (ch == 'N' || ch == 'n'){
            break;
        }
    }
}

/*******************************************************

 * Function Name: <Print state>

 * Purpose: <Function to print the state of all devices>

 * Return: <state>

 *******************************************************/
void print_device_states() {
    cout << "Code\t Device Name\t State\n";
    for (auto const& [code, state] : devices_state) {
        cout << code << "\t";
        switch (code) {
            case 65:
                cout << "Air Purifier\t";
                break;
            case 66:
                cout << "Appliances\t";
                break;
            case 67:
                cout << "Blinds\t\t";
                break;
            case 68:
                cout << "Computer\t";
                break;
            case 69:
                cout << "Curtains\t";
                break;
            case 70:
                cout << "Door Locks\t";
                break;
            case 71:
                cout << "Door Sensors\t";
                break;
            case 72:
                cout << "Entertainment\t";
                break;
            case 73:
                cout << "Garage Door\t";
                break;
            case 74:
                cout << "Home Sensors\t";
                break;
            case 75:
                cout << "Indoor Plug\t";
                break;
            case 76:
                cout << "Indoor Security Camera\t";
                break;
            case 77:
                cout << "Lawn Sprinkler Controller\t";
                break;
            case 78:
                cout << "Light\t";
                break;
            case 79:
                cout << "Light Bulbs\t";
                break;
            case 80:
                cout << "Meter\t";
                break;
            case 81:
                cout << "Outdoor Security Camera\t";
                break;
            case 82:
                cout << "Oven\t";
                break;
            case 83:
                cout << "Robot Vacuum\t";
                break;
            case 84:
                cout << "Siren\t";
                break;
            case 85:
                cout << "Smart Lock\t";
                break;
            case 86:
                cout << "Smoke & CO2 Detectors\t";
                break;
            case 87:
                cout << "Speaker\t";
                break;
            case 88:
                cout << "Thermostats\t";
                break;
            case 89:
                cout << "Video Doorbell\t";
                break;
            case 90:
                cout << "Window Sensors\t";
                break;
        }
        cout << state << endl;
    }
}
