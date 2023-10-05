#include <iostream>
#include <vector>

int main() {
    int32_t T = 0;
    std::cin >> T;
    while (T--) {
        int32_t N = 0;
        std::cin >> N;

        std::vector<std::pair<int32_t, int32_t>> item;
        for (int32_t i = 0 ; i < N ; i++) {
            int32_t P = 0, W = 0;
            std::cin >> P >> W;

            item.emplace_back(std::make_pair(P, W));

        }
        int32_t G = 0;
        std::cin >> G;
        std::vector<int32_t> stands;
        int32_t max = 0;
        for (int32_t i = 0 ; i < G ; i++) {
            int32_t M = 0;
            std::cin >> M;
            stands.emplace_back(M);
            max = std::max(max, M);
        }

        std::vector<std::vector<int32_t>> DP;
        for (int32_t i = 0 ; i < N + 1 ; i++) {
            std::vector<int32_t> temp(max + 1, 0);
            DP.emplace_back(temp);
        }

        for (int32_t i = 0 ; i < N ; i++) {
            for (int32_t j = 0; j < max + 1; j++) {
                DP[i + 1][j] = std::max(DP[i + 1][j], DP[i][j]);
                if (j + item[i].second > max) {
                    continue;
                }
                DP[i + 1][j + item[i].second] = std::max(DP[i + 1][j + item[i].second], DP[i][j] + item[i].first);
            }
        }

        int32_t ans = 0;
        for (int32_t i = 0 ; i < stands.size() ; i++) {
            int32_t max_w = 0;
            for (int32_t j = 0 ; j < N + 1; j++) {
                if (DP[j][stands[i]] > max_w) {
                    max_w = DP[j][stands[i]];
                }
            }
            ans += max_w;
        }

        std::cout << ans << std::endl;
    }
    return 0;
} 
