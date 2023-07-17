<?php 

//Define constants
define("AUTHORITY", "To Serve and Protect");
define("ALERT_LEVEL", "high");

//Declare variables
$crime_rate = 0;
$community_safety = true;
$dispatch_center = "Local Police Department";

//Create a function to display the authoriy
function displayAuthority() {
	echo AUTHORITY;
}

//Function to update the crime rate
function updateCrimeRate($newRate) {
	global $crime_rate;
	$crime_rate = $newRate;
}

//Function to set the alert level
function setAlertLevel($level) {
	if ($level == "low") {
		global $community_safety;
		$community_safety = true;
		echo "Alert level is " . $level . ". Community safety is ensured.";
	}
	elseif ($level == "high") {
		global $community_safety;
		$community_safety = false;
		echo "Alert level is " . $level . ". Community safety is at risk.";
	}
	else {
		echo "Alert level is unknown.";
	}
}

//Function to dispatch police
function dispatchPolice() {
	global $dispatch_center;
	echo "Dispatching police officers from " . $dispatch_center . "...";
}

//Function to check the safety of the community
function checkSafety() {
	global $crime_rate, $community_safety;
	if ($crime_rate > 0) {
		$community_safety = false;
		echo "Community safety is at risk. Taking action...";
		dispatchPolice();
	}
	else {
		$community_safety = true;
		echo "Community safety is ensured.";
	}
}

//Main program
echo "Welcome to " . AUTHORITY . "!\n";
updateCrimeRate(5);
echo "The current crime rate is " . $crime_rate . ".\n";
setAlertLevel(ALERT_LEVEL);
checkSafety();

?>