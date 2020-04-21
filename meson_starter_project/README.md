# C++ Meson Starter Project

C++ Project Skeleton.

## Build

```sh
# Install conan & meson
pip3 install --user --upgrade conan meson

# Create build directory
mkdir build && cd build

# Add build dir to pkg-config search path
export PKG_CONFIG_PATH=$(pwd)

# Configure project
meson ..

# Build project
ninja
```

If not working, ensure that Conan is set to use gcc10 in `.conan/settings.yml`