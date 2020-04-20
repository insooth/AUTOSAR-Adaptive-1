subdir('framework')

srcs = [
    'lib1_test.cpp'
]

tests_exec = executable('tests',
    srcs,
    dependencies: [
        test_framework_dep,
        library1_dep,
        dependency('spdlog')
    ]
)

test('tests', tests_exec)