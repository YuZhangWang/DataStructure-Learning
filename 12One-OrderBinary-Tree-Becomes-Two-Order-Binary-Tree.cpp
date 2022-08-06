/***********************************
 * @author: YuZhangWang
 * @date: 2022/8/4 22:15
 * @link: https://www.yuzhang.wang/
***********************************/

#include<iostream>
#include<malloc.h>

using namespace std;

//二叉排序树
typedef int ElemType;
//二叉搜索树节点
typedef struct BSTNode
{
    ElemType data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

//重要操作：插入操作 and 删除操作

/*
二叉排序树的插入：
T=NULL,从空树开始构造，根指针指向根节点
根据左小右大原则，递归插入到左(右)子树
树为空/子树为空时插入结点(递归出口)
 */
void insertKey(BSTree &T, ElemType key)
{
    if (NULL == T)
    {
        BSTNode *pNode = (BSTNode *) malloc(sizeof(BSTNode));
        pNode->lchild = NULL;
        pNode->rchild = NULL;
        pNode->data = key;
        T = pNode;
    }
    else if (key > T->data)
    {
        insertKey(T->rchild, key);
    }
    else if (key < T->data)
    {
        insertKey(T->lchild, key);
    }
}

BSTNode *createBSTree()
{
    BSTNode *T = NULL;
    ElemType keyList[] = {40, 10, 45, 15, 23, 42, 12, 43};
    int keyListLength = 8;
    for (int i = 0; i < keyListLength; i++)
    {
        insertKey(T, keyList[i]);
    }
    return T;
}

/*
删除结点：传入删除结点的父节点指向孩子的指针变量&(T->lchild)
线性：当删除结点只有一个子树时，像链表一样删除(前驱指向后继的后继)
非线性，将其转化为线性：
找到左子树的最大值，将右子树挂到左子树最大结点的右孩子上
或者将左子树挂到右子树最小结点
叶子结点直接删除
*/
void deleteOper(BSTree &T)
{ //删除结点
    if (NULL == T->rchild && NULL == T->lchild)
    {
        //叶子结点
        free(T);
        T = NULL;
    }
    else if (NULL == T->lchild)
    {
        //只有右子树
        BSTNode *pNode = T;
        T = T->rchild;
        free(pNode);
    }
    else if (NULL == T->rchild)
    {
        //只有左子树
        BSTNode *pNode = T;
        T = T->lchild;
        free(pNode);
    }
    else
    {
        //左右子树都有
        BSTNode *pMax = T->lchild;
        while (pMax->rchild != NULL)
        {
            pMax = pMax->rchild;
        }
        pMax->rchild = T->rchild;
        BSTNode *pNode = T;
        T = T->lchild;
        free(pNode);
    }
}

void deleteBST(BSTree &T, ElemType x)
{
    if (T != NULL)
    {
        if (x == T->data)
        {
            //删除结点
            deleteOper(T);
        }
        else if (x > T->data)
        {   //传入的是指向孩子结点的指针变量(rchild)
            deleteBST(T->rchild, x);//引用父亲结点的rchild
        }
        else if (x < T->data)
        {
            deleteBST(T->lchild, x);
        }
    }
}

/*
查找成功ASL
查找成功的前提，该结点一定在该二叉排序树中
只需要考虑树中已有的结点：将所有情况求出来，取平均
查找失败ASL，失败：找到空子树
空不算一次比较，空上一个比较结点上的空指针
将所有情况列举出来(空)，计算均值
*/


/*
将二叉排序树分解成两个二叉排序树(以key为界限)   先序遍历
key=根时，左子树和右子树分别插入到t1，t2
key>根，将根和左子树插入t1中.继续分解右子树.
key<根，将根和右子树插入t2中,继续分解左子树.
递归上述步骤，直到不存在未划分结点
*/
void insertNode(BSTNode *rNode, BSTree &T)
{
    //插入子树(先序)
    if (T == NULL)
    {
        T = rNode;
    }
    else if (rNode->data > T->data)
    {
        insertNode(rNode, T->rchild);
    }
    else
    {
        insertNode(rNode, T->lchild);
    }
}

void preOrderTraversing(ElemType key, BSTree &T, BSTree &T1, BSTree &T2)
{
    //分离树
    if (NULL != T)
    {
        if (key < T->data)
        {
            //key<根，将根和右子树插入t2中,继续分解左子树.
            preOrderTraversing(key, T->lchild, T1, T2);
            T->lchild = NULL;
            insertNode(T, T2);
        }
        else if (key == T->data)
        {
            //key=根时，左子树和右子树分别插入到t1，t2
            insertNode(T->lchild, T1);
            insertNode(T->rchild, T2);
            free(T);
            T = NULL;
        }
        else
        {
            //key>根，将根和左子树插入t1中.继续分解右子树.
            preOrderTraversing(key, T->rchild, T1, T2);
            T->rchild = NULL;
            insertNode(T, T1);
        }
    }
}

void spilitBSTree(ElemType key, BSTree &T, BSTree &T1, BSTree &T2)
{
    T1 = NULL;
    T2 = NULL;
    preOrderTraversing(key, T, T1, T2);

}

//中序遍历二叉排序树(是递增的哦)
void inOrderTravsing(BSTree T)
{
    if (T != NULL)
    {
        inOrderTravsing(T->lchild);
        printf("%d ", T->data);
        inOrderTravsing(T->rchild);
    }
}

int main()
{
    BSTNode *T = createBSTree();
    inOrderTravsing(T);
    printf("\n");
    //deleteBST(T,40);
    BSTNode *T1 = NULL;
    BSTNode *T2 = NULL;
    spilitBSTree(26, T, T1, T2);
    inOrderTravsing(T1);
    printf("\n");
    inOrderTravsing(T2);
    return 0;
}