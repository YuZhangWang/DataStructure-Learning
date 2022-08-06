/***********************************
 * @author: YuZhangWang
 * @date: 2022/8/4 22:15
 * @link: https://www.yuzhang.wang/
***********************************/

#include<iostream>
#include<malloc.h>

using namespace std;

//����������
typedef int ElemType;
//�����������ڵ�
typedef struct BSTNode
{
    ElemType data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

//��Ҫ������������� and ɾ������

/*
�����������Ĳ��룺
T=NULL,�ӿ�����ʼ���죬��ָ��ָ����ڵ�
������С�Ҵ�ԭ�򣬵ݹ���뵽��(��)����
��Ϊ��/����Ϊ��ʱ������(�ݹ����)
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
ɾ����㣺����ɾ�����ĸ��ڵ�ָ���ӵ�ָ�����&(T->lchild)
���ԣ���ɾ�����ֻ��һ������ʱ��������һ��ɾ��(ǰ��ָ���̵ĺ��)
�����ԣ�����ת��Ϊ���ԣ�
�ҵ������������ֵ�����������ҵ��������������Һ�����
���߽��������ҵ���������С���
Ҷ�ӽ��ֱ��ɾ��
*/
void deleteOper(BSTree &T)
{ //ɾ�����
    if (NULL == T->rchild && NULL == T->lchild)
    {
        //Ҷ�ӽ��
        free(T);
        T = NULL;
    }
    else if (NULL == T->lchild)
    {
        //ֻ��������
        BSTNode *pNode = T;
        T = T->rchild;
        free(pNode);
    }
    else if (NULL == T->rchild)
    {
        //ֻ��������
        BSTNode *pNode = T;
        T = T->lchild;
        free(pNode);
    }
    else
    {
        //������������
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
            //ɾ�����
            deleteOper(T);
        }
        else if (x > T->data)
        {   //�������ָ���ӽ���ָ�����(rchild)
            deleteBST(T->rchild, x);//���ø��׽���rchild
        }
        else if (x < T->data)
        {
            deleteBST(T->lchild, x);
        }
    }
}

/*
���ҳɹ�ASL
���ҳɹ���ǰ�ᣬ�ý��һ���ڸö�����������
ֻ��Ҫ�����������еĽ�㣺����������������ȡƽ��
����ʧ��ASL��ʧ�ܣ��ҵ�������
�ղ���һ�αȽϣ�����һ���ȽϽ���ϵĿ�ָ��
����������оٳ���(��)�������ֵ
*/


/*
�������������ֽ����������������(��keyΪ����)   �������
key=��ʱ�����������������ֱ���뵽t1��t2
key>��������������������t1��.�����ֽ�������.
key<��������������������t2��,�����ֽ�������.
�ݹ��������裬ֱ��������δ���ֽ��
*/
void insertNode(BSTNode *rNode, BSTree &T)
{
    //��������(����)
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
    //������
    if (NULL != T)
    {
        if (key < T->data)
        {
            //key<��������������������t2��,�����ֽ�������.
            preOrderTraversing(key, T->lchild, T1, T2);
            T->lchild = NULL;
            insertNode(T, T2);
        }
        else if (key == T->data)
        {
            //key=��ʱ�����������������ֱ���뵽t1��t2
            insertNode(T->lchild, T1);
            insertNode(T->rchild, T2);
            free(T);
            T = NULL;
        }
        else
        {
            //key>��������������������t1��.�����ֽ�������.
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

//�����������������(�ǵ�����Ŷ)
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