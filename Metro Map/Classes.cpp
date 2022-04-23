#include <iostream>
#include <stdio.h>
using namespace std;

template<typename anyType>
class Vertex{
    
private:
    
    static int counter;
    anyType value;      //[4]
    int vertexID;
    
public:
    
    //Default Constructor
    Vertex();
    
    //Parameterzied Constructor
    Vertex(anyType);
    
    //Copy Constructor
    Vertex(const Vertex&);
    
    //Set & Get Functions
    int getVertexID() const;
    anyType getValue() const;
    
    void setVertexID(int);
    void setValue(anyType);
    
    //Member Functions
    void print();
    
    //Destructor
    ~Vertex();
};


template<typename anyType>
int Vertex<anyType>::counter = 0;

//Default constructor implementation
template<typename anyType>
Vertex<anyType>::Vertex(){
    this->value = nullptr;
    this->vertexID = 0;
}

//Parameterzied constructor implementation
template<typename anyType>
Vertex<anyType>::Vertex(anyType value){
    this->value = value;
    this->counter++;
    this->vertexID = counter;
}

//Copy constructor implementation
template<typename anyType>
Vertex<anyType>::Vertex(const Vertex &v1){
    this->value = v1.value;
    this->vertexID = v1.vertexID;
}

//Set & Get functions implementation
template<typename anyType>
int Vertex<anyType>::getVertexID() const{
    return this->vertexID;
}

template<typename anyType>
anyType Vertex<anyType>::getValue() const{
    return this->value;
}

template<typename anyType>
void Vertex<anyType>::setVertexID(int vertexID){
    this->vertexID = vertexID;
}

template<typename anyType>
void Vertex<anyType>::setValue(anyType value){
    this->value = value;
}

//Print Function Implementation
template<typename anyType>
void Vertex<anyType>::print(){
    cout << this->value;
}

//Destructor Implementation
template<typename anyType>
Vertex<anyType>::~Vertex(){
    
}


//----------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------EDGE-------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------


template<typename anyType>
class Edge{
    
private:
    
    static int counter;
    Vertex<anyType>* start;
    Vertex<anyType>* end;
    int edgeID;
    
public:

    Edge();
    Edge(Vertex<anyType>*,Vertex<anyType>*);
    Edge(const Edge&);
    
    //getters and setters
    Vertex<anyType>* getStart() const;
    Vertex<anyType>* getEnd() const;
    int getEdgeID() const;
    
    void setStart(Vertex<anyType>*);
    void setEnd(Vertex<anyType>*);
    
    void print();
    ~Edge();
};


//initilalize counter for ids
template<typename anyType>
int Edge<anyType>::counter = 0;

//Default constructor implementation
template<typename anyType>
Edge<anyType>::Edge(){
    
    this->start = nullptr;
    this->end = nullptr;
    this->edgeID = 0;
    
}

//Parametrized Constructor implementation
template<typename anyType>
Edge<anyType>::Edge(Vertex<anyType>* start,Vertex<anyType>* end){
    this->start = start;
    this->end = end;
    
    this->counter++;
    this->edgeID = counter;
}

//Copy constructor implementation
template<typename anyType>
Edge<anyType>::Edge(const Edge& e){
    
    this->start = e.start;
    this->end = e.end;
    this->edgeID = e.edgeID;
    
}

//getters and setters
template<typename anyType>
Vertex<anyType>* Edge<anyType>::getStart() const{
    return this->start;
}
template<typename anyType>
Vertex<anyType>* Edge<anyType>::getEnd() const{
    return this->end;
}
template<typename anyType>
int Edge<anyType>::getEdgeID() const{
    return this->edgeID;
}

template<typename anyType>
void Edge<anyType>::setStart(Vertex<anyType>* start){
    this->start = start;
}
template<typename anyType>
void Edge<anyType>::setEnd(Vertex<anyType>* end){
    this->end = end;
}

//print function and destructor
template<typename anyType>
void Edge<anyType>::print(){
    cout << "(";
    this->start->print();
    cout << ", ";
    this->end->print();
    cout << ")";
}

template<typename anyType>
Edge<anyType>::~Edge(){
    delete start;
    delete end;
}


//----------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------GRAPH------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------


template<typename anyType>
class Graph{
    
protected:
    
    int numOfVertices, numOfEdges;
    int maxNumVertices, maxNumEdges;
    Vertex<anyType>** vertices;
    Edge<anyType>** edges;
    
public:
    //Default Constructor
    Graph();            //[1]
    
    //Parametrized Constructors
    Graph (int,int);    //input size of vertex and edge arrays
    Graph (Graph&);     //copy constructor
    
    virtual int getNumOfVertices() const;
    virtual int getNumOfEdges() const;
    virtual int getMaxNumVertices() const;
    virtual int getMaxNumEdges() const;
    
    
    virtual bool addVertex(Vertex<anyType>&) = 0;    //[3]
    virtual bool addEdge(Edge<anyType>&) = 0;        //[3]
    
    virtual bool removeVertex (Vertex<anyType>&) = 0;     //remove the vertex
    virtual bool removeEdge(Edge<anyType>&) = 0;          // remove the edge
    
    virtual bool containsVertex(anyType) = 0;               // [8] return true if a Vertex with given value exists in a graph
    virtual bool containsEdge(const Edge<anyType>&) = 0;    // [7] return true if an Edge exists in a graph
    
    virtual Vertex<anyType>* requestVertex(anyType) = 0;                //return pointer to requested vertex given vertex value
    virtual Edge<anyType>* requestEdge(anyType val1, anyType val2) = 0; //return pointer to requested edge given start and end vertex values
    
    virtual void printPaths() = 0;                                      // [5]
    virtual void printVertexPaths(const Vertex<anyType>&) = 0;          // [6]
    

    
    virtual ~Graph();
};


//Default constructor implementation
template<typename anyType>
Graph<anyType>::Graph(){
    this->numOfVertices = 0;
    this->numOfEdges = 0;
    
    this->maxNumVertices = 500;
    this->maxNumEdges = 500;
    
    this->vertices = new Vertex<anyType>*[maxNumVertices];
    this->edges = new Edge<anyType>*[maxNumEdges];
}

//Parametrized constructor implementation
template<typename anyType>
Graph<anyType>::Graph (int maxNumOfVertices, int maxNumOfEdges){
    this->numOfVertices = 0;
    this->numOfEdges = 0;
    
    this->maxNumVertices = maxNumVertices;
    this->maxNumEdges = maxNumEdges;
    
    this->vertices = new Vertex<anyType>*[maxNumVertices];
    this->edges = new Edge<anyType>*[maxNumEdges];
}

//Copy constructor implementation
template<typename anyType>
Graph<anyType>::Graph (Graph& g){
    this->numOfVertices = g.numOfVertices;
    this->numOfEdges = g.numOfEdges;
    
    this->maxNumVertices = g.maxNumVertices;
    this->maxNumEdges = g.maxNumEdges;
    
    this->vertices = new Vertex<anyType>*[g.maxNumEdges];
    this->edges = new Edge<anyType>*[g.maxNumVertices];
    
    for(int i=0; i<g.numOfVertices; i++){
        this->vertices[i] = g.vertices[i];
    }
    for(int i=0; i<g.numOfEdges; i++){
        this->edges[i] = g.edges[i];
    }
    
}

//Getters implementation
template<typename anyType>
int Graph<anyType>::getNumOfEdges() const{
    return this->numOfEdges;
}
template<typename anyType>
int Graph<anyType>::getNumOfVertices() const{
    return this->numOfVertices;
}
template<typename anyType>
int Graph<anyType>::getMaxNumEdges() const{
    return this->maxNumEdges;
}
template<typename anyType>
int Graph<anyType>::getMaxNumVertices() const{
    return this->maxNumVertices;
}

//virtual destructor
template<typename anyType>
Graph<anyType>::~Graph(){
    
    cout << "Graph DELETED" << endl;
    delete[] vertices;
    delete[] edges;
}


//----------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------UGRAPH-----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------


template<typename anyType>
class UndirectedGraph : public Graph<anyType>{
    //[2] here we are making an undirected graph
public:
    UndirectedGraph();
    UndirectedGraph(int,int);
    UndirectedGraph(UndirectedGraph&);
    
    bool addVertex(Vertex<anyType>&);    //[3]
    bool addEdge(Edge<anyType>&);        //[3]
    
    bool removeVertex (Vertex<anyType>&);     //remove the vertex
    bool removeEdge(Edge<anyType>&);          // remove the edge
    
    bool containsVertex(anyType);               // [8] return true if a Vertex with given value exists in a graph
    bool containsEdge(const Edge<anyType>&);    // [7] return true if an Edge exists in a graph
    
    Vertex<anyType>* requestVertex(anyType);                //return pointer to requested vertex given vertex value
    Edge<anyType>* requestEdge(anyType val1, anyType val2); //return pointer to requested edge given start and end vertex values
    
    void printPaths();                                      // [5]
    void printVertexPaths(const Vertex<anyType>&);          // [6]
    
    ~UndirectedGraph();
    
    
    bool operator==(const UndirectedGraph& g2) const;
    const UndirectedGraph& operator=(const UndirectedGraph& g2);
    UndirectedGraph operator+(const UndirectedGraph& g2) const;
    
    //operator<< needs to be defined within the class in order to function with a template
    friend ostream& operator<< (ostream& out, const UndirectedGraph<anyType>& g){
        out << "G(V,E)\nV = {";
        for(int i=0; i<g.numOfVertices; i++){

            out << g.vertices[i]->getValue();

            if(i < g.numOfVertices-1){
                out << ", ";
            }
        }
        out << "}\nE = {";
        for(int i=0; i<g.numOfEdges; i++){

            out << "(" << g.edges[i]->getStart()->getValue() << "-" << g.edges[i]->getEnd()->getValue() << ")";

            if(i < g.numOfEdges-1){
                out << ", ";
            }
        }
        out << "}\n";

        return out;
    }

    
    
};



//Default constructor from parent is called
template<typename anyType>
UndirectedGraph<anyType>::UndirectedGraph() : Graph<anyType>(){
    
}

//Parametrized constructor from parent is called
template<typename anyType>
UndirectedGraph<anyType>::UndirectedGraph(int maxNumVertices, int maxNumEdges) : Graph<anyType>(maxNumVertices,maxNumEdges){
    
}

//Copy constructor from parent is called
template<typename anyType>
UndirectedGraph<anyType>::UndirectedGraph(UndirectedGraph& g) : Graph<anyType>(g){
    
}

//[3]
template<typename anyType>
bool UndirectedGraph<anyType>::addVertex(Vertex<anyType>& vert){
    
    //loop through the array
    for(int i=0; i<this->numOfVertices; i++){
        //ensure that this vertex is not already in the graph, end function if this vertex is found
        if(vert.getVertexID() == this->vertices[i]->getVertexID() || vert.getValue() == this->vertices[i]->getValue()){
            cout << "Vertex " << vert.getValue() << " Already in this Graph" << endl;
            //return true because the given vertex is technically present in this graph
            return true;
        }
    }
    //make sure the array of vertices is not full
    if(this->numOfVertices < this->maxNumVertices){
        //if this vertex does not already exist in the graph, add it to the array of vertices and increase the number of vertices
        cout << "Vertex " << vert.getValue() << " added to the graph" << endl;
        this->vertices[this->numOfVertices++] = &vert;
        return true;
    }
    else{
        cout << "Vertex Array Full" << endl;
        //only return false if the array is full
        return false;
    }
    
}

//[3]
template<typename anyType>
bool UndirectedGraph<anyType>::addEdge(Edge<anyType>& ed){
    
    //attempt to add the vertices this edge contains
    Vertex<anyType>* startPoint = ed.getStart();
    Vertex<anyType>* endPoint = ed.getEnd();
    
    //the only issue for adding the start and end verticies are when the array of vertices is full, in this case end the function
    if(!addVertex(*startPoint) || !addVertex(*endPoint)){
        return false;
    }
    
    //make sure the array of edges is not full
    if(this->numOfEdges < this->maxNumEdges){
        //loop through the array
        for(int i=0; i<this->numOfEdges; i++){
            //ensure that this edge is not already in the graph, end function if this vertex is found
            //also, since this is undirected ensure that the inverse of this edge is also not in the graph, end the function if the inverse is found
            if( ( startPoint->getVertexID() == this->edges[i]->getEnd()->getVertexID() && endPoint->getVertexID() == this->edges[i]->getStart()->getVertexID() ) || ( startPoint->getVertexID() == this->edges[i]->getStart()->getVertexID() && endPoint->getVertexID() == this->edges[i]->getEnd()->getVertexID() )){
                cout << "Path from " << startPoint->getValue() << " to " << endPoint->getValue() << " Already in this Undirected Graph" << endl;
                //return true because the given edge is technically present in this graph
                return true;
            }
        }
        //if this edge does not already exist in the graph, add it to the array of edges and increase the number of edges
        cout << "Path from " << startPoint->getValue() << " to " << endPoint->getValue() << " added to the graph" << endl;
        this->edges[this->numOfEdges++] = &ed;
        return true;
    }
    else{
        cout << "Edges Array Full" << endl;
        return false;
    }
    
}

template<typename anyType>
bool UndirectedGraph<anyType>::removeVertex (Vertex<anyType>& vert){

    //ensure that none of the edges use this vertex
    
    for(int i=0; i<this->numOfEdges; i++){
        //if any edges with this vertex as a start or end is found, remove those edges from the graph firstly
        if( ( this->edges[i]->getStart()->getValue() == vert.getValue() ) || ( this->edges[i]->getEnd()->getValue() == vert.getValue() )){
            removeEdge(*this->edges[i]);
            i--;
        }
    }
    
    //loop through the vertex array
    for(int i=0; i<this->numOfVertices; i++){
        //check if this vertex is present in the vertex array
        if(vert.getVertexID() == this->vertices[i]->getVertexID()){
            //shift all vertices down the array from this point
            for(int j=i; j<this->numOfVertices-1; j++){
                this->vertices[j] = this->vertices[j+1];
            }
            //decrease the number of vertices and return true
            this->numOfVertices--;
            cout << "Vertex " << vert.getValue() << " removed from this Graph" << endl;
            return true;
        }
    }
    //if the vertex is not found return false
    cout << "Vertex " << vert.getValue() << " not Found in this Graph" << endl;
    return false;

}

template<typename anyType>
bool UndirectedGraph<anyType>::removeEdge(Edge<anyType>& ed){

    //loop through the edge array
    for(int i=0; i<this->numOfEdges; i++){
        //check if this edge is present in the edge array
        if( ( ed.getStart()->getVertexID() == this->edges[i]->getStart()->getVertexID() && ed.getEnd()->getVertexID() == this->edges[i]->getEnd()->getVertexID() ) || ( ed.getStart()->getVertexID() == this->edges[i]->getEnd()->getVertexID() && ed.getEnd()->getVertexID() == this->edges[i]->getStart()->getVertexID() ) ){
            //shift all edges down the array from this point
            for(int j=i; j<this->numOfEdges-1; j++){
                this->edges[j] = this->edges[j+1];
            }
            //decrease the number of edges and return true
            this->numOfEdges--;
            cout << "Path from " << ed.getStart()->getValue() << " to " << ed.getEnd()->getValue() << " removed from this Graph" << endl;
            return true;
        }
    }
    //if the edge is not found return false
    cout << "Path from " << ed.getStart()->getValue() << " to " << ed.getEnd()->getValue() << " NOT Found in this Graph" << endl;
    return false;

}

//[8]
template<typename anyType>
bool UndirectedGraph<anyType>::containsVertex(anyType value){
    
    for (int i=0; i<this->numOfVertices; i++){
        if (this->vertices[i]->getValue() == value){
            cout << "Vertex " << value << " exists in this graph" <<endl;
            return true;
        }
    }
    cout << "Vertex " << value << " does NOT exist in this graph" <<endl;
    return false;

}

//[7]
template<typename anyType>
bool UndirectedGraph<anyType>::containsEdge(const Edge<anyType>& ed){
    
    for (int i=0; i<this->numOfEdges; i++){
        if ( ( ed.getStart()->getVertexID() == this->edges[i]->getStart()->getVertexID() && ed.getEnd()->getVertexID() == this->edges[i]->getEnd()->getVertexID() ) || ( ed.getStart()->getVertexID() == this->edges[i]->getEnd()->getVertexID() && ed.getEnd()->getVertexID() == this->edges[i]->getStart()->getVertexID() ) ){
            cout << "Edge from " << ed.getStart()->getValue() << " to " << ed.getEnd()->getValue() << " exists in this graph" << endl;
            return true;
        }
    }
    cout << "Edge from " << ed.getStart()->getValue() << " to " << ed.getEnd()->getValue() << " does NOT exist in this graph" << endl;
    return false;
    
}

template<typename anyType>
Vertex<anyType>* UndirectedGraph<anyType>::requestVertex(anyType val){
    
    for (int i=0; i<this->numOfVertices; i++){
        if (this->vertices[i]->getValue() == val){
            return this->vertices[i];
        }
    }
    return nullptr;
    
}

template<typename anyType>
Edge<anyType>* UndirectedGraph<anyType>::requestEdge(anyType val1, anyType val2){
    
    
    for (int i=0; i<this->numOfEdges; i++){
        if ( ( this->edges[i]->getStart()->getValue() == val1 && this->edges[i]->getEnd()->getValue() == val2 ) || ( this->edges[i]->getStart()->getValue() == val2 && this->edges[i]->getEnd()->getValue() == val1 )){
            return this->edges[i];
        }
    }
    cout << "Edge Does NOT Exist" << endl;
    return nullptr;
    
}

template<class anyType>
void UndirectedGraph<anyType>::printPaths(){
    //create an adjacency list
    anyType adjacencyList[this->numOfVertices][this->numOfVertices];
    
    //fill the adjacency list with rows of adjacent edges
    for(int i=0; i< this->numOfVertices; i++){
        int numAdjacentVertices = 0;
        for(int j=0; j< this->numOfEdges; j++){
            if(this->edges[j]->getStart()->getVertexID() == this->vertices[i]->getVertexID()){
                adjacencyList[i][numAdjacentVertices++] = this->edges[j]->getEnd()->getValue();
            }
            if(this->edges[j]->getEnd()->getVertexID() == this->vertices[i]->getVertexID()){
                adjacencyList[i][numAdjacentVertices++] = this->edges[j]->getStart()->getValue();
            }
        }
    }
    
    //print adjacency list
    for(int i=0; i<this->numOfVertices; i++){
        cout << this->vertices[i]->getValue() << "\t|\t";
        for(int j=0; j<this->numOfVertices; j++){
            cout << adjacencyList[i][j] << '\t';
        }
        cout << endl;
    }
    
}


template<typename anyType>
void UndirectedGraph<anyType>::printVertexPaths(const Vertex<anyType>& vert){
    //create an adjacency list
    anyType adjacencyList[this->numOfVertices][this->numOfVertices];
    
    //fill the adjacency list with rows of adjacent edges
    for(int i=0; i< this->numOfVertices; i++){
        int numAdjacentVertices = 0;
        for(int j=0; j< this->numOfEdges; j++){
            if(this->edges[j]->getStart()->getVertexID() == this->vertices[i]->getVertexID()){
                adjacencyList[i][numAdjacentVertices++] = this->edges[j]->getEnd()->getValue();
            }
            if(this->edges[j]->getEnd()->getVertexID() == this->vertices[i]->getVertexID()){
                adjacencyList[i][numAdjacentVertices++] = this->edges[j]->getStart()->getValue();
            }
        }
    }
    
    //print one line of adjacency list
    for(int i=0; i<this->numOfVertices; i++){
        if(vert.getValue() == this->vertices[i]->getValue()){
            cout << this->vertices[i]->getValue();
        
            cout << "\t|\t";
            for(int j=0; j<this->numOfVertices; j++){
                cout << adjacencyList[i][j] << '\t';
            }
            cout << endl;
        }
    }
    
}


template<typename anyType>
bool UndirectedGraph<anyType>::operator==(const UndirectedGraph& g2) const{
    
    int currentID, otherID;
        bool hasSameID = false;
        
        if(this->numOfVertices == g2.numOfVertices){
            for(int i=0; i<this->numOfVertices; i++){
                
                hasSameID = false;
                currentID = this->vertices[i]->getVertexID();
                
                for(int j=0; j<g2.numOfVertices; j++){
        
                    otherID = g2.vertices[j]->getVertexID();
                    if(currentID == otherID){
                        hasSameID = true;
                    }
                }
                if(!hasSameID){
                    return false;
                }
            }
        }
        else{
            return false;
        }
        if(this->numOfEdges == g2.numOfEdges){
            for(int i=0; i<this->numOfEdges; i++){
                
                hasSameID = false;
                currentID = this->edges[i]->getEdgeID();
                
                for(int j=0; j<g2.numOfEdges; j++){
        
                    otherID = g2.edges[j]->getEdgeID();
                    if(currentID == otherID){
                        hasSameID = true;
                    }
                }
                if(!hasSameID){
                    return false;
                }
            }
        }
        else{
            return false;
        }
        return true;

}

template<typename anyType>
const UndirectedGraph<anyType>& UndirectedGraph<anyType>::operator=(const UndirectedGraph& g2){
    
    this->numOfVertices = g2.numOfVertices;
    this->numOfEdges = g2.numOfEdges;
    
    this->maxNumVertices = g2.maxNumVertices;
    this->maxNumEdges = g2.maxNumEdges;
    
    this->vertices = new Vertex<anyType>*[this->maxNumVertices];
    this->edges = new Edge<anyType>*[this->maxNumEdges];
    
    for(int i=0; i<this->numOfVertices; i++){
        this->vertices[i] = g2.vertices[i];
    }
    for(int i=0; i<this->numOfEdges; i++){
        this->edges[i] = g2.edges[i];
    }
    
    return *this;
    
}

template<typename anyType>
UndirectedGraph<anyType> UndirectedGraph<anyType>::operator+(const UndirectedGraph& g2) const{
    
    UndirectedGraph g3;

    for(int i=0; i<this->numOfVertices; i++){
        g3.addVertex(*this->vertices[i]);
    }
    for(int i=0; i<g2.numOfVertices; i++){
        g3.addVertex(*g2.vertices[i]);
    }
    
    for(int i=0; i<this->numOfEdges; i++){
        g3.addEdge(*this->edges[i]);
    }
    for(int i=0; i<g2.numOfEdges; i++){
        g3.addEdge(*g2.edges[i]);
    }
    
    return g3;

}


template<typename anyType>
UndirectedGraph<anyType>::~UndirectedGraph(){
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------DGRAPH-----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------


template<typename anyType>
class DirectedGraph : public Graph<anyType>{
    //[2] here we are making a directed graph
public:
    DirectedGraph();
    DirectedGraph(int,int);
    DirectedGraph(DirectedGraph&);
    
    bool addVertex(Vertex<anyType>&);    //[3]
    bool addEdge(Edge<anyType>&);        //[3]
    
    bool removeVertex (Vertex<anyType>&);     //remove the vertex
    bool removeEdge(Edge<anyType>&);          // remove the edge
    
    bool containsVertex(anyType);               // [8] return true if a Vertex with given value exists in a graph
    bool containsEdge(const Edge<anyType>&);    // [7] return true if an Edge exists in a graph
    
    Vertex<anyType>* requestVertex(anyType);                //return pointer to requested vertex given vertex value
    Edge<anyType>* requestEdge(anyType val1, anyType val2); //return pointer to requested edge given start and end vertex values
    
    void printPaths();                                      // [5]
    void printVertexPaths(const Vertex<anyType>&);          // [6]
    
    ~DirectedGraph();
    
    
    bool operator==(const DirectedGraph& g2) const;
    const DirectedGraph& operator=(const DirectedGraph& g2);
    DirectedGraph operator+(const DirectedGraph& g2) const;
    
    //operator<< needs to be defined within the class in order to function with a template
    friend ostream& operator<< (ostream& out, const DirectedGraph<anyType>& g){
        out << "G(V,E)\nV = {";
        for(int i=0; i<g.numOfVertices; i++){

            out << g.vertices[i]->getValue();

            if(i < g.numOfVertices-1){
                out << ", ";
            }
        }
        out << "}\nE = {";
        for(int i=0; i<g.numOfEdges; i++){

            out << "(" << g.edges[i]->getStart()->getValue() << "->" << g.edges[i]->getEnd()->getValue() << ")";

            if(i < g.numOfEdges-1){
                out << ", ";
            }
        }
        out << "}\n";

        return out;
    }

    
    
};



//Default constructor from parent is called
template<typename anyType>
DirectedGraph<anyType>::DirectedGraph() : Graph<anyType>(){
    
}

//Parametrized constructor from parent is called
template<typename anyType>
DirectedGraph<anyType>::DirectedGraph(int maxNumVertices, int maxNumEdges) : Graph<anyType>(maxNumVertices,maxNumEdges){
    
}

//Copy constructor from parent is called
template<typename anyType>
DirectedGraph<anyType>::DirectedGraph(DirectedGraph& g) : Graph<anyType>(g){
    
}

//[3]
template<typename anyType>
bool DirectedGraph<anyType>::addVertex(Vertex<anyType>& vert){
    
    //loop through the array
    for(int i=0; i<this->numOfVertices; i++){
        //ensure that this vertex is not already in the graph, end function if this vertex is found
        if(vert.getVertexID() == this->vertices[i]->getVertexID() || vert.getValue() == this->vertices[i]->getValue()){
            cout << "Vertex " << vert.getValue() << " Already in this Graph" << endl;
            //return true because the given vertex is technically present in this graph
            return true;
        }
    }
    //make sure the array of vertices is not full
    if(this->numOfVertices < this->maxNumVertices){
        //if this vertex does not already exist in the graph, add it to the array of vertices and increase the number of vertices
        cout << "Vertex " << vert.getValue() << " added to the graph" << endl;
        this->vertices[this->numOfVertices++] = &vert;
        return true;
    }
    else{
        cout << "Vertex Array Full" << endl;
        //only return false if the array is full
        return false;
    }
    
}

//[3]
template<typename anyType>
bool DirectedGraph<anyType>::addEdge(Edge<anyType>& ed){
    
    //attempt to add the vertices this edge contains
    Vertex<anyType>* startPoint = ed.getStart();
    Vertex<anyType>* endPoint = ed.getEnd();
    
    //the only issue for adding the start and end verticies are when the array of vertices is full, in this case end the function
    if(!addVertex(*startPoint) || !addVertex(*endPoint)){
        return false;
    }
    
    //make sure the array of edges is not full
    if(this->numOfEdges < this->maxNumEdges){
        //loop through the array
        for(int i=0; i<this->numOfEdges; i++){
            //ensure that this edge is not already in the graph, end function if this vertex is found
            if( ( startPoint->getVertexID() == this->edges[i]->getStart()->getVertexID() && endPoint->getVertexID() == this->edges[i]->getEnd()->getVertexID() )){
                cout << "Path from " << startPoint->getValue() << " to " << endPoint->getValue() << " Already in this Undirected Graph" << endl;
                //return true because the given edge is technically present in this graph
                return true;
            }
        }
        //if this edge does not already exist in the graph, add it to the array of edges and increase the number of edges
        cout << "Path from " << startPoint->getValue() << " to " << endPoint->getValue() << " added to the graph" << endl;
        this->edges[this->numOfEdges++] = &ed;
        return true;
    }
    else{
        cout << "Edges Array Full" << endl;
        return false;
    }
    
}

template<typename anyType>
bool DirectedGraph<anyType>::removeVertex (Vertex<anyType>& vert){

    //ensure that none of the edges use this vertex
    
    for(int i=0; i<this->numOfEdges; i++){
        //if any edges with this vertex as a start or end is found, remove those edges from the graph firstly
        if( ( this->edges[i]->getStart()->getValue() == vert.getValue() ) || ( this->edges[i]->getEnd()->getValue() == vert.getValue() )){
            removeEdge(*this->edges[i]);
            i--;
        }
    }
    
    //loop through the vertex array
    for(int i=0; i<this->numOfVertices; i++){
        //check if this vertex is present in the vertex array
        if(vert.getVertexID() == this->vertices[i]->getVertexID()){
            //shift all vertices down the array from this point
            for(int j=i; j<this->numOfVertices-1; j++){
                this->vertices[j] = this->vertices[j+1];
            }
            //decrease the number of vertices and return true
            this->numOfVertices--;
            cout << "Vertex " << vert.getValue() << " removed from this Graph" << endl;
            return true;
        }
    }
    //if the vertex is not found return false
    cout << "Vertex " << vert.getValue() << " not Found in this Graph" << endl;
    return false;

}

template<typename anyType>
bool DirectedGraph<anyType>::removeEdge(Edge<anyType>& ed){

    //loop through the edge array
    for(int i=0; i<this->numOfEdges; i++){
        //check if this edge is present in the edge array
        if( ( ed.getStart()->getVertexID() == this->edges[i]->getStart()->getVertexID() && ed.getEnd()->getVertexID() == this->edges[i]->getEnd()->getVertexID() ) ){
            //shift all edges down the array from this point
            for(int j=i; j<this->numOfEdges-1; j++){
                this->edges[j] = this->edges[j+1];
            }
            //decrease the number of edges and return true
            this->numOfEdges--;
            cout << "Path from " << ed.getStart()->getValue() << " to " << ed.getEnd()->getValue() << " removed from this Graph" << endl;
            return true;
        }
    }
    //if the edge is not found return false
    cout << "Path from " << ed.getStart()->getValue() << " to " << ed.getEnd()->getValue() << " NOT Found in this Graph" << endl;
    return false;

}

//[8]
template<typename anyType>
bool DirectedGraph<anyType>::containsVertex(anyType value){
    
    for (int i=0; i<this->numOfVertices; i++){
        if (this->vertices[i]->getValue() == value){
            cout << "Vertex " << value << " exists in this graph" <<endl;
            return true;
        }
    }
    cout << "Vertex " << value << " does NOT exist in this graph" <<endl;
    return false;

}

//[7]
template<typename anyType>
bool DirectedGraph<anyType>::containsEdge(const Edge<anyType>& ed){
    
    for (int i=0; i<this->numOfEdges; i++){
        if ( ( ed.getStart()->getVertexID() == this->edges[i]->getStart()->getVertexID() && ed.getEnd()->getVertexID() == this->edges[i]->getEnd()->getVertexID() ) ){
            cout << "Edge from " << ed.getStart()->getValue() << " to " << ed.getEnd()->getValue() << " exists in this graph" << endl;
            return true;
        }
    }
    cout << "Edge from " << ed.getStart()->getValue() << " to " << ed.getEnd()->getValue() << " does NOT exist in this graph" << endl;
    return false;
    
}

template<typename anyType>
Vertex<anyType>* DirectedGraph<anyType>::requestVertex(anyType val){
    
    for (int i=0; i<this->numOfVertices; i++){
        if (this->vertices[i]->getValue() == val){
            return this->vertices[i];
        }
    }
    return nullptr;
    
}

template<typename anyType>
Edge<anyType>* DirectedGraph<anyType>::requestEdge(anyType val1, anyType val2){
    
    
    for (int i=0; i<this->numOfEdges; i++){
        if ( ( this->edges[i]->getStart()->getValue() == val1 && this->edges[i]->getEnd()->getValue() == val2 ) ){
            return this->edges[i];
        }
    }
    cout << "Edge Does NOT Exist" << endl;
    return nullptr;
    
}

template<class anyType>
void DirectedGraph<anyType>::printPaths(){
    //create an adjacency list
    anyType adjacencyList[this->numOfVertices][this->numOfVertices];
    
    //fill the adjacency list with rows of adjacent edges
    for(int i=0; i< this->numOfVertices; i++){
        int numAdjacentVertices = 0;
        for(int j=0; j< this->numOfEdges; j++){
            if(this->edges[j]->getStart()->getVertexID() == this->vertices[i]->getVertexID()){
                adjacencyList[i][numAdjacentVertices++] = this->edges[j]->getEnd()->getValue();
            }
        }
    }
    
    //print adjacency list
    for(int i=0; i<this->numOfVertices; i++){
        cout << this->vertices[i]->getValue() << "\t|\t";
        for(int j=0; j<this->numOfVertices; j++){
            cout << adjacencyList[i][j] << '\t';
        }
        cout << endl;
    }
    
}


template<typename anyType>
void DirectedGraph<anyType>::printVertexPaths(const Vertex<anyType>& vert){
    //create an adjacency list
    anyType adjacencyList[this->numOfVertices][this->numOfVertices];
    
    //fill the adjacency list with rows of adjacent edges
    for(int i=0; i< this->numOfVertices; i++){
        int numAdjacentVertices = 0;
        for(int j=0; j< this->numOfEdges; j++){
            if(this->edges[j]->getStart()->getVertexID() == this->vertices[i]->getVertexID()){
                adjacencyList[i][numAdjacentVertices++] = this->edges[j]->getEnd()->getValue();
            }
        }
    }
    
    //print one line of adjacency list
    for(int i=0; i<this->numOfVertices; i++){
        if(vert.getValue() == this->vertices[i]->getValue()){
            cout << this->vertices[i]->getValue();
        
            cout << "\t|\t";
            for(int j=0; j<this->numOfVertices; j++){
                cout << adjacencyList[i][j] << '\t';
            }
            cout << endl;
        }
    }
    
}


template<typename anyType>
bool DirectedGraph<anyType>::operator==(const DirectedGraph& g2) const{
    
    int currentID, otherID;
        bool hasSameID = false;
        
        if(this->numOfVertices == g2.numOfVertices){
            for(int i=0; i<this->numOfVertices; i++){
                
                hasSameID = false;
                currentID = this->vertices[i]->getVertexID();
                
                for(int j=0; j<g2.numOfVertices; j++){
        
                    otherID = g2.vertices[j]->getVertexID();
                    if(currentID == otherID){
                        hasSameID = true;
                    }
                }
                if(!hasSameID){
                    return false;
                }
            }
        }
        else{
            return false;
        }
        if(this->numOfEdges == g2.numOfEdges){
            for(int i=0; i<this->numOfEdges; i++){
                
                hasSameID = false;
                currentID = this->edges[i]->getEdgeID();
                
                for(int j=0; j<g2.numOfEdges; j++){
        
                    otherID = g2.edges[j]->getEdgeID();
                    if(currentID == otherID){
                        hasSameID = true;
                    }
                }
                if(!hasSameID){
                    return false;
                }
            }
        }
        else{
            return false;
        }
        return true;

}

template<typename anyType>
const DirectedGraph<anyType>& DirectedGraph<anyType>::operator=(const DirectedGraph& g2){
    
    this->numOfVertices = g2.numOfVertices;
    this->numOfEdges = g2.numOfEdges;
    
    this->maxNumVertices = g2.maxNumVertices;
    this->maxNumEdges = g2.maxNumEdges;
    
    this->vertices = new Vertex<anyType>*[this->maxNumVertices];
    this->edges = new Edge<anyType>*[this->maxNumEdges];
    
    for(int i=0; i<this->numOfVertices; i++){
        this->vertices[i] = g2.vertices[i];
    }
    for(int i=0; i<this->numOfEdges; i++){
        this->edges[i] = g2.edges[i];
    }
    
    return *this;
    
}

template<typename anyType>
DirectedGraph<anyType> DirectedGraph<anyType>::operator+(const DirectedGraph& g2) const{
    
    DirectedGraph g3;

    for(int i=0; i<this->numOfVertices; i++){
        g3.addVertex(*this->vertices[i]);
    }
    for(int i=0; i<g2.numOfVertices; i++){
        g3.addVertex(*g2.vertices[i]);
    }
    
    for(int i=0; i<this->numOfEdges; i++){
        g3.addEdge(*this->edges[i]);
    }
    for(int i=0; i<g2.numOfEdges; i++){
        g3.addEdge(*g2.edges[i]);
    }
    
    return g3;

}

template<typename anyType>
DirectedGraph<anyType>::~DirectedGraph(){
}
