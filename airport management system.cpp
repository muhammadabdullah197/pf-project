#include <iostream>
#include <string>
using namespace std;

struct Flight {
    int flightNo;
    string origin;
    string destination;
    string time;
};

const int MAX_FLIGHTS = 100;
Flight flights[MAX_FLIGHTS];
int totalFlights = 0;

void addFlight() {
    if (totalFlights >= MAX_FLIGHTS) {
        cout << "\nFlight list is full!\n";
        return;
    }

    Flight f;
    cout << "\nEnter Flight Number: ";
    cin >> f.flightNo;
    cout << "Enter Origin: ";
    cin >> f.origin;
    cout << "Enter Destination: ";
    cin >> f.destination;
    cout << "Enter Departure Time: ";
    cin >> f.time;

    flights[totalFlights] = f;
    totalFlights++;

    cout << "\n Flight added successfully!\n";
}


void viewFlights() {
    if (totalFlights == 0) {
        cout << "\nNo flights available!\n";
        return;
    }

    cout << "\n----- All Flights -----\n";
    for (int i = 0; i < totalFlights; i++) {
        cout << "Flight No: " << flights[i].flightNo
             << " From: " << flights[i].origin
             << " To: " << flights[i].destination
             << " Time: " << flights[i].time << endl;
    }
}

void searchFlight() {
    if (totalFlights == 0) {
        cout << "\nNo flights available to search!\n";
        return;
    }

    int searchNo;
    cout << "\nEnter Flight Number to search: ";
    cin >> searchNo;

    bool found = false;
    for (int i = 0; i < totalFlights; i++) {
        if (flights[i].flightNo == searchNo) {
            cout << "\nFlight Found!\n";
            cout << "Flight No: " << flights[i].flightNo
                 << " From: " << flights[i].origin
                 << " To: " << flights[i].destination
                 << " Time: " << flights[i].time << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nFlight not found!\n";
}

void adminMenu() {
    string password;
    cout << "\nEnter Admin Password: ";
    cin >> password;

    if (password != "PointedFellows") {
        cout << "\n Access Denied!\n";
        return;
    }

    int choice;
    do {
        cout << "\n----- Admin Menu -----\n";
        cout << "1. Add Flight\n";
        cout << "2. View All Flights\n";
        cout << "3. Search Flight\n";
        cout << "4. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addFlight();
                break;
            case 2:
                viewFlights();
                break;
            case 3:
                searchFlight();
                break;
            case 4:
                cout << "\nLogging out...\n";
                break;
            default:
                cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 4);
}

void userMenu() {
    int choice;
    do {
        cout << "\n----- User Menu -----\n";
        cout << "1. View Flights\n";
        cout << "2. Search Flight\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewFlights();
                break;
            case 2:
                searchFlight();
                break;
            case 3:
                cout << "\nReturning to main menu...\n";
                break;
            default:
                cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 3);
}

int main() {
    int choice;

    do {
        cout << "\n----- Airport Management System -----\n";
        cout << "1. Admin Mode\n";
        cout << "2. User Mode\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                adminMenu();
                break;
            case 2:
                userMenu();
                break;
            case 3:
                cout << "\nThank you \n";
                break;
            default:
                cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}