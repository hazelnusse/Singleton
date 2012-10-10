#ifndef SINGLETON_H
#define SINGLETON_H

#include <cstdint>

class Singleton {
 public:
  static Singleton & Instance();

 private:
  Singleton();
  ~Singleton();
  Singleton & operator=(const Singleton &) = delete;
  Singleton(const Singleton &) = delete;

  static void * operator new(std::size_t, void * location);
  static Singleton * instance_;
};
#endif
