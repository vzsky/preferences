return {
  {
    'nvim-telescope/telescope.nvim',
    tag = '0.1.4',
    depedencies = { 'nvim-lua/plenary.nvim' },
    config = function()
      local builtin = require('telescope.builtin')
      vim.keymap.set('n', '<leader>ff', builtin.find_files, { desc = "files find" })
      vim.keymap.set('n', '<leader>fg', builtin.live_grep, { desc = "files grep" })
      vim.keymap.set('n', '<leader>fl', builtin.buffers, { desc = "files last" })
    end
  },
  {
    "nvim-telescope/telescope-file-browser.nvim",
    dependencies = { "nvim-telescope/telescope.nvim", "nvim-lua/plenary.nvim" },
    config = function()
      require("telescope").load_extension("file_browser")
      local fb = require("telescope").extensions.file_browser
      vim.keymap.set('n', '<leader>fb', fb.file_browser, { desc = "file browser" })
    end
  },
  {
    "nvim-telescope/telescope-ui-select.nvim",
    config = function()
      require("telescope").setup({
        extensions = {
          ["ui-select"] = {
            require("telescope.themes").get_dropdown {}
          }
        }
      })
      require("telescope").load_extension("ui-select")
    end
  }
}
