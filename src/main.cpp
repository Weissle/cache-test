#include <chrono>
#include <iostream>

int main(int argc, char* argv[])
{
    constexpr int len = 1 << 25;
    auto arr = new int[len];
    int times = 20;
    auto start = std::chrono::high_resolution_clock::now();
    while (times--)
    {
#ifndef Method1
        for (int i = 0; i < times; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                arr[j]++;
            }
        }
#else
        for (int j = 0; j < len; ++j)
        {
            for (int i = 0; i < times; ++i)
            {
                arr[j]++;
            }
        }
#endif
    }
    auto end = std::chrono::high_resolution_clock::now();
    double us =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start)
            .count();
    std::cout << " Time Cost:" << us / 1e6 << "s" << std::endl;
    return 0;
}

