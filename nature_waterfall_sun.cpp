#include <iostream> 
#include <string> 

using namespace std; 

// function to update the status of a citizen 
void UpdateCitizenStatus(int citizenID, string status)
{ 
	// printing the message
	cout << "Updating citizen status with ID " << citizenID << " to " << status << endl; 

	// Updating the status of the citizen 
	// in the database using a SQL statement 
	string updateStatusQuery = "UPDATE citizens SET status = '" + status + "' WHERE id = " + citizenID; 

	// executing the statement 
	cout << "Executing the query " << updateStatusQuery << endl; 
} 

// function to add a new incident to the database 
void AddIncident(string incidentType, string incidentLocation)
{ 
	// printing the message
	cout << "Adding incident of type " << incidentType << " at " << incidentLocation << endl; 

	// Updating the status of the citizen 
	// in the database using a SQL statement 
	string addIncidentQuery = "INSERT INTO incidents(type, location) VALUES('" + incidentType + "', '" + incidentLocation + "')";

	// executing the statement 
	cout << "Executing the query " << addIncidentQuery << endl; 
} 

// function to assign police officers to investigate an incident 
void AssignPoliceOfficers(string incidentID, int noOfOfficers)
{ 
	// printing the message
	cout << "Assigning " << noOfOfficers << " officers to investigate incident with ID " << incidentID << endl; 

	// Assigning the police officers
	// using a SQL statement 
	string assignOfficersQuery = "INSERT INTO officers_assigned (incidentID, no_of_officers) VALUES('" + incidentID + "', " + noOfOfficers + ")";

	// executing the statement 
	cout << "Executing the query " << assignOfficersQuery << endl; 
} 

// function to update the status of an incident 
void UpdateIncidentStatus(int incidentID, string status)
{ 
	// printing the message
	cout << "Updating incident status with ID " << incidentID << " to " << status << endl; 

	// Updating the status of the incident 
	// in the database using a SQL statement 
	string updateStatusQuery = "UPDATE incidents SET status = '" + status + "' WHERE id = " + incidentID; 

	// executing the statement 
	cout << "Executing the query " << updateStatusQuery << endl; 
} 

// function to display the status of a citizen 
void DisplayCitizenStatus(int citizenID)
{ 
	// printing the message
	cout << "Displaying citizen status with ID " << citizenID << endl; 

	// Retrieving the status of the citizen 
	// in the database using a SQL statement 
	string retrieveStatusQuery = "SELECT status FROM citizens WHERE id = " + citizenID; 

	// executing the statement 
	cout << "Executing the query " << retrieveStatusQuery << endl; 
} 

// function to display the status of an incident 
void DisplayIncidentStatus(int incidentID)
{ 
	// printing the message
	cout << "Displaying incident status with ID " << incidentID << endl; 

	// Retrieving the status of the incident 
	// in the database using a SQL statement 
	string retrieveStatusQuery = "SELECT status FROM incidents WHERE id = " + incidentID; 

	// executing the statement 
	cout << "Executing the query " << retrieveStatusQuery << endl; 
} 

// function to retrieve the number of police officers assigned to an incident 
void DisplayNoOfOfficers(int incidentID)
{ 
	// printing the message
	cout << "Retrieving the number of officers assigned to incident with ID " << incidentID << endl; 

	// Retrieving the number of officers 
	// in the database using a SQL statement 
	string retrieveOfficersQuery = "SELECT no_of_officers FROM officers_assigned WHERE incidentID = " + incidentID; 

	// executing the statement 
	cout << "Executing the query " << retrieveOfficersQuery << endl; 
} 

int main() 
{ 
	// To serve and protect 
	cout << "Welcome to the Police Department" << endl; 
	cout << "--------------------------------" << endl; 

	// examples of using the various functions 
	UpdateCitizenStatus(1, "safe"); 
	AddIncident("assault", "123 Main Street"); 
	AssignPoliceOfficers("1", 10); 
	UpdateIncidentStatus(1, "investigated"); 
	DisplayCitizenStatus(1); 
	DisplayIncidentStatus(1); 
	DisplayNoOfOfficers(1); 

	return 0; 
}