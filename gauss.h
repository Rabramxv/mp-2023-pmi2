﻿#pragma once
#ifndef GAUSS_H
#define GAUSS_H

#include "vecmat.h"

class Gauss {
private:
    Matrix* A;
    Vector* x;
    Vector* b;
    int status;
    Matrix M;
    Vector bold;

public:
    Gauss(Matrix* A, Vector* x, Vector* b);
    void Solve();
    double Check();
};

#endif