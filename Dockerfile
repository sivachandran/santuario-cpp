# Dockerfile for libxml-security-c build environment
FROM ubuntu:22.04

RUN apt -y update && \
    apt -y install build-essential

RUN apt -y install cmake
RUN apt -y install libxerces-c-dev libxalan-c-dev
RUN apt -y install libssl-dev
