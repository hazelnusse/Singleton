#include "Singleton.h"
#include "gtest/gtest.h"

class SpecificSingleton : public Singleton<SpecificSingleton>
{
  friend class Singleton<SpecificSingleton>;
 public:
  int Data() const { return Data_; }
 private:
  SpecificSingleton() : Data_(42) {}
  ~SpecificSingleton() {}
  int Data_;
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
