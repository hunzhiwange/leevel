#!/usr/bin/env bash

set -e

CURRENT_BRANCH="master"

REMOTE="tests";

echo "Pull $REMOTE";

commit=$(date "+Update tests %Y-%m-%d %H:%M:%S")

TMP_DIR="./leevel-tmp-tests"
REMOTE_URL="git@github.com:leevels/$REMOTE.git"

rm -rf $TMP_DIR;

(
    git clone -b $CURRENT_BRANCH $REMOTE_URL --depth=1 $TMP_DIR

    rm -rf "$TMP_DIR/.git"

    cp -rf "$TMP_DIR/"* ./tests/

    rm -rf $TMP_DIR;

    git add $TMP_DIR
    git commit -m "$commit" -n
)
