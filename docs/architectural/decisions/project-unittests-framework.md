# Project unit tests framework

Date: 07.06.2020

## Status

Proposed

## Context

Decision to choose unit testing and mocking frameworks for AP functional cluster C++ implementations.

Considered avaliable unit testing frameworks:
* Boost.Test
  - \+ Feature rich, comprehensible syntax
  - \+ Powerful dataset concept for generating test cases
  - \- No build-in mocking FW (can be used with boost.turtle)
* Catch2
  - \+ Lightweight, header-only (no external dependencies)
  - \+ Beautiful, simple syntax
  - \+ Support for side-effects safe, isolated and named sections
  - \+ Only one core assertion macro for comparisons
  - \+ Test cases tagging (usefull for traceability)
  - \- No built-in mocking FW (supports many popular mocking libraries)
* Google Test
  - \+ Widely known, feature-rich, industry standard FW
  - \+ Comes with google mock (hard to use with other mocking FW)
  - \+ Supports death-tests
  - \- Complex API with a lot of different macros

Considered avaliable mocking frameworks:
* FakeIT
  - \+ Simple, header-only
  - \+ Can be integrated with GTest, Boost.Test
  - \+ Expressive syntax
  - \+ No limitation on number of method arguments.
  - \- On GCC, optimization flag O2 and O3 are not supported
  - \- Can't mock classes with multiple and/or virtual inheritance
  - \- Not thread-safe
  - \- No support for `override` specifier
* GMock
  - \+ Widely known, feature-rich, industry standard FW
  - \+ Comes with GTest
  - \+ Comes with a rich set of matchers for validating function arguments
  - \- Not thread-safe
* Trompeloeil
  - \+ Header only
  - \+ Easy integration with unit testing libraries
  - \+ Simple and powerful syntax
  - \+ Thread safe
  - \- Hardly pronounced/spelled name

## Decision

A pair, Catch2/Trompeloeil is going to be used for unit testing and mocking respectively.

Catch2 is easy to learn and integrate with C++ projects, which, together with its philosophy, reduces the additional development work and boilerplate code in unit tests.
BDD-style sections are self-explanatory and provides side-effect safe implementation of unit tests.
Support for tagging test cases can be used for requirement traceability.  
Although Catch2 does not provide its own mocking fraework, it can be easily integrated with any popular mocking frameworks.

Trompeloeil seems to be feature rich enough, easy to integrate with Catch2 and learn. It's also thread-safe!

## Consequences

We will use Catch2/Trompeloeil for the whole Adaptive AUTOSAR Functional Clusters C++ implementations. Each Functional Cluster will integrate Catch2 and Trompeloeil using Meson and Conan configuration.
