#include <gtest/gtest.h>

#include <string>
#include <tuple>

auto getPerson() {
  const std::string name = "Petia";
  const std::string secondName = "Ivanoff";
  const std::size_t age = 23;
  const std::string department = "Sale";
  return std::make_tuple(name, secondName, age, department);
}

template <typename... T>
constexpr std::tuple<T&...> custom_tie(T&... args) {
  return std::tuple<T&...>(args...);
}

TEST(TestCustomTie, BasicAssertions) {
  std::string name, secondName, department;
  std::size_t age;
  custom_tie(name, secondName, age, department) = getPerson();

  EXPECT_STREQ(name.c_str(), "Petia");
  EXPECT_STREQ(secondName.c_str(), "Ivanoff");
  EXPECT_STREQ(department.c_str(), "Sale");
  EXPECT_EQ(age, 23);
}