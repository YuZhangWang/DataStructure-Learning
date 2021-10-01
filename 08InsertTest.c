#include <stdio.h>
#include <stdbool.h>

#define MaxSize 5

typedef struct {    //����һ��˳���SqList(��̬����)
    int data[MaxSize];
    int length;
} SqList;

void initSqlist(SqList *l) {     //��ʼ��˳���
    for (int i = 0; i < MaxSize; ++i) {     //��˳���������Ԫ�س�ʼ��Ϊ0
        l->data[i] = 0;
    }
    l->length = 0;      //���ȶ���Ϊ0
}

void empty(SqList *l) {       //�пղ���
    if (l->length == 0) {
        printf("��ǰ˳���Ϊ��\n");
    } else {
        printf("��ǰ˳���ǿ�,˳�����Ϊ%d\n", l->length);
    }
}

int insertSqList(SqList *l, int i, int e) {       //��˳����ڲ���Ԫ��
    if (l->length + 1 > MaxSize) {      //�жϲ���󳤶��Ƿ񳬹�������󳤶�
        printf("˳����ѵ��󳤶�,����ʧ��\n");
        return 0;
    } else if (i < 1 || i > l->length + 1) {     //�жϲ���λ���Ƿ���ȷ
        printf("Ҫ�����λ�ò���ȷ\n");
        return 0;
    } else {
        for (int j = l->length; j >= i; j--) {
            l->data[j] = l->data[j - 1];
        }
        l->data[i - 1] = e;
        printf("����ǰ˳�����Ϊ%d\n", l->length);
        l->length++;
        printf("����ɹ�,�����˳�����Ϊ%d\n", l->length);
        return 1;
    }
}

void printSqList(SqList *l) {     //�������˳���
    if (l->length == 0) {
        printf("��ǰ˳�����û��Ԫ��\n");
    } else {
        printf("��ǰ˳�����Ԫ����: ");
        for (int i = 0; i < l->length; ++i) {
            printf("%d ", l->data[i]);
        }
        printf("\n");
    }
}

int get(SqList *l, int i) {     //��λ����
    if (i < 1 || i > l->length) {      //�ж�����λ���Ƿ�Ϸ�
        printf("����λ�ò�����");
        return 0;
    } else {      //���Ҳ����ؽ��
        int flag = l->data[i - 1];
        //printf("���ҳɹ�,����λ��Ԫ��Ϊ%d",flag);
        return flag;
    }
}

void locate(SqList *l, int e) {      //��ֵ����
    for (int i = 0; i < l->length; ++i) {
        if (e == l->data[i]) {
            printf("���ҳɹ�!ֵΪ%d��λ��Ϊ%d\n", e, i + 1);
        }
    }
}

void change(SqList *l, int i, int e) {        //����i��λ�õ�Ԫ���޸ĳ�e
    if (i < 1 || i > l->length) {
        printf("���޸ĵ�λ�ò�����!");
    } else {
        l->data[i - 1] = e;
    }
}

bool deleteSqList(SqList *l, int i) {        //ɾ��ָ��λ��Ԫ��
    if (i < 1 || i > l->length) {
        printf("ɾ��ʧ��!�����λ�ò�����\n");
        return false;
    } else {
        for (int j = i - 1; j < l->length; j++) {
            l->data[j] = l->data[j + 1];
        }
        l->length--;
        return true;
    }
}

int main() {
    SqList l;   //����˳���
    initSqlist(&l);     //��ʼ��˳���
    empty(&l);      //�пղ���
    insertSqList(&l, 1, 3);       //�ڵ�һ��λ�ò���3
    insertSqList(&l, 1, 2);       //�ڵ�һ��λ�ò���2
    insertSqList(&l, 1, 1);       //�ڵ�һ��λ�ò���1
    insertSqList(&l, 1, 4);       //�ڵ�һ��λ�ò���3
    insertSqList(&l, 1, 4);       //�ڵ�һ��λ�ò���3
    insertSqList(&l, 1, 4);       //�ڵ�һ��λ�ò���3
    empty(&l);      //�пղ���
    printSqList(&l);        //�������˳���
    int flag = get(&l, 3);       //����λ��Ϊ3��Ԫ�ز���ֵ��flag(��λ����)
    printf("������λ�õ�ֵΪ:%d\n", flag);
    locate(&l, 3);       //����ֵΪ3��Ԫ�ز����(��ֵ����)
    deleteSqList(&l, 2);     //ɾ��λ��Ϊ2��Ԫ��
    printSqList(&l);        //�������˳���,�鿴ɾ����Ľ��
    change(&l, 1, 5);     //����һ��λ�õ�Ԫ���޸ĳ�5
    printSqList(&l);        //�������˳���,�鿴ɾ����Ľ��
    return 0;
}