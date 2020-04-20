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

#ifndef GMOCK_CATCH_INTERCEPTOR
#define GMOCK_CATCH_INTERCEPTOR

#include "gmock/gmock.h"

namespace test::framework
{
class gmock_catch_interceptor : public ::testing::EmptyTestEventListener
{
public:
    virtual ~gmock_catch_interceptor() = default;

    // Called after a failed assertion or a SUCCEED() invocation.
    virtual void OnTestPartResult(::testing::TestPartResult const &test_part_result) override;
};
} /* namespace test::framework */

#endif /* GMOCK_CATCH_INTERCEPTOR */
