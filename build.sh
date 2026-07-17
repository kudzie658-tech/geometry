#!/data/data/com.termux/files/usr/bin/bash

PROJECT="Geometry"
BUILD_DIR="build"
OUTPUT="$BUILD_DIR/$PROJECT"

if [ "$1" == "clean" ]; then
    rm -rf $BUILD_DIR
    echo "🧹 Build folder removed"
    exit
fi

mkdir -p $BUILD_DIR

echo "🔨 Building $PROJECT..."

FLAGS="-std=c++23 -Wall -Wextra"

if [ "$1" == "debug" ]; then
    echo "🐞 Debug mode enabled"
    FLAGS="$FLAGS -g -O0"
else
    FLAGS="$FLAGS -O2"
fi

clang++ $FLAGS src/*.cpp -o $OUTPUT

if [ $? -eq 0 ]; then
    echo "✅ Build successful"
    echo "▶ Running $PROJECT..."
    echo ""

    ./$OUTPUT
else
    echo "❌ Build failed"
fi
