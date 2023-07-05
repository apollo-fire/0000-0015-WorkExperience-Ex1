### 0000-0015-WorkExperience-Ex1

##Work Experience Exercise 1

#1	Summary
This exercise is designed to give an overview of the software design process from requirements through to implementation.
##2	Objectives
•	Demonstrate an understanding of the design process: from requirements to design to implementation to verification.
•	Design a software program from requirements.
•	Obtain an understanding of the power of object oriented design and the importance of a well-defined interface (one module only has to care about it’s responsibilities)
•	Design unit tests.
•	Implement a design in C code with unit tests.
•	Obtain an understanding of software quality and associated tools.
#3	Exercise
3.1.1	DoR
•	Have access to Enterprise Architect (EA).
•	Code Composer Studio V11.2.0 is installed.
•	Have a GitHub account.
•	Have access to the Apollo public work experience repository. 
•	Have Git Bash download and linked to your GitHub account.
•	G-test is installed. Setting Up GoogleTest In Code Composer Studio Using MinGW - Software Development Team - Confluence (spectrumhosting.net)

3.1.2	DoD
•	An EA model has been created with:
o	Use cases,
o	Class diagram,
o	Sequence diagrams,
o	Activity diagrams.
o	Consideration to the hardware interface.
•	A code project has been created that: 
o	Is stored and controlled in GitHub.
o	Implements the model in EA.
o	Has 100% unit test coverage.
•	Software quality processes have been followed.
 
3.1.3	Method
1.	Read and understand the following requirements.
ID	Requirement	Notes
WE-EX1-0001	A green LED must flash at 0.5Hz (±10%)	V1.0
WE-EX1-0002	A green LED must flash at 1Hz (±10%)	V1.0
WE-EX1-0003	A red LED must flash at 0.5Hz (±10%)	V1.0
WE-EX1-0004	A red LED must flash at 1Hz (±10%)	V1.0
WE-EX1-0005	The flash rate of the LEDS must be controlled by a button	V1.0
WE-EX1-0006	When the LED in on it must be visible from 30cm away in a standard office environment	V1.0

2.	Extract the use cases from the requirements.
Ask yourself these questions:
What exactly do the requirements say the design has to do, not what do these requirements imply?
Do these requirements give all of the information needed for this design?
Think about sentences like: 
As a user I want to see two different LEDs flashing at two different flash rates.
As a user I want to control the flash rate dynamically.
3.	Create a design to fulfil the requirements.
a.	Class diagram
A class diagram shows the interaction between classes/modules. Which interface talks to which interface. What each class/module can do. The diagram should also show the ‘layers’ of interaction.
b.	Sequence diagram
A sequence diagram shows the interactions between classes/modules within time. What communication between classes/modules happens in which order?
c.	Activity diagrams
An activity diagram is like a flow chart. It shows the actions and activities performed by each function inside a class/module.
4.	Design the unit tests for each function.
Think about ‘paths’ through the activity diagrams. Unit tests should give 100% branch coverage. A branch is created at each decision point.
5.	Write the code in parallel to the unit tests.
Remember to export the code files from the model to give you a head start. There should be a unit test project per ‘layer’.
6.	Run the code through the public workflows on the GitHub repository.
This is to ensure quality of software. Is it safe, readable, and free of obvious mistakes?
 
#4	Appendix
4.1	Glossary
TERM	DESCRIPTION
DOR	Definition of ready. All items in this checklist must be complete before the task can start.
DOD	Definition of done. All items in this checklist must be complete for the task to be done.
AAA	Arrange, Act, Assert. A unit testing framework. 
RGR	Red, Green, Refactor. A unit test implementation method.
CCS	Code Composer Studio. An IDE.
IDE	Integrated Development Environment. An application to write and test software in.

#4.2	Relevant documentation
Development board datasheets: MSP430FR4133 data sheet, product information and support | TI.com
##4.3	Design
#4.3.1	Diagram Examples
 
TBD - add image
Figure 1 - Class diagram example

TBD - add image
Figure 2 - Sequence diagram example

TBD - add image
Figure 3 Activity diagram example

4.3.2	Layers
Code designs are split into layers to help with organisation and isolation of functionality. There are usually three layers: application, middleware, and driver. Each layer can only talk to the layer above or below it; it cannot skip a layer.
The application is the top layer and the modules inside it make ‘big commands’ like “Do this thing”.
The middleware layer is the next layer down and interprets the ‘big commands’ like “To do this thing, I need to move this and set that”.
The driver layer is the bottom layer and actions the commands from the middleware. 

4.3.3	Modules/Classes
A module/class is a group of related functionalities. The orange boxes in Figure 1 are classes. A class can have multiple interfaces. Each class is responsible for performing one set of related activities.
They are called a module and a class interchangeable, but be careful as ‘class’ means something specific in certain code languages.

4.3.4	Interfaces
An interface is a contract, where the module promises it can perform all the functions inside the interface. The interface contains public functions and variables, meaning that anything in the interface can be accessed by another module. The purple boxes in Figure 1 are interfaces. 
#4.4	Unit testing
Unit tests should be named after what they are trying to test, in the format: FucntionUnderTest_Results_WhenConditions. This matches up to Act_Assert_Arrage in the AAA section below.
4.4.1	AAA
The internals of a unit test are setup in the AAA order: Arrange, Act, Assert. 
The unit test should start by arranging the code to be in the correct state: setting flags, modes etc. Then the test should act; call the relevant function under test. Finally, the test should assert that the outcome from the action matched a known result.
 
4.4.2	RGR
The process of creating a unit test is RGR: Red, Green, Refactor. This means the unit test is written first and fails (red), the main code is then written just enough to make the test pass (green) and then the code is tidied up (refactor). A unit test is only useful if it can both pass and fail.
 
#4.5	Timer code
LED flashing, Timer A1. FLASH_RATE_FAST is a custom define, everything else comes with the microcontroller #include<msp430.h>.
 
TBD - add image

The ISR.
TBD - add image
 
