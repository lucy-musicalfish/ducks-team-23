#include "robot.hpp"

// core maze function for robot
void core(double vLeft, double vRight){
	
    takePicture();
    
	int row = 95; //changed row to 95, and used row. the 95 is closer to the robot and makes it better at fowlling the line. cause 50 is halfway into the robots view.
	int average = (74 + 75 + 76 + 77) /4;
	int error = 0;
	double motorR = vRight;
	double motorL = vLeft;
	// for gets the current column and the gets the pixel at that column
    for (int column = 0; column < 150; column++){
		int pix = get_pixel(cameraView, row, column, 3); //used row instead of "50"
		int isWhite;
		
		// checks if pixel colour is white
		if(pix > 250){
			isWhite = 1;
			// determines the error that the white line is at. If the column of the white does not equal the rough middle of the camera
			if(column != average - 2 || column != average - 1 || column != average || column != average + 1){
				error = column - average;
			}
			
		} else {
			isWhite = 0;
		}
		std::cout<<isWhite<<" ";
	}
	
	// calculates the error correction for the robot for left motor wheel
	
	//changed to make it turn at high speeds. last version only changed the speed by a small amount. adding the * vleft or vRight made the turn have a bighger change. making it not come off track at high speeds cause the tunrning has a bigger range now.
	if (error > 0){
		
		motorL = vLeft + error/vLeft * vLeft/2;
		
	
	// calculates the error correction for the robot for right motor wheel
	} else if(error < 0){
		motorR = vRight - error/vRight * vRight/2;
	}
	
	// sets motor speed
	setMotors(motorL,motorR); 
	  
    std::cout<<"\nvLeft="<<motorL<<"  vRight="<<motorR<<std::endl;
    usleep(10000);
        
}

int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
    double vLeft = 30.0;
    double vRight = 30.0;
    std::string robotVersion;
    
    while(1){ // Allows the user to choose what robot version to use 
		std::cout<<"What Robot version are you running? (core, completion, or challenge)"<<std::endl;
		std::cin>>robotVersion;
		
		for(int i = 0; i< robotVersion.length(); i++){ // Converts the robotVersion to lowercase so any variation of the three are accepted
			robotVersion[i] = tolower(robotVersion[i]);
		}
		if(robotVersion == "core"||robotVersion == "completion"||robotVersion == "challenge"){ // Checks if the user entered a valid robotVersion. If not makes them reenter a version
			break;
		} else {
			std::cout<<"That robot version does not exist. Please try again."<<std::endl;
		}
	}
	
    while(1){
		if (robotVersion == "core"){
			core(vLeft, vRight);
		}
		
  } //while
  
  return 0;

} // main
