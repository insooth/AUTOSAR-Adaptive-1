# Project structure - the Pitchfork layout

Date: 11.05.2020

## Status

Accepted

## Context

We need to choose the common project structure for all repositories (main repository and submodules).

## Decision

We will use [the Pitchfork layout](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs) for the whole project.


The main repository will contain the following directories: `tools/`, `docs/`, `libs/`. The `libs/` directory will include functional clusters as git submodules.

The functional cluster repositories will contain the following directories: 

`src/`, `tests/`, `include/ara/`, `examples/`, `tools/`, `docs/`. The project binaries will be stored in the `build/` directory.

## Consequences

All repositories will be consistent and allow you to easily find all required sources and documents.