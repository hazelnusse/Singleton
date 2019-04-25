#pragma once

#include <cstdint>

template <typename T>
class Singleton {
 public:
  static T & Instance();

 protected:
  Singleton();
  ~Singleton();

 private:
  T & operator=(const T &) = delete;
  Singleton(const T &) = delete;

  static void * operator new(std::size_t, void * location);
  static T * instance_;
};

#include "Singleton_priv.h"
