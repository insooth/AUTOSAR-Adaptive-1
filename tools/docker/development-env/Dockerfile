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
       clang \
       python3 \
       python3-pip \
       python3-setuptools \
       python3-wheel \
       doxygen \
       graphviz \
       clang-tidy \
       flex \
       bison \
       vim

# Yocto pkgs
RUN apt -qq install -y \
       gawk \
       git-core \
       diffstat \
       unzip \
       texinfo \
       gcc-multilib \
       build-essential \
       chrpath \
       socat \
       cpio \
       python3-pexpect \
       xz-utils \
       debianutils \
       iputils-ping \
       python3-git \
       python3-jinja2 \
       libegl1-mesa \
       libsdl1.2-dev \
       pylint3 \
       xterm \
       locales

# Install Python packages: Meson, Conan and gcovr
RUN pip3 install meson conan gcovr

# Create user for development
RUN useradd -m dev --uid=1000 && echo "dev:dev" | chpasswd

# Set login shell for dev to /bin/bash
RUN chsh -s /bin/bash dev

# Add user to sudo group
RUN sudo usermod -aG sudo dev

#set Locale, Yocto need UTF-8
RUN sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen && \
        echo 'LANG="en_US.UTF-8"'>/etc/default/locale && \
        dpkg-reconfigure --frontend=noninteractive locales && \
        update-locale LANG=en_US.UTF-8

ENV LC_ALL en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US.UTF-8

# Set user and work directory
USER dev
WORKDIR /home/dev
