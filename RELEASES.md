# Release Integrity

Official firmware releases are published with cryptographic checksums and maintainer signatures. Release manifests identify the exact source revision, compiler profile, and build configuration used for each artifact.

The release process supports reproducible builds. Independent builders can use the documented toolchain profile to recreate an artifact and compare its digest with the published manifest.

Unsigned or locally modified artifacts are not considered official releases.
