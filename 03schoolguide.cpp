#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
//�洢���·��ֵ
int ShortestPathvalue[32][32] = {0};
//�洢����·��
int ShortestPathmatrix[32][32] = {0};
//�ص���Ϣ
char _mapName[32][50] = {"����¥", "ʵ��¥D", "��ѧ¥A", "����", "����", "A4", "ʵ��¥C", "��ѧ¥B", "A2", "A6", "�����ϵ", "�չ�����",
                         "������Ʒ", "ʵ��¥A", "��ѧ¥C", "ͼ���", "һʳ��", "D2", "D8", "C4", "�й���ͨ", "��ë��", "����",
                         "B5", "B7", "D4", "D6", "C8", "C6", "��ʳ��", "һ�������̰�", "B11"};
//������Ϣ,_distance[0][1] = 50;������±�Ϊ0���±�Ϊ1�ص����Ϊ50
int _distance[32][32] = {0};
//�߱���
typedef struct EdgeNode {
    //�����Ӧ���±�
    int adjvex;
    //Ȩֵ
    int weight;
    //ָ����һ���ڽӵ�
    struct EdgeNode *next;
} edgeNode;

//�������
typedef struct VertexNode {
    //��������
    char data[50];
    //�߱�ͷָ��
    edgeNode *firstedge;
} VertexNode, AdjList[100];

//����
typedef struct {
    AdjList adjList;
    //�������ͱ���
    int numVertexes, numEdges;
} GraphAdjList;

class AdjacencyList {
public:


    void ShowALGraph(GraphAdjList *G);

    void Test();

    //��ʼ����ͼ
    void InitMap(GraphAdjList *G);

    //������ͼ
    void CreateALGraph(GraphAdjList *G);

    //�����������֮�����·��
    void ShortestPath_Floyd(GraphAdjList *G, int P[32][32], int D[32][32]);

    //���·�����Ⱥ;���·��
    void ShowShortestResult(int originPos, int endPos);
};

//������ͼ
void AdjacencyList::CreateALGraph(GraphAdjList *G) {
    edgeNode *e;
    //���붥����Ϣ�����������
    for (int i = 0; i < G->numVertexes; i++) {
        //���붥����Ϣ
        strcpy(G->adjList[i].data, _mapName[i]);
        //���߱���Ϊ�ձ�
        G->adjList[i].firstedge = NULL;
    }
    //�����߱�ͷ�巨��
    for (int i = 0; i < G->numVertexes; i++) {
        for (int j = 0; j < i; j++) {
            int temp;
            if (_distance[i][j] != 0 || _distance[j][i] != 0) {
                if (_distance[i][j] != 0) {
                    temp = _distance[i][j];
                    _distance[j][i] = _distance[i][j];
                }
                else {
                    temp = _distance[j][i];
                    _distance[i][j] = _distance[j][i];
                }
                e = new EdgeNode;
                e->adjvex = j;
                e->next = G->adjList[i].firstedge;
                e->weight = temp;
                G->adjList[i].firstedge = e;

                e = new EdgeNode;

                e->adjvex = i;
                e->next = G->adjList[j].firstedge;
                e->weight = temp;
                G->adjList[j].firstedge = e;
            }

        }
    }

}

void AdjacencyList::Test() {
    cout << "ALL IS OK." << endl;
}

void AdjacencyList::ShowALGraph(GraphAdjList *G) {
    for (int i = 0; i < G->numVertexes; i++) {
        cout << "����" << i << ": " << G->adjList[i].data << "--firstedge--";
        edgeNode *p = new edgeNode;
        p = G->adjList[i].firstedge;
        while (p) {
            cout << p->adjvex << "--Weight: " << p->weight << "--Next--";
            p = p->next;
        }
        cout << "--NULL" << endl;
    }

}

//��ʼ����ͼ��������
void AdjacencyList::InitMap(GraphAdjList *G) {
    //���붥�����ͱ���
    G->numVertexes = 32;
    G->numEdges = 59;
    _distance[0][2] = 60;

    _distance[1][2] = 190;
    _distance[1][7] = 210;
    _distance[1][6] = 70;

    _distance[2][7] = 80;
    _distance[2][16] = 320;
    _distance[2][3] = 120;

    _distance[3][7] = 100;
    _distance[3][14] = 170;
    _distance[3][4] = 80;

    _distance[4][11] = 180;
    _distance[4][8] = 90;
    _distance[4][5] = 140;

    _distance[5][9] = 70;

    _distance[6][7] = 220;
    _distance[6][10] = 50;

    _distance[7][10] = 210;
    _distance[7][14] = 90;
    _distance[7][16] = 260;

    _distance[8][11] = 110;
    _distance[8][9] = 60;

    _distance[9][11] = 110;

    _distance[10][17] = 190;
    _distance[10][13] = 50;

    _distance[11][16] = 80;
    _distance[11][12] = 90;

    _distance[12][16] = 100;

    _distance[13][17] = 160;
    _distance[13][18] = 170;
    _distance[13][15] = 120;
    _distance[13][14] = 190;

    _distance[14][15] = 80;
    _distance[14][16] = 210;

    _distance[15][18] = 140;
    _distance[15][20] = 200;
    _distance[15][21] = 170;

    _distance[16][21] = 200;
    _distance[16][23] = 80;

    _distance[17][25] = 60;
    _distance[17][18] = 70;

    _distance[18][26] = 70;
    _distance[18][19] = 120;

    _distance[19][20] = 60;

    _distance[20][21] = 100;
    _distance[20][22] = 110;
    _distance[20][27] = 130;
    _distance[20][28] = 120;

    _distance[21][22] = 90;

    _distance[22][29] = 120;
    _distance[22][30] = 110;
    _distance[22][24] = 110;

    _distance[23][24] = 80;

    _distance[24][30] = 40;

    _distance[25][26] = 80;

    _distance[26][27] = 80;

    _distance[28][29] = 80;

    _distance[29][31] = 180;
    _distance[29][30] = 100;

    _distance[30][31] = 100;
}

void AdjacencyList::ShortestPath_Floyd(GraphAdjList *G, int P[32][32], int D[32][32]) {
    //��ʼ��D��P
    for (int v = 0; v < G->numVertexes; ++v) {
        for (int w = 0; w < G->numVertexes; ++w) {
            if (_distance[v][w] == 0 && v != w) {
                _distance[v][w] = 10000;
            }
            D[v][w] = _distance[v][w];
            P[v][w] = w;
        }
    }
    for (int k = 0; k < G->numVertexes; ++k) {
        for (int v = 0; v < G->numVertexes; ++v) {
            for (int w = 0; w < G->numVertexes; ++w) {
                if (D[v][w] > D[v][k] + D[k][w]) {
                    D[v][w] = D[v][k] + D[k][w];
                    P[v][w] = P[v][k];
                }
            }
        }
    }

}

void AdjacencyList::ShowShortestResult(int originPos, int endPos) {
    int temp;
    cout << "�ص�" << _mapName[originPos] << "���ص�" << _mapName[endPos] << "��̾���Ϊ" << ShortestPathvalue[originPos][endPos]
         << endl;
    temp = ShortestPathmatrix[originPos][endPos];
    cout << "����·��Ϊ��" << _mapName[originPos] << "����>";
    while (temp != endPos) {
        cout << _mapName[temp] << "����>";
        temp = ShortestPathmatrix[temp][endPos];
    }
    cout << _mapName[endPos] << endl;
}


int main() {
    AdjacencyList adjacencyList;
    int originPos, endPos;
    GraphAdjList *GA = new GraphAdjList;
    adjacencyList.Test();
    adjacencyList.InitMap(GA);
    adjacencyList.CreateALGraph(GA);
    adjacencyList.ShortestPath_Floyd(GA, ShortestPathmatrix, ShortestPathvalue);
    cout << "��ͼ���������Ѿ���ʼ�����,��ͼͼ������ʾ" << endl;
    while (1) {
        cout << "�밴��ͼƬѡ������ȥ�ĵط���������ʼ���Ŀ�ĵص���ţ��Կո�����" << endl;
        cout << "��׼��ʽ ��0 1�ر�ͼƬ���س�" << endl;
        cout << "����������ɣ���ر�ͼƬ���ٰ��»س�����������ʾ·����" << endl;
        system("mspaint SchoolMap.png");
        cin >> originPos >> endPos;
        adjacencyList.ShowShortestResult(originPos, endPos);
    }

    return 0;
}
 