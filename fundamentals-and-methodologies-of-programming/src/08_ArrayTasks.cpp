//--------------------------------------------------------
// Различные задачи поиска минимального элемента в массиве
//  ------------------------------------------------------
#include <iostream>

int main() {
    int a[] = { -7, 1, -3, 9, 34, 2 };
    constexpr int m = sizeof(a) / sizeof(a[0]);
    int b[m];
    for (auto i = 0; i < m; ++i)
        b[i] = a[i];
    
    std::cout << "a: ";
    for (const auto x : a) { 
        std::cout << x << " "; 
    }
    std::cout << std::endl;

    int xMin = a[0];
    for (auto i = 1; i < m; ++i)
        if (a[i] < xMin) xMin = a[i];
    std::cout << "xMin=" << xMin << std::endl;
    
    // Найти минимальный среди положительных
    int xMinP = -1;
    // a) Найти первый положительный элемент, если он существует
    int i;
    for (i = 0; i < m; ++i)
        if (a[i] > 0) {
            xMinP = a[i]; 
            break; 
        }

    if (xMinP == -1)
        std::cout << "No positive elements" << std::endl;
    else {
        // В xMinP первый положительный элемент
        // б) Найти минимальный среди положительных в a[i..m-1]
        for (; i < m; ++i)
            if (a[i] > 0 && a[i] < xMinP) xMinP = a[i];
        std::cout << "xMinP=" << xMinP << std::endl;
    }
    return 0;
}
