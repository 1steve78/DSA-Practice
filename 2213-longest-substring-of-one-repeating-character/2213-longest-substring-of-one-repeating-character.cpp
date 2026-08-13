class Solution {
public:
    struct Node {
        char lc, rc;
        int len;
        int pref, suff, mx;

        Node() {
            lc = rc = '#';
            len = pref = suff = mx = 0;
        }

        Node(char c) {
            lc = rc = c;
            len = pref = suff = mx = 1;
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node &a, Node &b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        res.pref = a.pref;
        res.suff = b.suff;

        res.mx = max(a.mx, b.mx);

        // Boundary characters are same
        if (a.rc == b.lc) {
            res.mx = max(res.mx, a.suff + b.pref);

            if (a.pref == a.len)
                res.pref = a.len + b.pref;

            if (b.suff == b.len)
                res.suff = b.len + a.suff;
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, char c) {
        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, c);
        else
            update(node * 2 + 1, mid + 1, r, pos, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            int pos = queryIndices[i];
            char c = queryCharacters[i];

            s[pos] = c;

            update(1, 0, n - 1, pos, c);

            ans.push_back(tree[1].mx);
        }

        return ans;
    }
};