#include <iostream>
#include <string>

using namespace std;

class PoliceOfficer {
    public:
        // constructor
        PoliceOfficer(string name, int badgeNumber) {
            this->name = name;
            this->badgeNumber = badgeNumber;
        }
        // getters and setters
        string getName() { return name; }
        int getBadgeNumber() { return badgeNumber; }
        void setName(string name) { this->name = name; }
        void setBadgeNumber(int badgeNumber) { this->badgeNumber = badgeNumber; }
        // other methods
        void patrol() {
            cout << name << " (badge number " << badgeNumber << ") is on patrol." << endl;
        }
        void arrest(string suspectName) {
            cout << name << " (badge number " << badgeNumber << ") arrested a suspect named " << suspectName << endl;
        }
    private:
        // instance variables
        string name;
        int badgeNumber;
};

int main()
{
    // Create a police officer with name Joe and badge number 100
    PoliceOfficer Joe( "Joe", 100 );
    // Output that Joe is on patrol
    Joe.patrol();
    // Joe arrests a suspect named Bob
    Joe.arrest( "Bob" );
    // Change Joe's name to John
    Joe.setName( "John" );
    // Output that John is on patrol
    Joe.patrol();
    // Joe arrests a suspect named John
    Joe.arrest( "John" );
    // Change Joe's badge number to 200
    Joe.setBadgeNumber( 200 );
    // Output that John is on patrol
    Joe.patrol();
    // Joe arrests a suspect named Jane
    Joe.arrest( "Jane" );
    return 0;
}