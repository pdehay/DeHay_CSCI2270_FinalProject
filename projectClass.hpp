#ifndef PROJECT_CLASS_HPP
#define PROJECT_CLASS_HPP

class Queue{
private:
	int queueHead; //index
	int queueTail; //index
	std::string *arrayQueue;
	int queueCount; //current elements in array
	int queueSize;
	
	bool isEmpty();
	bool isFull();
public:
	Queue(int);
	~Queue();
	void enqueue(std::string);
	void dequeue();
	void printQueue();
	int searchQueue(std::string name);
};

struct vertex;

struct edge{
    vertex *v;
    int distance;
};

struct vertex{
    std::string name;
    std::string address;
    int switchQuantity;
    std::vector<edge> adj;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int dist);
        void addVertex(std::string n, std::string a, int q);
        void displayEdges();
        void setHome();
        std::string getHome();
        void printClosest();
        void printInventory();
        void printStores();
        void adjustQuantity(vertex *store, int amount);
        vertex *search(std::string store);
        int getQuantity(std::string store);
    private:
		vertex *home = nullptr;
		std::vector<edge> edges;
        std::vector<vertex> vertices;
        
};

#endif

