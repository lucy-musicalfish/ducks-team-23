
#include "robot.hpp"

void core(double vLeft, double vRight){
    takePicture();
    //SavePPMFile("i0.ppm",cameraView);
	
	int row = 75;
    for (int column = 0; column < 150; column++){
		int pix = get_pixel(cameraView, 50, column, 3);
		int isWhite;
		if(pix > 250){
			isWhite = 1;
		} else {
			isWhite = 0;
		}
		std::cout<<isWhite<<" ";
	}
	setMotors(vLeft,vRight);   
    std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
    usleep(10000);
        
}

int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
    double vLeft = 10.0;
    double vRight = 10.0;
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
