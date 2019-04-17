#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

#ifdef DEBUG
struct Timestamper {
  string msg;
  clock_t start;

  Timestamper(const string &_msg) : msg(_msg), start(clock()) {}
  ~Timestamper() {
    eprintf("[ %s ] Time=%.3lfs\n", msg.c_str(), (clock() - start) * 1.0 / CLOCKS_PER_SEC);
  }
} __timestamper("end");
#else
struct Timestamper {};
#endif

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

const int inf = 1e9;

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi src(n);
    forn (i, n) {
      scanf("%d", &src[i]);
    }
    reverse(src.begin(), src.end());
    list<int> vals;
    forn (i, n)
      vals.pb(src[i]);

    typedef list<int>::iterator it;
    vector<it> toCheck;
    for (auto x = vals.begin(); x != vals.end(); x++) toCheck.pb(x);

    int ans = 0;
    for (;;) {
//      eprintf("new:\n");
      vector<it> q;

      auto prevCheck = vals.end();

      q.clear();
      for (auto x : toCheck) {
        if (x == prevCheck) continue;
        prevCheck = x;

        auto y = x; y++;
        if (y == vals.end()) continue;
        if (*x > *y) {
//          eprintf("del %d (%d)\n", *x, *y);
          q.pb(x);
        }
      }
      if (q.empty()) break;

      ans++;
      toCheck.clear();
      for (auto x : q) {
        if (x != vals.begin()) {
          auto y = x; y--;
          toCheck.pb(y);
//          eprintf("toCheck %d\n", *y);
        }
        vals.erase(x);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
