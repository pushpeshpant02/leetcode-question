class PQNode {
public:
    int i, j;
    long long val;

    PQNode(int i, int j, long long val) {
        this->i = i;
        this->j = j;
        this->val = val;
    }
};

class SegmentTree {
private:
    struct Node {
        int start, end;
        int mn, mx;
        Node* left;
        Node* right;

        Node(int s, int e) {
            start = s;
            end = e;
            mn = INT_MAX;
            mx = INT_MIN;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

    Node* buildTree(vector<int>& nums, int start, int end) {
        Node* node = new Node(start, end);

        if (start == end) {
            node->mn = nums[start];
            node->mx = nums[start];
            return node;
        }

        int mid = (start + end) / 2;

        node->left = buildTree(nums, start, mid);
        node->right = buildTree(nums, mid + 1, end);

        node->mn = min(node->left->mn, node->right->mn);
        node->mx = max(node->left->mx, node->right->mx);

        return node;
    }

    pair<int, int> query(Node* node, int start, int end) {
        if (!node) {
            return {INT_MAX, INT_MIN};
        }

        if (start <= node->start && node->end <= end) {
            return {node->mn, node->mx};
        }

        if (node->end < start || end < node->start) {
            return {INT_MAX, INT_MIN};
        }

        auto left = query(node->left, start, end);
        auto right = query(node->right, start, end);

        int mn = min(left.first, right.first);
        int mx = max(left.second, right.second);

        return {mn, mx};
    }

public:
    SegmentTree(vector<int>& nums) {
        root = buildTree(nums, 0, nums.size() - 1);
    }

    pair<int, int> query(int start, int end) {
        return query(root, start, end);
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SegmentTree st(nums);

        auto cmp = [](const PQNode& a, const PQNode& b) {
            return a.val < b.val;
        };

        priority_queue<PQNode, vector<PQNode>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < n; i++) {
            int j = n - 1;

            auto res = st.query(i, j);

            long long val = 1LL * res.second - res.first;

            pq.push(PQNode(i, j, val));
        }

        long long ans = 0;

        while (k--) {
            PQNode peak = pq.top();
            pq.pop();

            ans += peak.val;

            int i = peak.i;
            int j = peak.j - 1;

            if (i <= j) {
                auto res = st.query(i, j);

                long long val = 1LL * res.second - res.first;

                pq.push(PQNode(i, j, val));
            }
        }

        return ans;
    }
};