#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>

using namespace std::chrono;
using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n > 2 && n % 2 == 0) {
        return false;
    }
    int max_div = floor(static_cast<float>(sqrt(n)));
    for (int i = 3; i < 1 + max_div; i+=2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << setprecision(12);

    auto start = high_resolution_clock::now();
    
    int c = 0;
    for (int i = 50000; i < 1000000; i++) {
        int x = is_prime(i);
        c += x;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    double nsec = duration.count();

    cout << "Total prime numbers in range : " << c << endl;

    cout << "Time required (ns): " << nsec << endl;

}
