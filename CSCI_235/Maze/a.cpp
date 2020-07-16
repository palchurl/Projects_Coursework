MazeNode* currentPtr = a_maze.getFirstNode();
MazeNode* lastPtr = a_maze.getLastNode();
vector<MazeNode>traversal_order;
traversal_order.push_back(currentPtr);
currentPtr->setVisited();
queue<MazeNode>myqueue;
myqueue.push(currentPtr);
while(!(myqueue.isEmpty()))
{
    if(canTravel(currentPtr->getDirectionNode(directions::NORTH)))
    {
        currentPtr=currentPtr->getDirectionNode(directions::NORTH);
        myqueue.pop(front);
        traversal_order.push_back(currentPtr);
        myqueue.push(currentPtr);
        curentPtr->setVisited();

    }
}
/*************************************************/
MazeNode* currentPtr= a_maze.getFirstNode();
MazeNode* lastPtr= a_maze.getLastNode();
vector<MazeNode>traversal_order;
traversal_order.push_back(currentPtr);
currentPtr->setVisited();
stack<MazeNode>mystack;

while(!(mystack.isEmpty())
{
    if(canTravel(currentPtr->getDirectionNode(directions::NORTH)))
    {
        currentPtr=currentPtr->getDirectionNode(directions::NORTH);
        traversal_order.push_back(currentPtr);
        mystack.push(currentPtr);
        curentPtr->setVisited();
    }

    else if(canTravel(currentPtr->getDirectionNode(directions::NORTH)))
    {
        currentPtr=currentPtr->getDirectionNode(directions::EAST);
        traversal_order.push_back(currentPtr);
        mystack.push(currentPtr);
        curentPtr->setVisited();
    }   

    else if(canTravel(currentPtr->getDirectionNode(directions::NORTH)))
    {
        currentPtr=currentPtr->getDirectionNode(directions::EAST);
        traversal_order.push_back(curentPtr);
        mystack.push(currentPtr);
        curentPtr->setVisited();
    }

    else if(canTravel(currentPtr->getDirectionNode(directions::NORTH)))
    {
        currentPtr=currentPtr->getDirectionNode(directions::EAST);
        traversal_order.push_back(curentPtr);
        mystack.push(currentPtr);
        curentPtr->setVisited();
    }
    else
    {   
        mystack.pop();
    }
}

return traversal_order;

/********************************************/


    MazeNode* p = a_maze.getFirstNode();
    MazeNode* last = a_maze.getLastNode();
    vector<MazeNode> path;
    path.push_back(p);
    p->setVisited();

   while(!(path.isEmpty()))
   {
       if(canTravel(p->getDirectionNode(directions::NORTH)))
       {
           p = p->getDirectionNode(directions::NORTH); 
            p->setVisited();
           path.push_back(p);

           
           //ADD NODE TO STACK and MARK AS VISITED
       }
       else if (canTravel(p->getDirectionNode(directions::EAST)))
       {
           p = p->getDirectionNode(directions::EAST); 
           p->setVisited();
           path.push_back(p);

           /*if(path.back() == last)
           {
               return path;
           }*/
       }
       else if (canTravel(p->getDirectionNode(directions::SOUTH))
       {
           p = p->getDirectionNode(directions::SOUTH); 
            p->setVisited();
           path.push_back(p);
           /*if(path.back() == last)
           {
               return path;
           }*/
       }
       else if (canTravel(p->getDirectionNode(directions::WEST))
       {
           p = p->getDirectionNode(directions::WEST); 
            p->setVisited();
           path.push_back(p);
           /*if(path.back() == last)
           {
               return path;
           }*/
       }
       //________BACKTRACK___________
       /*if(p->getNumberofWalls() == 3 && ) //getNumberOfWalls = 3 and previous node is visited -> pop
       {

           //pop from the stack move ptr to 
       }*/
   }
   return path;

   /***************************************************************/

   vector <MazeNode*> beento; //to store all the visited nodes and refer back to them

   vector <MazeNode> path; //the vector for the final path nodes

   MazeNode* start = a_maze.getFirstNode(); //store starting location

   MazeNode* startCopy = a_maze.getFirstNode(); //want to traverse with this

   MazeNode* end = a_maze.getLastNode(); //store the ending location

   path.push_back(*startCopy); //insert start node into vector

   MazeNode* storeMe; //will store node to be inserted into vector

   int selectMe = 0; //want a counter to access nodes in visted-node-vector (beento)

 

 

   while (startCopy != end)

  { //check the nodes in each direction to see if they are visited or a wall

 

 

  if (startCopy->getDirectionNode(directions::NORTH) != nullptr && canTravel(startCopy->getDirectionNode(directions::NORTH)))

  {

      startCopy->setVisited(); //mark visited

      beento.push_back(startCopy); //put the visited node into the visted node vector

      storeMe = startCopy->getDirectionNode(directions::NORTH); //store the one in north

      path.push_back(*storeMe); //insert new node into path

      startCopy = startCopy->getDirectionNode(directions::NORTH); //update location of startCopy to continue traversing

      selectMe++; //increment to keep track of place in vector beento

  }

 

  else if (startCopy->getDirectionNode(directions::EAST) != nullptr && canTravel(startCopy->getDirectionNode(directions::EAST)))

  {

      startCopy->setVisited();

      beento.push_back(startCopy);

      storeMe = startCopy->getDirectionNode(directions::EAST); //store the one in east

      path.push_back(*storeMe); //insert new node

      startCopy = startCopy->getDirectionNode(directions::EAST);

      selectMe++;

  }

 

  else if (startCopy->getDirectionNode(directions::SOUTH) != nullptr && canTravel(startCopy->getDirectionNode(directions::SOUTH)))

  {

      startCopy->setVisited();

      beento.push_back(startCopy);

      storeMe = startCopy->getDirectionNode(directions::SOUTH); //store the one in south

      path.push_back(*storeMe); //insert new node

      startCopy = startCopy->getDirectionNode(directions::SOUTH);

      selectMe++;  

  }

 

  else if (startCopy->getDirectionNode(directions::WEST) != nullptr && canTravel(startCopy->getDirectionNode(directions::WEST)))

  {

      startCopy->setVisited();

      beento.push_back(startCopy);

      storeMe = startCopy->getDirectionNode(directions::WEST); //store the one in west

      path.push_back(*storeMe); //insert new node

      startCopy = startCopy->getDirectionNode(directions::WEST);

      selectMe++;

  }

 

  else //there was no where to go

  {

      startCopy->setVisited(); //set the place as visited

      //cout << "count is: " << selectMe << endl;

      //cout << "stuck at: " << startCopy->getStrPos() << endl;

      path.pop_back(); //remove the node where you got stuck

      startCopy = beento[selectMe-1]; //update the current node to be the one behind it

      beento.pop_back(); //remove the node you were stuck at [BUT IT THAT NODE WILL STILL BE MARKED VISITED]

      selectMe--; //decrement to maintain correct positioning in vector beento

  }

  }

  return path; 

/****************************************************************/


    queue <MazeNode> beento; //queue all visited nodes for processing
    queue <MazeNode> travorder;
    vector <MazeNode> path; //the vector for the final path nodes

    MazeNode* start = a_maze.getFirstNode(); //store starting location
    MazeNode* startCopy = a_maze.getFirstNode(); //want to traverse with this
    MazeNode* end = a_maze.getLastNode(); //store the ending location
    MazeNode* storeMe; //will store node to be inserted into vector

    path.push_back(*startCopy); //insert starting position into path vector

    beento.push(*startCopy); //first thing in the queue
    travorder.push(*startCopy);
    startCopy->setVisited(); //origin marked as visited
    MazeNode tracer;
    MazeNode keeper;

    while(!beento.empty())
    {
        //startCopy = beento.front();
        tracer = beento.front();
        //cout << "tracer is: " << tracer.getStrPos() << endl;
        beento.pop();

        if (tracer.getDirectionNode(directions::NORTH) != nullptr && canTravel(tracer.getDirectionNode(directions::NORTH)))
        {
            storeMe = tracer.getDirectionNode(directions::NORTH);
            storeMe->setVisited();
            travorder.push(*storeMe);
            beento.push(*storeMe);
        }

        if (tracer.getDirectionNode(directions::EAST) != nullptr && canTravel(tracer.getDirectionNode(directions::EAST)))
        {
            storeMe = tracer.getDirectionNode(directions::EAST);
            storeMe->setVisited();
            travorder.push(*storeMe);
            beento.push(*storeMe);
        }

        if (tracer.getDirectionNode(directions::SOUTH) != nullptr && canTravel(tracer.getDirectionNode(directions::SOUTH)))
        {
            storeMe = tracer.getDirectionNode(directions::SOUTH);
            storeMe->setVisited();
            travorder.push(*storeMe);
            beento.push(*storeMe);
        }

        if (tracer.getDirectionNode(directions::WEST) != nullptr && canTravel(tracer.getDirectionNode(directions::WEST)))
        {
            storeMe = tracer.getDirectionNode(directions::WEST);
            storeMe->setVisited();
            travorder.push(*storeMe);
            beento.push(*storeMe);
        }

        else //there was no where to go
        {
        }

    }
    cout << endl;
    cout << "size of travorder " << travorder.size() << endl;
    cout << "whats in the travorder queue" << endl;
    while (!travorder.empty())
    {
        cout << travorder.front().getStrPos() << endl;
        travorder.pop();
    }
    cout << "end of travorder" << endl;

    cout << "whats in the beento queue" << endl;
    while(!beento.empty())
    {
        cout << beento.front().getStrPos() << endl;
        beento.pop();
    }
    cout << "end of beento" << endl;

    return path; //return vector

     /***************/

    queue<MazeNode *> q;
    unordered_map<MazeNode *, MazeNode *> parents;
    MazeNode *node = a_maze.getFirstNode();
    node->setVisited();
    q.push(node); 

    while(!q.empty())
    {
        node = q.front(); 
        q.pop();

        if(hasUnvisitedNeighbors(node)) 
        {
            for(directions::nesw dir = directions::NORTH; dir <= directions::WEST; dir = directions::nesw(dir + 1))
            {
                if(canTravel(node->getDirectionNode(dir))) 
                {
                    parents[node->getDirectionNode(dir)] = node; 
                    node->getDirectionNode(dir)->setVisited();
                    q.push(node->getDirectionNode(dir));
                }
                if(q.front() == a_maze.getLastNode())
                {
                    break;]
                }
            }
        }
    }
    vector<MazeNode> path = backtrace(parents, a_maze.getFirstNode(), a_maze.getLastNode());
    return path;

/******************/
    queue<MazeNode *> q;
    unordered_map<MazeNode *, MazeNode *> parents;      //pair change to pairs rather than map if possible.
    MazeNode *node = a_maze.getFirstNode();
    node->setVisited();
    q.push(node); 

    while(!q.empty())
    {
        node = q.front(); 
        q.pop();

        if(hasUnvisitedNeighbors(node)) 
        {
            for(directions::nesw dir = directions::NORTH; dir <= directions::WEST; dir = directions::nesw(dir + 1))  //replace with 4 if statemests
            {
                if(canTravel(node->getDirectionNode(dir))) 
                {
                    parents[node->getDirectionNode(dir)] = node; 
                    node->getDirectionNode(dir)->setVisited();
                    q.push(node->getDirectionNode(dir));
                }
                if(q.front() == a_maze.getLastNode())
                {
                    break;
                }
            }
        }

/*******************************************/

std::vector<MazeNode> path;
std::stack<MazeNode *> deadEnds; // holds all the dead ends and the neighbors its explored
for(auto &it : a_maze.getNodes())
{
    if(!it.isWall() && getNumberOfWalls(&it) >= 3 && it.getStrPos() != a_maze.getLastNode()->getStrPos() && it.getStrPos() != a_maze.getFirstNode()->getStrPos())
    {
        a_maze.contains(it.getPos())->setVisited(); // find the dead ends and mark them as visited
        deadEnds.push(a_maze.contains(it.getPos())); // push them onto the deadEnd stack
    }
}

MazeNode *node = deadEnds.top();
while(!deadEnds.empty()) // loops until there are no more dead ends to process
{
    node = deadEnds.top(); //process the dead ends
    deadEnds.pop();

    for(directions::nesw dir = directions::NORTH; dir <= directions::WEST; dir = directions::nesw(dir+1))
    {
        if(canTravel(node->getDirectionNode(dir)) && getNumberOfWalls(node->getDirectionNode(dir)) >= 3)
        {
            node->getDirectionNode(dir)->setWall(); // if there are 3 walls then we are at a dead end so mark the current node as a wall
            deadEnds.push(node->getDirectionNode(dir)); // push any other explorable neighbors onto the stack and check if they qualify as dead ends
        }
    }
}

path = solveDFS(a_maze); // get the remaining path that is not a wall, which will be the path to the end.
return path;


/*********************/

    vector<MazeNode> path;

    stack<MazeNode *> DeadEndsandNeighbors; 

    //gp through every node in maxe and store deadends
    cout << "before for" << endl;
    vector<MazeNode> mazeNodeVector = a_maze.getNodes();
    for(int i = 0; i < mazeNodeVector.size(); i++)
    {
        if(!mazeNodeVector[i].isWall() && getNumberOfWalls(&mazeNodeVector[i]) >= 3 && &mazeNodeVector[i] != a_maze.getFirstNode() && &mazeNodeVector[i] != a_maze.getLastNode())
        {
            a_maze.contains(mazeNodeVector[i].getPos())->setVisited(); 
            DeadEndsandNeighbors.push(&mazeNodeVector[i]); 
        }
    }
    
    //closing of dead end paths
    cout << "before while" << endl;

    MazeNode *traversingPtr = DeadEndsandNeighbors.top();

    cout << "traversing" << endl;
    while(!DeadEndsandNeighbors.empty()) 
    {
        cout << "in while" << endl;
        
        traversingPtr = DeadEndsandNeighbors.top(); 
        //DeadEndsandNeighbors.pop();
            
        cout << "if statements follow" << endl;

        //stop when next node has one wall

        if(canTravel(traversingPtr->getDirectionNode(directions::NORTH)) && getNumberOfWalls(traversingPtr->getDirectionNode(directions::NORTH)) >= 2)
        {
            traversingPtr->getDirectionNode(directions::NORTH)->setWall();
            DeadEndsandNeighbors.push(traversingPtr->getDirectionNode(directions::NORTH)); 
        }

        //if there are 3 walls then we are at a dead end so mark the current node as a wall

        if(canTravel(traversingPtr->getDirectionNode(directions::EAST)) && getNumberOfWalls(traversingPtr->getDirectionNode(directions::EAST)) >= 2)
        {
            traversingPtr->getDirectionNode(directions::EAST)->setWall();
            DeadEndsandNeighbors.push(traversingPtr->getDirectionNode(directions::EAST)); 
        }

        if(canTravel(traversingPtr->getDirectionNode(directions::SOUTH)) && getNumberOfWalls(traversingPtr->getDirectionNode(directions::SOUTH)) >= 2)
        {
            traversingPtr->getDirectionNode(directions::SOUTH)->setWall();
            DeadEndsandNeighbors.push(traversingPtr->getDirectionNode(directions::SOUTH)); 
        }

        if(canTravel(traversingPtr->getDirectionNode(directions::WEST)) && getNumberOfWalls(traversingPtr->getDirectionNode(directions::WEST)) >= 2)
        {
            traversingPtr->getDirectionNode(directions::WEST)->setWall();
            DeadEndsandNeighbors.push(traversingPtr->getDirectionNode(directions::WEST)); 
        }
        
    }
    cout << "after if statements and while loop" << endl;
    //now that all implausible paths are closed off a path is found using def
    path = solveDFS(a_maze);
    return path;



/*******************/


/*
The method is to 1) find all of the dead-ends in the maze, and then 
2) "fill in" the path from each dead-end until the first junction is met. Note that some passages wo
nt become parts of dead end passages until other dead ends are removed first.
*/

    cout << "1" << endl;
    vector<MazeNode> path;
    stack<MazeNode *> deadEnds; 
    for(auto &it : a_maze.getNodes())
    {
        if(!it.isWall() && getNumberOfWalls(&it) >= 3 && it.getStrPos() != a_maze.getLastNode()->getStrPos() && it.getStrPos() != a_maze.getFirstNode()->getStrPos())
        {
            a_maze.contains(it.getPos())->setVisited(); 
            deadEnds.push(a_maze.contains(it.getPos())); 
        }
    }
    
    cout << "2" << endl;

   
    MazeNode * node = deadEnds.top();

    /*
    cout << "2.5" << endl;

    while(!deadEnds.empty())
    {
        cout << "3" << endl;

        node = deadEnds.top(); 

        deadEnds.pop();

        cout << "4" << endl;

        for(directions::nesw dir = directions::NORTH; dir <= directions::WEST; dir = directions::nesw(dir+1))
        {
            if(canTravel(node->getDirectionNode(dir)) && getNumberOfWalls(node->getDirectionNode(dir)) >= 3)
            {
                node->getDirectionNode(dir)->setWall(); 
                deadEnds.push(node->getDirectionNode(dir)); 
            }
        }
    }
    cout << "5" << endl;

    path = solveDFS(a_maze); */
    return path;




/*

[ [ 12/6] ]

[ [12/6, 12/5] ]

[ [12/6, 12/5, 12/4] ]

[12/6, 12/5, 12/4]

[12/6, 12/5, 12/4, 13/4]

[ [12/6, 12/5, 12/4, 13/4] ]

[ [12/6, 12/5, 12/4, 11/4] ]

 [12/6, 12/5, 12/4, 11/4]

[ [12/6, 12/5, 12/4, 13/4] ,  [12/6, 12/5, 12/4, 11/4] ]

{ [12/6, 12/5, 12/4, 13/4] ,  [12/6, 12/5, 12/4, 11/4] }

queue.front() =

\ [12/6, 12/5, 12/4, 13/4]

{ [14/4] ,  [12/6, 12/5, 12/4, 11/4] }

{ [12/6, 12/5, 12/4, 13/4] ,  [12/6, 12/5, 12/4, 11/4]   [12/6, 12/5, 12/4, 13/4, 14/4 } 


{ [12/6, 12/5, 12/4, 13/4, 14/4] ,  [12/6, 12/5, 12/4, 11/4] }

{ [12/6, 12/5, 12/4, 11/4], [12/6, 12/5, 12/4, 13/4, 14/4] ,   }

q.front  = [12/6, 12/5, 12/4, 11/4]

{ [12/6, 12/5, 12/4, 13/4, 14/4] ,[12/6, 12/5, 12/4, 11/4, 10/4],    }

{  ,[12/6, 12/5, 12/4, 11/4, 10/4],   [12/6, 12/5, 12/4, 13/4, 14/4. 15/4], [12/6, 12/5, 12/4, 13/4, 14/4, 14/5] }

{  [12/6, 12/5, 12/4, 13/4, 14/4. 15/4], [12/6, 12/5, 12/4, 13/4, 14/4, 14/5], ,[12/6, 12/5, 12/4, 11/4, 10/4, 9/4],    }

14/4 , 14/5, 9/4

14/5, 9/4


14/5 15/5

15/5 8/4

8/4 15/4

8/4 15/4 16/5

15/4 16/5 7/4


compiler: g++ -std=c++11 -o pi main.cpp Maze.cpp MazeNode.cpp 

__________________
 queue<a_node> traversalOrder;   
    //traversalOrder Make a queue called traversalOrder

    stack<a_node> vertexStack; 
    //vertexStack Make a stack called vertexStack

    originVertex->isVisited();
    traversalOrder.push_back(originVertex); //enqueue
    vertexStack.push_back(originVertex);

    while(!vertexStack.isEmpty())
    {
        topVertex = vertexStack.peek();
        if(topVertex has an unvisited neighbor)   //?
        {
            nextNeighbor = next unvisited neighbor of topvertex  //?
            nextNeighbor->isVisited();
            traversalOrder.push_back(nextNeighbor); //enqueue
            vertexStack.push_back(nextNeighbor);
        }
        else
        {
            vertexStack.pop();
        }
        
    }
    return traversalOrder;
______________________________

queue<a_node> traversalOrder;   
    queue<a_node> vertexQueue; 

    originVertex->isVisited();
    traversalOrder.push_back(originVertex); //enqueue
    vertexQueue.push_back(originVertex);    //enqueue

    while(!vertexQueue.isEmpty())
    {
        frontVertex = vertexQueue.front(); //peekfront
        vertexQueue.pop(); //dequeue
        while(frontVertex has a neighbor) // ??
        {
            nextNeighbor = next neighbor of frontvertex; //  ??
            if(nextNeighbor->!isVisited())
            {
                nextNeighbor->isVisited();
                traversalOrder.push_back(nextNeighbor); //enqueue
                vertexQueue.push_back(nextNeighbor);//enqueue
            }
        }
    }
    return traversalOrder;
__________________________________________________

    queue<MazeNode *> node_queue;  
    MazeNode* traversingPtr = a_maze.getFirstNode();     
    MazeNode* last = a_maze.getLastNode();              
    vector<MazeNode> path;                                  
    traversingPtr->setVisited();                        
    node_queue.push(traversingPtr);      

    MazeNode frontVertex = new MazeNode();
    while(!(node_queue.empty()))
    {
        frontVertex = node_queue.front(); //peekfront
        vertexQueue.pop(); //dequeue
        while(frontVertex has a neighbor)  //cantravel n || s || e || w??
        {
            IF YOU CAN TRAVEL NORTH THEN ADD TO NODE TO queue
            IF YOU CAN TRAVEL EAST THEN ADD TO queue

        }
    }
    return path;
    
    queue<MazeNode *> 
    queue<vector<MazeNode *>>
    pop queue and insert
    while(!queue is not empty)
    {
    }
    push first node into queue
    now push neighbors
    q front pop and push its neighbors
        element = queue . front()
        q.pop()

    //every single adjacent one
    
*/

    /*MazeNode* traversingPtr = a_maze.getFirstNode();
    MazeNode* last = a_maze.getLastNode();

    queue<MazeNode *> traversalOrder;
    queue<MazeNode *> temp_queue;
    vector<MazeNode> path;

    traversalOrder.push(traversingPtr);
    temp_queue.push(traversingPtr);
    traversingPtr->setVisited();

    while(!(temp_queue.empty()))
    {
        if(canTravel(traversingPtr->getDirectionNode(directions::NORTH)))
        {
            traversingPtr = traversingPtr->getDirectionNode(directions::NORTH);
            temp_queue.push(traversingPtr);
            traversalOrder.push(traversingPtr);
            traversingPtr->setVisited();
        }

        if(canTravel(traversingPtr->getDirectionNode(directions::EAST)))
        {
            traversingPtr = traversingPtr->getDirectionNode(directions::EAST);
            temp_queue.push(traversingPtr);
            traversalOrder.push(traversingPtr);
            traversingPtr->setVisited();
        }

        if(canTravel(traversingPtr->getDirectionNode(directions::SOUTH)))
        {
            traversingPtr = traversingPtr->getDirectionNode(directions::SOUTH);
            temp_queue.push(traversingPtr);
            traversalOrder.push(traversingPtr);
            traversingPtr->setVisited();
        }

        if(canTravel(traversingPtr->getDirectionNode(directions::WEST)))
        {
            traversingPtr = traversingPtr->getDirectionNode(directions::WEST);
            temp_queue.push(traversingPtr);
            traversalOrder.push(traversingPtr);
            traversingPtr->setVisited();
        }

        temp_queue.pop();
        traversingPtr = temp_queue.front();

        if(traversalOrder.back() == last)   
        {
            while(!(traversalOrder.empty()))
            {
                path.push_back(*traversalOrder.front());
                traversalOrder.pop();                       
            }
            return path;
        }
    }
    return path; 
    
    
    //newvector = oldvector + push_back(last node);

   //return {}; 
   
    126  
    
    unordered_map<MazeNode *, MazeNode *> parent_child_pairs;      //pair change to pairs rather than map if possible.
    
    after each if statement
    
    parent_child_pairs[traversingPtr->getDirectionNode(directions::NORTH)] = traversingPtr; 
    parent_child_pairs[traversingPtr->getDirectionNode(directions::EAST)] = traversingPtr; 
    parent_child_pairs[traversingPtr->getDirectionNode(directions::SOUTH)] = traversingPtr; 
    parent_child_pairs[traversingPtr->getDirectionNode(directions::WEST)] = traversingPtr; 
   
   after while loop--
   MazeNode *node = lastNode; 
    
    while(node != firstNode) 
    {
        path.push_back(*node); 
        node = parent_child_pairs[node]; 
    }
    
    path.push_back(*firstNode);
    reverse(path.begin(), path.end()); 

    MazeNode *node = lastNode; 
    
    while(node != firstNode) 
    {
        path.push_back(*node); 
        node = parent_child_pairs[node]; 
    }
    
    path.push_back(*firstNode);
    reverse(path.begin(), path.end()); 

    while(current_node != a_maze.getLastNode())



        //BACKTRACE     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // a mazenode vector to keep store the path
    // start from the end of the maze
    // loop until the node reaches the beginning
    // push the node
    // set the node to the parent of the current node
    // since we stopped at the start, we also have to push the start into the path
    // since our path is backwards from end to start, reverse the vector to get a path from start to finish.
    
    
    temp pointer = last node's previous pointer
    while temp pointer != first pointer
    find temp pointer's previous pointer
    temp pointer = temp pointers's previous pointer
    for all pairs in vector:    
    if pair.second == last node 
     MazeNode *tmpPtr =  ;
    for(int i = 0; i < parent_child_pairs.size(); i++)
    {
        parent_child_pairs.second == lastNode;
    }
    
    while()
    find last nodes prev ptr
    store it in temp
    while 
    iterate through vector
    
*/


100 //********************************************CONSIDER BREAKING AND MOVING THE REST OUTSIDE FOR LOOP  ************************************************