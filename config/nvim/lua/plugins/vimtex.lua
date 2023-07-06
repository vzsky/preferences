vim.g.vimtex_view_method = "zathura"

return {
  'lervag/vimtex',
  config = function ()
    vim.g.vimtex_compiler_latexmk = {
      build_dir = "out"
    }
  end
}
