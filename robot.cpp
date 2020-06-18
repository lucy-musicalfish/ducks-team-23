#include "robot.hpp"

/**Core Code*/
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
	
	// adjust motor speed based on error and kp values
	double motorL = vSpeed + kp * error;
	double motorR = vSpeed - kp * error;
	
	// sets motor speed
	setMotors(motorL,motorR);   
    std::cout<<"\nvLeft="<<motorL<<"  vRight="<<motorR<<std::endl;
    usleep(10000);
}

/**Completion Code*/
void completion(double vSpeed) {
	 
	takePicture();
	
	int rowSelected = 80; // row used for width checking
	int columnLeft = 0; // left side of camera
	int columnRight = cameraView.width - 1; // right side of camera
	int fovArraySize = cameraView.width + 2 * cameraView.height; // array size of number of pixels
	int* fov = new int[fovArraySize]; // array to store all pixels white or not
	
	double motorR = vSpeed -15;
	double motorL = vSpeed -15;
	
	// gets the left side of robot FOV for whiteness
    for (int column = 0; column < cameraView.width; column++) { 
		for (int row = rowSelected; row < cameraView.height; row++){
			// get the pixel colour at our current row and columnLeft
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
			// get the pixel colour at our current row and columnLeft
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
			// get the pixel colour at our current row and columnLeft
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
		
		// if white add to whiteCount and add the position to sumCoords
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
			
			// motor speed changer if the white is not in the center of the camera.
			if (averagePos >= 0 && averagePos <= fovArraySize/2 - 2){ // if there is white on the left change motor speed to enable us to go to it
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
	// If robot has reached a deadend where the white is gone. Make it turn around.
	if(fovContainsWhite == false) {
		motorR = -20;
		motorL = 20;
	}	
	
	// sets motor speed
	setMotors(motorL,motorR);   
    std::cout<<"\nvLeft="<<motorL<<"  vRight="<<motorR<<std::endl;
    usleep(10000);
}


/**Challenge Code*/
void challenge(double vSpeed) {
	 
	takePicture();
	
	int rowSelected = 80; // row used for width checking
	int columnLeft = 5; // left side of camera
	int columnHeight = cameraView.height - rowSelected; // the amount of pixels between our robot and rowSelected
	
	int fovArraySize = cameraView.width + columnHeight; // array size of number of pixels
	int* fov = new int[fovArraySize]; // array to store all pixels white or not
	
	// default motor speeds
	double motorR = vSpeed;
	double motorL = vSpeed;
	
	// gets the left side of robot FOV for whiteness
	for (int row = rowSelected; row < cameraView.height; row++){
		
		// gets the red, green, and blue values of the pixel
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
		fov[row - rowSelected] = isRed;
	}
	
	// gets the center side of robot FOV for whiteness
    for (int column = 0; column < cameraView.width; column++){
		
		// gets the red, green, and blue values of the pixel
		int pixRed = get_pixel(cameraView, rowSelected, column, 0);
		int pixGreen = get_pixel(cameraView, rowSelected, column, 1);
		int pixBlue = get_pixel(cameraView, rowSelected, column, 2);
		int isRed;
		
		// check if middle is red or has a white line so that robot can find maze first
		if (pixRed > 250 && pixGreen < 50 && pixBlue < 50 || get_pixel(cameraView, rowSelected, cameraView.width/2, 3) > 250){
			
			// if the pixel is white add a 2 if red add one
			if( get_pixel(cameraView, rowSelected, cameraView.width/2, 3) > 250){
				isRed = 2;
			} else {
				isRed = 1;
			}
		}else {
			isRed = 0;
		}
		// adds the pixel to the overall array
		fov[columnHeight + column] = isRed;
	}
	
	int redCount = 0; // how many times in a row red appears
	int whiteCount = 0; // used at the start so robot can find maze
	int firstRedPos = fovArraySize; // the first appearence of red in the array
	int lastRedPos = 0; // the last appearence of red in the array
	
	// iterate through all array values
	for (int pos = 0; pos < fovArraySize; pos++){
		
		// if red add to redCount and add the position to sumCoords
		if(fov[pos] == 1){
			redCount += 1; // add one to red count
			
			if( pos <= firstRedPos) {// checks to see if the current position is the first appearence of the red pixel
				firstRedPos = pos;
			
			// checks to see if the current postion is the last appearence of the red pixel
			} else if (pos >= lastRedPos){
				lastRedPos = pos;
			}
		} else if(fov[pos] == 2){ // checks if the pix is white for a line to follow into the maze
			whiteCount += 1;
		}
	}
	
	if(redCount > 0 || whiteCount > 0){ // checks if red or white count is not zero so only runs when it finds a red cluster or the white line
		
		// checks if the wall in on the left if so lets user know. Has a error range as robot does not fully stay aligned to wall 
		if(firstRedPos <= 5 && lastRedPos <= 38){
			std::cout<<"The wall is on the left"<<std::endl;
		
		// determines if the wall is on the left and forward and makes robot turn right
		} else if (firstRedPos <= 23 && lastRedPos == fovArraySize - 1 && redCount >= fovArraySize - 5){
			std::cout<<"The wall is on the left and forward"<<std::endl;
			motorR = -84.3;
			motorL = 84.3;
		
		// determines if the wall is only in front and then turns left
		} else if (redCount >= cameraView.width / 2){
			std::cout<<"Forward wall only turn right"<<std::endl;
			motorR = -84.3;
			motorL = 84.3;
			
		} else if(whiteCount > 0){ // if robot see white line let user know
			std::cout<<"Following white line"<<std::endl;
		
		// used to determine if there is no white on left no matter if there is red on right
		} else if (firstRedPos > fovArraySize / 2){
			
			std::cout<<"No red on left TURNING!"<<std::endl;
			// this for loop makes the robot "Sleep" it makes it go forward a certain distance and then turn.
			for (int i = 0; i < 20; i++){
				
				setMotors(motorL,motorR);
				usleep(10000);
			}
			// makes robot turn left
			motorR = 84.3;
			motorL = -84.3;
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
    double vSpeed = 40.0;
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
