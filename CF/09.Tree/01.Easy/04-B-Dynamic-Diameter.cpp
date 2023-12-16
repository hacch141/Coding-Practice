#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vll vector<long long>
#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rrep(i, a, b) for (ll i = (b) - 1; i >= (a); --i)
#define trav(a, x) for (auto &a : x)

#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

struct Node {
    vector<Node*> adj;
    ll dist;
    bool diam = false;
};

void bfs(Node* u, Node* nodes[], ll n) {
    rep(i, 0, n) nodes[i]->dist = -1;
    u->dist = 0;
    queue<Node*> q;
    q.push(u);
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        trav(v, curr->adj) {
            if(v->dist == -1) {
                v->dist = 1 + curr->dist;
                q.push(v);
            }
        }
    }
}

Node* farthest(Node* nodes[], ll n) {
    Node* mx = nodes[0];
    rep(i, 1, n) {
        if(nodes[i]->dist > mx->dist) mx = nodes[i];
    }
    return mx;
}

void solve() {
    ll n;
    cin >> n;
    Node* nodes[n];
    rep(i, 0, n) nodes[i] = new Node();
    rep(i, 1, n) {
        ll u, v;
        cin >> u >> v;
        nodes[u-1]->adj.pb(nodes[v-1]);
        nodes[v-1]->adj.pb(nodes[u-1]);
    }

    bfs(nodes[0], nodes, n);
    Node* farNode = farthest(nodes, n);
    bfs(farNode, nodes, n);
    farNode = farthest(nodes, n);
    ll d = farNode->dist;
    trav(v, nodes) v->diam |= v->dist == d;
    bfs(farNode, nodes, n);
    trav(v, nodes) v->diam |= v->dist == d;

    rep(i, 0, n) {
        cout << (nodes[i]->diam ? d + 1 : d) << endl;
    }

    rep(i, 0, n) delete nodes[i];
}

int main() {
    speed();
    solve();
    return 0;
}
