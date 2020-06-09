#include "robot.hpp"

// core maze function for robot
void core(double vLeft, double vRight){
	
    takePicture();
	int row = 75;
	int average = (74 + 75 + 76 + 77) /4;
	int error = 0;
	double motorR = vRight;
	double motorL = vLeft;
	// for gets the current column and then gets the pixel at that column
    for (int column = 0; column < 150; column++){
		int pix = get_pixel(cameraView, 50, column, 3);
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
	if (error > 0){
		motorL = vLeft + error/vLeft;
	
	// calculates the error correction for the robot for right motor wheel
	} else if(error < 0){
		motorR = vRight - error/vRight;
	}
	
	// sets motor speed
	setMotors(motorL,motorR);   
    std::cout<<"\nvLeft="<<motorL<<"  vRight="<<motorR<<std::endl;
    usleep(10000);
        
}
void completion(double vLeft, double vRight) {
	 
	takePicture();
	int row = 75;
	int average = (74 + 75 + 76 + 77) /4;
	int error = 0;
	double motorR = vRight;
	double motorL = vLeft;
	// for gets the current column and the gets the pixel at that column
    for (int column = 0; column < 150; column++){
		int pix = get_pixel(cameraView, 50, column, 3);
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
	if (error > 0){
		motorL = vLeft + error/vLeft;
	
	// calculates the error correction for the robot for right motor wheel
	} else if(error < 0){
		motorR = vRight - error/vRight;
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
    double vLeft = 15.0;
    double vRight = 15.0;
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
		} else if (robotVersion == "completion") {
			completion(vLeft, vRight);
		}
				
  } //while
   
  return 0;

} // main
