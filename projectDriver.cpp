/* 
Paul DeHay 
CSCI 2270 Summer 2017
Assignment Final Project
Instructor: Shirly Montero-Quesada
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <algorithm>

#include "projectClass.hpp"
#include "projectClass.cpp"
using namespace std;



int main(){
	//graph building
	Graph test;
	//possible home locations
	test.addVertex("NW", "Home: You are here", -1);
	test.addVertex("NE", "Home: You are here", -1);
	test.addVertex("SW", "Home: You are here", -1);
	test.addVertex("SE", "Home: You are here", -1);
	//store locations
	test.addVertex("GameStop 1", "Boulder, CO 80301", 0);
	test.addVertex("GameStop 2", "Fort Collins, CO 80522", 2);
	test.addVertex("GameStop 3", "Greeley, CO 80543", 0);
	test.addVertex("GameStop 4", "Parker, CO 80134", 1);
	test.addVertex("GameStop 5", "Centennial, CO 80015", 0);
	test.addVertex("GameStop 6", "Littleton, CO 80166", 1);
	//NW links to stores
	test.addEdge("NW", "GameStop 1", 10);
	test.addEdge("NW", "GameStop 6", 20);
	test.addEdge("NW", "GameStop 2", 25);
	test.addEdge("NW", "GameStop 5", 30);
	test.addEdge("NW", "GameStop 3", 35);
	test.addEdge("NW", "GameStop 4", 40);
	//NE links to stores
	test.addEdge("NE", "GameStop 3", 10);
	test.addEdge("NE", "GameStop 4", 20);
	test.addEdge("NE", "GameStop 2", 25);
	test.addEdge("NE", "GameStop 5", 30);
	test.addEdge("NE", "GameStop 1", 35);
	test.addEdge("NE", "GameStop 6", 40);
	//SW links to stores
	test.addEdge("SW", "GameStop 6", 10);
	test.addEdge("SW", "GameStop 1", 20);
	test.addEdge("SW", "GameStop 5", 25);
	test.addEdge("SW", "GameStop 2", 30);
	test.addEdge("SW", "GameStop 4", 35);
	test.addEdge("SW", "GameStop 3", 40);
	//SE links to stores
	test.addEdge("SE", "GameStop 4", 10);
	test.addEdge("SE", "GameStop 3", 20);
	test.addEdge("SE", "GameStop 5", 25);
	test.addEdge("SE", "GameStop 2", 30);
	test.addEdge("SE", "GameStop 6", 35);
	test.addEdge("SE", "GameStop 1", 40);
	
	//print test
	//test.displayEdges();
	
	
	
	Queue one(5);
		one.enqueue("John");
		one.enqueue("Amy");
		one.enqueue("Nicole");
		one.enqueue("Tim");
		one.enqueue("Dorothy");
	Queue two(5);
	Queue three(5);
		three.enqueue("Jessie");
		three.enqueue("Hana");
	Queue four(5);
		four.enqueue("Diego");
	Queue five(5);
	Queue six(5);
		six.enqueue("Jasmine");
	
	
	
	//intro
	cout << "Welcome to the Nintendo Switch Locator!" << endl;
	cout << "Created by: Paul DeHay for CSCI 2270 SU2017 Project" << endl<<endl;
	cout << "Please start with Option 1 to input your home region." << endl;
	//menu
	while(true){
		cout << "======Main Menu======" << endl;
		cout << "1. Pick home region" << endl;
		cout << "2. Find closest stores" << endl;
		cout << "3. Check store inventory" << endl;
		cout << "4. Add self to store's waitlist" << endl;
		cout << "5. Check position in waitlist" << endl;
		cout << "6. Print all stores" << endl;
		cout << "7. Admin Menu" << endl;
		cout << "8. Quit" << endl << endl;


		int choice = 0;
		cin >> choice;
		cin.ignore();
		int store = 0;
		string name = "";
		
		switch(choice){
			case 1: //pick one of 4 home regions
				test.setHome();
				//cout << test.getHome() << endl; //test if home was saved
				continue;
				
			case 2: //Output top 3 stores in order of closeness to home
				test.printClosest();
				continue;
				
			case 3: //print store inventory
				test.printInventory();
				continue;
				
			case 4: //add to waitlist
				cout << "Enter store number: ";
				cin >> store;
				cout << "Enter name: ";
				cin >> name;
				if(store == 1){
					if(test.getQuantity("GameStop 1") == 0){
						one.enqueue(name);
						cout << "You were added to the waitlist." << endl;
					}
					else cout << "Store has Switches in stock!" << endl;			
				}
				if(store == 2){
					if(test.getQuantity("GameStop 2") == 0){
						two.enqueue(name);
						cout << "You were added to the waitlist." << endl;
					}
					else cout << "Store has Switches in stock!" << endl;
				}
				if(store == 3){
					if(test.getQuantity("GameStop 3") == 0){
						three.enqueue(name);
						cout << "You were added to the waitlist." << endl;
					}
					else cout << "Store has Switches in stock!" << endl;
				}
				if(store == 4){
					if(test.getQuantity("GameStop 4") == 0){
						four.enqueue(name);
						cout << "You were added to the waitlist." << endl;
					}
					else cout << "Store has Switches in stock!" << endl;
				}
				if(store == 5){
					if(test.getQuantity("GameStop 5") == 0){
						five.enqueue(name);
						cout << "You were added to the waitlist." << endl;
					}
					else cout << "Store has Switches in stock!" << endl;
				}
				if(store == 6){
					if(test.getQuantity("GameStop 6") == 0){
						six.enqueue(name);
						cout << "You were added to the waitlist." << endl;
					}
					else cout << "Store has Switches in stock!" << endl;
				}
				cin.ignore();
				
				
				continue;
				
			case 5: //print store queue position
				cout << "Enter store number: ";
				cin >> store;
				cout << "Enter name: ";
				cin >> name;
				if(store == 1){
					if(one.searchQueue(name) >= 0){
						cout << "Your poition in the waitlist is: " << one.searchQueue(name)+1 << endl;
					}
					else{
						cout << "You are not on the list." << endl;
					}
				}
				if(store == 2){
					if(two.searchQueue(name) >= 0){
						cout << "Your poition in the waitlist is: " << two.searchQueue(name)+1 << endl;
					}
					else{
						cout << "You are not on the list." << endl;
					}
				}
				if(store == 3){
					if(three.searchQueue(name) >= 0){
						cout << "Your poition in the waitlist is: " << three.searchQueue(name)+1 << endl;
					}
					else{
						cout << "You are not on the list." << endl;
					}
				}
				if(store == 4){
					if(four.searchQueue(name) >= 0){
						cout << "Your poition in the waitlist is: " << four.searchQueue(name)+1 << endl;
					}
					else{
						cout << "You are not on the list." << endl;
					}
				}
				if(store == 5){
					if(five.searchQueue(name) >= 0){
						cout << "Your poition in the waitlist is: " << five.searchQueue(name)+1 << endl;
					}
					else{
						cout << "You are not on the list." << endl;
					}
				}
				if(store == 6){
					if(six.searchQueue(name) >= 0){
						cout << "Your poition in the waitlist is: " << six.searchQueue(name)+1 << endl;
					}
					else{
						cout << "You are not on the list." << endl;
					}
				}
				cin.ignore();
				continue;
				
			case 6: //list all stores and addresses
				test.printStores();
				continue;
				
			case 7: //admin queue menu to dequeue waitlist and alter inventory
				while(true){
					cout << "======Admin Menu======" << endl;
					cout << "1. Print waitlist" << endl;
					cout << "2. Manage store inventory" << endl;
					cout << "3. Return" << endl << endl;

					int value = 0;
					cin >> value;
					cin.ignore();
					int num = 0;
					int q = 0;
					int n = 0;
					
					switch(value){
						case 1: //prints queue for specified store, and pops next
							cout << "Input store number: ";
							cin >> num;
							if(num == 1){
								one.printQueue();
								one.dequeue();
							}
							if(num == 2){
								two.printQueue();
								two.dequeue();
							}
							if(num == 3){
								three.printQueue();
								three.dequeue();
							}
							if(num == 4){
								four.printQueue();
								four.dequeue();
							}
							if(num == 5){
								five.printQueue();
								five.dequeue();
							}
							if(num == 6){
								six.printQueue();
								six.dequeue();
							}
							cin.ignore();
							continue;
							
						case 2: //change quantity of item at specified store
							cout << "Input store number: ";
							cin >> n;
							
							vertex *temp;
							if(n == 1){
								temp = test.search("GameStop 1");							
							}
							if(n == 2){
								temp = test.search("GameStop 2");
							}
							if(n == 3){
								temp = test.search("GameStop 3");
							}
							if(n == 4){
								temp = test.search("GameStop 4");
							}
							if(n == 5){
								temp = test.search("GameStop 5");
							}
							if(n == 6){
								temp = test.search("GameStop 6");
							}/*
							else{
								cout << "Store not found." << endl;
								cin.ignore();
								continue;
							}*/
							cin.ignore();
							cout << "Enter new quantity: ";
							cin >> q;
							test.adjustQuantity(temp, q);
							cin.ignore();
							continue;
							
						case 3://return to top menu
							break;
							
					}
					break;
				}
				continue;
				
			case 8://quit and delete graph
				cout << "Thanks for using the Nintendo Switch Locator!" << endl;
				return 0;
				
		}
	}
	
	
}
