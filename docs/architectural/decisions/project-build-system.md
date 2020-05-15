# Project build system

Date: 13.05.2020

## Status

Accepted

## Context

We need to choose the build system for the whole Adaptive Platform. We consider CMake with Conan, Meson with Conan, and Bazel. The CMake is a feature-rich and known tool, however, it is a bit old. It is quite challenging to handle the big projects with it and the CMake documentation is sometimes vague. The Bazel and Meson are much more user-friendly tools because they are modern and both are based on Python. Adding Conan makes management of external dependencies much easier, which was sometimes quite difficult when using only CMake.

## Decision

We will use Meson as a build system, with a Conan as a dependency management system. The Meson usage is similar to CMake, so it should be quite easy for developers who know CMake to learn it. The Meson integration with Conan is very simple, as it supports the pkg-config files. 

The Bazel is a great build system, but the usage of it, on the other hand, is quite problematic in C++ projects as there are no easy ways to handle external non-Bazel dependencies. Bazel requires creating the BUILD file for each dependency, which can be problematic in some cases. The integration of Conan would require to write some generator class or .bzl extensions to handle generated files from other generators. The Bazel has own solution for dependency management, but it requires extra effort to make it working anyway.

## Consequences

We will use Meson and Conan for the whole Adaptive AUTOSAR Platform. Each Functional Cluster will have meson.build files with a conanrequirements.txt and configure.py file.