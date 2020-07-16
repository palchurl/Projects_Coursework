#include <iostream>
#include "Maze.hpp"
#include "Solutions.cpp"
using namespace std;

int main()
{
    
    //DFS TESTING 
    cout << "DFS MAZE 1:    " << endl;
    Maze maze1("../Maze/Maze Data/maze_1.csv");   
    //cout << maze1 << endl;

    vector<MazeNode> answer = solutions::solveDFS(maze1);
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i].getStrPos() << endl;
    }

    cout << endl<<"DFS MAZE 2:    " << endl;
    Maze maze2("../Maze/Maze Data/maze_2.csv");   

    vector<MazeNode> answer2 = solutions::solveDFS(maze2);
    for(int i = 0; i < answer2.size(); i++)
    {
        cout << answer2[i].getStrPos() << endl;
    }
    
    cout << endl << "DFS MAZE 3:    " << endl;
    Maze maze3("../Maze/Maze Data/maze_3.csv"); 

    //cout << "after making maze 3 ";
    vector<MazeNode> answer3 = solutions::solveDFS(maze3);
    
    //cout << "after making ans vector 3 ";
    for(int i = 0; i < answer3.size(); i++)
    {
        cout << answer3[i].getStrPos() << endl;
    }
    
    
    //BFS TESTING
    /*
    cout << "BFS MAZE 1:" << endl;
    Maze maze1("../Maze/Maze Data/maze_1.csv");   
    //cout << maze1 << endl;

    vector<MazeNode> answerBFS1 = solutions::solveBFS(maze1);
    for(int i = 0; i < answerBFS1.size(); i++)
    {
        cout << answerBFS1[i].getStrPos() << endl;
    }
    
    cout << "BFS MAZE 2:" << endl;
    Maze maze2("../Maze/Maze Data/maze_2.csv");   
    //cout << maze1 << endl;

    vector<MazeNode> answerBFS2 = solutions::solveBFS(maze2);
    for(int i = 0; i < answerBFS2.size(); i++)
    {
        cout << answerBFS2[i].getStrPos() << endl;
    }
    
    cout << "BFS MAZE 3:" << endl;
    Maze maze3("../Maze/Maze Data/maze_3.csv");   
    //cout << maze1 << endl;

    vector<MazeNode> answerBFS3 = solutions::solveBFS(maze3);
    for(int i = 0; i < answerBFS3.size(); i++)
    {
        cout << answerBFS3[i].getStrPos() << endl;
    }
    */
    /*
    //DEF TESTING
    cout << "DEF MAZE 1:" << endl;
    Maze maze1("../Maze/Maze Data/maze_1.csv");   
    //cout << maze1 << endl;

    vector<MazeNode> answerDEF1 = solutions::solveDEF(maze1);
    for(int i = 0; i < answerDEF1.size(); i++)
    {
        cout << answerDEF1[i].getStrPos() << endl;
    }
    
    
    cout << "DEF MAZE 2:" << endl;
    Maze maze2("../Maze/Maze Data/maze_2.csv");   
    //cout << maze1 << endl;
    
    vector<MazeNode> answerDEF2 = solutions::solveDEF(maze2);
    for(int i = 0; i < answerBFS2.size(); i++)
    {
        cout << answerDEF2[i].getStrPos() << endl;
    }
    
    cout << "DEF MAZE 3:" << endl;
    Maze maze3("../Maze/Maze Data/maze_3.csv");   
    //cout << maze1 << endl;

    vector<MazeNode> answerDEF3 = solutions::solveDEF(maze3);
    for(int i = 0; i < answerDEF3.size(); i++)
    {
        cout << answerDEF3[i].getStrPos() << endl;
    }*/

    return 0;
}

//g++ -std=c++11 -o pi main.cpp Maze.cpp MazeNode.cpp