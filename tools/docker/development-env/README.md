# The container with dev environment

The Dockerfile contains configuration of the container with development environment:

- C++20
- Python3
- Conan
- Meson
- Git

### Build image

In `tools/dev_env` use:

`docker build -t autosar-adaptive-dev .`

### Run container
`docker run -d -t --name <container_name> -v <repository_path>:<workspace_path> autosar-adaptive-dev`

i.e

`docker run -d -t --name autosar-adaptive-dev-container -v C:\AUTOSAR-Adaptive:/home/dev/workspace autosar-adaptive-dev`

### Connect to Container bash console
`docker exec -it autosar-adaptive-dev-container /bin/bash`

### Credentials 
`dev:dev`

### Usage with VS Code

https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.vscode-remote-extensionpack

### Building library

Go to any library root folder (which are submodules)
i.e.: cd /home/dev/workspace/libs/core

and then:

mkdir build && cd build
meson setup -Db_coverage=true --pkg-config-path .
ninja

### Coverage

Run tests and coverage:
ninja test
ninja coverage-html
