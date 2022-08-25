/* �ڽӵ�Ķ��� */
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;        /* �ڽӵ��±� */
    PtrToAdjVNode Next; /* ָ����һ���ڽӵ��ָ�� */
};

/* �����ͷ���Ķ��� */
typedef struct Vnode{
    PtrToAdjVNode FirstEdge; /* �߱�ͷָ�� */
} AdjList[MaxVertexNum];     /* AdjList���ڽӱ����� */

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;     /* ������ */
    int Ne;     /* ����   */
    AdjList G;  /* �ڽӱ� */
};
typedef PtrToGNode LGraph; /* ���ڽӱ�ʽ�洢��ͼ���� */


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
