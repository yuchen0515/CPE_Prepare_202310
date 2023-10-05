#include <iostream>
#include <string>

int main() {
    int32_t K = 0;
    while (true) {
        std::cin >> K;
        if (K == 0) {
            break;
        }

        int32_t N = 0, M = 0;
        std::cin >> N >> M;

        for (int32_t i = 0 ; i < K ; i++) {
            int32_t X = 0, Y = 0;
            std::cin >> X >> Y;

            if (N == X || M == Y) {
                std::cout << "divisa" << std::endl;
            } else if (N > X && Y > M) {
                std::cout << "NO" << std::endl;
            } else if (N < X && Y > M) {
                std::cout << "NE" << std::endl;
            } else if (N < X && Y < M) {
                std::cout << "SE" << std::endl;
            } else if (N > X && Y < M) {
                std::cout << "SO" << std::endl;
            }

        }

    }

    return 0;
}
