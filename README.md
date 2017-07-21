# DeHay_CSCI2270_FinalProject

Project Summary:

	My project will utilize the graph data structure to find the closest 
video game retail store that has an item the user wants in stock. For example, 
if the user wanted to buy a Nintendo Switch gaming console, the user would input what 
they are looking for, the program will then search the graph for the top five nearest 
locations to the user's location that supplies the item, and place those locations 
into a stack. If that item does not exist at any location, 
the program will prompt the user to input another selection. If the item does exist,
then it will let the user know if that item is in stock at the first location in the 
stack. If the item is not available at that location, the user will be given the 
option to add themselves to a waiting list (queue) to be the next to have a a chance 
to buy that item, and/or to check the inventory of the next closest retail location in 
the Top Five stack. Once a location is found that has the item in stock, the user
will be able to print the address of that location.
All distances and locations are fictional, and the user's starting location wil be based on 
a value that the user inputs in order to have different cases of figuring out the 
closest retail stores to the user's location.