#include <time.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define Lc (o -> Ch[0])
#define Rc (o -> Ch[1])
#define val (o -> v)
#define pre (o -> p)
#define siz (o -> S)

struct Treap {
    Treap *Ch[2];//The Node's Two Child Tree
    int p, v, S;//Priority Value And Size
};


void Update(Treap *&o) {//Mountain O's Size
    siz = 1;
    if (Lc != NULL)siz += Lc->S;
    if (Rc != NULL)siz += Rc->S;
}

void Rotate(Treap *&o, int d) {
    Treap *P = o->Ch[d ^ 1];//P Is A Point That Willing To Be A Root
    o->Ch[d ^ 1] = P->Ch[d];//Eh......Rotate Should Give P's Child To O
    P->Ch[d] = o;//O Is Going Down So It Is P's Child
    Update(o);
    Update(P);//Points' Size Has Been Changed
    o = P;//Use P To Replace O
}

void Insert(Treap *&o, int x) {
    if (o == NULL) {//Insert It To Leaves
        o = new Treap();
        Lc = Rc = NULL;
        pre = rand();
        val = x;
    } else {//Rotate And Let x Going Up
        int d = x < val;
        Insert(o->Ch[d], x);
        if ((pre) > o->Ch[d]->p)Rotate(o, d ^ 1);
    }
    Update(o);//Mountain O's Size
}

int Find(Treap *o, int x) {
    while (o != NULL) {
        if (val == x)return 1;
        o = (x < val) ? Rc : Lc;//Oh It's Easy
    }
    return 0;
}

void Delete(Treap *&o, int x) {
    if (val == x) {//If Find Out X
        if (Lc == NULL)o = Rc;
        else if (Rc == NULL)o = Lc;//Link Child To Father Straight
        else {
            int T = (Lc->p) < (Rc->p);//Search A Child Tree That Has A Less Pre
            Rotate(o, T);
            Delete(o->Ch[T], x);//Rotate It And Delete It In Child Tree
        }
    } else Delete(o->Ch[x < val], x);
    if (o != NULL)Update(o);
}

int Kth_Min(Treap *o, int k) {
    if (o == NULL || k <= 0 || k > siz)return 0;//Clearly Can't Find Kth Cases
    int S = (Rc == NULL) ? 0 : (Rc->S);//A Half's Size
    if (k == S + 1)
        return val;//Has Found It
    else if (k <= S)
        return Kth_Min(Rc, k);//Find It In Child Tree
    else return Kth_Min(Lc, k - S - 1);
}

struct Card {
    int a;
    int b;

    friend bool operator<(const Card &a, const Card &b) {
        if (a.a == b.a)
            return a.b < b.b;
        else
            return a.a < b.a;
    }
} cards[200000 + 1];

int min_b, th_n_sub_i_plus_one, th_n;
long long h1, h2;
long long MAX_SUM = -1;
int n;
int a, b;
Treap *root = NULL;

void read_data() {

    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a >> b;
        if (a > b)
            a = a ^ b, b = a ^ b, a = a ^ b;
        cards[i].a = a, cards[i].b = b;
        Insert(root, b); // 按 b 构成 treap树堆
    }
    // 按a从小到大排序
    sort(cards, cards + 2 * n, less<Card>());
}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    srand(time(NULL));
    read_data();

    // 固定a的最小值到第一堆
    int const HEAP_ONE_A_MIN = cards[0].a;
    int HEAP_ONE_B_MIN = cards[0].b;
    Delete(root, cards[0].b);

    for (int i = 1; i <= n; ++i) {

        Delete(root, cards[i].b);                // 把cards[i].a认为是第二堆a的最小，把这个先从堆中删除，然后处理b
        min_b = Kth_Min(root, 1);                // 取除了cards[i].b 以外最小的。
        th_n_sub_i_plus_one = Kth_Min(root, n - i + 1);    // 取除了cards[i].b 以外， 第n-i+1小的b。
        th_n = Kth_Min(root, n);                // 第n小的b。前面n-1个留给第二堆，第n个开始的留给第一堆。

        // 把前面n-i个卡牌放到第一堆，那么第二堆最小的b就是		min{第n-i+1小, cards[i].b}
        h1 = (long long) HEAP_ONE_A_MIN * min(HEAP_ONE_B_MIN, min_b);
        h2 = (long long) cards[i].a * min(th_n_sub_i_plus_one, cards[i].b);
        if (h1 + h2 > MAX_SUM) {
            MAX_SUM = h1 + h2;
        }

        // 把后面n-i张卡牌放入第一堆，那么第二堆最小的就是min_b。
        h1 = (long long) HEAP_ONE_A_MIN * min(HEAP_ONE_B_MIN, th_n);// 后面的n-i个元素，也就是n开始。
        h2 = (long long) cards[i].a * min(cards[i].b, min_b); // 最小的留给了自己。
        if (h1 + h2 > MAX_SUM) {
            MAX_SUM = h1 + h2;
        }
        // 把a[i] 放入第一堆
        HEAP_ONE_B_MIN = min(cards[i].b, HEAP_ONE_B_MIN);
    }

    cout << MAX_SUM;
    return 0;
}