#!/bin/sh
# Fetch the official SQLite amalgamation and place it in thirdparty/sqlite3.
#
# The SQLite amalgamation is public domain.  We compile it together with tbox
# to provide a real database backend for the connection test.
#
# Override the version/year with SQLITE_VERSION / SQLITE_YEAR if needed.
set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
DEST="$ROOT/thirdparty/sqlite3"

SQLITE_VERSION=${SQLITE_VERSION:-3540100}
SQLITE_YEAR=${SQLITE_YEAR:-2026}
URL="https://www.sqlite.org/${SQLITE_YEAR}/sqlite-amalgamation-${SQLITE_VERSION}.zip"

TMP=$(mktemp -d)
trap 'rm -rf "$TMP"' EXIT INT TERM

echo "fetching SQLite amalgamation: $URL"
curl -fL --retry 3 --retry-delay 2 -o "$TMP/sqlite.zip" "$URL"
unzip -q "$TMP/sqlite.zip" -d "$TMP"

mkdir -p "$DEST"
cp "$TMP/sqlite-amalgamation-${SQLITE_VERSION}/sqlite3.c" "$DEST/sqlite3.c"
cp "$TMP/sqlite-amalgamation-${SQLITE_VERSION}/sqlite3.h" "$DEST/sqlite3.h"

echo "SQLite ${SQLITE_VERSION} installed in $DEST"
