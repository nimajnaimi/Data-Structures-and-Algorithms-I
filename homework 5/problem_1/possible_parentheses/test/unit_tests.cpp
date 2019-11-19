#include "gtest/gtest.h"
#include "possible_parentheses.h"

void showResult(std::list<std::string> & result) {
    for (std::list<std::string>::iterator i = result.begin(); i!=result.end(); ++i) {
        printf("%s\n", (*i).c_str());
    }
};

TEST(test_recursive, 0) {
    std::list<std::string> result;
    possibleParenthesis(0, result);
    ASSERT_EQ(result.size(), 0);
}

TEST(test_recursive, 1) {
    std::list<std::string> result;
    possibleParenthesis(1, result);
    ASSERT_EQ(result.size(), 1);
    result.remove("{}");
    ASSERT_EQ(result.size(), 0);
}

TEST(test_recursive, 2) {
    std::list<std::string> result;
    possibleParenthesis(2, result);
    ASSERT_EQ(result.size(), 2);
    std::string results[2] = {"{}{}", "{{}}"};
    for (int i = 2; i >= 0; i--) {
        result.remove(results[i]);
        ASSERT_EQ(result.size(), i);
    }
}

TEST(test_recursive, 3) {
    std::list<std::string> result;
    possibleParenthesis(3, result);
    ASSERT_EQ(result.size(), 5);
    std::string results[5] = {"{}{}{}", "{}{{}}", "{{}}{}", "{{}{}}", "{{{}}}"};
    for (int i = 4; i >= 0; i--) {
        result.remove(results[i]);
        ASSERT_EQ(result.size(), i);
    }
}
