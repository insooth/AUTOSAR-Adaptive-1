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

#define CATCH_CONFIG_RUNNER
#include <gmock/gmock.h>
#include <catch2/catch.hpp>
#include <cstdlib>

#include "TestSession.hpp"
#include "gmock_catch_interceptor.hpp"

namespace test::framework
{

TestSession::TestSession()
{
    auto &listeners = ::testing::UnitTest::GetInstance()->listeners();
    delete listeners.Release(listeners.default_result_printer());
    listeners.Append(new test::framework::gmock_catch_interceptor());
}

int TestSession::run(int argc, char *argv[])
{
    int return_code;
    try
    {
        testing::InitGoogleMock();
        return_code = Catch::Session().run(argc, argv);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return_code = EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "Unknown exception caught";
        return_code = EXIT_FAILURE;
    }

    return return_code;
}

} // namespace test::framework