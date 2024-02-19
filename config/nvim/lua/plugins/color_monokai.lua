return {
  'patstockwell/vim-monokai-tasty',
  config = function()
    vim.api.nvim_create_autocmd({ "ColorScheme" }, {
      callback = function()
        vim.api.nvim_set_hl(0, "Normal", {})
      end
    })
    vim.cmd.colorscheme "vim-monokai-tasty"
  end
}
