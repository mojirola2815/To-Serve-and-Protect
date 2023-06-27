#include <stdio.h>
#include <stdlib.h>

#define MAX_POLICE_SIZE 2000

// Struct to represent a police officer
typedef struct 
{
  int officerID;
  char *name;
  int rank;
  char *gender;

} PoliceOfficer;

// Initialize the police officers
PoliceOfficer policeOfficers[MAX_POLICE_SIZE];

// Function declarations
void initializeOfficer(int officerID, char *name, int rank, char *gender);
void patrolArea(PoliceOfficer *officer, char *area);
void respondToEmergency(PoliceOfficer *officer, char *emergency);
void arrestSuspect(PoliceOfficer *officer, char *suspect);
void investigateCrime(PoliceOfficer *officer, char *crime);
void administerJustice(PoliceOfficer *officer, char *case);

// Main function
int main() 
{
  // Initialize the police officers
  initializeOfficer(1, "Bart Simpson", 2, "Male");
  initializeOfficer(2, "Lisa Simpson", 1, "Female");
  initializeOfficer(3, "Marge Simpson", 3, "Female");
  initializeOfficer(4, "Homer Simpson", 4, "Male");

  // Let the officers patrol the city
  printf("The officers start their patrol...\n");
  patrolArea(&policeOfficers[0], "Springfield");
  patrolArea(&policeOfficers[1], "Springfield");
  patrolArea(&policeOfficers[2], "Springfield");
  patrolArea(&policeOfficers[3], "Springfield");

  // Respond to an emergency
  printf("\nThe officers respond to an emergency call...\n");
  respondToEmergency(&policeOfficers[0], "Robbery");
  respondToEmergency(&policeOfficers[1], "Robbery");
  respondToEmergency(&policeOfficers[2], "Robbery");
  respondToEmergency(&policeOfficers[3], "Robbery");

  // Arrest a suspect
  printf("\nThe officers arrest a suspect...\n");
  arrestSuspect(&policeOfficers[0], "Burl Grimes");
  arrestSuspect(&policeOfficers[1], "Burl Grimes");
  arrestSuspect(&policeOfficers[2], "Burl Grimes");
  arrestSuspect(&policeOfficers[3], "Burl Grimes");

  // Investigate a crime
  printf("\nThe officers investigate a crime...\n");
  investigateCrime(&policeOfficers[0], "Grand Theft Auto");
  investigateCrime(&policeOfficers[1], "Grand Theft Auto");
  investigateCrime(&policeOfficers[2], "Grand Theft Auto");
  investigateCrime(&policeOfficers[3], "Grand Theft Auto");

  // Administer justice
  printf("\nThe officers administer justice...\n");
  administerJustice(&policeOfficers[0], "Burl Grimes");
  administerJustice(&policeOfficers[1], "Burl Grimes");
  administerJustice(&policeOfficers[2], "Burl Grimes");
  administerJustice(&policeOfficers[3], "Burl Grimes");

  printf("\nTo Serve and Protect!\n");

  return 0;
}

// Function definitions
void initializeOfficer(int officerID, char *name, int rank, char *gender)
{
  policeOfficers[officerID].officerID = officerID;
  policeOfficers[officerID].name = name;
  policeOfficers[officerID].rank = rank;
  policeOfficers[officerID].gender = gender;
}

void patrolArea(PoliceOfficer *officer, char *area)
{
  printf("Officer %s is patrolling in %s\n", officer->name, area);
}

void respondToEmergency(PoliceOfficer *officer, char *emergency)
{
  printf("Officer %s is responding to %s\n", officer->name, emergency);
}

void arrestSuspect(PoliceOfficer *officer, char *suspect)
{
  printf("Officer %s is arresting %s\n", officer->name, suspect);
}

void investigateCrime(PoliceOfficer *officer, char *crime)
{
  printf("Officer %s is investigating %s\n", officer->name, crime);
}

void administerJustice(PoliceOfficer *officer, char *case)
{
  printf("Officer %s is administering justice for %s\n", officer->name, case);
}