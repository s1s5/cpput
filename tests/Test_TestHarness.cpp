#include "../TestHarness.hpp"
#include <string>
#include <math.h>

// ----------------------------------------------------------------------------
// ASSERT_TRUE

TEST(macro_ASSERT_TRUE, simple_expressions_equal_true)
{
  ASSERT_TRUE(true);
  ASSERT_TRUE(!false);
  ASSERT_TRUE(1 == 1);
  ASSERT_TRUE(2 != 5);
  ASSERT_TRUE(1 < 10);
  ASSERT_TRUE(100 > 2.34);
  ASSERT_TRUE(10 > 2);
  ASSERT_TRUE(1.123 < 3.14);
}

// ----------------------------------------------------------------------------
// ASSERT_FALSE

TEST(macro_ASSERT_FALSE, simple_expressions_equal_false)
{
  ASSERT_FALSE(false);
  ASSERT_FALSE(!true);
  ASSERT_FALSE(1 == 2);
  ASSERT_FALSE(2 == 5);
  ASSERT_FALSE(1 > 10);
  ASSERT_FALSE(100 < 2.34);
  ASSERT_FALSE(10 < 2);
  ASSERT_FALSE(1.123 > 3.14);
}

// ----------------------------------------------------------------------------
// ASSERT_EQ

TEST(macro_ASSERT_EQ, equality_of_simple_types)
{
  ASSERT_EQ(42, 42);
  ASSERT_EQ(99, 'c');
}

TEST(macro_ASSERT_EQ, string_objects_test_out_equal)
{
  std::string s1;
  std::string s2;
  ASSERT_EQ(s1, s1);
}

// ----------------------------------------------------------------------------
// ASSERT_NEQ

TEST(macro_ASSERT_NEQ, string_objects_test_out_not_equal)
{
  std::string s1("foo");
  std::string s2("bar");
  ASSERT_NEQ(s1, s2);
}

// ----------------------------------------------------------------------------
// ASSERT_STREQ

TEST(macro_ASSERT_STREQ, conversion_to_string_objects_tests_out_equal)
{
  ASSERT_STREQ("murrekatt", "murrekatt");
}

// ----------------------------------------------------------------------------
// ASSERT_NEAR

TEST(macro_ASSERT_NEAR, floats_test_out_to_equal_within_given_epsilon)
{
  ASSERT_NEAR(3.1415, M_PI, 0.0001);
}

// ----------------------------------------------------------------------------
// Fixtures

namespace
{

struct Magic
{
  int value() const { return 42; }
};

struct MagicFixture
{
  Magic magic_;
};

} // namespace

TEST_F(MagicFixture, magic_value_is_42)
{
  ASSERT_EQ(42, magic_.value());
}

// ----------------------------------------------------------------------------
// Internals

TEST(TextResultWriter, initial_number_of_failures_are_zero)
{
  cpput::TextResultWriter writer;
  ASSERT_EQ(0, writer.getNumberOfFailures());
}

TEST(TextResultWriter, end_test_with_success_does_not_increment_failures)
{
  cpput::TextResultWriter writer;
  writer.endTest(true);
  ASSERT_EQ(0, writer.getNumberOfFailures());
}

TEST(TextResultWriter, end_test_with_failure_does_not_increment_failures)
{
  cpput::TextResultWriter writer;
  writer.endTest(false);
  ASSERT_EQ(0, writer.getNumberOfFailures());
}

TEST(XmlResultWriter, initial_number_of_failures_are_zero)
{
  cpput::XmlResultWriter writer;
  ASSERT_EQ(0, writer.getNumberOfFailures());
}
