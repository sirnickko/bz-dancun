#include<iostream>
#include<string>
#include<fstream>
#include<vector>

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

string tofilestring() const{
    return to_string(room_number)+" "+ to_string(is_booked)+" "+customer_name+ "\n";

}








}