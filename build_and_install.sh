#!/bin/bash
set -e

BUILD_DIR=build
PREFIX=$HOME/.local

if [ -d "$BUILD_DIR" ]; then
    echo "[info] Found existing build directory: $BUILD_DIR"
    rm -rf $BUILD_DIR
fi

mkdir "$BUILD_DIR"
echo "[info] Configuring project..."
cmake -S . -B $BUILD_DIR -DCMAKE_INSTALL_PREFIX=$PREFIX

echo "[info] Building project..."
cmake --build $BUILD_DIR

read -p "Install to $PREFIX? (y/n): " choice
if [[ $choice == "y" ]]; then
    cmake --install $BUILD_DIR
    echo "[+] Installed to $PREFIX"
else
    echo "[-] Install skipped."
fi

build/cpp-example

build/c-example