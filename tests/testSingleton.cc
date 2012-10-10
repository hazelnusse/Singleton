#include "Singleton.h"
#include "gtest/gtest.h"

class SpecificSingleton : public Singleton<SpecificSingleton>
{
 public:
  SpecificSingleton() : someData_(42) {}
  ~SpecificSingleton() {}
 private:
  int someData_;
};

TEST(SpecificSingletonTest, InstanceUniqueness)
{
  SpecificSingleton & a = SpecificSingleton::Instance();
  SpecificSingleton & b = SpecificSingleton::Instance();
  EXPECT_EQ(&a, &b);
}

TEST(SpecificSingletonTest, InstanceSize)
{
  EXPECT_EQ(sizeof(SpecificSingleton::Instance()), sizeof(int));
}

