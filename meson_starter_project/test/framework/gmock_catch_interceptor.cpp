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

#include "gmock_catch_interceptor.hpp"

#include <catch2/catch.hpp>

namespace
{
void adapter_catch_msg(const char *fileName, const std::size_t lineNr, const Catch::ResultWas::OfType type,
                       const Catch::ResultDisposition::Flags resultDisposition, const std::string msg)
{
    const auto lineInfo = ::Catch::SourceLineInfo(fileName, lineNr);
    Catch::AssertionHandler catchAssertionHandler("GMOCK_FAIL", lineInfo, Catch::StringRef(), resultDisposition);
    catchAssertionHandler.handleMessage(type, (Catch::MessageStream() << msg + ::Catch::StreamEndStop()).m_stream.str());
    catchAssertionHandler.complete();
}
} // namespace

namespace test::framework
{

void gmock_catch_interceptor::OnTestPartResult(
    const ::testing::TestPartResult &gmock_assertion_result)
{
    if (gmock_assertion_result.failed())
    {
        const auto resultDisposition = gmock_assertion_result.fatally_failed() ? Catch::ResultDisposition::Normal : Catch::ResultDisposition::ContinueOnFailure;

        if (gmock_assertion_result.file_name() != nullptr)
        {
            adapter_catch_msg(gmock_assertion_result.file_name(), gmock_assertion_result.line_number(),
                              Catch::ResultWas::ExpressionFailed, resultDisposition, gmock_assertion_result.summary());
        }
        else
        {
            adapter_catch_msg("gmock_error", 0ul, Catch::ResultWas::ExpressionFailed, resultDisposition, gmock_assertion_result.message());
        }
    }
    else
    {
        std::cerr << "Other reason for OnTestPartResult: " << gmock_assertion_result.message() << std::endl;
    }
}

} // namespace test::framework
