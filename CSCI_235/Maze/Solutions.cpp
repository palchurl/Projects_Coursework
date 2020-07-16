/** @file Solutions.cpp */

/*
Author: Lakshmi Palchuri
Instructor: Wole Oyekoya
Assignment: Project 4 - Linked-Based Maze Traversal
Date: 5/10/2020

Purpose: This file has the implementation of 
solution functions that are meant to solve mazes. 
These solution functions draw upon three approaches used
to solve mazes: Depth First Search, Breadth First Search 
and Dead End FIlling. This file also draws upon Maze and
MazeNode files/methods which were provided.
*/
#include "Maze.hpp" 
#include <stack>  
#include <vector>   
#include <queue>
#include <algorithm>  
#include <vector>
#include <utility>
using namespace std;

namespace solutions
{

/** Gets the number of walls that a MazeNode which is passed as a parameter has (Acessor) 
@return an integer representing the number of walls a node is adjacent too */
int getNumberOfWalls(MazeNode *a_node)
{
    int wall_counter = 0;
    for (directions::nesw dir = directions::NORTH; dir < directions::EAST; dir = directions::nesw(dir + 1))
    {
        if (a_node->getDirectionNode(dir) == nullptr || a_node->getDirectionNode(dir)->isWall() || a_node->getDirectionNode(dir)->isVisited())
        {
            wall_counter++;
        }
    }
    return wall_counter;
}

/** Informs whether a MazeNode is not set to nullptr, is already visited or is a wall all of which inhibit a node ability to travel
@return a boolean value if a node can travel it returns false or 0 and true or 1 otherwise */
bool canTravel(MazeNode *a_node)
{
    if (a_node == nullptr || a_node->isVisited() || a_node->isWall())
    {
        return false;
    }
    return true;
}

/** Informs whether a node passed as a parameter has any unvisited adjacent nodes in any direction
@return a boolean value if a node has unvisited neighboring nodes it returns true or 1 otherwise it returns false or 0 */
bool UnvisitedAdjacentNodes(MazeNode *MazeNodePtr) 
{
    if(canTravel(MazeNodePtr->getDirectionNode(directions::NORTH)))     //If the MazeNode can travel North that means there is a neighbor 
    {                                                                   //to the north and this node has unvisited ajacent nodes so return true
        return true;    
    }

    if(canTravel(MazeNodePtr->getDirectionNode(directions::EAST)))      //If the MazeNode can travel East that means there is a neighbor 
    {                                                                   //to the east and this node has unvisited ajacent nodes so return true
        return true;
    }

    if(canTravel(MazeNodePtr->getDirectionNode(directions::SOUTH)))     //If the MazeNode can travel South that means there is a neighbor 
    {                                                                   //to the south and this node has unvisited ajacent nodes so return true
        return true;
    }

    if(canTravel(MazeNodePtr->getDirectionNode(directions::WEST)))      //If the MazeNode can travel West that means there is a neighbor 
    {                                                                   //to the west and this node has unvisited ajacent nodes so return true
        return true;
    }

    return false;                                                       //If the MazeNode cannot travel north, east, west or south then it 
                                                                        //has no unvisted neighbors so return true
}

/** Produces a solution to a maze given as a parameter with a Depth First Search approach
@return a vector containing a path of mazenodes giving a DFS approach to finding the last 
node in the maze from the start node */
std::vector<MazeNode> solveDFS(Maze &a_maze)
{

    MazeNode* traversingPtr = a_maze.getFirstNode();     //Assigns traversingPtr to the start or first node of the maze, this ptr 
                                                         //will be traversing through the nodes of the maze
    traversingPtr->setVisited();                         //Sets or marks first/starting node as visited 
    MazeNode* last = a_maze.getLastNode();               //Assigns ptr last to the end node of the maze or the final destination node
    vector<MazeNode> path;                               //Creates a vector called path its purpose is to contain the path of nodes     
                                                         //it takes to reach the end/last node, is is returned at the end of function
    
    stack<MazeNode *> node_stack;                        //Create a stack where Mazenodes ptrs will be added and deleted as we come across them on the path
    node_stack.push(traversingPtr);                      //Pushing the first or starting node into the stack

    while(!(node_stack.empty()))                         //while loop continues while stack is not empty and stops when stack is empty
    {
        if(node_stack.top() == last)                     //The while loop will end when top node in the stack is the same as the last node in the maze
        {                      
            while(!(node_stack.empty()))                 //This while loop continues until all the nodes in the stack are popped out
            {
                path.push_back(*node_stack.top());       //Each iteration of the while loop we are pushing the item on top of the stack into the result vector
                node_stack.pop();                        //Every time we copy the top of the stack we pop it so eventually we can exit the loop after all items are copied
            }                                           

            reverse(path.begin(), path.end());           //Since the we are copying items in the stack starting with the ending and ending with the first node 
                                                         //and we would like the path to be in the opposite order we reverse the order

            return path;                                 //At this point we should have a vector with a path of nodes using a DFS manner being returned
        }

        else if(canTravel(traversingPtr->getDirectionNode(directions::NORTH)))      
        {           
            traversingPtr = traversingPtr->getDirectionNode(directions::NORTH);
            node_stack.push(traversingPtr);
            traversingPtr->setVisited();   
        }
        //This else if statement first checks the traversingPtr can travel NORTH than moves traversingPtr one 
        //node north, marks it as visited and pushes this node into the stack we made that keeps track of our path of nodes

        else if(canTravel(traversingPtr->getDirectionNode(directions::EAST)))
        {
            traversingPtr = traversingPtr->getDirectionNode(directions::EAST);
            node_stack.push(traversingPtr);
            traversingPtr->setVisited();
        }   
        //If else if statement is invoked then the node cannot travel north statement so it 
        //checks if the traversingPtr can travel EAST if it can it then moves traversingPtr one node EAST
        //then it marks it as visited and pushes this node into the node stack

        else if(canTravel(traversingPtr->getDirectionNode(directions::SOUTH)))
        {
            traversingPtr = traversingPtr->getDirectionNode(directions::SOUTH);
            node_stack.push(traversingPtr);
            traversingPtr->setVisited();
        }
        //This else if statement, only invoked if the traversingPtr cannot travel North or East,
        //it checks if traversingPtr can travel SOUTH and if it can it then moves traversingPtr one node SOUTH
        //then it marks it as visited and pushes this node into the node stack

        else if(canTravel(traversingPtr->getDirectionNode(directions::WEST)))
        {
            traversingPtr = traversingPtr->getDirectionNode(directions::WEST);
            node_stack.push(traversingPtr);
            traversingPtr->setVisited();
        }
        //This else if statement, only invoked if the traversingPtr cannot travel North or East or South,
        //it checks if traversingPtr can travel WEST and if it can it then moves traversingPtr one node WEST
        //then it marks it as visited and pushes this node into the node stack

        else                                               //If the traversingPtr cannot travel in any direction because its blocked 
        {                                                  //it needs to backtrack so we pop the top node from stack until we can travel 
            node_stack.pop();
            traversingPtr = node_stack.top();              //again and reassign the traversing ptr accordingly
        }
    }
    return path;                                           //If no path is found just return an empty vector
}

//DFS Approach: The approach starts at the first or starting node node in the map and tries traveling in the NORTH, EAST, SOUTH and WEST 
//directions as far as it can before being forced to backtrack. This approach is exhaustive in that the traversingPtr used attempts to travel
//in every possible direction (else if statements) it can before backtracking (else statement). The while loop and if statements aid in 
//checking the directions and the if statement checks if the top of the stack matches the last node and if so all the elements of the stack 
//are copied into a vector called path and this is returned.



/** Produces a solution to a maze given as a parameter with a Breadth First Search approach
@return a vector containing a path of mazenodes giving a BFS approach to finding the last 
node in the maze from the start node */
std::vector<MazeNode> solveBFS(Maze &a_maze)
{   
    queue<MazeNode *> traversalOrder;                           //Create a queue to add MazeNode pointerson the correct path of the maze
    vector<pair<MazeNode *, MazeNode *>> parent_child_pairs;    //Create a vector made up of pairs of MazeNode pointers each pair consists of
                                                                //a a pointer to a node and a pointer to the next node in the path
    vector<MazeNode> path;                                      //This vector will contain the shortest path of all the nodes collected in the vector of pairs

    MazeNode *lastNode = a_maze.getLastNode();                  //MazeNode ptr called lastNode assigned to point to the last node of the maze
    MazeNode *firstNode = a_maze.getFirstNode();                //MazeNode ptr called lastNode assigned to point to the first node of the maze

    MazeNode *traversingPtr = a_maze.getFirstNode();            //Making a MazeNode ptr and assign it to the first node in the maze this 
                                                                //ptr will be moving throgh the maze
    traversingPtr->setVisited();                                //Sets the traversing ptr to be visited and pushes it into the queue keeping track of
    traversalOrder.push(traversingPtr);                         //nodes we have come across

    while(!traversalOrder.empty())                              //This while loop is there to keep traversingPtr moving through the maze and the loop 
    {                                                           //will continue till the queue with the node path is empty
        traversingPtr = traversalOrder.front();                 //Assigning the traversingPtr the front of the queue every iteration
        traversalOrder.pop();                                   //Then popping traversalOrder

        if(UnvisitedAdjacentNodes(traversingPtr))               //Checks if the traversing pointer has any unvisited adjacent neighbors 1 node/level away 
        {
            if(traversalOrder.front() == lastNode)              //This is the ending condition for the while loop if the front item in traversal 
            {                                                   //order is the last node exit the while loop
                break;
            }
            
            if(canTravel(traversingPtr->getDirectionNode(directions::NORTH))) 
            {
                pair<MazeNode *, MazeNode *> addPair = make_pair(traversingPtr,traversingPtr->getDirectionNode(directions::NORTH));
                parent_child_pairs.push_back(addPair); 
                traversingPtr->getDirectionNode(directions::NORTH);
                traversingPtr->setVisited();
                traversalOrder.push(traversingPtr->getDirectionNode(directions::NORTH));
            }
            //This if statement checks if the ptr has an ajacent node north of it and if it does it makes a pair called addPair 
            //and adds the traversingPtr and the neighbor to the north as the two items. Then adds this new pair to the vector of pairs.
            //Then the traversing ptr moves North and is set as visited and the the moved pointers node pushed into the queue 

            if(canTravel(traversingPtr->getDirectionNode(directions::EAST))) 
            {
                pair<MazeNode *, MazeNode *> addPair = make_pair(traversingPtr,traversingPtr->getDirectionNode(directions::EAST));
                parent_child_pairs.push_back(addPair); 
                traversingPtr->getDirectionNode(directions::EAST);
                traversingPtr->setVisited();
                traversalOrder.push(traversingPtr->getDirectionNode(directions::EAST));
            }
            //This if statement checks if the ptr has an ajacent node East of it and if it does it makes a pair called addPair 
            //and adds the traversingPtr and the neighbor to the East as the two items. Then adds this new pair to the vector of pairs.
            //Then the traversing ptr moves east and is set as visited and the the moved pointers node pushed into the queue 


            if(canTravel(traversingPtr->getDirectionNode(directions::SOUTH))) 
            {
                pair<MazeNode *, MazeNode *> addPair = make_pair(traversingPtr,traversingPtr->getDirectionNode(directions::SOUTH));
                parent_child_pairs.push_back(addPair); 
                traversingPtr->getDirectionNode(directions::SOUTH);
                traversingPtr->setVisited();
                traversalOrder.push(traversingPtr->getDirectionNode(directions::SOUTH));
            }
            //This if statement checks if the ptr has an ajacent node south of it and if it does it makes a pair called addPair 
            //and adds the traversingPtr and the neighbor to the south as the two items. Then adds this new pair to the vector of pairs.
            //Then the traversing ptr moves south and is set as visited and the the moved pointers node pushed into the queue

            if(canTravel(traversingPtr->getDirectionNode(directions::WEST))) 
            {
                pair<MazeNode *, MazeNode *> addPair = make_pair(traversingPtr,traversingPtr->getDirectionNode(directions::WEST));
                parent_child_pairs.push_back(addPair);                 
                traversingPtr->getDirectionNode(directions::WEST);
                traversingPtr->setVisited();
                traversalOrder.push(traversingPtr->getDirectionNode(directions::WEST));
            }
            //This if statement checks if the ptr has an ajacent node west of it and if it does it makes a pair called addPair 
            //and adds the traversingPtr and the neighbor to the west as the two items. Then adds this new pair to the vector of pairs.
            //Then the traversing ptr moves west and is set as visited and the the moved pointers node pushed into the queue 
        }
    }

    stack<MazeNode *> node_stack;                               //Created a stack called node stack to trasfer items from the vector of pairs            

    MazeNode* tempPtr = a_maze.getLastNode();                   //Created a temp ptr and assigned it the last node of the maze.
    for(int i = 0; i < parent_child_pairs.size(); i++)          //Have a for loop going through every pair in the vector
    {
        if(parent_child_pairs[i].second == tempPtr)             //This if statement finds if the second item of any pair element was the last ptr
        {
            node_stack.push(parent_child_pairs[i].first);       //pushes the first item of this pair into the stach and assigns the tempptr to be the first 
            tempPtr = parent_child_pairs[i].first;              //element of the pair
        }
    }

    while(tempPtr != firstNode)                                 //This while loop keeps going till the tempPtr is the starting node of the maze
    {
        for(int i = 0; i < parent_child_pairs.size(); i++)      //This for loop is the same as the one above and it keeps moving the tempptr backwards
        {                                                       //and keeps pushing nodes that are in the path into the stack
            if(parent_child_pairs[i].second == tempPtr)
            {
                node_stack.push(parent_child_pairs[i].first);
                tempPtr = parent_child_pairs[i].first;
            }
         }
    }
    
    while(!(node_stack.empty()))                                //This while loop is intended to copy all the elements of the stack into the result vector
    {                                                           //and pop all each elements of the stack after copying it and pushes the first element of the maze
        path.push_back(*node_stack.top());                      //at the end
        node_stack.pop();                       
    }
    path.push_back(*lastNode);

    return path;                                                //returns the result vector which should be the shortest path from the start to the ending node
    */
}
//BFS Approach: This approach is a traversing approach where you should start traversing from a the start or first node in the maze   
//and traverse the maze by level this allows us to search each nodes neighbors and brach out through this method going to different 
//layers/levels till we find the last node. The while loop and series of if statements allow us to search for paths through the neigbors 
//of the source or first node and we continue till we found and added the last node to our vector of pairs.



/** Produces a solution to a maze given as a parameter with a Dead End Filling approach
@return a vector containing a path of mazenodes giving a DFS approach to finding the last 
node in the maze from the start node */
std::vector<MazeNode> solveDEF(Maze &a_maze)
{   
    return {};
}


/** Produces a solution to a maze given as a parameter with a Depth First Search approach
@return a vector containing a path of mazenodes giving a DFS approach to finding the last 
node in the maze from the start node */
std::vector<MazeNode> solveCustom(Maze &a_maze)
{
    return solveDFS(a_maze);
}
} // namespace solutions

