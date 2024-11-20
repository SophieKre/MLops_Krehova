#include "min_max_scaling.h"
#include <gtest/gtest.h>

TEST(MinMaxScalingTests, MinMaxScaling) {
  std::vector<double> input = {1.0, 2.0, 3.0, 4.0};
    std::vector<double> expected = {0.0, 0.3333333333333333, 0.6666666666666666, 1.0};

    auto result = MinMaxScaling::MMS(input);

    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        EXPECT_NEAR(result[i], expected[i], 1e-9);
    }
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
