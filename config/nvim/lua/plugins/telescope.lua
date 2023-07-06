return {
  'nvim-telescope/telescope.nvim', tag = '0.1.1',
  depedencies = { 'nvim-lua/plenary.nvim' },
  config = function ()
    local builtin = require('telescope.builtin')
    vim.keymap.set('n', '<leader>ff', builtin.find_files, { desc = "files find" })
    vim.keymap.set('n', '<leader>fg', builtin.live_grep, { desc = "files grep" })
    vim.keymap.set('n', '<leader>fl', builtin.buffers, { desc = "files last"})
  end
}
