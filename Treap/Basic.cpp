mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct node {
  node *l, *r;
  int key, prior;
  node(int id) {
    l = r = nullptr;
    key = id;
    prior = rnd();
  }
};

struct treap {
  node *root;
  
  treap(): root(nullptr) {}

  void split(node *t, int pos, node *&l, node *&r) {
    if (t == nullptr) {
      l = r = nullptr;
      return;
    }

    if (t->key <= pos) {
      split(t->r, pos, l, r);
      t->r = l;
      l = t;
    } else {
      split(t->l, pos, l, r);
      t->l = r;
      r = t;
    }
  }

  node* merge(node *l, node *r) {
    if (!l || !r) return l ? l : r;

    if (l->prior < r->prior) {
      l->r = merge(l->r, r);
      return l;
    }
    
    r->l = merge(l, r->l);
    return r;
  }

  void insert(int id) {
    node *l, *r;
    split(root, id, l, r);
    root = merge(merge(l, new node(id)), r);
  }

  void erase(int id) {
    node *l, *m, *r;

    split(root, id, l, m);
    split(m, id + 1, m, r);

    delete m;

    root = merge(l, r);
  }
};