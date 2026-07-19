# A-Star Grid

A reusable C++17 grid planner with map loading, route validation, A-star search and shortest-path cross-checks.

**C++** · Reusable core · CLI examples · Regression checks · Reproducible benchmark

> **Provenance:** created with AI assistance on **2026-11-01**.
> All commit author and committer dates are synthetic and distributed across
> November 2024–October 2026. They do not establish work on those dates.

## Quick start

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j2
./build/experiment_cli examples/warehouse.map 0 0 5 9
```

## Repository map

- `include/` — public algorithm and analysis interfaces.
- `src/` — library implementation and CLI.
- `tests/` — independent reference and analysis executables.
- `examples/` — standalone library consumer and input fixtures.
- `benchmarks/` — compiled workload.
- `CMakeLists.txt` — library, executable and CTest targets.

## How it works

A priority queue stores estimated total cost and actual distance. Stale entries are skipped. Manhattan distance is admissible for the four-connected, unit-cost grid. The I/O layer parses maps, and an independent route validator checks bounds, obstacles, endpoints and adjacency. Seeded random maps compare A-star against zero-heuristic uniform-cost search.

## Verification

```sh
sh scripts/check.sh
```

Four CTest suites with multiple assertions exercise reference cases, invalid inputs, and relevant invariants.
The complete local run is in [docs/verification.txt](docs/verification.txt).
The [checks workflow](.github/workflows/check.yml) executes the same source checks.

## Boundaries

Movement is four-connected with unit cost. Dynamic obstacles, diagonal travel, robot footprint, and collision clearance are not modeled. The zero-heuristic baseline is uniform-cost search, not a separate BFS implementation.

See [architecture](docs/architecture.md), [usage](docs/usage.md),
[release notes](CHANGELOG.md), and [provenance](PROVENANCE.json).

## License

MIT — [LICENSE](LICENSE).
