#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#include <Windows.h>
using namespace std;
#include "function.h"


int width, length;//�����Թ�maze�ĳ��Ϳ�
const int bx = 1, by = 0;//���̶������Ͻ�
const int INF = 0x3f3f3f3f;
int ex = 0, ey = 0;//�յ㲻ȷ�����ȳ�ʼ��Ϊ0
vector< vector<char> > maze(width, vector<char>(length, '#'));//�����Թ�maze������#����
int BeginDigx, BeginDigy;//���ڵ�
int dx[4] = {-1, 1, 0, 0};//��ʾ�ƶ�������
int dy[4] = {0, 0, -1, 1};

vector< vector<int> > d(width, vector<int>(length, INF));
vector< vector<char> > mazeanother(width, vector<char>(length));
vector< vector<char> > mazeanother1(width, vector<char>(length));
vector<position> path;

void GenerateInitialize() {	//���������Թ�ǰ�����ݳ�ʼ��
    maze.resize(width);
    for(int i = 0; i < width; i++) {	//����maze�ĳ�������#����
        maze[i].resize(length, '#');
    }
    for (int i = 0; i < width; i++) {
        for(int j = 0; j < length; j++) {
            maze[i][j] = '#';
        }
	}

	d.resize(width);
    for(int i = 0; i < width; i++) {	//����d�ĳ�������INF��ʼ��
        d[i].resize(length, INF);
    }
	for (int i = 0; i < width; i++) {
        for(int j = 0; j < length; j++) {
            d[i][j] = INF;
        }
	}
    maze[bx][by] = '.';	 //�ڿ�Ԥ��������
    maze[1][1] = '.';
	maze[2][1] = '.';

	BeginDigx = 2;
	BeginDigy = 1;
	//cout<<BeginDigx<<' '<<BeginDigy<<endl;
}

bool IsInMaze(int x, int y) {	//�жϵ�ǰλ���Ƿ����Թ���
	return (0 < x) && (x < (width - 1)) && (0 < y) && (y < (length - 1)) ? 1 : 0;
}

bool CanBeDig(int curx, int cury, int nx, int ny) {	//�жϵ�maze[nx][ny]�ܲ����ڣ������ڷ���0�����ڷ���1
	//cout<<"curx, cury:"<<curx<<' '<<cury<<'\n';
	//cout<<"nx,ny:"<<nx<<" "<<ny<<endl;
	for (int i = 0; i < 4; i++) {
		int nnx = nx + dx[i],
			nny = ny + dy[i];
		//cout<<nnx<<' ' <<nny<<'\n';exit(0);
		if (IsInMaze(nnx, nny) && maze[nnx][nny] == '.' ) {
                if (((nnx == curx) && (nny == cury)) || ((nnx == bx) && (nny == by)) || ((nnx == ex) && (nny == ey))) {
                    continue;
                } else 
					return 0;
        }
    }
    return 1;
}

void GenerateMaze(int beginx, int beginy) {
	stack<position> st;
	position bs = {beginx, beginy};
	st.push(bs);
	//maze[beginx][beginy] = '.';

	while(st.size()) {
		position cur = st.top();
		//maze[cur.x][cur.y] = '.';
		//cout<<cur.x<<' '<<cur.y<<endl;
		st.pop();

		srand((unsigned int)time(NULL));
		for(int i = 0; i < 4; i++) {	//�������������˳��
			int r = rand() % 4;
			while(r == i) {
				r = rand() % 4;
			}
			swap(dx[i], dx[r]);
			swap(dy[i], dy[r]);
		}
		
		for(int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			position ns = {nx, ny};
			//cout<<CanBeDig(cur.x, cur.y, nx, ny)<<' ';
			if ((nx == 2 && ny == 3) || (nx ==2 && ny == 7) || (ny == nx*2) || (nx == width - 2 && ny == length - 3)) {
				continue;
			}
			if (IsInMaze(nx, ny) && maze[nx][ny] == '#' && CanBeDig(cur.x, cur.y, nx, ny)) {
				st.push(ns);
				maze[nx][ny] = '.';
			}
			if (nx == 1 && ny == 1) {
				st.push(ns);
				maze[nx][ny] = '.';
			}
			if (ny == (length -1) && 0 < nx && nx < (width - 1) && ex == 0 && ey == 0) {
				ex = nx;
				ey = ny;
				st.push(ns);
				maze[nx][ny] = '.';
			}
		}
	}
}

void DistanceFromBegin() {
	//��BFS����㵽ÿһ��������·�̣�����vector<position> d�У���ΪINF����ý���޷�����

	queue<position> que;
	//����ǰ����push�����
	position bs = {bx, by};
	que.push(bs);
	d[bx][by] = 0;

	while (que.size()) {
		position a = que.front();

		//maze[a.x][a.y] = 'x';
		que.pop();
		
		//��������յ���ֹͣ
		if (a.x == ex && a.y == ey) break;

		//�����ĸ��������
		for (int i = 0; i < 4; i++) {
			int nx = a.x + dx[i], ny = a.y + dy[i];
			//cout<<nx<<' '<<ny<<"ha"<<endl;
			position ns = {nx, ny};
			
			//cout<<IsInMaze(nx, ny)<<' '<<(maze[nx][ny] != '#')<<' '<<(d[nx][ny] == INF)<<endl;
			if (IsInMaze(nx, ny) && (maze[nx][ny] != '#') && (d[nx][ny] == INF)) {
				que.push(ns);
				d[nx][ny] = d[a.x][a.y] + 1;
				//cout<<d[nx][ny]<<"ha1"<<endl;
			}
		}
	}
	//��㵽�յ����·��
	d[ex][ey] = d[ex][ey-1] + 1;
}

void TraversalMaze(position cur) {//���յ��������Թ�
	maze[cur.x][cur.y] = 'x';
	if (cur.x == bx && cur.y == by) return;
	int t = 0;
	for (int i = 0; i < 4; i++) {
		int nx = cur.x + dx[i],
			ny = cur.y + dy[i];
		position n = {nx, ny};
		if (IsInMaze(nx, ny) && maze[nx][ny] == '.') {
			if (d[nx][ny] == d[cur.x][cur.y] - 1 && !t) {
				t++;
				TraversalMaze(n);
			}
		}
	}
}

void printMaze() {
    for (vector< vector<char> >::iterator it = maze.begin(); it != maze.end(); it++) {
        for (vector<char>::iterator it1 = (*it).begin(); it1 != (*it).end(); it1++) {
            cout<<(*it1)<<' ';
        }
        cout<<endl;
    }
}

void savePath(position cur) {
	path.push_back(cur);
	mazeanother1[cur.x][cur.y] = 'x';
	if (cur.x == ex && cur.y == ey) return;
	int t = 0;
	for (int i = 0; i < 4 && t == 0; i++) {
		int nx = cur.x + dx[i], ny = cur.y + dy[i];
		if (IsInMaze(nx, ny) && maze[nx][ny] == 'x' && mazeanother1[nx][ny] == '.') {
			position n = {nx, ny};
			t++;
			savePath(n);
		}
	}
	//return;
}

void printPath() {
	HANDLE hOutput;
    COORD coord = {0,0};
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	for (int i = 0; i < path.size(); i++) {
		SetConsoleCursorPosition(hOutput, coord);
		int w = path[i].x, l = path[i].y;
		mazeanother[w][l] = 'x';
		
		for (vector< vector<char> >::iterator it = mazeanother.begin(); it != mazeanother.end(); it++) {
			for (vector<char>::iterator it1 = (*it).begin(); it1 != (*it).end(); it1++) {
			  cout<<(*it1)<<' ';
			}
			cout<<endl;
		}
		Sleep(40);
	}
	SetConsoleCursorPosition(hOutput, coord);
	printMaze();
	cout<<"Succeed! Enter to return..."<<endl;
	system("pause");
}