/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;        /* 邻接点下标 */
    PtrToAdjVNode Next; /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode{
    PtrToAdjVNode FirstEdge; /* 边表头指针 */
} AdjList[MaxVertexNum];     /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;     /* 顶点数 */
    int Ne;     /* 边数   */
    AdjList G;  /* 邻接表 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */


void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
    int queue[1010];
    int l=0,r=0;
    queue[r++]=S;
    (*Visit)(S);
    Visited[S]=true;
    PtrToAdjVNode tmp;
    while(l!=r)
    {
        tmp=Graph->G[queue[l++]].FirstEdge;
        while(tmp)
        {
            Vertex pos=tmp->AdjV;
            if(!Visited[pos])
            {
                Visit(pos);
                Visited[pos]=true;
                queue[r++]=pos;
            }
            tmp=tmp->Next;
        }
    }
}
