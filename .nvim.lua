-- Mapping helpers ==========================================================
local map = function(mode, lhs, rhs, desc, opts)
  opts = opts or {}
  opts.desc = desc
  vim.keymap.set(mode, lhs, rhs, opts)
end

local nmap = function(...) map("n", ...) end
local C = function(cmd) return "<Cmd>" .. cmd .. "<CR>" end

-- Basic mappings ===========================================================
nmap("<M-w>", C "!cd build && make -j6", "make")
nmap("<leader><M-w>", C "!cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=true -DCMAKE_BUILD_TYPE=Debug ..", "cmake")
nmap("<M-r>", C "!./build/vststation", "run")

-- nmap("<M-w>", C "!make d2", "make")
