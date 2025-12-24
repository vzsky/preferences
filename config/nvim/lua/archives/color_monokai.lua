return {
  'patstockwell/vim-monokai-tasty',
  config = function()
     
    vim.api.nvim_create_autocmd({ "ColorScheme" }, {
      callback = function()
        vim.api.nvim_set_hl(0, "Normal", {})
        vim.api.nvim_set_hl(0, 'DiffAdd', { fg="#7af76c" })
        vim.api.nvim_set_hl(0, 'DiffChange', { fg="#09edd2" })
        vim.api.nvim_set_hl(0, 'DiffDelete', { fg="#ed0955" })
        vim.api.nvim_set_hl(0, "LineNr", { fg="#989895" })
      end
    })

    vim.cmd.colorscheme "vim-monokai-tasty"

    vim.g.vim_monokai_tasty_italic = 1
    vim.g.vim_monokai_tasty_highlight_active_window = 1

    vim.api.nvim_set_hl(0, "@comment.typescript", { link = "Comment" })
    vim.api.nvim_set_hl(0, "@keyword.typescript", { link = "Identifier" })
    vim.api.nvim_set_hl(0, "@keyword.function.typescript", { link = "Identifier" })

  end
}
