#include <iostream>
#define print_output

using std::cout;
using std::endl;

class QuickFind {
    private:
        int *id;
    public:
        QuickFind(int);
        void union_pts(int, int);
        bool connected(int, int) const;
};

QuickFind::QuickFind(int N)
{
    id = (int *) malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
        id[i] = i;
}

void QuickFind::union_pts(int p, int q)
{

#ifdef print_output
    cout << "connecting " << p << " and " << q << endl;
#endif
    if(id[p] != id[q]) {
        int p_id = id[p];
        int q_id = id[q];
        int N = (sizeof(id) / sizeof(id[0]));
        for(int i = 0; i < N; i++) {
            if(id[i] == p_id)
                id[i] = q_id;
        }
    }
}

bool QuickFind::connected(int p, int q) const {
    bool result = id[p] == id[q];
#ifdef print_output
    cout << p << " connected to " << q << " ? " << result << endl;
#endif
    return result;
}

int main()
{
    QuickFind qf(10);

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

