# 🏢 Room Allotment & Booking System

* A simple yet efficient Room Booking CLI application written in C++ using Advanced Data Structures.
* The program allows users to book different types of rooms, assign hosts, set schedules, and check availability — all while preventing overlapping bookings and saving data persistently.

-----------------------------------------------------

# 📋 Features
6-Step Guided Room Booking:

1. Select a Room Type:

    Meeting Hall

    Break Room

    Workspace Room

    Kitchen Room

    Coffee Table Room

    Lean Back Room

    Staff Room

2. Set the Host name.

3. Set the Start Time.

4. Set the End Time.

5. Set the Chair Booking Capability.

6. Define the Room Number.

Prevents time slot overlaps using set<Booking>.

Stores and retrieves data from a data/ folder for persistent bookings.

Displays room status with host, time slot, and chair details.

Shows all rooms (booked or available).

Automatically creates new rooms if they don’t exist.

-----------------------------------------------------

# 🚀 Getting Started

Prerequisites
C++17 compiler (e.g., g++).

Basic knowledge of compiling and running C++ programs.

-----------------------------------------------------

# How to use

When you start the program, You'Ll see a Menu

===== Room Scheduling System =====
1. Schedule Room (6-step process)
2. Check Room Status
3. Show All Rooms
4. Exit

-----------------------------------------------------

# Installation & Run

# 1️⃣ Clone the repository
git clone https://github.com/your-username/room-booking-system.git
cd room-booking-system

# 2️⃣ Compile the code
g++ main.cpp -o booking_system

# 3️⃣ Run the program
./booking_system


-----------------------------------------------------

# File Structure

room-booking-system/
├── main.cpp        # Main program with all logic
├── data/           # Stores persistent booking data
│   └── bookings.txt
└── README.md       # Project documentation

-----------------------------------------------------

# Sample Output

===== Room Scheduling System =====
1. Schedule Room (6-step process)
2. Check Room Status
3. Show All Rooms
4. Exit

Enter choice: 1

Select Room Type:
1. Meeting Hall
2. Break Room
3. Workspace Room
4. Kitchen Room
5. Coffee Table Room
6. Lean Back Room
7. Staff Room


Enter choice: 1

Enter Host Name: John Smith

Enter Start Time (HH:MM): 10:00

Enter End Time (HH:MM): 12:00

Enter Chairs Needed: 20

Enter Room Number: 101

✅ Room 101 (Meeting Hall) booked successfully!

-----------------------------------------------------
