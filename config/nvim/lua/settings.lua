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

--------------- Keymaps --------------

vim.keymap.set('n', '<leader>p', '<C-^><CR>', { desc = "previously edit file" })
vim.keymap.set('n', '<c-n>', ':wincmd j<CR>', { silent = true })
vim.keymap.set('n', '<c-e>', ':wincmd k<CR>', { silent = true })
vim.keymap.set('n', '<c-m>', ':wincmd h<CR>', { silent = true })
vim.keymap.set('n', '<c-i>', ':wincmd l<CR>', { silent = true })

-- remove Ctrl + O
vim.keymap.set('n', '<c-o>', "<CR>", { silent = true })

--------------------------------------
