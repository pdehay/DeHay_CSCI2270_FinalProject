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
using namespace std;



//Queue Implementation
Queue::Queue(int size){
	queueSize = size;
	arrayQueue = new string[queueSize];
	queueHead = 0;
	queueTail = 0;
	queueCount = 0;
}
Queue::~Queue(){};
//adds a word to the queue
void Queue::enqueue(string input){
	string name = "";
	istringstream iss(input);
	
	//parse input, place each word in queue
	while(getline(iss, name, ' ')){
		if(isFull()) {
			cout << "Waitlist is full" << endl;
		}
		else{
    		arrayQueue[queueTail] = name;
    		queueTail++;
    		queueCount++;
    		//set tail to 0 if queue at last index
    		if(queueTail == queueSize) queueTail = 0;
    		
    		//cout << name << " added to waitlist." << endl;

		}
	}
		
}
//removes word from queue
void Queue::dequeue(){
	if(isEmpty()){
		cout << "Waitlist is empty" << endl;
		return;
	}
	queueHead++;
	queueCount--;

	cout << "Name: " << arrayQueue[queueHead-1] << " is next to be able to purchase a Nintendo Switch. Please contact." << endl;
}
//prints queue from head to tail
void Queue::printQueue(){
	for(int i = queueHead; i < queueCount+queueHead; i++){
		cout << i << ": " << arrayQueue[i] << endl;
		
	}
}
bool Queue::isFull(){
	return queueCount==queueSize; 
}
bool Queue::isEmpty(){
	return queueCount==0;
}
int Queue::searchQueue(std::string name){
	for(int i = queueHead; i < queueCount+queueHead; i++){
		if(arrayQueue[i] == name){
			return i;
		}
	}
	return -1;
}
	


// graph implementation
Graph::Graph(){};
Graph::~Graph(){
	vertices.clear();
}
void Graph::addEdge(string v1, string v2, int dist){

    for(int i = 0; i < (int)vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < int(vertices.size()); j++){
                if(vertices[j].name == v2 && i != j){
                    edge av;
                    av.v = &vertices[j];
                    av.distance = dist;
                    vertices[i].adj.push_back(av);
                }
            }
        }
    }
}
void Graph::addVertex(string n, string a, int q){
    bool found = false;
    if(vertices.size() != 0){
        for(int i = 0; i < int(vertices.size())+1; i++){
            if(vertices[i].name == n){
                found = true;
                cout<<vertices[i].name<<" already exits."<<endl;
            }
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        v.address = a;
        v.switchQuantity = q;
        vertices.push_back(v);

    }
}
void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < int(vertices.size()); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < int(vertices[i].adj.size()); j++){
            //i = j;
            cout<<vertices[i].adj[j].v->name<<"***";
        }
        cout<<endl;
    }

}
void Graph::setHome(){
	cout<<"Choose the region in Colorado you are located" << endl;
	cout<<"\t-----------------------------"<< endl;
	cout<<"\t|             |             |"<< endl;
	cout<<"\t|     NW      |     NE      |"<< endl;
	cout<<"\t|             |             |"<< endl;
	cout<<"\t|             |             |"<< endl;
	cout<<"\t|-------------|-------------|"<< endl;
	cout<<"\t|             |             |"<< endl;
	cout<<"\t|     SW      |     SE      |"<< endl;
	cout<<"\t|             |             |"<< endl;
	cout<<"\t|             |             |"<< endl;
	cout<<"\t-----------------------------"<< endl;
	cout<< "Region: ";
	string input = "";
	getline(cin, input);
	cout << endl;
	//search vertices
	bool found = false;
	if(vertices.size() != 0){
		for(int i = 0; i < int(vertices.size())+1; i++){
			if(vertices[i].name == input){
				found = true;
				home = &vertices[i];
				cout << "Home region set to: " << vertices[i].name << endl<<endl;
			}
		}
	}
	if(found == false){
		cout << "Please try again." << endl<<endl;
	}

}
string Graph::getHome(){
	return home->name;
}
void Graph::printClosest(){
	vector<int> distances;
	for(int j = 0; j < (int)home->adj.size(); j++){
		distances.push_back(home->adj[j].distance);
	}
	sort (distances.begin(), distances.end());
	
	cout << "The three stores near the " << home->name << " region in order are:" << endl;
	
	for(int i = 0; i < 3; i++){
		for(int l = 0; l < (int)home->adj.size(); l++){
			if(home->adj[l].distance == distances[i]){
				cout << "Store: "<< home->adj[l].v->name << endl;
			}
		}
	}
}
void Graph::printInventory(){
	for (int i = 0; i < (int)home->adj.size(); i++){
		cout << "Store: " << home->adj[i].v->name << "\tNintendo Switch Quantity: " << home->adj[i].v->switchQuantity << endl;
	}
}
void Graph::printStores(){
	for (int i = 0; i < (int)home->adj.size(); i++){
		cout << "Store: " << home->adj[i].v->name << "\tNintendo Switch Quantity: " << home->adj[i].v->switchQuantity << endl;
		cout << "Address: " << home->adj[i].v->address << endl << endl;
	}
}
void Graph::adjustQuantity(vertex *store, int amount){
	store->switchQuantity = amount;
}
vertex *Graph::search(string store){
	for(int i = 0; i < (int)home->adj.size(); i++){
		if(home->adj[i].v->name == store){
			return home->adj[i].v;
		}
	}
	return nullptr;
}
int Graph::getQuantity(string store){
	vertex *temp = search(store);
	return temp->switchQuantity;
}


