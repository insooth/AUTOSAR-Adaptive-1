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

#ifndef SRC_TESTING_FRAMEWORK_TESTSESSION
#define SRC_TESTING_FRAMEWORK_TESTSESSION

namespace test::framework
{

class TestSession
{
public:
    TestSession();

    int run(int argc, char *argv[]);
};

} // namespace test::framework

#endif /* SRC_TESTING_FRAMEWORK_TESTSESSION */
