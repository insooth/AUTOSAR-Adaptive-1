srcs = [
    'lib1.cpp',
]

lib = library('library1',
    srcs,
    include_directories: include_directories(['./'])
)

library1_dep = declare_dependency(
    link_with: lib,
    include_directories: ['./']
)
