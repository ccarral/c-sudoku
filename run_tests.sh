#!/bin/bash

echo "Running tests..."

echo "Compiling"

make --directory="tests"

./tests/tests

rm ./tests/tests
