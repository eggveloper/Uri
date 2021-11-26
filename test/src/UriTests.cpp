/**
 * @file UriTests.cpp
 * 
 * This module contains the unit tests of the Uri::Uri class.
 * 
 * © 2021 by Callum Ali
 */

#include <gtest/gtest.h>
#include <stddef.h>
#include <Uri/Uri.hpp>

TEST(UriTests, ParseFromStringUrl) {
    Uri::Uri uri;

    ASSERT_TRUE(uri.parseFromString("http://www.example.com/foo/bar"));
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
}

TEST(UriTests, ParseFromStringUrnDefaultPathDelimiter) {
    Uri::Uri uri;

    ASSERT_TRUE(uri.parseFromString("urn:book:fantasy:Hobbit"));
    ASSERT_EQ("urn", uri.getScheme());
    ASSERT_EQ("", uri.getHost());
    ASSERT_EQ(
        (std::vector<std::string> {
            "book:fantasy:Hobbit",
        }),
        uri.getPath()
    );
}

TEST(UriTests, ParseFromStringUrnSingleCharacterPathDelimiter) {
    Uri::Uri uri;

    uri.setPathDelimiter(":");

    ASSERT_TRUE(uri.parseFromString("urn:book:fantasy:Hobbit"));
    ASSERT_EQ("urn", uri.getScheme());
    ASSERT_EQ("", uri.getHost());
    ASSERT_EQ(
        (std::vector<std::string> {
            "book",
            "fantasy",
            "Hobbit",
        }),
        uri.getPath()
    );
}

TEST(UriTests, ParseFromStringUrnMultiCharacterPathDelimiter) {
    Uri::Uri uri;

    uri.setPathDelimiter("/-");

    ASSERT_TRUE(uri.parseFromString("urn:bo-/o-k/-fant/asy/-Hob-bit"));
    ASSERT_EQ("urn", uri.getScheme());
    ASSERT_EQ("", uri.getHost());
    ASSERT_EQ(
        (std::vector<std::string> {
            "bo-/o-k",
            "fant/asy",
            "Hob-bit",
        }),
        uri.getPath()
    );
}

TEST(UriTests, ParseFromStringPathCornerCases) {
    struct TestVector {
        std::string pathIn;
        std::vector<std::string> pathOut;
    };

    const std::vector<TestVector> testVectors {
        {"", {}},
        {"/", {""}},
        {"/foo", {"", "foo"}},
        {"foo/", {"foo", ""}},
    };

    size_t index = 0;

    for (const auto& testVector : testVectors) {
        Uri::Uri uri;

        ASSERT_TRUE(uri.parseFromString(testVector.pathIn)) << "Tested vector " << index << ".";
        ASSERT_EQ(testVector.pathOut, uri.getPath()) << "Tested vector " << index << ".";
        
        ++index;
    }
}