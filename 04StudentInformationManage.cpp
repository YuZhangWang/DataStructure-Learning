/***********************************
 * @author: YuZhangWang
 * @date: 2021/9/3 16:42
 * @link: https://www.yuzhang.wang/
***********************************/

#include<iostream>
#include<string>

using namespace std;

typedef struct Node {
    int num;
    char name[20];
    float DataStructure;
    float English;
    float average;
    Node *next;
} Node;

class StudList {
    Node *head;//ͷ�ڵ�
public:
    StudList();//���캯��
    void CreateList();//����һ���ձ�
    void Display();//��ʾ����
    int getlen();//��ȡ������

    Node *GetHead();

    void averGrade(Node *node);//��ƽ���ɼ�
    void Add();//ͷ�巨���һ��ѧ��
    void Insert();//�ڵ�i��λ�ò���һ��ѧ��
    void Delete();//ɾ��һ����ѧ��
    void Alter();//�޸�ָ��ѧ��ѧ������Ϣ
    void sort();//��������Ĳ�������ʹ��ĳ�ſγ̳ɼ�����
    void sortD();//�����ݽṹ�ɼ�����
    void sortE();//����ѧӢ��ɼ�����
    void sortAver();//ƽ���ɼ�����
    void Seek();//�������ѧ����Ϣ

    void CountNode();//��ѯĳһ��ѧ�Ʋ�����������ͳɼ���
    int CountNotD();//��ѯ���ݽṹ������������ͳɼ���
    int CountNotE();//��ѯĳ��ѧӢ�ﲻ����������ͳɼ���
    void menu(StudList *list); //��ʾ�˵�
    void swapNode(Node *a, Node *b); //�������ڽ����Ϣ
};

StudList::StudList() {
    head = new Node();
    head->next = NULL;
}

void StudList::CreateList() {
    head->num = 0;
}

void StudList::Display() {
    Node *cur = head;
    int len = getlen();
    cout << "ѧ������:" << len << endl;
    while (len--) {
        cout << "ѧ��:" << cur->num;
        cout << " ����:" << cur->name;
        cout << " ���ݽṹ�ɼ�:" << cur->DataStructure;
        cout << " ��ѧӢ��ɼ�:" << cur->English;
        cout << " ƽ���ɼ�:" << cur->average << endl;
        cur = cur->next;
    }
}

int StudList::getlen() {
    int n = 0;
    Node *cur;
    cur = head;
    while (cur) {
        n++;
        cur = cur->next;
    }
    return n;
}

Node *StudList::GetHead() {
    return head;
}

void StudList::averGrade(Node *node) {
    node->average = (node->English + node->DataStructure) / 2;
}

void StudList::Add() {
    Node *p, *t;
    if (!head) {
        head = new Node();
    }
    t = head;
    p = new Node();

    cout << "����ѧ��:" << endl;
    cin >> p->num;

    while (t) {
        if (t->num == p->num) {
            cout << "�Ѵ��ڸ�ѧ�ţ�" << endl;
            return;
        }
        t = t->next;
    }

    cout << "��������:" << endl;
    cin >> p->name;
    cout << "�������ݽṹ�ɼ�:" << endl;
    cin >> p->DataStructure;
    cout << "�����ѧӢ��ɼ�:" << endl;
    cin >> p->English;

    averGrade(p);

    if (head->num == 0) {
        head = p;
        return;
    }

    p->next = head;
    head = p;
}

void StudList::Insert() {
    int i, len;
    cout << "����Ҫ����ѧ����λ��(���뵽��λ��ǰ):";
    cin >> i;
    len = getlen();

    Node *cur, *t, *pr, *newNode;
    if (head == NULL || head->num == 0) {
        cout << "��ǰ��Ϊ�գ�" << endl;
        StudList();
        return;
    }

    if (i < 2 || i > len) {
        cout << "��λ�ò�����" << endl;
        return;
    }

    cur = head;
    pr = head;

    i--;

    while (cur && i--) {
        pr = cur;
        cur = cur->next;
    }

    newNode = new Node();

    t = head;
    cout << "�������ѧ����ѧ��:" << endl;
    cin >> newNode->num;

    while (t)//�ж��Ƿ��������ѧ��
    {
        if (t->num == newNode->num) {
            cout << "�Ѵ��ڸ�ѧ��!" << endl;
            return;
        }
        t = t->next;
    }

    cout << "��������:" << endl;
    cin >> newNode->name;
    cout << "�������ݽṹ�ɼ�:" << endl;
    cin >> newNode->DataStructure;
    cout << "�����ѧӢ��ɼ�:" << endl;
    cin >> newNode->English;
    averGrade(newNode);

    pr->next = newNode;
    newNode->next = cur;
}

void StudList::Delete() {
    int n;//n��ʾѧ��
    Node *cur, *pr;
    cur = head;
    pr = head;
    cout << "����Ҫɾ��ѧ����ѧ��:";
    cin >> n;
    while (cur) {
        if (cur->num == n) {
            if (cur == head) {
                head = head->next;//���ɾ������ͷ�ڵ㣬ֱ����ͷ�ڵ�Ϊͷ�ڵ����һ�ڵ�
                return;
            }
            pr->next = cur->next;
            return;
        }
        pr = cur;
        cur = cur->next;
    }
    cout << "û�в鵽Ҫɾ����ѧ��" << endl;
    return;
}

void StudList::Alter() {
    int a, n;//nΪѧ��
    Node *cur;
    cur = head;
    cout << "����Ҫ�޸�ѧ����ѧ��:";
    cin >> n;
    int len = getlen();
    if (n < 1 || n > len) {
        cout << "�����ڸ�ѧ��!" << endl;
        return;
    }

    while (cur) {
        if (cur->num == n) {
            cout << "1.�޸�����" << endl;
            cout << "2.�޸����ݽṹ�ɼ�" << endl;
            cout << "3.�޸Ĵ�ѧӢ��ɼ�" << endl;
            cout << "������Ҫ�޸ĵ���Ŀ(�������������޸�):";
            cin >> a;
            switch (a) {
                case 1:
                    cout << "�������޸�����:";
                    cin >> cur->name;
                    return;
                case 2:
                    cout << "�������޸ĵ����ݽṹ�ɼ�:";
                    cin >> cur->DataStructure;
                    averGrade(cur);
                    return;
                case 3:
                    cout << "�������޸ĵĴ�ѧӢ��ɼ�:";
                    cin >> cur->English;
                    averGrade(cur);
                    return;
                default:
                    cout << "�˳��޸�" << endl;
                    return;
            }
        }
        cur = cur->next;
    }
    return;
}

void StudList::sort() {
    int m;
    cout << "1.�����ݽṹ�ɼ�����" << endl;
    cout << "2.����ѧӢ��ɼ�����" << endl;
    cout << " ѡ��ĳһ������ʽ:";
    cin >> m;
    switch (m) {
        case 1:
            sortD();
            break;
        case 2:
            sortE();
            break;
        default:
            break;
    }
}

void StudList::sortD() {
    int len, inlen;
    Node *cur;
    len = getlen();
    while (--len) {
        inlen = len;
        cur = head;
        while (inlen--) {
            if (cur->DataStructure < cur->next->DataStructure) {
                swapNode(cur, cur->next);
            }
            cur = cur->next;
        }
    }
}

void StudList::sortE() {
    int len, inlen;
    Node *cur;
    cur = head;
    len = getlen();
    while (--len) {
        inlen = len;
        cur = head;
        while (cur && inlen--) {
            if (cur->English < cur->next->English) {
                swapNode(cur, cur->next);
            }
            cur = cur->next;
        }
    }
}

void StudList::sortAver() {
    int len, inlen, rank = 1;
    Node *cur;
    cur = head;
    len = getlen();
    while (--len) {
        inlen = len;
        cur = head;
        while (cur && inlen--) {
            if (cur->average < cur->next->average) {
                swapNode(cur, cur->next);
            }
            cur = cur->next;
        }
    }
    cur = head;
    while (cur) {
        cout << "ѧ��:" << cur->num
             << " ����:" << cur->name
             << "  ���ݽṹ�ɼ�:" << cur->DataStructure
             << "  ��ѧӢ��ɼ�:" << cur->English
             << "  ƽ���ɼ�:" << cur->average
             << " ����:" << rank << endl;

        if (cur->next && cur->average == cur->next->average) {
            cur = cur->next;
            continue;
        }
        rank++;
        cur = cur->next;
    }
}

void StudList::Seek() {
    int n;//n��ʾѧ��
    Node *cur, *pr;
    cur = head;
    pr = head;
    cout << "����Ҫ����ѧ����ѧ��:";
    cin >> n;
    while (cur) {
        if (cur->num == n) {
            cout << "ѧ��:" << cur->num;
            cout << "  ����:" << cur->name;
            cout << "  ���ݽṹ�ɼ�:" << cur->DataStructure;
            cout << "  ��ѧӢ��ɼ�:" << cur->English;
            cout << "  ƽ���ɼ�:" << cur->average << endl;
            return;
        }
        pr = cur;
        cur = cur->next;
    }
    cout << "û�в鵽Ҫ���ҵ�ѧ��" << endl;
    return;
}

void StudList::CountNode() {
    int m;
    cout << "1.ͳ�����ݽṹ�ɼ�������������" << endl;
    cout << "2.ͳ�ƴ�ѧӢ��ɼ�������������" << endl;
    cout << "����ѡ��ʽ��";
    cin >> m;
    switch (m) {
        case 1:
            CountNotD();
            break;
        case 2:
            CountNotE();
            break;
        default:
            break;
    }
}

int StudList::CountNotE() {
    int n = 0;
    Node *cur;
    cur = head;
    while (cur) {
        if (cur->English < 60) {
            cout << "ѧ��:" << cur->num
                 << " ����:" << cur->name
                 << " �ɼ�:" << cur->English << endl;
            n++;
        }
        cur = cur->next;
    }
    cout << "���ƴ�ѧӢ�ﲻ��������:" << n << endl;
    return n;
}

int StudList::CountNotD() {
    int n = 0;
    Node *cur;
    cur = head;
    while (cur) {
        if (cur->DataStructure < 60) {
            cout << "ѧ�ţ�" << cur->num
                 << " ������" << cur->name
                 << " �ɼ���" << cur->DataStructure << endl;
            n++;
        }
        cur = cur->next;
    }
    cout << "�������ݽṹ������������" << n << endl;
    return n;
}

void StudList::menu(StudList *list) {
    int a;
    cout << "------------------------------------" << endl;
    cout << "--   ��ӭʹ��ѧ���ɼ������ϵͳ   --" << endl;
    cout << "------------------------------------" << endl;
    while (1) {
        cout << "  " << "--------------------------------" << endl;
        cout << "  " << "|   1.��ʾ����ѧ����Ϣ         |" << endl;
        cout << "  " << "|   2.���һ��ѧ����Ϣ         |" << endl;
        cout << "  " << "|   3.�޸�һ��ѧ���ɼ�         |" << endl;
        cout << "  " << "|   4.ɾ��һ��ѧ���ɼ�         |" << endl;
        cout << "  " << "|   5.����һ��ѧ���ɼ�         |" << endl;
        cout << "  " << "|   6.��ƽ���ɼ�����           |" << endl;
        cout << "  " << "|   7.��ĳһ�γɼ�����         |" << endl;
        cout << "  " << "|   8.ͳ��ĳһ�γɼ����������� |" << endl;
        cout << "  " << "|   9.�������ѧ����Ϣ         |" << endl;
        cout << "  " << "--------------------------------" << endl;
        cin >> a;
        switch (a) {
            case 1:
                list->Display();
                break;

            case 2:
                list->Add();
                break;

            case 3:
                list->Display();
                list->Alter();
                list->Display();
                break;

            case 4:
                list->Display();
                list->Delete();
                list->Display();
                break;

            case 5:
                list->Display();
                list->Insert();
                list->Display();
                break;

            case 6:
                list->sortAver();
                break;

            case 7:
                list->sort();
                list->Display();
                break;

            case 8:
                list->CountNode();
                break;

            default:
                list->Seek();
                break;
        }
    }
}

void StudList::swapNode(Node *a, Node *b)//������������Ϣ 
{
    int temp;
    char c;
    float ft;

    temp = a->num;
    a->num = b->num;
    b->num = temp;


    for (int i = 0; i < 20; i++)//��������
    {
        c = a->name[i];
        a->name[i] = b->name[i];
        b->name[i] = c;
    }

    ft = a->DataStructure;
    a->DataStructure = b->DataStructure;
    b->DataStructure = ft;

    ft = a->English;
    a->English = b->English;
    b->English = ft;

    ft = a->average;
    a->average = b->average;
    b->average = ft;
}

int main() {
    StudList list;
    list.CreateList();
    list.menu(&list);
    return 0;
}