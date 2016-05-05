#ifndef _FUNCTION_H_
#define	_FUNCTION_H_
extern struct position {
	int x;
	int y;
};
extern int width, length;//�����Թ�maze�ĳ��Ϳ�
extern const int bx, by;//���̶������Ͻ�
extern int ex, ey;//�յ㲻ȷ�����ȳ�ʼ��Ϊ0
extern vector< vector<char> > maze;//�����Թ�maze������#����
extern int BeginDigx, BeginDigy;//���ڵ�
extern int dx[4];//��ʾ�ƶ�������
extern int dy[4];
extern const int INF;
extern vector< vector<int> > d;
extern vector< vector<char> > mazeanother;
extern vector< vector<char> > mazeanother1;
extern vector<position> path;

void GenerateInitialize(); //���������Թ�ǰ�����ݳ�ʼ��
bool IsInMaze(int x, int y);	//�жϵ�ǰλ���Ƿ����Թ���
void GenerateMaze(int beginx, int beginy);
void DistanceFromBegin();
void TraversalMaze(position cur);//���յ��������Թ�
void printMaze();
void savePath(position cur);
void printPath();

#endif