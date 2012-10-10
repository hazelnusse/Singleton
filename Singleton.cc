#include <cstdint>
#include "Singleton.h"

Singleton * Singleton::instance_ = 0;

Singleton::Singleton()
{

}

Singleton::~Singleton()
{

}

Singleton & Singleton::Instance()
{
  static uint8_t allocation[sizeof(Singleton)];

  if (instance_ == 0)
    instance_ = new (allocation) Singleton;

  return * instance_;
} // Instance

void * Singleton::operator new(std::size_t, void * location)
{
  return location;
} // operator new()
