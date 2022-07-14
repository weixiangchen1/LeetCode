#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* CreateTree(char* str, int* pi)
{
    if(str[(*pi)] == '#')
    {
        (*pi)++;
        return NULL;
    }
    
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = str[(*pi)++];
    root->left = CreateTree(str, pi);
    root->right = CreateTree(str, pi);
    
    return root;
}

void InOrder(struct TreeNode* root)
{
    if(root == NULL)
        return;
    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);
}

int main()
{
    char str[110];
    scanf("%s", str);
    int i = 0;
    struct TreeNode* root = CreateTree(str, &i);
    
    InOrder(root);
    return 0;
}
