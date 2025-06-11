# Fetch base image
# FROM [--platform=<platform>] <image> [AS <name>]
#FROM ubuntu:22.04
#FROM python:3.6.9-stretch
FROM python:3.13.4-bookworm

# Install prerequirements (run at once, in order to change the base image)
# Install Python
# RUN [OPTIONS] <command> ...
# RUN [OPTIONS] [ "<command>", ... ]
RUN \
    apt-get update && \
    apt-get install -y wget build-essential autoconf automake libtool

# Create a directory for the project
RUN mkdir /project

# Copy the project into image
# COPY [OPTIONS] <src> ... <dest>
# COPY [OPTIONS] ["<src>", ... "<dest>"]
COPY src /project/src
COPY tests /project/tests
COPY Makefile /project/Makefile

# Download, unpack and build CppUTest
RUN \
    mkdir /project/tools && \
    cd /project && \
    wget https://github.com/cpputest/cpputest/releases/download/v4.0/cpputest-4.0.tar.gz && \
    tar xf cpputest-4.0.tar.gz && \
    mv cpputest-4.0 tools/cpputest && \
    cd tools/cpputest/ && \
    autoreconf -i && \
    ./configure && \
    make

# Entry point of container's start
# ENTRYPOINT ["executable", "param1", "param2"]
ENTRYPOINT ["make", "test", "-C", "/project"]
