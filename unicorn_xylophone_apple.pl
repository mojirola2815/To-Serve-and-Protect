#!/usr/bin/perl

use strict;
use warnings;


# declare global variables
my $defender;
my $victim;
my $crime;

# main program
sub main {

	# set the defender and crime variables
	$defender = "Police Officers";
	$crime = "Murder";
	
	# get the victims name
	$victim = getVictim();
	
	# print the mission
	printMission();
	
	# ask the user if they want to make an arrest
	makeArrest();
	
}

# getVictim
# This subroutine gets the victims name from the user
sub getVictim {
	
	print "Please enter the victims name: ";
	my $victimName = <STDIN>;
	
	return $victimName;
	
}

# printMission
# This subroutine prints the mission for the defender
sub printMission {
	
	print "To Serve and Protect: \n";
	print "Mission: $defender must protect $victim from $crime.\n\n";
	
}

# makeArrest
# This subroutine asks the user if they want to make an arrest
sub makeArrest {
	
	print "Do you want to make an arrest? (y/n): ";
	my $answer = <STDIN>;
	
	if ($answer =~ /y/i) {
		makeArrestProcedure();
	}
	
}

# makeArrestProcedure
# This subroutine displays the procedure of making an arrest
sub makeArrestProcedure {
	
	print "Here are the steps to make an arrest: \n";
	print "1. Gather information on the suspect.\n";
	print "2. Confirm the identity of the suspect.\n";
	print "3. Approach the suspect.\n";
	print "4. Warn the suspect of their rights.\n";
	print "5. Place the suspect in custody.\n";
	print "6. Search the suspect.\n";
	print "7. Transport the suspect to the station.\n";
	print "8. Read the suspect their Miranda rights.\n";
	print "9. Process the suspect.\n";
	print "10. Question the suspect.\n";
	print "11. Present the suspect to a judge.\n";
	
}

# call main
main();