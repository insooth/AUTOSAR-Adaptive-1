# Base image is the Ubuntu Focal from Docker Hub
FROM ubuntu:focal

LABEL maintainer="Bartosz Burda <Bartosz.Burda@umlaut.com>"

# Set the env variables
ENV CXX=/usr/bin/g++-10 \
    CC=/usr/bin/gcc-10 \
# This should be changed to your Timezone
    TZ=Europe/Warsaw

# Set timezone
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Add x86 support
RUN dpkg --add-architecture i386

# Install dependencies using apt
RUN DEBIAN_FRONTEND=noninteractive apt -qq update && \
       apt -qq install -y \
       sudo \
       wget \
       git \
	   curl \
	   gcc-10 \ 
	   g++-10 \
       cmake \
	   ninja-build \
       pkg-config \
       gdb \
	   clang-format \
	   python3 \
	   python3-pip \
       python3-setuptools \
       python3-wheel
       
# Install Python packages: Meson and Conan
RUN pip3 install meson conan

# Create user for development
RUN useradd -m dev --uid=1000 && echo "dev:dev" | chpasswd

# Set login shell for dev to /bin/bash
RUN chsh -s /bin/bash dev

# Add user to sudo group
RUN sudo usermod -aG sudo dev

# Set user and work directory
USER dev
WORKDIR /home/dev
