#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

class room{
    public:
    int room_number;
    bool is_booked;
    string customer_name;

    // constructor;initializes room data and default values are provided for loading from files or creating new values

    room(int number= 0,bool booked = false, string name = ""){
        room_number = number;
        is_booked = booked;
        customer_name = name;
    }

    void checkIn(const string& name){
        if(is_booked){
            customer_name=name;
            is_booked=true;
            cout<<"check in succesful....\n";
        }
        else{
            cout<<"room is already booked...\n";

        }
    }
    void checkOut() {
    if (is_booked) {
        cout << "Customer checked out...\n";
        customer_name = "";
        is_booked = false;
    } else {
        cout << "Room is already empty.\n";
    }
}
void displaystatus() const{
    cout<<"room"<<room_number<<"-"<<(is_booked?"booked":"available");
    if(is_booked)cout<<"by"<<customer_name;
    cout<<endl;

}
// saving the room to the file 
//Converts room data into a single line string for saving in file.

string toFileString() const{
    return to_string(room_number)+" "+ to_string(is_booked)+" "+customer_name+ "\n";

}
//loading the room from the file
static room fromFileString(const string& line) {
    int num;
    bool booked;
    string name;
    istringstream iss(line);
    iss >> num >> booked;
    getline(iss, name);
    if (!name.empty() && name[0] == ' ') name = name.substr(1);  // remove leading space
    return room(num, booked, name);
}
//saving all rooms to room.txt
void saverooms(const vector<room> & rooms){
    ofstream out("room.txt");
    for ( const room& r:rooms){
        out << r.toFileString();
    }
    out.close();

}
//load all rooms from text file
vector<room> loadRooms(int totalRooms) {
    vector<room> rooms;
    ifstream in("rooms.txt");
    if (in) {
        string line;
        while (getline(in, line)) {
            rooms.push_back(room::fromFileString(line));
        }
        in.close();
    } else {
        for (int i = 1; i <= totalRooms; ++i) {
            rooms.push_back(room(i));
        }
    }
    return rooms;
}










};