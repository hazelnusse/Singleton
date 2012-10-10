#include <cstdint>
#include "Singleton.h"

template <typename T>
T * Singleton<T>::instance_ = 0;

template <typename T>
Singleton<T>::Singleton()
{

}

template <typename T>
Singleton<T>::~Singleton()
{
  instance_ = 0;
}

template <typename T>
inline T & Singleton<T>::Instance()
{
  static uint8_t allocation[sizeof(T)];

  if (instance_ == 0)
    instance_ = new (allocation) T;

  return * instance_;
}

template <typename T>
inline void * Singleton<T>::operator new(std::size_t, void * location)
{
  return location;
}
