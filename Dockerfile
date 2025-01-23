FROM ubuntu:latest

RUN apt update && apt install -y \
    cmake \
    g++-12 \
    libgtest-dev \
    googletest \
    google-mock \
    libboost-dev \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /matrix

COPY . /matrix

RUN rm -rf build

RUN cmake -S . -B build -DCMAKE_CXX_COMPILER=g++-12 -DCMAKE_BUILD_TYPE=Release
RUN cmake --build build

CMD ["valgrind", "--leak-check=full", "./build/testex"]
#CMD ["./build/testex"]