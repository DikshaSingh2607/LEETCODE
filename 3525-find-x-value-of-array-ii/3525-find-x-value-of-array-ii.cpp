class Solution {
public:
    struct Node {
        int cnt[5] = {0, 0, 0, 0, 0};
        int prod = 1;
    };

    int k;
    vector<Node> tree;

    Node mergeNode(const Node &L, const Node &R) {
        Node res;

        res.prod = (L.prod * R.prod) % k;

        // Prefixes completely inside left
        for (int r = 0; r < k; r++) {
            res.cnt[r] = L.cnt[r];
        }

        // Prefixes containing all of left + prefix of right
        for (int r = 0; r < k; r++) {
            if (R.cnt[r] == 0)
                continue;

            int rem = (L.prod * r) % k;
            res.cnt[rem] += R.cnt[r];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            int rem = nums[l] % k;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        build(nums, node << 1, l, mid);
        build(nums, node << 1 | 1, mid + 1, r);

        tree[node] = mergeNode(
            tree[node << 1],
            tree[node << 1 | 1]
        );
    }

    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            // Reset node
            tree[node] = Node();

            int rem = value % k;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(node << 1, l, mid, idx, value);
        else
            update(node << 1 | 1, mid + 1, r, idx, value);

        tree[node] = mergeNode(
            tree[node << 1],
            tree[node << 1 | 1]
        );
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) >> 1;

        if (qr <= mid)
            return query(node << 1, l, mid, ql, qr);

        if (ql > mid)
            return query(node << 1 | 1, mid + 1, r, ql, qr);

        Node L = query(node << 1, l, mid, ql, qr);
        Node R = query(node << 1 | 1, mid + 1, r, ql, qr);

        return mergeNode(L, R);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        this->k = k;

        int n = nums.size();

        tree.resize(4 * n + 5);

        build(nums, 1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update
            update(1, 0, n - 1, index, value);

            // Query [start, n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};