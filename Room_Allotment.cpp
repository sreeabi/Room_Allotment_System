#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Booking {
    string start, end;
    bool operator<(const Booking &b) const {
        return start < b.start; // Sort by start time
    }
};

class Room {
public:
    int roomNumber;
    string roomType;
    int chairsAvailable;
    bool isBooked;
    string host;
    string startTime;
    string endTime;
    set<Booking> schedule; // Prevent time clashes

    Room(int number, string type, int chairs) {
        roomNumber = number;
        roomType = type;
        chairsAvailable = chairs;
        isBooked = false;
    }

    bool checkOverlap(string start, string end) {
        Booking newB{start, end};
        auto it = schedule.lower_bound(newB);
        if (it != schedule.end() && it->start < end) return true;
        if (it != schedule.begin()) {
            --it;
            if (it->end > start) return true;
        }
        return false;
    }

    void addBooking(string hostName, string start, string end, int chairs) {
        host = hostName;
        startTime = start;
        endTime = end;
        chairsAvailable = chairs;
        isBooked = true;
        schedule.insert({start, end});
        cout << "✅ Room " << roomNumber << " (" << roomType << ") booked successfully!\n";
    }

    void displayStatus() {
        cout << "\n--- Room " << roomNumber << " (" << roomType << ") ---\n";
        cout << "Chairs Available: " << chairsAvailable << "\n";
        cout << "Status: " << (isBooked ? "Booked" : "Available") << "\n";
        if (isBooked) {
            cout << "Host: " << host << "\n";
            cout << "Time Slot: " << startTime << " - " << endTime << "\n";
        }
        cout << "---------------------------\n";
    }
};

class BookingSystem {
private:
    unordered_map<int, Room*> rooms;
    vector<string> roomTypes = {
        "Meeting Hall", "Break Room", "Workspace Room",
        "Kitchen Room", "Coffee Table Room", "Lean Back Room", "Staff Room"
    };

public:
    void scheduleRoom() {
        // Step 1: Book a type of room
        cout << "Select Room Type:\n";
        for (int i = 0; i < roomTypes.size(); i++) {
            cout << i + 1 << ". " << roomTypes[i] << "\n";
        }
        int typeChoice;
        cout << "Enter choice: ";
        cin >> typeChoice;
        if (typeChoice < 1 || typeChoice > roomTypes.size()) {
            cout << "❌ Invalid choice.\n";
            return;
        }
        string chosenType = roomTypes[typeChoice - 1];

        // Step 2: Set the host
        string host;
        cin.ignore();
        cout << "Enter Host Name: ";
        getline(cin, host);

        // Step 3: Set the start time
        string start;
        cout << "Enter Start Time (HH:MM): ";
        getline(cin, start);

        // Step 4: Set the end time
        string end;
        cout << "Enter End Time (HH:MM): ";
        getline(cin, end);

        // Step 5: Set chair booking capability
        int chairsNeeded;
        cout << "Enter Chairs Needed: ";
        cin >> chairsNeeded;

        // Step 6: Define room number
        int roomNo;
        cout << "Enter Room Number: ";
        cin >> roomNo;

        // Check if room exists, if not create it
        if (rooms.find(roomNo) == rooms.end()) {
            rooms[roomNo] = new Room(roomNo, chosenType, chairsNeeded);
        }

        Room* room = rooms[roomNo];

        // Check overlap
        if (room->checkOverlap(start, end)) {
            cout << "❌ Time slot overlaps with existing booking.\n";
            return;
        }

        // Check chairs
        if (chairsNeeded > room->chairsAvailable) {
            cout << "❌ Not enough chairs available.\n";
            return;
        }

        // Book the room
        room->addBooking(host, start, end, chairsNeeded);
    }

    void checkStatus(int roomNo) {
        if (rooms.find(roomNo) == rooms.end()) {
            cout << "❌ Room not found.\n";
            return;
        }
        rooms[roomNo]->displayStatus();
    }

    void showAllRooms() {
        for (auto& r : rooms) {
            r.second->displayStatus();
        }
    }
};

int main() {
    BookingSystem system;
    int choice;

    while (true) {
        cout << "\n===== Room Scheduling System =====\n";
        cout << "1. Schedule Room (6-step process)\n";
        cout << "2. Check Room Status\n";
        cout << "3. Show All Rooms\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            system.scheduleRoom();
        }
        else if (choice == 2) {
            int num;
            cout << "Enter Room Number: ";
            cin >> num;
            system.checkStatus(num);
        }
        else if (choice == 3) {
            system.showAllRooms();
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "❌ Invalid choice!\n";
        }
    }
    return 0;
}