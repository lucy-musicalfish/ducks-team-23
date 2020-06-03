# CodingForDucks
ENGR101 Project 3 Team 23

This is our Read Me file, we will use this to keep track of all the files. I will update this regularly when I see new files/anything changes - Lucy

Planning is being done on the wiki.
I will add all changes to the official planning doc as well. 

please make sure you have all read the project 3 document fully and properly, and understand it. Especially the stuff around the marking. 

Make sure you understand how to use github, and read the wiki. 
I will post links to some tutorials on how to use github on the Tutorials Page in the Wiki

INSTALL: 
Step 1:

Go to https://www.sfml-dev.org/download/sfml/2.5.1/ and download the MinGW 32 bit or 64 bit version depending on your system. Unzip this file into C:\ (If you can't exact here, anywhere is fine. I will explain what to do in later steps).

Step 2:

Download the AVC_Win10.zip from the attachments in Assignment 3 page. Extract this to any file location you want E.G. C:\User\Documents\ENGR101\Assignment\Project 3 You will have two folders AVC_robot and AVC_server.

Step 3:

This step is here for if you extracted SFML to a different folder to C:. In AVC_robot open the "makefile" with Geany. Where it says DIR = C:\SFML change C:\SFML to where you extracted SFML E.G. C:\Users\Stephen\Downloads\SFML. Do the same for the AVC_server "makefile".

Step 4:

Open server3.cpp from the AVC_server folder with MinGW. Open up the Build drop down menu and then click Build Setting Commands. Where it says Independent commands. Set the Make as mingw32-make. Click Ok.

Step 5:

With server3.cpp still open, click build and then make, or Shift + F9. Click Execute and the server program will start. Allow it through your firewall with public/private access otherwise you will run into issues. It will most likely be a white program that has a loading icon as the mouse this is all good.

Step 6:

While the server program is still running. Open robot.cpp from AVC_robot. Geany will still have the custom make commands saved in its build option. All you need to do is build and then make, or Shift + F9. You then need to execute robot.cpp (F5 by default). May need to execute twice to run the program.

