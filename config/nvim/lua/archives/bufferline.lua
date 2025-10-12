return {
  "akinsho/bufferline.nvim",
  dependencies = { "nvim-tree/nvim-web-devicons" },
  config = function()
    vim.opt.termguicolors = true
    local bufferline = require('bufferline')
    bufferline.setup {
      highlights = {
        fill = {
          fg = "NONE",
          bg = "NONE",
        },
      },
      options = {
        buffer_close_icon = '',
        diagnostics = "nvim_lsp"
      }
    }
    vim.keymap.set("n", "<leader>fe", ":BufferLineCyclePrev<CR>", {desc="File (in buffer) prev"})
    vim.keymap.set("n", "<leader>fn", ":BufferLineCycleNext<CR>", {desc="File (in buffer) next"})
  end
}
