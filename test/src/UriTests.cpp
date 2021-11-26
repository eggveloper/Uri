/**
 * @file UriTests.cpp
 * 
 * This module contains the unit tests of the Uri::Uri class.
 * 
 * © 2021 by Callum Ali
 */

#include <gtest/gtest.h>
#include <Uri/Uri.hpp>

TEST(UriTests, ParseFromString) {
    Uri::Uri uri;

    ASSERT_TRUE(uri.parseFromString("http://example.com/foo/bar"));
    ASSERT_EQ("http", uri.getScheme());
    ASSERT_EQ("www.example.com", uri.getHost());
    ASSERT_EQ(
        (std::vector<std::string> {
            "",
            "foo",
            "bar",
        }),
        uri.getPath()
    );

    ASSERT_TRUE(uri.parseFromString("urn:book:fantasy:Hobbit"));
    ASSERT_EQ("urn", uri.getScheme());
    ASSERT_EQ("", uri.getHost());
    ASSERT_EQ(
        (std::vector<std::string> {
            "book",
            "fantasy",
            "hobbit",
        }),
        uri.getPath()
    );
}