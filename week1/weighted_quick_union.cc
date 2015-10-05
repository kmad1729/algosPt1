#include <iostream>
#define print_output


using std::cout;
using std::endl;

class WeightedQuickUnion {
    private:
        int *id;
        int *tr_sizes;
        int root(int);
        int sz;
    public:
        WeightedQuickUnion(int);
        void union_pts(int, int);
        bool connected(int, int);
};

WeightedQuickUnion::WeightedQuickUnion(int n) {
    sz = n;
    id = new int[sz];
    tr_sizes = new int[sz];
    for(int i = 0; i < sz; i++) {
        id[i] = i;
        tr_sizes[i] = 1;
    }
};

int WeightedQuickUnion::root(int p) {
    while(p != id[p]) {
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}

bool WeightedQuickUnion::connected(int p, int q)
{
    bool result = root(p) == root(q);
#ifdef print_output
    cout << p << " connected to " << q << " ? " << result << endl;
#endif
    return result;
}

void WeightedQuickUnion::union_pts(int p, int q)
{
#ifdef print_output
    cout << "connecting " << p << " and " << q << endl;
#endif
    int p_root = root(p);
    int q_root = root(q);
    if(p_root != q_root) {
        if(tr_sizes[p_root] < tr_sizes[q_root]) {
            id[p_root] = q_root;
            tr_sizes[q_root] += tr_sizes[p_root];
        } else {
            id[q_root] = p_root;
            tr_sizes[p_root] += tr_sizes[q_root];
        }
    }
}

int main()
{
    WeightedQuickUnion qf(10);

    qf.union_pts(0, 5);
    qf.union_pts(5, 6);
    qf.connected(0, 6);
    qf.connected(0, 9);

    qf.union_pts(1, 2);
    qf.union_pts(7, 2);
    qf.union_pts(1, 0);
    qf.connected(6, 7);
    qf.connected(6, 9);

    qf.union_pts(3, 4);
    qf.union_pts(3, 8);
    qf.union_pts(8, 9);
    qf.connected(3, 5);
    qf.connected(5, 5);
    qf.connected(3, 9);

}

