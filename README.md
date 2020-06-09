# CodingForDucks
ENGR101 Project 3 Team 23

This is our Read Me file, we will use this to keep track of all the files. I will update this regularly when I see new files/anything changes - Lucy

Planning is being done on the wiki.
I will add all changes to here (the ReadMe) as well

please make sure you have all read the project 3 document fully and properly, and understand it. Especially the stuff around the marking. 

Make sure you understand how to use github, and read the wiki. 
I will post links to some tutorials on how to use github on the Tutorials Page in the Wiki

# AVC Plan

***

## Team Name: CodingForDucks

***

## Team Members & Contact Info:
Lucy Carver, 0273115725, carverlucy1@myvuw.ac.nz , ID: 300439983

***

Liam Hurren, 0210366176, hurrenliam@myvuw.ac.nz , ID: 300534302

***

Stephen Thessman, 0277774033, thessmstep@myvuw.ac.nz , ID: 300539537

***

Toby Balls, 0211527242, ballstoby@myvuw.ac.nz , ID: 300494308

## Communication Tool:
Discord, Github

## Roles:
Lucy - Project Manager (organising team meetings, reporting regularly on progress)

***

Stephen - Software Architect (writing core code and extending functionality)

***

Liam - Software Writer (Writing, testing and documenttaion. Debugging software and committing to Git, writing test cases and documenting performance against milestones)

***

Toby - Software Writer (Writing, testing and documenttaion. Debugging software and committing to Git, writing test cases and documenting performance against milestones)

***

Github: https://github.com/lucy-musicalfish/CodingForDucks

**Week One Objectives**


**DATE:** Week Ending 5 June


**Objectives:** Start the Project


**Due Date:** 4 June


**Item Due:** AVC Plan


**Conflicts:**
* ENGR121 Assignment 6 Due 3 June
* COMP102 Assignment 7 Due 4 June
* ENGR121 Lab 3 Due 5 June


**Tasks:**


All: Complete AVC plan
* Lucy - Finish the written plan and edit it, put all the wiki stuff on the plan doc. Make the excel spreadsheet to keep records for the individual logs. Post on github for download by monday 8th june meeting
* Stephen - Find Arthurs Github. Email and ask what exactly does the plan need to have. Help install SFML stuff
* Liam - Help Toby sort SFML. Liam is moving back to wellington this week, so will be in and out.
* Toby - Email Arthur, sort SFML. If possible, make a start on looking at the code and getting ideas up. 

**Week Two Objectives**

**DATE:** Week Ending 14 June


**Objectives:** Core and Completion


**Due Date:** 11 June


**Item Due:** Core Code


**Conflicts:**


**Tasks:**


Video Meeting: Monday Wednesday Friday 1pm
* Lucy - Updating progress on github and wiki, help resolve issues on Github. Make an excel doc for logging hours and distribute to team. put ducks in code. Edit real ducks to take photo shop, to put in place of other ducks in code.
* Liam - Writing code, make notes on changes. Keep track of hours and logs. Make the core code look "pretty"
* Stephen - Write core code, document additions to code. Mark any issues on Github. Keep track of hours and logs. Photoshop our own duck photos. 
* Toby - Writing code, make notes on changes. Keep track of your hours and logs. Make the core code look "pretty"

* All - Keep track of hours, excel doc will be posted on github for all to download and use to keep track of hours by Monday meeting. Will check in about making sure everyone is keeping on top of keeping records at fridays meeting

**Week Three Objectives**

**DATE:** Week Ending 21 June


**Objectives:** Challenge, Logs


**Due Date:** 19 June


**Item Due:** All Code


**Conflicts:**
* ENGR121 Test Two - 17 June
* COMP102 Assignment 9 - Due 18 June


**Tasks:**
* Lucy - Ensure all documentation is on github, on the readme. Make sure everyones logs are up to scratch. Edit and proofread stuff. Assist Liam with the install testing stuff
* Liam - Find someone to test the install procedure on - make sure it fits the marking criteria of "There should be clear instructions (imagine that you are writing a game for 12 years old) on how to install (download, compile, build and run) your code from the scratch (including SFML library) in Install section of README.md. It is acceptable to provide version for specific Operating System.". 
* Stephen - Keep working on code
* Toby - Make sure all bugs are fixed. 


**Week Four Objectives**

**DATE:** Week Ending 28 June


**Objectives:** Finish Project


**Due Date:** 24 June


**Item Due:** Group and Individual Logs


**Conflicts:** Potentially CYBR171 Test


**Tasks:**
* Lucy - 
* Liam -
* Stephen - 
* Toby - 

**INSTALL:**

**Step 1:**

Go to https://www.sfml-dev.org/download/sfml/2.5.1/ and download the MinGW 32 bit. Unzip this file into C:\ (If you can't exact here, anywhere is fine. I will explain what to do in later steps). ENSURE your MinGW version is also the same version as SFML (7.3.0).

**Step 1.1**

Checking MinGW version. Open windows powershell, (search powershell), type g++ --version. It will then display the MinGW version installed on the first line at the very end. Should be 7.3.0 if not install this version else you will run into issues.

**Step 2:**

Download the AVC_server and AVC_robot from the Master branch of CodingForDucks GitHub page. Put this file anywhere you want E.G. C:\User\Documents\ENGR101\Assignment\Project 3

**Step 3:**

This step is here for if you extracted SFML to a different folder to C:. In AVC_robot open the "makefile" with Geany. Where it says DIR = C:\SFML change C:\SFML to where you extracted SFML E.G. C:\Users\Stephen\Downloads\SFML. Do the same for the AVC_server "makefile".

**Step 4:**

Open server3.cpp from the AVC_server folder with MinGW. Open up the Build drop down menu and then click Build Setting Commands. Where it says Independent commands. Set the Make as mingw32-make. Click Ok.

**Step 5:**

With server3.cpp still open, click build and then make, or Shift + F9. Click Execute and the server program will start. Allow it through your firewall with public/private access otherwise you will run into issues. It will most likely be a white program that has a loading icon as the mouse this is all good.

**Step 6:**

While the server program is still running. Open robot.cpp from AVC_robot. Geany will still have the custom make commands saved in its build option. All you need to do is build and then make, or Shift + F9. You then need to execute robot.cpp (F5 by default). May need to execute twice to run the program.


**NOTES:**

Core works, now need to finesse it.

We will have video meetings on Monday/Wednesday/Friday at 1pm. Notes from the meetings are on the Wiki.

Emailed Arthur with a few questions

Changed the github photo, made it a duck photo
