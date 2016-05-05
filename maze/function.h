#ifndef _FUNCTION_H_
#define	_FUNCTION_H_
extern struct position {
	int x;
	int y;
};
extern int width, length;//定义迷宫maze的长和宽
extern const int bx, by;//起点固定在左上角
extern int ex, ey;//终点不确定，先初始化为0
extern vector< vector<char> > maze;//定义迷宫maze，先用#铺满
extern int BeginDigx, BeginDigy;//开挖点
extern int dx[4];//表示移动的向量
extern int dy[4];
extern const int INF;
extern vector< vector<int> > d;
extern vector< vector<char> > mazeanother;
extern vector< vector<char> > mazeanother1;
extern vector<position> path;

void GenerateInitialize(); //进行生成迷宫前的数据初始化
bool IsInMaze(int x, int y);	//判断当前位置是否在迷宫内
void GenerateMaze(int beginx, int beginy);
void DistanceFromBegin();
void TraversalMaze(position cur);//从终点逆向走迷宫
void printMaze();
void savePath(position cur);
void printPath();

#endif