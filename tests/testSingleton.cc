#include "Singleton.h"
#include "gtest/gtest.h"

TEST(SingletonTest, InstanceUniqueness)
{
  Singleton & a = Singleton::Instance();
  Singleton & b = Singleton::Instance();
  EXPECT_EQ(&a, &b);
}

