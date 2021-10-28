/***********************************************************
Name: Tomas Vasquez, Benjamin Swann, Jesus Rivera III
Assignment: Final Project
Purpose: This program opens 3 diff files based on user input from command line (conducts basic file validation checks), 
and conducts graph operations based on if they are weighted or not and writes original contents to a file. The file operations: 
Breath First Search, Depth First Search, add a vertex, delete a vertex, conduct checks for duplicates(edges or vertex), check 
to delete an existing node, and checks connectivity and provides a list of items not connected.
Notes: Operations: Breath First Search, Depth First Search, add/ delete (vertex/edge) and write to file (example.txt).
***********************************************************/

#include "main.h"
int main(int argc, char *argv[])
{
    srand(time(NULL));                  // Time 
    int h=0;                            //ARGV counter
    h = argc-1;                         // maintenance counter control
    bool loca2=false;                   //determine if graph is weighted
    
    if (h==0)
    {
        cout<<"cannot enter no arguments"<<endl;

    } else if (h>=1){
        for (int i = 1; i < argc; ++i)
        {
            ifstream infile; 
            infile.open(argv[i]);
            infile.peek();
            cout<<endl;

            if (!infile.is_open()){
                cout<<"file doesnt exist"<<endl;
            } else if(infile.eof())
            {
                cout<<"nothing is there"<<endl;
                
            }  else  ////////// File open and has data //////////////
            {
                string firstline;
                int size = 0;
                bool hasLables = false;
                getline(infile, firstline);
                int i =0;
                if(firstline[i] == 'X')
                {
                    hasLables=true;
                    i++;
                }

                for(; i<firstline.length(); i++)
                {
                    if(isalnum(firstline[i]))
                        size++;
                }

                if(!hasLables)
                    infile.seekg(0, infile.beg);


                Graph g(size, hasLables);

                /*
                *  Displaying list 
                */
                cout << "Dispaying Adjacency list" << endl;
                cout << "==============================================" << endl;
                char ch;                        // character read from the file
                int number;                     //number reader
                int row = 0, col = 0;           //column counter
                ch = infile.peek();
                while (!infile.eof())
                {
                    //cout << ch ;
                    if (isdigit(ch))
                    {
                        infile >> number;
                        if (number>1)
                        {
                            loca2=true;
                        }
                        
                        if(number > 0)
                        {
                            cout << "value: " << ch << '\t';            //for visual representation of edges & weights
                            cout << row << ", " << col << endl;
                            g.addEdge(row,col, number);
                        }
                        col++;
                    }
                    else{
                        ch = infile.get();
                        if(ch == '\n')
                        {
                            row++;
                            col=0;
                        }
                        else if(ch == 'x')
                        {
                            col++;
                        }
                    }
                    
                    ch = infile.peek();
                }
        
                infile.close();
                /*
                *  Generating test data numbers to conduct tests
                */
                                    //Testing variables that will be reused
                int size2 =20;                      
                int num1 = rand() % size;           
                int num2 = rand() % size;
                int num3 = rand() % size2;
                int num4 =rand() % size2;
                int edgeWeight = rand() % size2;
                int DFSnum = rand() % size;
                cout<<endl;
                            //*************************************************************
                            //   Main Data Test-Checking for error & failure              *
                            //*************************************************************  
                for (int i = 0; i < 300; i++)                                                           //LOOP TO IMPLEMENT AND TEST FOR PROJECT!!!!!!!!!!!!
                {
                    cout << endl << endl;
                    g.display(hasLables);             //Displaying table for visual reference
                    g.print(hasLables);             //Writing table to txt file 
                    cout<<endl<<endl<<endl;
                    cout<<"Intial counts  from Adjacency list"<<endl;
                    cout << "==============================================" << endl;                
                    cout<<"Edge count: "<<g.numEdges()<<endl;
                    cout<<"Vertex count: "<<g.numVertex()<<endl;
                    cout<<endl<<endl<<endl;

                    if(hasLables)
                    {
                        char label3;                //alpha place holder
                        char label4;                //alpha place holder
                        int size3 = 26;             //locally contained due to alphabet only has 26 letters
                        int num = rand()%size3;
                        num2 = rand()%size3;

                        cout << "Testing Adding Edge NOT from Adjacency list" << endl;
                        cout << "==============================================" << endl;  
                        label3=g.conversion (0);
                        label4=g.conversion (5);              
                        cout<<"Adding edge from: " << label3<<" to "<<label4 <<endl;  
                        g.addEdge(0,5) ? cout << "added" << endl : cout << "failed" << endl;
                        cout<<endl; 

                        cout << "Testing Adding Vertex NOT from Adjacency list" << endl;
                        cout << "==============================================" << endl;
                        label3=g.conversion (10);                
                        cout<<"Adding vertex: " <<label3<<endl;
                        g.addVertice(10) ? cout << "added" << endl : cout << "failed" << endl;
                        cout<<endl;   

                        cout << "Testing Adding Duplicate Edge from Adjacency list" << endl;
                        cout << "==============================================" << endl;  
                        label3=g.conversion (0);
                        label4=g.conversion (1);  
                        cout<<"Adding edge from: " << label3<<" to "<<label4 <<endl;               
                        g.addEdge(0,1) ? cout << "added" << endl : cout << "failed--It already exists" << endl;
                        cout<<endl;  

                        cout << "Testing Removing RANDOM Edge from Adjacency list (part1)" << endl;
                        cout << "==============================================" << endl;                
                        label3=g.conversion (num1);
                        label4=g.conversion (num2); 
                        cout<<"Removing:"<< label3<<" to "<<label4 <<endl;
                        g.removeEdge(num1,num2) ? cout << "removed" << endl : cout << "failed" << endl;
                        cout<<endl;

                    

                        /*
                        *  Resetting a new number 
                        */

                        num2 = rand() % size; 

                        cout << "Testing Removing RANDOM Vertex from Adjacency list" << endl;
                        cout << "==============================================" << endl;
                        label4=g.conversion (num2); 
                        cout<<"Removing vertex: "<<label4<<": "<<endl;
                        g.removeVertex(num2) ? cout << "removed" << endl : cout << "failed" << endl;
                        cout<<endl;

                        

                        cout << "Testing removing Vortex OUTSIDE of SIZE of Adjacency list" << endl;
                        cout << "==============================================" << endl;                
                        cout<<"Removing out of scope edge: "<<endl;  
                        g.removeVertex(11) ? cout << "removed" << endl : cout << "failed" << endl;
                        cout<<endl;

                        
                        cout << "Testing Adding "<<num4 << " Vertex to Adjacency list" << endl;
                        cout << "==============================================" << endl; 
                        num1 = rand() % size;       //resetting to generate diff test case 
                        num2 = rand() % size;       //resetting to generate diff test case
                        
                        for (int i=0; i<num4; i++)
                        {
                            num2 = rand() % size2;
                            label4=g.conversion (num2); 
                            cout<<"Adding: "<<label4<< " vertex: "<<endl; 
                            g.addVertice(num2) ? cout << "added" << endl : cout << "failed" << endl;
                            cout<<endl;
                        }

                        num4 = rand() % size2;
                        cout << "Testing Removing  "<<num4 << " edges to Adjacency list" << endl;
                        cout << "==============================================" << endl; 
                        for (int i=0; i<num4; i++)
                        {
                            num1 = rand() % size;
                            num2 = rand() % size;
                            label3=g.conversion (num1); 
                            label4=g.conversion (num2); 
                            cout<<"Removing edge from: "<<label3<<" to "<<label4<<" edge: "<<endl; 
                            g.removeEdge(num1,num2) ? cout << "removed" << endl : cout << "failed" << endl;
                            cout<<endl;
                        }

                        if(g.removeEdge(num1,num2))
                        {
                            cout<<"Is the graph Connected: "<<endl;
                            g.isConnected() ? cout << "Yes" << endl : cout << "No" << endl;
                            cout<<endl;
                        }

                        cout << "Testing Adding RANDOM number of Edges to Adjacency list" << endl;
                        cout << "==============================================" << endl;   
                        num1 = rand() % size;       //resetting to generate diff test case 
                        num2 = rand() % size;       //resetting to generate diff test case
                        num3 = rand() % size2;

                        if(loca2)
                        {
                            cout<<"Testing adding RANDOM number of edges with WEIGHTS"<<endl;
                            for (int i =0; i<num3; i++)
                            {
                                num1 = rand() % size;       //resetting during each iteration 
                                num2 = rand() % size; 
                                edgeWeight = rand() % size2;
                                label3=g.conversion (num1); 
                                label4=g.conversion (num2);
                                cout<<endl<<endl;
                                cout<<"Adding: "<<label3<<","<<label4<<","<<edgeWeight<<endl;
                                g.addEdge(num1,num2,edgeWeight) ? cout << "added" << endl : cout << "failed-- already exists" << endl;
                                cout<<endl;
                            }
                        } else
                        {
                            cout<<"Testing adding RANDOM number of edges"<<endl;
                            for (int i =0; i<num3; i++)
                            {
                                num1 = rand() % size;       //resetting during each iteration 
                                num2 = rand() % size; 
                                label3=g.conversion (num1); 
                                label4=g.conversion (num2);      

                                cout<<"Adding edge from: "<<label3<<" to "<<label4<<endl; 
                                g.addEdge(num1,num2) ? cout << "added" << endl : cout << "failed-- already exists" << endl;
                            }

                        }


                        cout << "DFS & BFS w/ same vertex" << endl;
                        cout << "==============================================" << endl;                
                        cout<<"Breath first Search results: "<<endl;
                        g.BFS(5, hasLables);
                        cout<<endl;
                        cout<<"Depth first Search results:"<<endl;
                        g.DFS(5, hasLables);
                        cout<<endl<<endl;

                        /*
                        *  To account for connected but disjointed graphs that are from original graph 
                        */

                        cout << "DFS & BFS w/ Random vertex" << endl;
                        cout << "==============================================" << endl;  
                        label3=g.conversion (DFSnum);              
                        cout<<"Breath first Search results from "<<label3<<": "<<endl;
                        g.BFS(DFSnum, hasLables);
                        cout<<endl;
                        DFSnum = rand() % size;
                        label4=g.conversion (DFSnum); 
                        cout<<"Depth first Search results from "<<label4<<": "<<endl;
                        g.DFS(DFSnum, hasLables);
                        cout<<endl;

                        cout << "DFS & BFS w/ Random vertex and Random number of times" << endl;
                        cout << "==============================================" << endl; 
                        for (int i=0;i<num2;i++)
                        {
                            label3=g.conversion (DFSnum); 
                            cout<<"Breath first Search results from "<<label3<<": "<<endl;
                            g.BFS(DFSnum, hasLables);
                            cout<<endl;
                            DFSnum = rand() % size;
                            label4=g.conversion (DFSnum); 
                            cout<<"Depth first Search results from "<<label4<<": "<<endl;
                            g.DFS(DFSnum, hasLables);
                            cout<<endl<<endl;

                        }       
                        cout <<"Adjacency list edge/vortex Info" << endl;
                        cout <<"==============================================" << endl;
                        cout<<"Edge count: "<<g.numEdges()<<endl;
                        cout<<"Vertex count: "<<g.numVertex()<<endl;
                        cout<<"Is the graph Connected: "<<endl;
                        g.isConnected() ? cout << "Yes" << endl : cout << "No" << endl;
                        cout<<endl;
                        if(!g.isConnected())
                        {
                            cout<<"List the disconnected:"<<endl;
                            g.listDisconnected(hasLables);
                        }


                    }else
                    {
                            cout << "Testing Adding Edge NOT from Adjacency list" << endl;
                            cout << "==============================================" << endl;                
                            cout<<"Adding edge (0,5): "<<endl;  
                            g.addEdge(0,5) ? cout << "added" << endl : cout << "failed" << endl;
                            cout<<endl; 

                            cout << "Testing Adding Vertex NOT from Adjacency list" << endl;
                            cout << "==============================================" << endl;                
                            cout<<"Adding vertex 10: "<<endl;
                            g.addVertice(10) ? cout << "added" << endl : cout << "failed" << endl;
                            cout<<endl;   

                            cout << "Testing Adding Duplicate Edge from Adjacency list" << endl;
                            cout << "==============================================" << endl;                
                            cout<<"Adding edge (0,1): "<<endl;
                            g.addEdge(0,1) ? cout << "added" << endl : cout << "failed--It already exists" << endl;
                            cout<<endl;  

                            cout << "Testing Removing RANDOM Edge from Adjacency list (part1)" << endl;
                            cout << "==============================================" << endl;                
                            cout<<"Removing ("<<num1<<","<<num2<<") edge: "<<endl; 
                            g.removeEdge(num1,num2) ? cout << "removed" << endl : cout << "failed" << endl;
                            cout<<endl;

                            if (g.removeEdge(num1,num2))
                            {
                                cout<<"Is the graph Connected: "<<endl;
                                g.isConnected() ? cout << "Yes" << endl : cout << "No" << endl;
                                cout<<endl;
                            }

                            /*
                            *  Resetting a new number 
                            */

                            num2 = rand() % size; 

                            cout << "Testing Removing RANDOM Vertex from Adjacency list" << endl;
                            cout << "==============================================" << endl;
                            cout<<"Remove vertex "<<num2<<": "<<endl;
                            g.removeVertex(num2) ? cout << "removed" << endl : cout << "failed" << endl;
                            cout<<endl;

                            

                            cout << "Testing removing Vortex OUTSIDE of SIZE of Adjacency list" << endl;
                            cout << "==============================================" << endl;                
                            cout<<"Removing out of scope edge: "<<endl;  
                            g.removeVertex(11) ? cout << "removed" << endl : cout << "failed" << endl;
                            cout<<endl;

                            
                            cout << "Testing Adding "<<num4 << " Vertex to Adjacency list" << endl;
                            cout << "==============================================" << endl; 
                            num1 = rand() % size;       //resetting to generate diff test case 
                            num2 = rand() % size;       //resetting to generate diff test case
                            
                            for (int i=0; i<num4; i++)
                            {
                                num2 = rand() % size2;
                                cout<<"Adding: "<<num2<< " vertex: "<<endl; 
                                g.addVertice(num2) ? cout << "added" << endl : cout << "failed" << endl;
                                cout<<endl;
                            }

                            num4 = rand() % size2;
                            cout << "Testing Removing  "<<num4 << " edges to Adjacency list" << endl;
                            cout << "==============================================" << endl; 
                            for (int i=0; i<num4; i++)
                            {
                                num1 = rand() % size;
                                num2 = rand() % size;
                                cout<<"Removing ("<<num1<<","<<num2<<") edge: "<<endl; 
                                g.removeEdge(num1,num2) ? cout << "removed" << endl : cout << "failed" << endl;
                                cout<<endl;
                            }

                            if(g.removeEdge(num1,num2))
                            {
                                cout<<"Is the graph Connected: "<<endl;
                                g.isConnected() ? cout << "Yes" << endl : cout << "No" << endl;
                                cout<<endl;
                            }

                            cout << "Testing Adding RANDOM number of Edges to Adjacency list" << endl;
                            cout << "==============================================" << endl;   
                            num1 = rand() % size;       //resetting to generate diff test case 
                            num2 = rand() % size;       //resetting to generate diff test case
                            num3 = rand() % size2;

                            if(loca2)
                            {
                                cout<<"Testing adding RANDOM number of edges with WEIGHTS"<<endl;
                                for (int i =0; i<num3; i++)
                                {
                                    num1 = rand() % size;       //resetting during each iteration 
                                    num2 = rand() % size; 
                                    edgeWeight = rand() % size2;
                                    cout<<endl<<endl;
                                    cout<<"Adding: "<<num1<<","<<num2<<","<<edgeWeight<<endl;
                                    g.addEdge(num1,num2,edgeWeight) ? cout << "added" << endl : cout << "failed-- already exists" << endl;
                                    cout<<endl;
                                }
                            } else
                            {
                                cout<<"Testing adding RANDOM number of edges"<<endl;
                                for (int i =0; i<num3; i++)
                                {
                                    num1 = rand() % size;       //resetting during each iteration 
                                    num2 = rand() % size;       

                                    cout<<"Adding ("<<num1<<","<<num2<<") edge: "<<endl; 
                                    g.addEdge(num1,num2) ? cout << "added" << endl : cout << "failed-- already exists" << endl;
                                }

                            }


                            cout << "DFS & BFS w/ same vertex" << endl;
                            cout << "==============================================" << endl;                
                            cout<<"Breath first Search results: "<<endl;
                            g.BFS(5, hasLables);
                            cout<<endl;
                            cout<<"Depth first Search results:"<<endl;
                            g.DFS(5, hasLables);
                            cout<<endl<<endl;

                            /*
                            *  To account for connected but disjointed graphs that are from original graph 
                            */

                            cout << "DFS & BFS w/ Random vertex" << endl;
                            cout << "==============================================" << endl;                
                            cout<<"Breath first Search results from "<<DFSnum<<": "<<endl;
                            g.BFS(DFSnum, hasLables);
                            cout<<endl;
                            DFSnum = rand() % size;
                            cout<<"Depth first Search results from "<<DFSnum<<": "<<endl;
                            g.DFS(DFSnum, hasLables);
                            cout<<endl;

                            cout << "DFS & BFS w/ Random vertex and Random number of times" << endl;
                            cout << "==============================================" << endl; 
                            for (int i=0;i<num2;i++)
                            {
                                cout<<"Breath first Search results from "<<DFSnum<<": "<<endl;
                                g.BFS(DFSnum, hasLables);
                                cout<<endl;
                                DFSnum = rand() % size;
                                cout<<"Depth first Search results from "<<DFSnum<<": "<<endl;
                                g.DFS(DFSnum, hasLables);
                                cout<<endl<<endl;

                            }       
                            cout <<"Adjacency list edge/vortex Info" << endl;
                            cout <<"==============================================" << endl;
                            cout<<"Edge count: "<<g.numEdges()<<endl;
                            cout<<"Vertex count: "<<g.numVertex()<<endl;
                            cout<<"Is the graph Connected: "<<endl;
                            g.isConnected() ? cout << "Yes" << endl : cout << "No" << endl;
                            cout<<endl;
                            if(!g.isConnected())
                            {
                                cout<<"List the disconnected:"<<endl;
                                g.listDisconnected(hasLables);
                            }
                            
                    }
            
                } ///// end file read /////
                
            }  
    }                     
                
    } else {
        cout<<"file DNE (Does not exist)"<<endl;
    }

    return 0;
}
