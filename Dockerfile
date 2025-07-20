FROM ubuntu:22.04

# 设置环境变量避免交互式安装
ENV DEBIAN_FRONTEND=noninteractive

# 安装基础依赖
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    ninja-build \
    git \
    pkg-config \
    curl \
    zip \
    unzip \
    tar \
    python3 \
    python3-pip \
    && rm -rf /var/lib/apt/lists/*

# 安装 vcpkg
RUN git clone https://github.com/Microsoft/vcpkg.git /opt/vcpkg \
    && cd /opt/vcpkg \
    && ./bootstrap-vcpkg.sh

# 设置 vcpkg 环境变量
ENV VCPKG_ROOT=/opt/vcpkg
ENV PATH="$VCPKG_ROOT:$PATH"

# 创建工作目录
WORKDIR /workspace

# 复制项目文件
COPY . .

# 构建项目
RUN cmake --preset=default && \
    cmake --build --preset=debug

# 设置入口点
CMD ["./build/bin/folly_template"]
