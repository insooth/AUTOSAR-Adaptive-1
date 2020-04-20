srcs = [
    'gmock_catch_interceptor.cpp',
    'TestSession.cpp',
    'main.cpp'
]

dependencies = [
    dependency('catch2', required: true),
    dependency('gtest', required: true)
]

lib = library('test_framework_lib',
    srcs,
    include_directories: ['./'],
    dependencies: dependencies
)


test_framework_dep = declare_dependency(
    link_with: lib,
    include_directories: ['./'],
    dependencies: dependencies
)
