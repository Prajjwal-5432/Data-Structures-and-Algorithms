struct mhash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  uint64_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
struct DDSU {
  #define ll long long
  unordered_map<ll, ll, mhash> parent, degree;
  ll N;
    
  // DDSU(long long n) { N = n; }

  ll fset(ll vertex) {
    if (parent.find(vertex) != parent.end()) {
      if (parent[vertex] != vertex) {
        parent[vertex] = fset(parent[vertex]);
        return parent[vertex];
      }
    } else {
      parent.insert(make_pair(vertex, vertex));
      degree.insert(make_pair(vertex, 1));
    }

    return vertex;
  }

  void uset(ll vertexA, ll vertexB) {
    ll x = fset(vertexA);

    ll y = fset(vertexB);

    if (x == y) return;

    if (degree[x] > degree[y]) {
      parent[y] = x;
      degree[x] = degree[x] + degree[y];
    } else {
      parent[x] = y;
      degree[y] = degree[y] + degree[x];
    }
  }
    
  ll size(ll vertex) {
      return degree[fset(vertex)];
  }
};