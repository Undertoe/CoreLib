#include "gtest/gtest.h"
#include "container_helpers.hh"

#include <map>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <array>
#include <iostream>

TEST(CollectionHelpers, Vector_HasRandomAccess)
{
    std::vector<int> vector = {1, 2, 3};
    std::deque<int> deque = {1, 2, 3};
    std::forward_list<int> forwardlist = {1, 2, 3};
    std::list<int> list = {1, 2, 3};
    std::array<int, 3> array = {{1, 2, 3}};
    EXPECT_TRUE(Terryn::HasRandomAccess(vector));
    EXPECT_TRUE(Terryn::HasRandomAccess(deque));
    EXPECT_TRUE(Terryn::HasRandomAccess(array));
    EXPECT_TRUE(Terryn::DoesNotHaveRandomAccess(forwardlist));
    EXPECT_TRUE(Terryn::DoesNotHaveRandomAccess(list));
}

/// GetValueAtIndex -> std::optional<CollectionValueType>
TEST(CollectionHelpers, Vector_GetValueAtIndex)
{
    std::vector<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 0), 0);
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 9), 9);
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 16), 2);
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 20), std::nullopt);
}
TEST(CollectionHelpers, Deque_GetValueAtIndex)
{
    std::deque<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 0), 0);
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 9), 9);
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 16), 2);
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 20), std::nullopt);
}
TEST(CollectionHelpers, ForwardList_GetValueAtIndex)
{
    std::forward_list<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 0), 0);
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 9), 9);
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 16), 2);
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 20), std::nullopt);
}
TEST(CollectionHelpers, List_GetValueAtIndex)
{
    std::list<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 0), 0);
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 9), 9);
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 16), 2);
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 20), std::nullopt);
}
TEST(CollectionHelpers, Array_GetValueAtIndex)
{
    std::array<uint32_t, 19> testVals = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 0), 0);
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 9), 9);
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 16), 2);
    EXPECT_EQ(Terryn::GetValueAtIndex(testVals, 20), std::nullopt);
}

/// Count -> size_t
TEST(CollectionHelpers, Vector_Count)
{
    std::vector<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    EXPECT_EQ(Terryn::Count(testVals), 19);
}
TEST(CollectionHelpers, Deque_Count)
{
    std::deque<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    EXPECT_EQ(Terryn::Count(testVals), 19);
}
TEST(CollectionHelpers, ForwardList_Count)
{
    std::forward_list<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    EXPECT_EQ(Terryn::Count(testVals), 19);
}
TEST(CollectionHelpers, List_Count)
{
    std::list<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    EXPECT_EQ(Terryn::Count(testVals), 19);
}
TEST(CollectionHelpers, Array_Count)
{
    std::array<uint32_t, 19> testVals = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    EXPECT_EQ(Terryn::Count(testVals), 19);
}

/// reset colleciton
TEST(CollectionHelpers, Vector_ResetCollection)
{
    std::vector<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    Terryn::ResetCollection(testVals);
    EXPECT_EQ(Terryn::Count(testVals), 0);
}
TEST(CollectionHelpers, Deque_ResetCollection)
{
    std::deque<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    Terryn::ResetCollection(testVals);
    EXPECT_EQ(Terryn::Count(testVals), 0);
}
TEST(CollectionHelpers, Forward_list_ResetCollection)
{
    std::forward_list<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    Terryn::ResetCollection(testVals);
    EXPECT_EQ(Terryn::Count(testVals), 0);
}
TEST(CollectionHelpers, List_ResetCollection)
{
    std::list<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    Terryn::ResetCollection(testVals);
    EXPECT_EQ(Terryn::Count(testVals), 0);
}
TEST(CollectionHelpers, Array_ResetCollection)
{
    std::array<uint32_t, 19> testVals = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    Terryn::ResetCollection(testVals);
    EXPECT_EQ(Terryn::Count(testVals), 19);
}


///Terryn::Contains -> bool
TEST(CollectionHelpers, Vector_Contains)
{
    std::vector<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    std::vector<std::string> testString = {"AA", "BB", "CC", "DD", "EE"};

    EXPECT_TRUE(Terryn::Contains(testVals, 9));
    EXPECT_FALSE(Terryn::Contains(testVals, 10));
    EXPECT_NO_THROW(Terryn::Contains(testString, std::string("Z")));
    EXPECT_TRUE(Terryn::Contains(testString, std::string("BB")));

}
TEST(CollectionHelpers, Deque_Contains)
{
    std::deque<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    std::deque<std::string> testString = {"AA", "BB", "CC", "DD", "EE"};

    EXPECT_TRUE(Terryn::Contains(testVals, 9));
    EXPECT_FALSE(Terryn::Contains(testVals, 10));
    EXPECT_NO_THROW(Terryn::Contains(testString, std::string("Z")));
    EXPECT_TRUE(Terryn::Contains(testString, std::string("BB")));

}
TEST(CollectionHelpers, ForwardList_Contains)
{
    std::forward_list<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    std::forward_list<std::string> testString = {"AA", "BB", "CC", "DD", "EE"};

    EXPECT_TRUE(Terryn::Contains(testVals, 9));
    EXPECT_FALSE(Terryn::Contains(testVals, 10));
    EXPECT_NO_THROW(Terryn::Contains(testString, std::string("Z")));
    EXPECT_TRUE(Terryn::Contains(testString, std::string("BB")));

}
TEST(CollectionHelpers, List_Contains)
{
    std::list<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    std::list<std::string> testString = {"AA", "BB", "CC", "DD", "EE"};

    EXPECT_TRUE(Terryn::Contains(testVals, 9));
    EXPECT_FALSE(Terryn::Contains(testVals, 10));
    EXPECT_NO_THROW(Terryn::Contains(testString, std::string("Z")));
    EXPECT_TRUE(Terryn::Contains(testString, std::string("BB")));
}

TEST(CollectionHelpers, Array_Contains)
{
    std::array<uint32_t, 19> testVals = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::array<std::string, 5> testString = {{"AA", "BB", "CC", "DD", "EE"}};

    EXPECT_TRUE(Terryn::Contains(testVals, 9));
    EXPECT_FALSE(Terryn::Contains(testVals, 10));
    EXPECT_NO_THROW(Terryn::Contains(testString, std::string("Z")));
    EXPECT_TRUE(Terryn::Contains(testString, std::string("BB")));

}




/// these are just compile time tests to force the compiler to check that
/// the types are going to be ok
TEST(CollectionHelpers, Vector_Average)
{
    std::vector<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    auto avg = Terryn::Avg(testVals);
    //    std::cout << avg << std::endl;
    EXPECT_NO_THROW(Terryn::Avg(testVals));
    EXPECT_EQ(avg, 4);
}
TEST(CollectionHelpers, Deque_Average)
{
    std::deque<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    auto avg = Terryn::Avg(testVals);
    EXPECT_NO_THROW(Terryn::Avg(testVals));
    EXPECT_EQ(avg, 4);
}
TEST(CollectionHelpers, Forward_List_Average)
{
    std::forward_list<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    auto avg = Terryn::Avg(testVals);
    EXPECT_NO_THROW(Terryn::Avg(testVals));
    EXPECT_EQ(avg, 4);
}
TEST(CollectionHelpers, List_Average)
{
    std::list<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    auto avg = Terryn::Avg(testVals);
    EXPECT_NO_THROW(Terryn::Avg(testVals));
    EXPECT_EQ(avg, 4);
}
TEST(CollectionHelpers, Array_Average)
{
    std::array<uint32_t, 19> testVals = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    auto avg = Terryn::Avg(testVals);
    EXPECT_NO_THROW(Terryn::Avg(testVals));
    EXPECT_EQ(avg, 4);
}




/// LargestN algorithm.  Collects largest N values of a collection
TEST(CollectionHelpers, Vector_LargestN)
{
    std::vector<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    std::vector<uint32_t> largestN;
    EXPECT_NO_THROW(Terryn::LargestN(testVals, largestN, 3));
    std::cout << largestN.at(0) << " " << largestN.at(1) << " " << largestN.at(2) << std::endl;
    EXPECT_TRUE((largestN.at(0) == 9));
    EXPECT_TRUE((largestN.at(1) == 8));
    EXPECT_TRUE((largestN.at(2) == 7));
    EXPECT_TRUE(largestN.size() == 3);


    std::vector<uint32_t> returnedN;

    EXPECT_NO_THROW(returnedN = Terryn::LargestN(testVals, 4));
    std::cout << "executed successfully" << std::endl;
    EXPECT_TRUE(returnedN.size() == 4);
    EXPECT_TRUE((returnedN.at(0) == 9));
    EXPECT_TRUE((returnedN.at(1) == 8));
    EXPECT_TRUE((returnedN.at(2) == 7));
    EXPECT_TRUE((returnedN.at(3) == 6));
}
TEST(CollectionHelpers, ForwardList_LargestN)
{
    std::forward_list<uint32_t> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    std::forward_list<uint32_t> largestN;
    EXPECT_NO_THROW(Terryn::LargestN(testVals, largestN, 3));
    EXPECT_TRUE(Terryn::Count(largestN) == 3);
    EXPECT_TRUE(Terryn::GetValueAtIndex(largestN, 0) == 9);
    EXPECT_TRUE(Terryn::GetValueAtIndex(largestN, 1) == 8);
    EXPECT_TRUE(Terryn::GetValueAtIndex(largestN, 2) == 7);
    //    EXPECT_TRUE((largestN.at(0) == 9));
    //    EXPECT_TRUE((largestN.at(1) == 8));
    //    EXPECT_TRUE((largestN.at(2) == 7));
    //    EXPECT_TRUE(largestN.size() == 3);


    std::forward_list<uint32_t> returnedN;

    EXPECT_NO_THROW(returnedN = Terryn::LargestN(testVals, 4));
    EXPECT_TRUE(Terryn::Count(returnedN) == 4);
    EXPECT_TRUE(Terryn::GetValueAtIndex(returnedN, 0) == 9);
    EXPECT_TRUE(Terryn::GetValueAtIndex(returnedN, 1) == 8);
    EXPECT_TRUE(Terryn::GetValueAtIndex(returnedN, 2) == 7);
    EXPECT_TRUE(Terryn::GetValueAtIndex(returnedN, 3) == 6);
}
TEST(CollectionHelpers, Array_LargestN)
{
    std::array<uint32_t, 19> testVals = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0};
    std::array<uint32_t, 3> largestN;
    EXPECT_NO_THROW(Terryn::LargestN(testVals, largestN, 3));
    EXPECT_TRUE((largestN.at(0) == 9));
    EXPECT_TRUE((largestN.at(1) == 8));
    EXPECT_TRUE((largestN.at(2) == 7));
    EXPECT_TRUE(largestN.size() == 3);


    //    std::array<uint32_t, 4> returnedN;

    //    EXPECT_NO_THROW(returnedN = Terryn::LargestN(testVals, 4));
    //    std::cout << "executed successfully" << std::endl;
    //    EXPECT_TRUE(returnedN.size() == 4);
    //    EXPECT_TRUE((returnedN.at(0) == 9));
    //    EXPECT_TRUE((returnedN.at(1) == 8));
    //    EXPECT_TRUE((returnedN.at(2) == 7));
    //    EXPECT_TRUE((returnedN.at(3) == 6));
}



/// CompareCollections
struct ComparableTest
{
    bool ReturnsTrue;
};

inline bool operator != (const ComparableTest &one, const ComparableTest &two)
{
    return one.ReturnsTrue != two.ReturnsTrue;
}

inline bool operator == (const ComparableTest &one, const ComparableTest &two)
{
    return one.ReturnsTrue == two.ReturnsTrue;
}

TEST(CollectionHelpers, Vectors_CompareCollections)
{
    std::vector<std::string> testVals = {{"AA", "BB", "CC", "DD", "EE"}};
    std::vector<std::string> is_equal = {{"AA", "BB", "CC", "DD", "EE"}};
    std::vector<std::string> not_equal = {{"AA", "BBC", "CC", "DD", "EE"}};

    EXPECT_TRUE(Terryn::CompareCollections(testVals, is_equal));
    EXPECT_FALSE(Terryn::CompareCollections(testVals, not_equal));

    std::vector<uint32_t> testTwoVals = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::vector<uint32_t> is_equal_two = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::vector<uint32_t> is_not_equal_two = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 1, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};

    EXPECT_TRUE(Terryn::CompareCollections(testTwoVals, is_equal_two));
    EXPECT_FALSE(Terryn::CompareCollections(testTwoVals, is_not_equal_two));

    std::vector<ComparableTest> ComparableValues = {{true}, {true}, {false}, {true}, {false}};
    std::vector<ComparableTest> ComparableValues_equal = {{true}, {true}, {false}, {true}, {false}};
    std::vector<ComparableTest> ComparableValues_not_equal = {{true}, {true}, {false}, {false}, {false}};

    EXPECT_TRUE(Terryn::CompareCollections(ComparableValues, ComparableValues_equal));
    EXPECT_FALSE(Terryn::CompareCollections(ComparableValues, ComparableValues_not_equal));

    std::vector<ComparableTest> EqualSizeTest = {{true}, {true}, {false}, {true}, {false}};
    std::vector<ComparableTest> EqualSizeTest_equal = {{true}, {true}, {false}, {true}, {false}};
    std::vector<ComparableTest> EqualSizeTest_not_equal = {{true}, {false}, {true}, {false}};

    EXPECT_TRUE(Terryn::CompareCollections(EqualSizeTest, EqualSizeTest_equal));
    EXPECT_FALSE(Terryn::CompareCollections(EqualSizeTest, EqualSizeTest_not_equal));
}

TEST(CollectionHelpers, Vectors_Deque)
{
    std::deque<std::string> testVals = {{"AA", "BB", "CC", "DD", "EE"}};
    std::deque<std::string> is_equal = {{"AA", "BB", "CC", "DD", "EE"}};
    std::deque<std::string> not_equal = {{"AA", "BBC", "CC", "DD", "EE"}};

    EXPECT_TRUE(Terryn::CompareCollections(testVals, is_equal));
    EXPECT_FALSE(Terryn::CompareCollections(testVals, not_equal));

    std::deque<uint32_t> testTwoVals = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::deque<uint32_t> is_equal_two = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::deque<uint32_t> is_not_equal_two = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 1, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};

    EXPECT_TRUE(Terryn::CompareCollections(testTwoVals, is_equal_two));
    EXPECT_FALSE(Terryn::CompareCollections(testTwoVals, is_not_equal_two));

    std::deque<ComparableTest> ComparableValues = {{true}, {true}, {false}, {true}, {false}};
    std::deque<ComparableTest> ComparableValues_equal = {{true}, {true}, {false}, {true}, {false}};
    std::deque<ComparableTest> ComparableValues_not_equal = {{true}, {true}, {false}, {false}, {false}};

    EXPECT_TRUE(Terryn::CompareCollections(ComparableValues, ComparableValues_equal));
    EXPECT_FALSE(Terryn::CompareCollections(ComparableValues, ComparableValues_not_equal));

    std::deque<ComparableTest> EqualSizeTest = {{true}, {true}, {false}, {true}, {false}};
    std::deque<ComparableTest> EqualSizeTest_equal = {{true}, {true}, {false}, {true}, {false}};
    std::deque<ComparableTest> EqualSizeTest_not_equal = {{true}, {false}, {true}, {false}};

    EXPECT_TRUE(Terryn::CompareCollections(EqualSizeTest, EqualSizeTest_equal));
    EXPECT_FALSE(Terryn::CompareCollections(EqualSizeTest, EqualSizeTest_not_equal));
}

TEST(CollectionHelpers, forward_list_CompareCollections)
{

    std::forward_list<uint32_t> testTwoVals = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::forward_list<uint32_t> is_equal_two = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::forward_list<uint32_t> is_not_equal_two = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 1, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};

    EXPECT_TRUE(Terryn::CompareCollections(testTwoVals, is_equal_two));
    EXPECT_FALSE(Terryn::CompareCollections(testTwoVals, is_not_equal_two));

    std::forward_list<std::string> testVals = {{"AA", "BB", "CC", "DD", "EE"}};
    std::forward_list<std::string> is_equal = {{"AA", "BB", "CC", "DD", "EE"}};
    std::forward_list<std::string> not_equal = {{"AA", "BBC", "CC", "DD", "EE"}};

    EXPECT_TRUE(Terryn::CompareCollections(testVals, is_equal));
    EXPECT_FALSE(Terryn::CompareCollections(testVals, not_equal));

    std::forward_list<ComparableTest> ComparableValues = {{true}, {true}, {false}, {true}, {false}};
    std::forward_list<ComparableTest> ComparableValues_equal = {{true}, {true}, {false}, {true}, {false}};
    std::forward_list<ComparableTest> ComparableValues_not_equal = {{true}, {true}, {false}, {false}, {false}};

    EXPECT_TRUE(Terryn::CompareCollections(ComparableValues, ComparableValues_equal));
    EXPECT_FALSE(Terryn::CompareCollections(ComparableValues, ComparableValues_not_equal));

    std::forward_list<ComparableTest> EqualSizeTest = {{true}, {true}, {false}, {true}, {false}};
    std::forward_list<ComparableTest> EqualSizeTest_equal = {{true}, {true}, {false}, {true}, {false}};
    std::forward_list<ComparableTest> EqualSizeTest_not_equal = {{true}, {false}, {true}, {false}};

    EXPECT_TRUE(Terryn::CompareCollections(EqualSizeTest, EqualSizeTest_equal));
    EXPECT_FALSE(Terryn::CompareCollections(EqualSizeTest, EqualSizeTest_not_equal));
}

TEST(CollectionHelpers, List_CompareCollections)
{
    std::list<std::string> testVals = {{"AA", "BB", "CC", "DD", "EE"}};
    std::list<std::string> is_equal = {{"AA", "BB", "CC", "DD", "EE"}};
    std::list<std::string> not_equal = {{"AA", "BBC", "CC", "DD", "EE"}};

    EXPECT_TRUE(Terryn::CompareCollections(testVals, is_equal));
    EXPECT_FALSE(Terryn::CompareCollections(testVals, not_equal));

    std::list<uint32_t> testTwoVals = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::list<uint32_t> is_equal_two = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::list<uint32_t> is_not_equal_two = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 1, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};

    EXPECT_TRUE(Terryn::CompareCollections(testTwoVals, is_equal_two));
    EXPECT_FALSE(Terryn::CompareCollections(testTwoVals, is_not_equal_two));

    std::list<ComparableTest> ComparableValues = {{true}, {true}, {false}, {true}, {false}};
    std::list<ComparableTest> ComparableValues_equal = {{true}, {true}, {false}, {true}, {false}};
    std::list<ComparableTest> ComparableValues_not_equal = {{true}, {true}, {false}, {false}, {false}};

    EXPECT_TRUE(Terryn::CompareCollections(ComparableValues, ComparableValues_equal));
    EXPECT_FALSE(Terryn::CompareCollections(ComparableValues, ComparableValues_not_equal));

    std::list<ComparableTest> EqualSizeTest = {{true}, {true}, {false}, {true}, {false}};
    std::list<ComparableTest> EqualSizeTest_equal = {{true}, {true}, {false}, {true}, {false}};
    std::list<ComparableTest> EqualSizeTest_not_equal = {{true}, {false}, {true}, {false}};

    EXPECT_TRUE(Terryn::CompareCollections(EqualSizeTest, EqualSizeTest_equal));
    EXPECT_FALSE(Terryn::CompareCollections(EqualSizeTest, EqualSizeTest_not_equal));
}

TEST(CollectionHelpers, array_CompareCollections)
{
    std::array<std::string, 5> testVals = {{"AA", "BB", "CC", "DD", "EE"}};
    std::array<std::string, 5> is_equal = {{"AA", "BB", "CC", "DD", "EE"}};
    std::array<std::string, 5> not_equal = {{"AA", "BBC", "CC", "DD", "EE"}};

    EXPECT_TRUE(Terryn::CompareCollections(testVals, is_equal));
    EXPECT_FALSE(Terryn::CompareCollections(testVals, not_equal));

    std::array<uint32_t, 19> testTwoVals = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::array<uint32_t, 19> is_equal_two = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::array<uint32_t, 19> is_not_equal_two = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 1, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};

    EXPECT_TRUE(Terryn::CompareCollections(testTwoVals, is_equal_two));
    EXPECT_FALSE(Terryn::CompareCollections(testTwoVals, is_not_equal_two));

    std::array<ComparableTest, 5> ComparableValues = {{{true}, {true}, {false}, {true}, {false}}};
    std::array<ComparableTest, 5> ComparableValues_equal = {{{true}, {true}, {false}, {true}, {false}}};
    std::array<ComparableTest, 5> ComparableValues_not_equal = {{{true}, {true}, {false}, {false}, {false}}};

    EXPECT_TRUE(Terryn::CompareCollections(ComparableValues, ComparableValues_equal));
    EXPECT_FALSE(Terryn::CompareCollections(ComparableValues, ComparableValues_not_equal));

    std::array<ComparableTest, 5> EqualSizeTest = {{{true}, {true}, {false}, {true}, {false}}};
    std::array<ComparableTest, 5> EqualSizeTest_equal = {{{true}, {true}, {false}, {true}, {false}}};
    std::array<ComparableTest, 4> EqualSizeTest_not_equal = {{{true}, {false}, {true}, {false}}};

    EXPECT_TRUE(Terryn::CompareCollections(EqualSizeTest, EqualSizeTest_equal));
    EXPECT_FALSE(Terryn::CompareCollections(EqualSizeTest, EqualSizeTest_not_equal));
}


/// IndexOf
TEST(CollectionHelpers, Vector_IndexOf)
{
    std::vector<std::string> stringVals = {{"AA", "BB", "CC", "DD", "EE"}};
    std::vector<uint32_t> intVals = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::vector<ComparableTest> ComparableValues = {{true}, {true}, {true}, {true}, {true}};

    std::string FoundString = "AA";
    std::string InvalidString = "AF";

    uint32_t FoundUInt = 8;
    uint32_t InvalidUInt = 10;

    ComparableTest FoundComparable = {true};
    ComparableTest InvlaidComparable = {false};

    EXPECT_TRUE(Terryn::FirstIndexOf(stringVals, FoundString) == 0);
    EXPECT_TRUE(Terryn::FirstIndexOf(stringVals, InvalidString) == std::nullopt);

    EXPECT_TRUE(Terryn::FirstIndexOf(intVals, FoundUInt) == 8);
    EXPECT_TRUE(Terryn::FirstIndexOf(intVals, InvalidUInt) == std::nullopt);

    EXPECT_TRUE(Terryn::FirstIndexOf(ComparableValues, FoundComparable) == 0);
    EXPECT_TRUE(Terryn::FirstIndexOf(ComparableValues, InvlaidComparable) == std::nullopt);
}

TEST(CollectionHelpers, Deque_IndexOf)
{
    std::deque<std::string> stringVals = {{"AA", "BB", "CC", "DD", "EE"}};
    std::deque<uint32_t> intVals = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::deque<ComparableTest> ComparableValues = {{true}, {true}, {true}, {true}, {true}};

    std::string FoundString = "AA";
    std::string InvalidString = "AF";

    uint32_t FoundUInt = 8;
    uint32_t InvalidUInt = 10;

    ComparableTest FoundComparable = {true};
    ComparableTest InvlaidComparable = {false};

    EXPECT_TRUE(Terryn::FirstIndexOf(stringVals, FoundString) == 0);
    EXPECT_TRUE(Terryn::FirstIndexOf(stringVals, InvalidString) == std::nullopt);

    EXPECT_TRUE(Terryn::FirstIndexOf(intVals, FoundUInt) == 8);
    EXPECT_TRUE(Terryn::FirstIndexOf(intVals, InvalidUInt) == std::nullopt);

    EXPECT_TRUE(Terryn::FirstIndexOf(ComparableValues, FoundComparable) == 0);
    EXPECT_TRUE(Terryn::FirstIndexOf(ComparableValues, InvlaidComparable) == std::nullopt);
}

TEST(CollectionHelpers, ForwardList_IndexOf)
{
    std::forward_list<std::string> stringVals = {{"AA", "BB", "CC", "DD", "EE"}};
    std::forward_list<uint32_t> intVals = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::forward_list<ComparableTest> ComparableValues = {{true}, {true}, {true}, {true}, {true}};

    std::string FoundString = "AA";
    std::string InvalidString = "AF";

    uint32_t FoundUInt = 8;
    uint32_t InvalidUInt = 10;

    ComparableTest FoundComparable = {true};
    ComparableTest InvlaidComparable = {false};

    EXPECT_TRUE(Terryn::FirstIndexOf(stringVals, FoundString) == 0);
    EXPECT_TRUE(Terryn::FirstIndexOf(stringVals, InvalidString) == std::nullopt);

    EXPECT_TRUE(Terryn::FirstIndexOf(intVals, FoundUInt) == 8);
    EXPECT_TRUE(Terryn::FirstIndexOf(intVals, InvalidUInt) == std::nullopt);

    EXPECT_TRUE(Terryn::FirstIndexOf(ComparableValues, FoundComparable) == 0);
    EXPECT_TRUE(Terryn::FirstIndexOf(ComparableValues, InvlaidComparable) == std::nullopt);
}

TEST(CollectionHelpers, List_IndexOf)
{
    std::list<std::string> stringVals = {{"AA", "BB", "CC", "DD", "EE"}};
    std::list<uint32_t> intVals = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::list<ComparableTest> ComparableValues = {{true}, {true}, {true}, {true}, {true}};

    std::string FoundString = "AA";
    std::string InvalidString = "AF";

    uint32_t FoundUInt = 8;
    uint32_t InvalidUInt = 10;

    ComparableTest FoundComparable = {true};
    ComparableTest InvlaidComparable = {false};

    EXPECT_TRUE(Terryn::FirstIndexOf(stringVals, FoundString) == 0);
    EXPECT_TRUE(Terryn::FirstIndexOf(stringVals, InvalidString) == std::nullopt);

    EXPECT_TRUE(Terryn::FirstIndexOf(intVals, FoundUInt) == 8);
    EXPECT_TRUE(Terryn::FirstIndexOf(intVals, InvalidUInt) == std::nullopt);

    EXPECT_TRUE(Terryn::FirstIndexOf(ComparableValues, FoundComparable) == 0);
    EXPECT_TRUE(Terryn::FirstIndexOf(ComparableValues, InvlaidComparable) == std::nullopt);
}

TEST(CollectionHelpers, Array_IndexOf)
{
    std::array<std::string, 5> stringVals = {{"AA", "BB", "CC", "DD", "EE"}};
    std::array<uint32_t, 19> intVals = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7 ,6, 5, 4, 3, 2, 1, 0}};
    std::array<ComparableTest, 5> ComparableValues = {{{true}, {true}, {true}, {true}, {true}}};

    std::string FoundString = "AA";
    std::string InvalidString = "AF";

    uint32_t FoundUInt = 8;
    uint32_t InvalidUInt = 10;

    ComparableTest FoundComparable = {true};
    ComparableTest InvlaidComparable = {false};

    EXPECT_TRUE(Terryn::FirstIndexOf(stringVals, FoundString) == 0);
    EXPECT_TRUE(Terryn::FirstIndexOf(stringVals, InvalidString) == std::nullopt);

    EXPECT_TRUE(Terryn::FirstIndexOf(intVals, FoundUInt) == 8);
    EXPECT_TRUE(Terryn::FirstIndexOf(intVals, InvalidUInt) == std::nullopt);

    EXPECT_TRUE(Terryn::FirstIndexOf(ComparableValues, FoundComparable) == 0);
    EXPECT_TRUE(Terryn::FirstIndexOf(ComparableValues, InvlaidComparable) == std::nullopt);
}
