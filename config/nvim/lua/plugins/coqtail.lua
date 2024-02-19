return {
  'whonore/Coqtail',
  opts = {},
  init = function()
    vim.cmd([[
      augroup CoqtailHighlight
      autocmd!
      autocmd ColorScheme * hi def CoqtailChecked   guibg=#4E5E27
                        \ | hi def CoqtailSent      guibg=#546A1D
      augroup END
    ]])
  end,
  config = function()
    local prefix = " c"
    vim.g.coqtail_map_prefix = prefix

    vim.keymap.set("n", prefix .. "n", ":CoqNext<CR>")
    vim.keymap.set("n", prefix .. "e", ":CoqUndo<CR>")
  end
}
