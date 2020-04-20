/*
 * This file is part of Meson Starter Project.
 * 
 * This is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License Version 3 as published by
 * the Free Software Foundation.
 * 
 * Meson Starter Project is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 */

#include <catch2/catch.hpp>

#include <lib1.hpp>

TEST_CASE("Answer is given", "[answer]")
{
    // REQUIRE(library1::answer() == 123);
    REQUIRE(library1::answer() == 42);
}

TEST_CASE("Matchers test")
{
    using namespace Catch::Matchers;

    CHECK_THAT("Some string", Contains("Some"));
    REQUIRE_THAT("Some string", Contains("string"));
}

SCENARIO("vectors can be sized and resized", "[vector]")
{

    GIVEN("A vector with some items")
    {
        std::vector<int> v(5);

        REQUIRE(v.size() == 5);
        REQUIRE(v.capacity() >= 5);

        WHEN("the size is increased")
        {
            v.resize(10);

            THEN("the size and capacity change")
            {
                REQUIRE(v.size() == 10);
                REQUIRE(v.capacity() >= 10);
            }
        }
        WHEN("the size is reduced")
        {
            v.resize(0);

            THEN("the size changes but not capacity")
            {
                REQUIRE(v.size() == 0);
                REQUIRE(v.capacity() >= 5);
            }
        }
        WHEN("more capacity is reserved")
        {
            v.reserve(10);

            THEN("the capacity changes but not the size")
            {
                REQUIRE(v.size() == 5);
                REQUIRE(v.capacity() >= 10);
            }
        }
        WHEN("less capacity is reserved")
        {
            v.reserve(0);

            THEN("neither size nor capacity are changed")
            {
                REQUIRE(v.size() == 5);
                REQUIRE(v.capacity() >= 5);
            }
        }
    }
}