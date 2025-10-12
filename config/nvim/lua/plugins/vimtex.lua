-- the command to trigger live compiler is "\ll"
return {
  'lervag/vimtex',
  tag = "v2.15",
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

