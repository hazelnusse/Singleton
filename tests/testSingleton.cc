#include "Singleton.h"
#include "gtest/gtest.h"

class SpecificSingleton : public Singleton<SpecificSingleton>
{
 public:
  SpecificSingleton() : Data_(42) {}
  ~SpecificSingleton() {}
 private:
  int Data_;
};

class foo {
 public:
  foo() : MoreData_(0) {}
  int data() { return MoreData_; }
  void data(int d) { MoreData_ = d; }
 protected:
  int MoreData_;
};

class bar : public foo, public Singleton<bar>
{
 public:
  bar() : OtherData_(1) {}
  int otherdata() { return OtherData_; }
  void otherdata(int d) { OtherData_ = d; }
 private:
  int OtherData_;
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

TEST(InheritanceTest, InstanceUniqueness)
{
  bar & a = bar::Instance();
  bar & b = bar::Instance();

  EXPECT_EQ(&a, &b);
  EXPECT_EQ(a.data(), 0);
  EXPECT_EQ(a.otherdata(), 1);
  EXPECT_EQ(a.data(), b.data());
  EXPECT_EQ(a.otherdata(), b.otherdata());

  // Change data in parent class
  a.data(1);
  EXPECT_EQ(a.data(), 1);
  EXPECT_EQ(b.data(), 1);

  // Change data in sub-class
  a.otherdata(2);
  EXPECT_EQ(a.otherdata(), 2);
  EXPECT_EQ(b.otherdata(), 2);
}

TEST(InheritanceTest, InstanceSize)
{
  bar & a = bar::Instance();
  // foo has an int, bar has an int
  EXPECT_EQ(sizeof(a), sizeof(int)*2);
}
