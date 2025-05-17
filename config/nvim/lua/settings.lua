-------------- Settings --------------

vim.o.hlsearch = false

vim.wo.relativenumber = true
vim.wo.number = true

vim.opt.tabstop = 2
vim.opt.shiftwidth = 2
vim.opt.softtabstop = 2
vim.opt.expandtab = true

vim.opt.cursorline = true
vim.cmd.highlight("CursorLine", "guibg=#655855")

vim.cmd('autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o')

vim.wo.wrap = false

--------------- Keymaps --------------

vim.keymap.set('n', '<leader>p', '<C-^><CR>', { desc = "previously edit file" })
vim.keymap.set('n', '<c-n>', ':wincmd j<CR>', { silent = true, desc = "window change: down"})
vim.keymap.set('n', '<c-e>', ':wincmd k<CR>', { silent = true, desc = "window change: up"})
vim.keymap.set('n', '<c-m>', ':wincmd h<CR>', { silent = true, desc = "window change: left"})
vim.keymap.set('n', '<c-i>', ':wincmd l<CR>', { silent = true, desc = "window change: right"})

vim.keymap.set("n", "<c-h>", "<C-w>h")
vim.keymap.set("n", "<c-j>", "<C-w>j")
vim.keymap.set("n", "<c-k>", "<C-w>k")
vim.keymap.set("n", "<c-l>", "<C-w>l")


-- remove Ctrl + O
vim.keymap.set('n', '<c-o>', "<CR>", { silent = true })

--------------------------------------
