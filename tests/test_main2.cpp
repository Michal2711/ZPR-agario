#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE AgarioTests
#endif

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(bar_suite)

    BOOST_AUTO_TEST_CASE(constructor_test)
    {
        int i = 0;

        BOOST_CHECK_EQUAL(i, 0);
    }

BOOST_AUTO_TEST_SUITE_END()