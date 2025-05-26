
#include <string>

#include <gtest/gtest.h>

#include "funkcje.h"

using namespace std;

namespace
{

TEST(ZamienTest, PodstawoweZamiany) {
    EXPECT_EQ(zamien("margaryna", "a", "aa"), "maargaarynaa");
    EXPECT_EQ(zamien("margaryna", "a", ""), "mrgryn");
    EXPECT_EQ(zamien("margaryna", "ar", "x"), "mxgxyna");
}

TEST(ZamienTest, BrakDopasowania) {
    EXPECT_EQ(zamien("margaryna", "x", "yy"), "margaryna");
}

TEST(ZamienTest, PustyStringWejsciowy) {
    EXPECT_EQ(zamien("", "a", "b"), "");
}

TEST(ZamienTest, PustyWzorzec) {
    EXPECT_EQ(zamien("margaryna", "", "x"), "margaryna");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

} // namespace

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}