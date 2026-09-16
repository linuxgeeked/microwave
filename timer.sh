#!/usr/bin/env bash
set -euo pipefail

root_directory="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
build_directory="${root_directory}/build"

cmake -S "${root_directory}" -B "${build_directory}"
cmake --build "${build_directory}" --parallel "${BUILD_JOBS:-$(nproc 2>/dev/null || printf '2')}"

printf 'Build complete: %s/microwave_calculator\n' "${build_directory}"
