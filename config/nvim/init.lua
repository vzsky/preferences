vim.g.mapleader = ' '

local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
  vim.fn.system({
    "git",
    "clone",
    "--filter=blob:none",
    "https://github.com/folke/lazy.nvim.git",
    "--branch=stable",
    lazypath,
  })
end
vim.opt.rtp:prepend(lazypath)

require("lazy").setup({
  { import = "plugins" },
})

-------------- Settings --------------

vim.o.hlsearch = false

vim.wo.relativenumber = true
vim.wo.number = true

vim.opt.tabstop = 2
vim.opt.shiftwidth =2
vim.opt.softtabstop = 2
vim.opt.expandtab = true

vim.opt.cursorline = true
vim.cmd.highlight("CursorLine", "guibg=#655855")


vim.cmd('autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o')

--------------- Keymaps --------------

vim.keymap.set('n', '<leader>p', '<C-^><CR>', { desc = "previously edit file" })

--------------------------------------


