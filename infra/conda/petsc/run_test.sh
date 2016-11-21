set -e

export PETSC_DIR=${PREFIX}
cd "${SRC_DIR}/src/snes/examples/tests"
make ex1

# FIXME: runex1 causes early termination with success (?!) on Linux
# preventing upload. Still a complete mystery.
if [[ "$(uname)" == "Darwin" ]]; then
    make runex1
fi
