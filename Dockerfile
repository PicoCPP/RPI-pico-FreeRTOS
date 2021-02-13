FROM ubuntu:20.10
RUN apt update && apt install -y gcc-arm-none-eabi cmake make python3 git doxygen g++
RUN mkdir -pv /code
COPY . /code
WORKDIR /code
RUN git submodule init
RUN git submodule sync
RUN git submodule update --recursive
RUN cd pico-sdk && git submodule init && git submodule sync && git submodule update
RUN cd /code && mkdir build && cd build && cmake .. && make
