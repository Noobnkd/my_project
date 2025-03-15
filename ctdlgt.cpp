#include <iostream>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <math.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;

struct Node{
    int data;
    Node *next;
};

typedef struct Node* node;
//cap phat dong 1 node voi du lieu la so nguyen x
node MakeNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}
//Kiem tra rong
bool empty(node a){
    return a == NULL;
}
// Dem so luong ptu 
int Size(node a){
    int cnt = 0;
    while(a != NULL){
        ++cnt;
        a = a->next;
    }
    return cnt;
}
// Them mot phan tu vao dau danh sach
void insertFirst(node &a, int x){
    node tmp = MakeNode(x);
    if(a == NULL){
        a = tmp;
    }
    else{
        tmp->next = a;
        a = tmp;
    }
}
// Them mot phan tu vao cuoi danh sach
void insertLast(node &a, int x){
    node tmp = MakeNode(x);
    if(a == NULL){
        a = tmp;
    }
    else{
        node p = a;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
    }
}
// Them 1 phan tu vao giua
void insertMiddle(node &a, int x, int pos){
    int n = Size(a);
    if(n == 1){
        insertFirst(a,x);
        return;
    }
    else if(n + 1 == pos){
        insertLast(a,x);
        return;
    }
    node p = a;
    for(int i = 1; i < pos - 1; i++){
        p = p->next;
    }
    node tmp = MakeNode(x);
    tmp->next = p->next;
    p->next = tmp;
}
// Xoa phan tu dau
void deleteFirst(node &a){
    if(a == NULL) return;
    a= a->next;
}
// Xoa phan tu cuoi cung
void deleteLast(node &a){
    if(a == NULL) return;
    node truoc = NULL, sau = a;
    while(sau->next != NULL){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL){
        a = NULL;
    }
    else truoc->next = NULL; 
}
//Xoa phan tu o giua
void deleteMiddle(node &a, int pos){
    node truoc = NULL, sau = a;
    for(int i = 1; i<pos; i++){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL){
        a = a->next;
    }
    else truoc->next = sau->next;

}
void in(node a){
    cout << "--------------------------\n";
    while(a != NULL){
        cout << a->data << " ";
        a = a->next;
    }
    cout << "--------------------------\n";
}
void selectionsort(node &a){
    for(node p = a; p->next!=NULL;p=p->next){
        node min = p;
        for(node q = p->next; q != NULL; q=q->next){
            if(min->data < q->data){
                min = q;
            }
        }
        int tmp = min->data;
        min->data = p->data;
        p->data = min->data;
    }
}
int main(){
    node head = NULL;
    
    return 0;
}