#include "robot.hpp"

// core maze function for robot
void core(double vLeft, double vRight){
	
    takePicture();
	int row = 95; //changed the number to 95 since this is closer to the robot and will give it more accuracy in turning
	int average = (74 + 75 + 76 + 77) /4;
	int error = 0;
	double motorR = vRight;
	double motorL = vLeft ;
	// for gets the current column and the gets the pixel at that column
    for (int column = 0; column < cameraView.width; column++){
		int pix = get_pixel(cameraView, row, column, 3);
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
		motorL = vLeft + error/vLeft * vLeft/2; //added *vleft/2 to give the turning more range. this allows the robot to go faster than 15 without going off course..
	
	// calculates the error correction for the robot for right motor wheel
	} else if(error < 0){
		motorR = vRight - error/vRight * vRight/2;//added *vRIght/2 to give the robot more tunring range. the robot can now go faster than 15 without going off course.
	}
	
	// sets motor speed
	setMotors(motorL,motorR);   
    std::cout<<"\nvLeft="<<motorL<<"  vRight="<<motorR<<std::endl;
    usleep(10000);
}

// Completion code (Needs work a lot and needs functions to be broken into it)
void completion(double vLeft, double vRight) {
	 
	takePicture();
	
	int rowSelected = 0; // row used for width checking
	int columnLeft = 0; // keft side of camera
	int columnRight = cameraView.width - 1; // right side of camera
	int fovArraySize = cameraView.width + 2 * cameraView.height; // array size of number of pixels
	int* fov = new int[fovArraySize]; // array to store all pixels white or not
	
	double motorR = vRight -20;
	double motorL = vLeft -20;
	
	// gets the left side of robot FOV for whiteness
    for (int row = 0; row < rowSelected; row++){
		int pix = get_pixel(cameraView, row, columnLeft, 3);
		int isWhite;
		
		// checks if pixel colour is white
		if(pix > 250){
			isWhite = 1;
			
		} else {
			isWhite = 0;
		}
		// adds the pixel to the overall array
		fov[row] = isWhite;
	}
	
	// gets the center side of robot FOV for whiteness
    for (int column = 0; column < cameraView.width; column++){
		int pix = get_pixel(cameraView, rowSelected, column, 3);
		int isWhite;
		
		// checks if pixel colour is white
		if(pix > 250){
			isWhite = 1;
			
		} else {
			isWhite = 0;
		}
		// adds the pixel to the overall array
		fov[cameraView.height + column] = isWhite;
	}
	
	// gets the right side of robot FOV for whiteness
	for (int row = 0; row < rowSelected; row++){
		int pix = get_pixel(cameraView, row, columnRight, 3);
		int isWhite;
		
		// checks if pixel colour is white
		if(pix > 250){
			isWhite = 1;
			
		} else {
			isWhite = 0;
		}
		// adds the pixel to the overall array
		fov[cameraView.height + cameraView.width + row] = isWhite;
	}
	
	int whiteCount = 0; // how many times in a row white apeears
	int sumCoords = 0; // the coords of the white in a rows
	// iterate through all array values
	for (int pos = 0; pos < fovArraySize; pos++){
		
		// if white add to whiteCOunt and add the position to sumCoords
		if(fov[pos] == 1){
			std::cout<<fov[pos]<<std::endl;
			whiteCount += 1;
			sumCoords += pos;
		}		
		else if(whiteCount != 0){ // checks if white count is not zero so only runs when it finds a white cluster
			std::cout<<"\nNumber of white pixels: "<<whiteCount<<std::endl;
			int averagePos = sumCoords / whiteCount; // calculates the average pixel location of the summed pos
			std::cout<<"Average white coord is: "<<averagePos<<std::endl;
			
			// needs  changing does not work.
			if (averagePos >= fovArraySize/2 + 2 && averagePos <= fovArraySize){ // if there is white on the right change motor speed to enable us to go io it.
				motorL = vLeft + averagePos/vLeft;
			} 
			else if (averagePos >= 0 && averagePos <= fovArraySize/2 - 2){ // else if there is white on the left change motor speed to enable us to go to it
				motorR = vRight + averagePos/vRight;
			}
			
		// reset whiteCount and sumcoords so that next itereationg of white patch ahs fresh values
			whiteCount =0;
			sumCoords = 0;
		}
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
		} else if (robotVersion == "completion") {
			completion(vLeft, vRight);
		}
		
  } //while
  
  return 0;

} // main
