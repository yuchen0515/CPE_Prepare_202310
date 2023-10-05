#include <iostream>
#include <vector>
#include <map>

void init(std::vector<int32_t>& root) {
    for (int32_t i = 0 ; i < root.size() ; i++) {
        root[i] = i;
    }
}

int32_t find(int32_t a, const std::vector<int32_t>& root) {
    if (root[a] != a) {
        return find(root[a], root);
    }
    return a;
}

void join(int32_t a, int32_t b, std::vector<int32_t>& root) {
    int32_t A = find(a, root);
    int32_t B = find(b, root);

    if (A != B) {
        root[B] = A;
    }

}

int main() {
    int32_t t = 0;
    int32_t n = 0, m = 0;
    while (true) {
        std::cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        t += 1;

        std::vector<int32_t> root(n + 1, 0);
        init(root);

        for (int32_t i = 0 ; i < m ; i++) {
            int32_t x = 0, y = 0;
            std::cin >> x >> y;

            join(x, y, root);
        }

        std::map<int32_t, int32_t> count;
        for (int32_t i = 1 ; i < n + 1 ; i++) {
            int32_t res = find(i, root);
            count[res] += 1;
        }

        std::cout << "Case " << t << ": ";
        std::cout << count.size() << std::endl;
    }
    return 0;
}
