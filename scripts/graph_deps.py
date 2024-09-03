#!/usr/bin/env python3
from pathlib import Path


def get_deps(path: Path) -> list[str]:
    lines = path.read_text().split("\n")
    paths = []
    for line in lines:
        if not line.startswith("#include"):
            continue
        name = line[9:].strip()
        if name.startswith("<"):
            continue
        paths.append(name)
    return paths


def get_file_deps(path: Path) -> dict[str, list[str]]:
    headers = list(path.glob("**/*.h"))
    sources = list(path.glob("**/*.cpp"))
    data = {
        str(k.relative_to(path / "src")): get_deps(k)
        for k in sorted([*headers, *sources])
    }
    return data


def collapse_names(data: dict[str, list[str]]) -> dict[str, list[str]]:
    files = sorted(data.keys())
    collapsed: dict[str, list[str]] = {}
    for file in files:
        name = file
        if file.endswith(".cpp"):
            name = file[:-4]
        if file.endswith(".h"):
            name = file[:-2]
        if name in collapsed:
            collapsed[name].extend(data[file])
        else:
            collapsed[name] = data[file]
    return collapsed


def get_d2(data: dict[str, list[str]]) -> str:
    out = ""
    for k, v in data.items():
        if len(v) == 0:
            continue
        for vv in v:
            out += f"{k} -> {vv.strip("\"")}\n"
    return out


if __name__ == "__main__":
    import sys

    if len(sys.argv) < 3:
        print("USAGE: python scripts/graph_deps.py PATH_SOURCE PATH_D2")
        exit()
    path = Path(sys.argv[1])
    out = Path(sys.argv[2])
    data = get_file_deps(path)
    out.write_text(get_d2(data))
