//typedef struct GNode *PtrToGNode;
//struct GNode{
//    int Nv;  /* 顶点数 */
//    int Ne;  /* 边数   */
//    WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
//};
//typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */


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
