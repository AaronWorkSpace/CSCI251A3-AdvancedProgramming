//Done By: Aaron Lim Cong Kai
//UOW ID : 5985171

#include <math.h>

//getting the length value of x and y
//minus them
template <class T>
double scalar_difference(T x, T y){
    return fabs(x.getScalarValue() - y.getScalarValue());
}

//check for duplication
template <class T>
bool equals(T x, T y){
    if(x == y)
        return true;
    return false;
}

//check if descending
template <typename T>
bool DSC(const T& t1, const T& t2){
  return t1 > t2;
}

//check if ascending
template <typename T>
bool ASC(const T& t1, const T& t2){
  return t1 < t2;
}

