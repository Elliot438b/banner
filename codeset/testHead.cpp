//
// Created by liuwenbin on 18-4-14.
//

#include "Vector2.h"
#include <cmath>

using namespace std;//令std成员可见

double sqrt_sum(Vector2 &v) {
    double sum = 0;
    for (int i = 0; i != v.size(); ++i)sum += sqrt_sum(v[i]);
    return sum;
}