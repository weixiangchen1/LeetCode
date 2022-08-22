//typedef struct GNode *PtrToGNode;
//struct GNode{
//    int Nv;  /* ������ */
//    int Ne;  /* ����   */
//    WeightType G[MaxVertexNum][MaxVertexNum]; /* �ڽӾ��� */
//};
//typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */


void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) )
{
    int i;
    Visited[V]=true;
    Visit(V);
    for(i=0;i<Graph->Nv;i++)
    {
        if(Graph->G[V][i]==1&&!Visited[i])
        {
            DFS(Graph, i, Visit);
        }
    }
}
