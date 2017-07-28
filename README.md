# DeHay_CSCI2270_FinalProject

Project Name:
	Nintendo Switch Locator

Project Summary:
	My project will utilize the graph data structure to find the closest 
video game retail store that has a Nintendo Switch stock. 
The user will choose their home region, and the program will be able to list the three closest
retail stores to the user. The program also allows the user to check the inventory of all stores.
If the store does not have any of the item in stock, the user may add themselves to a waitlist or queue
to be the next to be notified when there are more of the item in stock. The user may also check their 
current position in the queue. The program also allows the user to print the names and addresses of all
the stores. The program also has an administrative menu(which is open access) to allow the user to 
manipulate the queues for each store as well as the inventory quantities at each store.

How to Run:
	Download projectClass.hpp, projectClass.cpp, and projectDriver.cpp to your computer and execute via
terminal. Once launched, the program will display a menu of options.
You must start with Option 1 in order for the program to work, from there, you can utilize any of the options
in any order. Option 1 sets your home region. Option 2 prints the top 3 nearest stores to your home. Option 3
prints the all the stores and their inventories. Option 4 prompts the user to choose a store and add their name 
to a queue. Option 5 outputs the user's position in the queue. Option 6 prints all stores and their addresses.
Option 7 runs the administrative menu. Option 7.1 prints the queue for a given store and dequeues the next person.
Option 7.2 allows the admin to change the inventory quantity at any store. Option 7.3 returns to the main menu. 
Option 8 exits the program.

Dependencies:
	None except for projectClass.hpp and projectClass.cpp files.

System Requirements:
	OS: Linux

Open Issues/Bugs:
	May need to remove the "#include projectClass.cpp" line depending on how program is executed.

Created by: Paul DeHay