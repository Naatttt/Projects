#include <iostream>
#include "Classes.cpp"
using namespace std;

int main() {
    
    cout << "Initialize and Create The Green Montreal Metro Line with All Confirmation Strings Printed" << endl;
    cout << "\nPress ENTER To Continue";
    cin.get();
    cout << endl;
    
    Vertex<string>* v1 = new Vertex<string>("Angrignon");
    Vertex<string>* v2 = new Vertex<string>("Monk");
    Vertex<string>* v3 = new Vertex<string>("Jolicoeur");
    Vertex<string>* v4 = new Vertex<string>("Verdun");
    Vertex<string>* v5 = new Vertex<string>("De L'Eglise");
    Vertex<string>* v6 = new Vertex<string>("LaSalle");
    Vertex<string>* v7 = new Vertex<string>("Charlevoix");
    Vertex<string>* v8 = new Vertex<string>("Lionel-Groulx");
    Vertex<string>* v9 = new Vertex<string>("Atwater");
    Vertex<string>* v10 = new Vertex<string>("Guy-Concordia");
    Vertex<string>* v11 = new Vertex<string>("Peel");
    Vertex<string>* v12 = new Vertex<string>("McGill");
    Vertex<string>* v13 = new Vertex<string>("Place-Des-Arts");
    Vertex<string>* v14 = new Vertex<string>("Saint-Laurent");
    Vertex<string>* v15 = new Vertex<string>("Berri-UQAM");
    Vertex<string>* v16 = new Vertex<string>("Beaudry");
    Vertex<string>* v17 = new Vertex<string>("Papineau");
    Vertex<string>* v18 = new Vertex<string>("Frontenac");
    Vertex<string>* v19 = new Vertex<string>("Prefonaine");
    Vertex<string>* v20 = new Vertex<string>("Joliette");
    Vertex<string>* v21 = new Vertex<string>("Pie-IX");
    Vertex<string>* v22 = new Vertex<string>("Viau");
    Vertex<string>* v23 = new Vertex<string>("Assomption");
    Vertex<string>* v24 = new Vertex<string>("Cadillac");
    Vertex<string>* v25 = new Vertex<string>("Langelier");
    Vertex<string>* v26 = new Vertex<string>("Radisson");
    Vertex<string>* v27 = new Vertex<string>("Honore-Beaugrand");
    Edge<string>* e1 = new Edge<string>(v1,v2);
    Edge<string>* e2 = new Edge<string>(v2,v3);
    Edge<string>* e3 = new Edge<string>(v3,v4);
    Edge<string>* e4 = new Edge<string>(v4,v5);
    Edge<string>* e5 = new Edge<string>(v5,v6);
    Edge<string>* e6 = new Edge<string>(v6,v7);
    Edge<string>* e7 = new Edge<string>(v7,v8);
    Edge<string>* e8 = new Edge<string>(v8,v9);
    Edge<string>* e9 = new Edge<string>(v9,v10);
    Edge<string>* e10 = new Edge<string>(v10,v11);
    Edge<string>* e11 = new Edge<string>(v11,v12);
    Edge<string>* e12 = new Edge<string>(v12,v13);
    Edge<string>* e13 = new Edge<string>(v13,v14);
    Edge<string>* e14 = new Edge<string>(v14,v15);
    Edge<string>* e15 = new Edge<string>(v15,v16);
    Edge<string>* e16 = new Edge<string>(v16,v17);
    Edge<string>* e17 = new Edge<string>(v17,v18);
    Edge<string>* e18 = new Edge<string>(v18,v19);
    Edge<string>* e19 = new Edge<string>(v19,v20);
    Edge<string>* e20 = new Edge<string>(v20,v21);
    Edge<string>* e21 = new Edge<string>(v21,v22);
    Edge<string>* e22 = new Edge<string>(v22,v23);
    Edge<string>* e23 = new Edge<string>(v23,v24);
    Edge<string>* e24 = new Edge<string>(v24,v25);
    Edge<string>* e25 = new Edge<string>(v25,v26);
    Edge<string>* e26 = new Edge<string>(v26,v27);
    

    UndirectedGraph<string>* greenLine = new UndirectedGraph<string>();
    cout << *greenLine << endl;
    
    //only need to add the edges since itll add the vertices as well
    greenLine->addEdge(*e1);
    greenLine->addEdge(*e2);
    greenLine->addEdge(*e3);
    greenLine->addEdge(*e4);
    greenLine->addEdge(*e5);
    greenLine->addEdge(*e6);
    greenLine->addEdge(*e7);
    greenLine->addEdge(*e8);
    greenLine->addEdge(*e9);
    greenLine->addEdge(*e10);
    greenLine->addEdge(*e11);
    greenLine->addEdge(*e12);
    greenLine->addEdge(*e13);
    greenLine->addEdge(*e14);
    greenLine->addEdge(*e15);
    greenLine->addEdge(*e16);
    greenLine->addEdge(*e17);
    greenLine->addEdge(*e18);
    greenLine->addEdge(*e19);
    greenLine->addEdge(*e20);
    greenLine->addEdge(*e21);
    greenLine->addEdge(*e22);
    greenLine->addEdge(*e23);
    greenLine->addEdge(*e24);
    greenLine->addEdge(*e25);
    greenLine->addEdge(*e26);
    
    cout << "\n\nMetro Stations and Paths\n" << endl;
    cout << *greenLine << endl;
    
    cout << "\nAdjacency List\n" << endl;
    greenLine->printPaths();
    cout << endl;
    
    
    bool done = false;
    int choice;
    while(!done){
        
        cout << "\n\nChoose One Of These Options" << endl;
        cout << "1. Add a Station to The Green Line" << endl;
        cout << "2. Add a Path to the Green Line" << endl;
        cout << "3. Remove a Station from the Green Line" << endl;
        cout << "4. Remove a Path from the Green Line" << endl;
        cout << "5. Print Adjacency of a Station" << endl;
        cout << "6. Print the Green Line" << endl;
        cout << "7. Test Operator Methods in UndirectedGraph Class" << endl;
        cout << "8. END" << endl;
        cout << "\nChoice: ";
        
        cin >> choice;
        cout << '\n' << endl;
        switch(choice){
                
            case 1: {
                string stationName;
            
                cout << "Enter the Name of The Station to Add: " << endl;
                cin.ignore();
                getline(cin, stationName);
                Vertex<string>* v = new Vertex<string>(stationName);
                greenLine->addVertex(*v);
                
                break;
            }
                
            case 2: {
                
                string stationName1, stationName2;
                
                cout << "Enter the Names of the Two Stations to Unite: " << endl;
                
                cout << "Station 1: " << endl;
                cin.ignore();
                getline(cin, stationName1);
                cout << "Station 2: " << endl;
                getline(cin, stationName2);
                
                if(greenLine->containsVertex(stationName1) && greenLine->containsVertex(stationName2)){
                    
                    Edge<string>* e = new Edge<string>(greenLine->requestVertex(stationName1),greenLine->requestVertex(stationName2));
                    greenLine->addEdge(*e);
                }
                
                break;
            }
            case 3: {
                
                string stationName;
                
                cout << "Enter the Name of the Station to Remove: " << endl;
                cin.ignore();
                getline(cin, stationName);
                if(greenLine->containsVertex(stationName)){
                    greenLine->removeVertex(*greenLine->requestVertex(stationName));
                }
                
                break;
            }
                
            case 4: {
                string stationName1, stationName2;
                
                cout << "Enter the Names of the Start and End Stations of the Path to Remove: " << endl;
                
                cout << "Station 1: " << endl;
                cin.ignore();
                getline(cin, stationName1);
                cout << "Station 2: " << endl;
                getline(cin, stationName2);
                
                greenLine->removeEdge(*greenLine->requestEdge(stationName1, stationName2));
                
                break;
            }
               
            case 5: {
                
                string stationName;
            
                cout << "Enter the Name of The Station to Print: " << endl;
                cin.ignore();
                getline(cin, stationName);
                
                if(greenLine->containsVertex(stationName)){
                    greenLine->printVertexPaths(*greenLine->requestVertex(stationName));
                }
                
                break;
            }
                
            case 6: {
                cout << "Metro Stations and Paths" << endl;
                cout << *greenLine << endl;
                
                cout << "\nAdjacency List" << endl;
                greenLine->printPaths();
                
                break;
            }
                
            case 7: {
                
                UndirectedGraph<string>* mtlMetroCopy = new UndirectedGraph<string>();
                *mtlMetroCopy = *greenLine;
                cout << *greenLine << endl;
                cout << *mtlMetroCopy << endl;
                
                if(*greenLine == *mtlMetroCopy){
                    cout << "These graphs are Equal" << endl;
                }
                else{
                    cout << "These graphs are NOT Equal" << endl;
                }
                
                mtlMetroCopy->removeEdge(*e1);
                mtlMetroCopy->containsEdge(*e1);
                greenLine->containsEdge(*e1);
                
                if(*greenLine == *mtlMetroCopy){
                    cout << "These graphs are Equal" << endl;
                }
                else{
                    cout << "These graphs are NOT Equal" << endl;
                }

                cout << *greenLine << endl;
                cout << *mtlMetroCopy << endl;
                
                break;
            }
            default:
                done = true;
        }
        
    }
    
    
    
    return 0;
}
