#!/bin/bash

echo "Running tests..."

echo "Compiling"

make --directory="src"

./src/tests

rm ./src/tests
