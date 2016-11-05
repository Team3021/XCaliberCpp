#include "WPILib.h"
#include "XCaliberShared.hpp"
#include "XCaliber.hpp"
#include "XCaliberObjects.hpp"

int AutoMode;
double overArching;
bool AutoCondition;


XCaliber::XCaliber(){

	StopWatch = new Timer();
	AutoCondition = false;
}

void XCaliber::RobotInit(){

		AutoMode=0;
		initialize();
		c->Start();
}

int XCaliber::GetAutonomousMode(){
   int mode_value = 0;
   if(SmartDashboard::GetBoolean("DB/Button 1", false)) {
      mode_value = 1;
   }
   if(SmartDashboard::GetBoolean("DB/Button 2", false)) {
	  mode_value += 2;
   }
   if(SmartDashboard::GetBoolean("DB/Button 3", false)) {
	  mode_value += 4;
   }
   return mode_value;
}

void XCaliber::AutonomousInit(){
	StopWatch->Reset();
	StopWatch->Start();

    myDrive->AutoInit();
    AutoMode = GetAutonomousMode();
	switch(AutoMode){
		case 1:
		   SmartDashboard::PutString("DB/String 0", "Auto Mode 1");
	       break;
		case 2:
		   SmartDashboard::PutString("DB/String 0", "Auto Mode 2");
	       break;
		case 3:
		   SmartDashboard::PutString("DB/String 0", "Auto Mode 3");
	       break;
		case 4:
		   SmartDashboard::PutString("DB/String 0", "Auto Mode 4");
	       break;
		case 5:
		   SmartDashboard::PutString("DB/String 0", "Auto Mode 5");
	       break;
		case 6:
		   SmartDashboard::PutString("DB/String 0", "Auto Mode 6");
	       break;
		case 7:
		   SmartDashboard::PutString("DB/String 0", "Auto Mode 7");
	       break;
		default:
		   AutoMode = 0;
		   SmartDashboard::PutString("DB/String 0", "Auto Mode 0");
		   break;
	}
}

void XCaliber::AutonomousPeriodic(){
	overArching = StopWatch->Get();
	Wait(0.001);
	printf("Total Overarching: %f", overArching);
	myDrive->Auto();
	myLauncher->Auto();


}

void XCaliber::TeleopInit(){
	//define some values here; maybe reset encoders
}

void XCaliber::TeleopPeriodic(){

	myDrive->TeleOp();
	myLauncher->TeleOp();
	//myLifter -> TeleOp();
	//myCamera->TeleOp();  // Comment if you do not want multiple cams

}


XCaliber::~XCaliber(){
	delete myDrive;
	delete myLauncher;

}

