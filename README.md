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
* Lucy - Finish the written plan and edit it, put all the wiki stuff on the plan doc
* Stephen - Find Arthurs Github. Email and ask what exactly does the plan need to have.
* Liam - Help Toby sort SFML. 
* Toby - Email Arthur, sort SFML

**Week Two Objectives**

**DATE:** Week Ending 14 June


**Objectives:** Core and Completion


**Due Date:** 11 June


**Item Due:** Core Code


**Conflicts:**


**Tasks:**


Video Meeting: Monday Wednesday Friday 1pm
* Lucy - Updating progress on github and wiki, checking all issues on github, distribute tutorials, help with code?
* Liam - helping with code, make notes on changes
* Stephen - Write core code, document additions to code
* Toby - helping with code, make notes on changes

**Week Three Objectives**

**DATE:** Week Ending 21 June


**Objectives:** Challenge, Logs


**Due Date:** 19 June


**Item Due:** All Code


**Conflicts:**
* ENGR121 Test Two - 17 June
* COMP102 Assignment 9 - Due 18 June


**Tasks:**
* Lucy - 
* Liam -
* Stephen - 
* Toby - 


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

Go to https://www.sfml-dev.org/download/sfml/2.5.1/ and download the MinGW 32 bit or 64 bit version depending on your system. Unzip this file into C:\ (If you can't exact here, anywhere is fine. I will explain what to do in later steps).

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

