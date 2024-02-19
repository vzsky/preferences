return {
  'lervag/vimtex',
  init = function()
    vim.g.vimtex_view_method = "zathura"
  end,
  config = function()
    vim.g.vimtex_compiler_latexmk = {
      out_dir = "out"
    }
    vim.g.vimtex_view_method = 'zathura'

    vim.cmd("set conceallevel=2")
  end
}
