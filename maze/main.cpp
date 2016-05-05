#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#include <Windows.h>
using namespace std;
#include "function.h"


int main() {
    cout<<"Please enter the length and width of your random maze:\n(length and width should be between 10 and 80)\n";
    cin>>width>>length;
    GenerateInitialize();
    GenerateMaze(BeginDigx, BeginDigy);
	mazeanother = mazeanother1 = maze;
	cout<<endl;
    printMaze();
    cout<<endl;
    cout<<"Do you want to watch the process of maze traversal£¿(Input: Y/N)\n";
    char flag;
    cin>>flag;
    if (flag == 'y' || flag == 'Y') {
		DistanceFromBegin();
		position e = {ex, ey};
		maze[bx][by] = 'x';
		TraversalMaze(e);
		position b = {1, 0};
		savePath(b);
    	printPath();
    } else {
    	cout<<"ByeBye~"<<endl;
    }
    return 0;
}