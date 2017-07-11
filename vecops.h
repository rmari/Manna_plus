#ifndef __Model_Vecops__
#define __Model_Vecops__
#include <vector>
#include <iostream>
#include <cmath>
#include<boost/dynamic_bitset.hpp>

namespace vops {
template <typename T1, typename T2>
inline std::vector<T1> operator * (const std::vector<T1>& a,
                                   const std::vector<T2>& b)
{
  if (a.size() != b.size()) {
    std::cerr << "*: incompatible sizes"  << std::endl;
    exit(1);
  }
  std::vector<T1> c(a.size());
  for (unsigned int i=0; i<a.size(); i++) {
    c[i] = a[i]*b[i];
  }
  return c;
}

template <typename T1, typename T2>
inline std::vector<T1>& operator *= (std::vector<T1>& a,
                                     const std::vector<T2>& b)
{
  if (a.size() != b.size()) {
    std::cerr << "*=: incompatible sizes"  << std::endl;
    exit(1);
  }
  for (unsigned int i=0; i<a.size(); i++) {
    a[i] *= b[i];
  }
  return a;
}

template <typename T1, typename T2>
inline std::vector<T1> operator * (const std::vector<T1>& a,
                                   const T2& b)
{
  std::vector<T1> c(a.size());
  for (unsigned int i=0; i<a.size(); i++) {
    c[i] = a[i]*b;
  }
  return c;
}

template <typename T1, typename T2>
inline std::vector<T1> operator * (const T2& b,
                                   const std::vector<T1>& a)
{
  return a*b;
}

template <typename T1, typename T2>
inline std::vector<T1>& operator *= (std::vector<T1>& a,
                                     const T2& b)
{
  for (unsigned int i=0; i<a.size(); i++) {
    a[i] *= b;
  }
  return a;
}

template <typename T1, typename T2>
inline std::vector<T1> operator / (const std::vector<T1>& a,
                                   const std::vector<T2>& b)
{
  if (a.size() != b.size()) {
    std::cerr << "/: incompatible sizes"  << std::endl;
    exit(1);
  }
  std::vector<T1> c(a.size());
  for (unsigned int i=0; i<a.size(); i++) {
    c[i] = a[i]/b[i];
  }
  return c;
}

template <typename T1, typename T2>
inline std::vector<T1>& operator /= (std::vector<T1>& a,
                                     const std::vector<T2>& b)
{
  if (a.size() != b.size()) {
    std::cerr << "/=: incompatible sizes"  << std::endl;
    exit(1);
  }
  for (unsigned int i=0; i<a.size(); i++) {
    a[i] /= b[i];
  }
  return a;
}

template <typename T1, typename T2>
inline std::vector<T1> operator / (const std::vector<T1>& a,
                                   const T2& b)
{
  std::vector<T1> c(a.size());
  for (unsigned int i=0; i<a.size(); i++) {
    c[i] = a[i]/b;
  }
  return c;
}

template <typename T1, typename T2>
inline std::vector<T1> operator / (const T2& b,
                                   const std::vector<T1>& a)
{
  std::vector<T1> c(a.size());
  for (unsigned int i=0; i<a.size(); i++) {
    c[i] = b/a[i];
  }
  return c;
}

template <typename T1, typename T2>
inline std::vector<T1>& operator /= (std::vector<T1>& a,
                                     const T2& b)
{
  for (unsigned int i=0; i<a.size(); i++) {
    a[i] /= b;
  }
  return a;
}

template <typename T1, typename T2>
inline std::vector<T1> operator + (const std::vector<T1>& a,
                                   const std::vector<T2>& b)
{
  if (a.size() != b.size()) {
    std::cerr << "+: incompatible sizes"  << std::endl;
    exit(1);
  }
  std::vector<T1> c(a.size());
  for (unsigned int i=0; i<a.size(); i++) {
    c[i] = a[i] + b[i];
  }
  return c;
}

template <typename T1, typename T2>
inline std::vector<T1>& operator += (std::vector<T1>& a,
                                     const std::vector<T2>& b)
{
  if (a.size() != b.size()) {
    std::cerr << "+=: incompatible sizes"  << std::endl;
    exit(1);
  }
  for (unsigned int i=0; i<a.size(); i++) {
    a[i] += b[i];
  }
  return a;
}


template <typename T1, typename T2>
inline std::vector<T1> operator + (const std::vector<T1>& a,
                                   const T2& b)
{
  std::vector<T1> c(a.size());
  for (unsigned int i=0; i<a.size(); i++) {
    c[i] = a[i] + b;
  }
  return c;
}

template <typename T1, typename T2>
inline std::vector<T1> operator + (const T2& b,
                                   const std::vector<T1>& a)
{
  return a+b;
}

template <typename T1, typename T2>
inline std::vector<T1>& operator += (std::vector<T1>& a,
                                     const T2& b)
{
  for (unsigned int i=0; i<a.size(); i++) {
    a[i] += b;
  }
  return a;
}


template <typename T1, typename T2>
inline std::vector<T1> operator - (const std::vector<T1>& a,
                                   const std::vector<T2>& b)
{
  if (a.size() != b.size()) {
    std::cerr << "-: incompatible sizes"  << std::endl;
    exit(1);
  }
  std::vector<T1> c(a.size());
  for (unsigned int i=0; i<a.size(); i++) {
    c[i] = a[i] - b[i];
  }
  return c;
}

template <typename T1, typename T2>
inline std::vector<T1>& operator -= (std::vector<T1>& a,
                                     const std::vector<T2>& b)
{
  if (a.size() != b.size()) {
    std::cerr << "/=: incompatible sizes"  << std::endl;
    exit(1);
  }
  for (unsigned int i=0; i<a.size(); i++) {
    a[i] -= b[i];
  }
  return a;
}

template <typename T1, typename T2>
inline std::vector<T1> operator - (const std::vector<T1>& a,
                                   const T2& b)
{
  std::vector<T1> c(a.size());
  for (unsigned int i=0; i<a.size(); i++) {
    c[i] = a[i] - b;
  }
  return c;
}

template <typename T1, typename T2>
inline std::vector<T1> operator - (const T2& b,
                                   const std::vector<T1>& a)
{
  return a-b;
}

template <typename T1, typename T2>
inline std::vector<T1>& operator -= (std::vector<T1>& a,
                                     const T2& b)
{
  for (unsigned int i=0; i<a.size(); i++) {
    a[i] -= b;
  }
  return a;
}

template <typename T>
inline std::vector<T> exp(const std::vector<T>& a)
{
  std::vector<T> b(a.size());
  for (unsigned int i=0; i<a.size(); i++) {
    b[i] = std::exp(a[i]);
  }
  return b;
}

inline double min(const std::vector<double>& a)
{
  double m = a[0];
  for (unsigned int i=1; i<a.size(); i++) {
    if (a[i] < m)
      m = a[i];
  }
  return m;
}

inline double max(const std::vector<double>& a)
{
  double m = a[0];
  for (unsigned int i=1; i<a.size(); i++) {
    if (m < a[i])
      m = a[i];
  }
  return m;
}

template <typename T>
inline std::vector<T> sum(const std::vector<T>& a)
{
  T total = 0;
  for (unsigned int i=0; i<a.size(); i++) {
      total += a[i];
  }
  return total;
}

template <typename T>
inline std::vector<T> abs(const std::vector<T>& a)
{
  std::vector<T> b(a.size());
  for (unsigned int i=0; i<a.size(); i++) {
    b[i] = std::abs(a[i]);
  }
  return b;
}

template <typename T>
inline boost::dynamic_bitset<> isin(const std::vector<T>& a,
                                  const std::vector<T>& b)
{
    boost::dynamic_bitset<> in (a.size());
    for (unsigned i=0; i<a.size(); i++) {
        for (auto elm: b) {
            in[i] |= a[i]==elm;
        }
    }
    return in;
}
}

#endif /* defined(__Model_Vecops__) */
