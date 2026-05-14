# Architecture

A priority queue stores estimated total cost and actual distance. Stale entries are skipped. Manhattan distance is admissible for the four-connected, unit-cost grid. The I/O layer parses maps, and an independent route validator checks bounds, obstacles, endpoints and adjacency. Seeded random maps compare A-star against zero-heuristic uniform-cost search.

## Data flow

- `include/` — public algorithm and analysis interfaces.
- `src/` — library implementation and CLI.
- `tests/` — independent reference and analysis executables.
- `examples/` — standalone library consumer and input fixtures.
- `benchmarks/` — compiled workload.
- `CMakeLists.txt` — library, executable and CTest targets.

## Limits

Movement is four-connected with unit cost. Dynamic obstacles, diagonal travel, robot footprint, and collision clearance are not modeled. The zero-heuristic baseline is uniform-cost search, not a separate BFS implementation.
