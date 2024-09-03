-- Mapping helpers ==========================================================
local map = function(mode, lhs, rhs, desc, opts)
  opts = opts or {}
  opts.desc = desc
  vim.keymap.set(mode, lhs, rhs, opts)
end

local nmap = function(...) map("n", ...) end
local C = function(cmd) return "<Cmd>" .. cmd .. "<CR>" end

-- Basic mappings ===========================================================
nmap("<M-w>", C "!make -j6", "make")
nmap("<leader><M-w>", C "!cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=true -DCMAKE_BUILD_TYPE=Debug .", "make")
nmap("<M-r>", C "!./vststation", "make")
