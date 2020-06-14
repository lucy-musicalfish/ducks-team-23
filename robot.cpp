#include "robot.hpp"

// core maze function for robot
void core(double vSpeed){
	
    takePicture();
	int row = cameraView.height*9/10 ; // robot sees the 10th row infront of it. Makes it so robot does not cut too much of corner
	int average = (74 + 75 + 76 + 77) /4; // where the white should be centered on the camera
	int error = 0; // how far off center the robot is
	double kp = 0.5; // the correction 
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
	
	// adjust motor speed based on erro and kp values
	double motorL = vSpeed + kp * error;
	double motorR = vSpeed - kp * error;
	
	// sets motor speed
	setMotors(motorL,motorR);   
    std::cout<<"\nvLeft="<<motorL<<"  vRight="<<motorR<<std::endl;
    usleep(10000);
}

// Completion code (Needs work a lot and needs functions to be broken into it)
void completion(double vSpeed) {
	 
	takePicture();
	
	int rowSelected = 80; // row used for width checking
	int columnLeft = 0; // keft side of camera
	int columnRight = cameraView.width - 1; // right side of camera
	int fovArraySize = cameraView.width + 2 * cameraView.height; // array size of number of pixels
	int* fov = new int[fovArraySize]; // array to store all pixels white or not
	
	double motorR = vSpeed -15;
	double motorL = vSpeed -15;
	
	// gets the left side of robot FOV for whiteness
    for (int column = 0; column < cameraView.width; column++) { 
		for (int row = rowSelected; row < cameraView.height; row++){
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
	for (int column = cameraView.width - 10; column < cameraView.width; column++) {
		for (int row = rowSelected; row < cameraView.height; row++){
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
	}
	int whiteCount = 0; // how many times in a row white apeears
	int sumCoords = 0; // the coords of the white in a rows
	bool fovContainsWhite = false;
	// iterate through all array values
	for (int pos = 0; pos < fovArraySize; pos++){
		
		// if white add to whiteCOunt and add the position to sumCoords
		if(fov[pos] == 1){
			std::cout<<fov[pos]<<std::endl;
			whiteCount += 1;
			sumCoords += pos;
			fovContainsWhite = true;
		}		
		else if(whiteCount != 0){ // checks if white count is not zero so only runs when it finds a white cluster
			std::cout<<"\nNumber of white pixels: "<<whiteCount<<std::endl;
			int averagePos = sumCoords / whiteCount; // calculates the average pixel location of the summed pos
			std::cout<<"Average white coord is: "<<averagePos<<std::endl;
			
			// needs  changing does not work.
			if (averagePos >= 0 && averagePos <= fovArraySize/2 - 2){ // else if there is white on the left change motor speed to enable us to go to it
				motorR = vSpeed + averagePos/vSpeed * vSpeed/10;
			}
			else if (averagePos >= fovArraySize/2 + 2 && averagePos <= fovArraySize){ // if there is white on the right change motor speed to enable us to go io it.
				motorL = vSpeed + averagePos/vSpeed * vSpeed/10;
			} 
			
		// reset whiteCount and sumcoords so that next itereationg of white patch ahs fresh values
			whiteCount =0;
			sumCoords = 0;
		}
		
	}
	if(fovContainsWhite == false) {
		motorR = -20;
		motorL = 20;
	}	
	
	// sets motor speed
	setMotors(motorL,motorR);   
    std::cout<<"\nvLeft="<<motorL<<"  vRight="<<motorR<<std::endl;
    usleep(10000);
}

// Challenge code (Needs work)
void challenge(double vSpeed) {
	 
	takePicture();
	
	int rowSelected = 80; // row used for width checking
	int columnLeft = 0; // left side of camera
	int columnRight = cameraView.width - 1; // right side of camera
	int fovArraySize = cameraView.width + 2 * cameraView.height; // array size of number of pixels
	int* fov = new int[fovArraySize]; // array to store all pixels white or not
	
	double motorR = vSpeed;
	double motorL = vSpeed;
	
	// gets the left side of robot FOV for whiteness
	for (int row = rowSelected; row < cameraView.height; row++){
		int pixRed = get_pixel(cameraView, row, columnLeft, 0);
		int pixGreen = get_pixel(cameraView, row, columnLeft, 1);
		int pixBlue = get_pixel(cameraView, row, columnLeft, 2);
		int isRed;
		
		// check if left side is red
		if (pixRed > 250 && pixGreen < 50 && pixBlue < 50){
			isRed =1;
		}else {
			isRed = 0;
		}
		// adds the pixel to the overall array
		fov[row] = isRed;
	}
	
	// gets the center side of robot FOV for whiteness
    for (int column = 0; column < cameraView.width; column++){
		int pixRed = get_pixel(cameraView, rowSelected, column, 0);
		int pixGreen = get_pixel(cameraView, rowSelected, column, 1);
		int pixBlue = get_pixel(cameraView, rowSelected, column, 2);
		int isRed;
		
		// check if middle is red
		if (pixRed > 250 && pixGreen < 50 && pixBlue < 50){
			isRed = 1;
		}else {
			isRed = 0;
		}
		// adds the pixel to the overall array
		fov[cameraView.height + column] = isRed;
	}
	
	// gets the right side of robot FOV for whiteness
	for (int row = rowSelected; row < cameraView.height; row++){
		int pix = get_pixel(cameraView, row, columnRight, 3);
		int pixRed = get_pixel(cameraView, row, columnRight, 0);
		int pixGreen = get_pixel(cameraView, row, columnRight, 1);
		int pixBlue = get_pixel(cameraView, row, columnRight, 2);
		int isRed;
		
		// check if right side is red
		if (pixRed > 250 && pixGreen < 50 && pixBlue < 50){
			isRed =1;
		}else {
			isRed = 0;
		}
		// adds the pixel to the overall array
		fov[cameraView.height + cameraView.width + row] = isRed;
	}
	int redCount = 0; // how many times in a row red appears
	int sumCoords = 0; // the coords of the white in a rows
	int averagePos = 0;
	bool fovContainsRed = false;
	
	int* redPos = new int[2] {0, 0}; // used to determine if there is red on the left sid eof robot or right side of robot or both
	// iterate through all array values
	for (int pos = 0; pos < fovArraySize; pos++){
		
		// if white add to whiteCOunt and add the position to sumCoords
		if(fov[pos] == 1){
			//std::cout<<fov[pos]<<std::endl;
			redCount += 1;
			sumCoords += pos;
			fovContainsRed = true;
			
			
		} else if(redCount > 0){ // checks if white count is not zero so only runs when it finds a red cluster
			averagePos = sumCoords / redCount; // calculates the average pixel location of the summed pos
			
			// thouht I could use the fact that when you split the FOVarraysize in half you would know if the position is on the left or right of screen and use this to determine if a U bend had shown up.
			if (averagePos > fovArraySize /2){
				redPos[1] = averagePos;
			}else {
				redPos[0] = averagePos;
			}
			
			std::cout<<"\nNumber of red pixels: "<<redCount<<std::endl;
			std::cout<<"Average red coord is: "<<averagePos<<std::endl;
			
			if (averagePos > 100 && averagePos < 200 && get_pixel(cameraView, rowSelected, cameraView.width/2, 3) < 250){ // if position is higher than follow left but less than a wall on the right and no white line is detected
				// rotate right to realign with maze
				motorR = -2.5;
				motorL = 2.5;
			}
			
			// reset redCount and sumCoords so that next itereationg of white patch ahs fresh values
			redCount =0;
			sumCoords = 0;
			
		}
		
	}
	
	// checks if robot has no red or white line and then rotates it.
	if(fovContainsRed == false && get_pixel(cameraView, rowSelected, cameraView.width/2, 3) < 250) {
		motorR = 15;
		motorL = -15;
		
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
    double vSpeed = 30.0;
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
			core(vSpeed);
		} else if (robotVersion == "completion") {
			completion(vSpeed);
		} else if (robotVersion == "challenge") {
			challenge (vSpeed);
		}
	
		
  } //while
  
  return 0;

} // main
